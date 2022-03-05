/**
 * @file jisho.c
 * @author Christian Sargusingh
 * @brief 
 * @version 0.1
 * @date 2022-03
 * 
 * @copyright Copyright © 2022 Christian Sargusingh
 * 
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <merase.h>
#include "jisho.h"

static element_t _DELETED_ELEM = {NULL, NULL};

static element_t *_new_element(const char *key, const char *value) {
  element_t *elem = malloc(sizeof(element_t));
  elem->key = strdup(key);
  elem->value = strdup(value);
  return elem;
}

static void _delete_element(element_t *elem) {
  if (elem == NULL || elem == &_DELETED_ELEM)
    return;
  trace("Freeing element key string: %s", elem->key);
  free(elem->key);
  trace("Freeing element key value %s", elem->value);
  free(elem->value);
  trace("Freeing element");
  free(elem);
}

static int _hash(const char *s, const int seed, const int bucket_size) {
  long hash = 0;
  const size_t str_length = strlen(s);
  for (int i = 0; i < str_length; i++) {
    hash += (long)pow(seed, str_length - (i+1)) * s[i];
    hash %= bucket_size;
  }
  return (int)hash;
}

static int _double_hash(const char *s, const int buckets, const int collisions) {
  const int hash_a = _hash(s, PRIMARY_HASH_PRIME, buckets);
  const int hash_b = _hash(s, SECONDARY_HASH_PRIME, buckets);
  // add 1 to secondary hash to avoid automatic collision at index 0
  return hash_a + (collisions * (hash_b + 1)) % buckets;
}

map_t* jisho_new() {
  map_t *map = malloc(sizeof(map_t));
  map->size = 53;
  map->count = 0;
  map->elements = calloc((size_t)map->size, sizeof(element_t));
  return map;
}

void jisho_delete(map_t *map) {
  if (map == NULL)
    return;
  for (int i = 0; i <  map->size; i++) {
    element_t *elem = map->elements[i];
    if (elem != NULL && elem != &_DELETED_ELEM)
      _delete_element(elem);
  }
  trace("Freeing map elements");
  free(map->elements);
  trace("Freeing map");
  free(map);
}

void jisho_insert(map_t *map, const char *key, const char *value) {
  int index;
  int collisions = -1;
  element_t *old_elem;
  element_t *new_elem = _new_element(key, value);
  do {
    index = _double_hash(new_elem->key, map->size, ++collisions);
    old_elem = map->elements[index];
    _delete_element(old_elem);
  } while (old_elem != NULL && old_elem != &_DELETED_ELEM);
  map->elements[index] = new_elem;
  map->count++;
  trace("Index: %d Count: %d", index, map->count);
  info("Inserted element: { %s: %s }", new_elem->key, new_elem->value);
}

char *jisho_get(map_t *map, const char *key) {
  int index;
  int collisions = -1;
  element_t *elem;
  do {
    index = _double_hash(key, map->size, ++collisions);
    elem = map->elements[index];
    trace("Index: %d", index);
    if (elem != &_DELETED_ELEM && strcmp(elem->key, key) == 0)
      info("Found element %s", key);
      return elem->value;
  } while (elem != NULL);
  return NULL;
}


void jisho_remove(map_t *map, const char *key) {
  int index;
  int collisions = -1;
  element_t *elem;
  do {
    index = _double_hash(key, map->size, ++collisions);
    elem = map->elements[index];
    if (elem != &_DELETED_ELEM && strcmp(elem->key, key) == 0) {
      info("Deleting element: { %s: %s }", elem->key, elem->value);
      _delete_element(elem);
      map->elements[index] = &_DELETED_ELEM;
    }
  } while (elem != NULL);
  map->count--;
}
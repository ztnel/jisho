/**
 * @file jisho.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03
 * 
 * @copyright Copyright © 2022 Christian Sargusingh
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "jisho.h"

static element_t *new_element(const char *key, const char *value) {
  element_t *elem = malloc(sizeof(element_t));
  elem->key = strdup(key);
  elem->value = strdup(value);
  return elem;
}

static void delete_element(element_t *elem) {
  free(elem->key);
  free(elem->value);
  free(elem);
}

map_t* jisho_new() {
  map_t *map = malloc(sizeof(map_t));
  map->size = 53;
  map->count = 0;
  map->elements = calloc((size_t)map->size, sizeof(element_t));
  return map;
}

void jisho_delete(map_t *map) {
  for (int i = 0; i <  map->size; i++) {
    element_t *elem = map->elements[i];
    if (elem != NULL)
      delete_element(elem);
  }
  free(map->elements);
  free(map);
}
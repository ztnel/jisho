/**
 * @file jisho.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03
 * 
 * @copyright Copyright © 2022 Christian Sargusingh
 * 
 */

#ifndef JISHO_H_
#define JISHO_H_

#define PRIMARY_HASH_PRIME 131
#define SECONDARY_HASH_PRIME 151

typedef struct {
  char *key;
  char *value;
} element_t;

typedef struct {
  element_t **elements;
  int size;
  int count;
} map_t;

void jisho_delete(map_t *map);
map_t* jisho_new();
void jisho_insert(map_t *map, const char *key, const char *value);
char *jisho_get(map_t *map, const char *key);
// void jisho_remove(map_t *map, const char *key);


#endif  // JISHO_H_

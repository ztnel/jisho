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


#endif  // JISHO_H_

/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03
 * 
 * @copyright Copyright © 2022 Christian Sargusingh
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <merase.h>
#include <jisho.h>

static map_t *jisho;

static void _handler() {
  jisho_delete(jisho);
}

int main(int argc, char **argv) {
  merase_set_level(TRACE);
  jisho = jisho_new();
  atexit(_handler);
  jisho_insert(jisho, "test", "key");
  printf("Get: %s", jisho_get(jisho, "test"));
  return EXIT_SUCCESS;
}
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

#include <stdio.h>
#include <jisho.h>

int main(int argc, char **argv) {
  char *string = argv[1];
  map_t *jisho = jisho_new();
  jisho_delete(jisho);
  int hash = jisho_hash(string, 151, 53);
  printf("Hash of %s is 0x%04x\n", string, hash);
}
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

#include <jisho.h>

int main(int argc, char **argv) {
  map_t *jisho = jisho_new();
  jisho_delete(jisho);
}
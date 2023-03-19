#ifndef __YEMU_H__
#define __YEMU_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      fprintf(stderr, format "\n", ## __VA_ARGS__); \
      assert(cond); \
    } \
  } while (0)
  
#define Perror(cond, format, ...) \
  Assert(cond, format ": %s", ## __VA_ARGS__, strerror(errno))

#define panic(...) Assert(0, __VA_ARGS__)

#define MSIZE 1024
extern uint8_t M[MSIZE];

#endif

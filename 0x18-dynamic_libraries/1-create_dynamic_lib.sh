#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -c -fPIC *.c
gcc -shared -o liball.so *.o

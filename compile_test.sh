#!/bin/sh

gcc -shared -fPIC g_ll.c -o libgll.so
gcc -L$(pwd) -o test test.c -lgll

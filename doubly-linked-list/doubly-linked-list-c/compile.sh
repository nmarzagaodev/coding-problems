#!/bin/bash

cflags="-Wall -Wextra -g -Wunreachable-code"

gcc $cflags -o list *.c *.h

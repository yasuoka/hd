hd.c
====

A small implementation of printing hexadecimal dump with ascii string in C

hd2.c is for more restricted systems(eg. bootloader).

Example
-------

    % cc -o example example.c hd.c
    % ./example < example.c
    00000000  23 69 6e 63 6c 75 64 65 - 20 3c 73 79 73 2f 74 79 |#include <sys/ty|
    00000010  70 65 73 2e 68 3e 0a 0a - 23 69 6e 63 6c 75 64 65 |pes.h>..#include|
    00000020  20 3c 73 74 64 6c 69 62 - 2e 68 3e 0a 23 69 6e 63 | <stdlib.h>.#inc|
    00000030  6c 75 64 65 20 3c 75 6e - 69 73 74 64 2e 68 3e 0a |lude <unistd.h>.|
    00000040  0a 76 6f 69 64 09 20 68 - 64 28 63 6f 6e 73 74 20 |.void. hd(const |
    00000050  75 5f 63 68 61 72 20 2a - 2c 20 69 6e 74 29 3b 0a |u_char *, int);.|
    00000060  0a 69 6e 74 0a 6d 61 69 - 6e 28 69 6e 74 20 61 72 |.int.main(int ar|
    00000070  67 63 2c 20 63 68 61 72 - 20 2a 61 72 67 76 5b 5d |gc, char *argv[]|
    00000080  29 0a 7b 0a 09 73 73 69 - 7a 65 5f 74 09 20 73 69 |).{..ssize_t. si|
    00000090  7a 3b 0a 09 63 68 61 72 - 09 20 62 75 66 5b 35 31 |z;..char. buf[51|
    000000a0  32 5d 3b 0a 0a 09 77 68 - 69 6c 65 20 28 28 73 69 |2];...while ((si|
    000000b0  7a 20 3d 20 72 65 61 64 - 28 53 54 44 49 4e 5f 46 |z = read(STDIN_F|
    000000c0  49 4c 45 4e 4f 2c 20 62 - 75 66 2c 20 73 69 7a 65 |ILENO, buf, size|
    000000d0  6f 66 28 62 75 66 29 29 - 29 20 3e 20 30 29 0a 09 |of(buf))) > 0)..|
    000000e0  09 68 64 28 62 75 66 2c - 20 73 69 7a 29 3b 0a 0a |.hd(buf, siz);..|
    000000f0  09 65 78 69 74 28 45 58 - 49 54 5f 53 55 43 43 45 |.exit(EXIT_SUCCE|
    00000100  53 53 29 3b 0a 7d 0a                              |SS);.}.         |
    %

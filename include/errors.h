#ifndef ERROR_H
#define ERROR_H

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define CHK(op)            \
    do {                   \
        if ((op) == -1)    \
            raler(1, #op); \
    } while (0)

#define CHKP(op)           \
    do {                   \
        if ((op) == NULL)  \
            raler(1, #op); \
    } while (0)

noreturn void raler(int syserr, const char *msg, ...);

#endif
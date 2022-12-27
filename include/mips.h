
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
// kill -9 `ps eaux | grep ordonnanceur | tr -s ' ' | cut -d ' ' -f2`
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "quads.h"
#include "tos.h"
extern listQ *Lglobal;
extern struct tos **tos[MAX_DEPTH];

void mips(void);

void QuadToMips(int file, listQ *liste, char *buffer);
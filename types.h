#ifndef TYPES_H
#define TYPES_H

#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <string.h>

typedef int ElementType;
typedef char *DirectoryOrFile;

#define NotFound -1

#define Max(a, b) \
    ((a) > (b) ? (a) : (b))

#define Error(s) printf(s)

#define FatalError(s) ({ \
    printf(s); \
})

#endif

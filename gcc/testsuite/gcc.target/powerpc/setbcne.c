/* { dg-do compile } */
/* { dg-options "-O2 -mcpu=future" } */

#define NAME ne
#define CODE !=

#include "setbc.h"

/* { dg-final { scan-assembler-times {\msetbcr\M} 20 } } */

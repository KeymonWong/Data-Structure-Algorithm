/** 二进制转换为十进制 利用栈 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 20
#define STACK_INCREMENT 10

typedef char ElemType;
typedef struct
{
  ElemType *base;
  ElemType *top;
  int stackSize;
}sqStack;

void initStack(sq)

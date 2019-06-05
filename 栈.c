#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
typedef int ElemType;

/** 栈的顺序存储结构 */
typedef struct
{
  ElemType *base; ///< 指向栈底的指针变量
  ElemType *top; ///< 指向栈顶的指针变量
  int stackSize; ///< 栈当前可使用的最大容量
}sqStack;

/** 创建一个栈 */
initStack(sqStack *s)
{
  s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
  if (!s->base)
  {
    exit(0);
  }

  s->top = s->base; // 最开始，栈顶就是栈底
  s->stackSize = STACK_INIT_SIZE;
}

/** 入栈 */
#define STACK_INCREMENT 10
push(sqStack *s, ElemType e)
{
  // 如果栈满，追加空间
  if (s->top - s->base >= s->stackSize)
  {
    s->base = (ElemType *)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(ElemType));
    if (!s->base)
    {
      exit(0);
    }

    s->top = s->base + s->stackSize; // 设置栈顶
    s->stackSize = s->stackSize + STACK_INCREMENT;
  }

  *(s->top) = e;
  s->top++;
}

/** 出栈 */
pop(sqStack *s, ElemType *e)
{
  if (s->top == s->base) // 栈空
  {
    return;
  }
  // top指向位置的下一个元素出栈
  *e = *--(s->top);
}
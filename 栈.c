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
void initStack(sqStack *s)
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
void push(sqStack *s, ElemType e)
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
void pop(sqStack *s, ElemType *e)
{
  if (s->top == s->base) // 栈空
  {
    return;
  }
  // top指向位置的下一个元素出栈
  *e = *--(s->top);
}

/** 清空栈 就是将栈中的元素全部作废，但栈本身的物理空间并不发生改变(不是销毁) */
void clearStack(sqStack *s)
{
  s->top = s->base;
}

/** 销毁栈 释放掉该栈占据的物理空间 */
void destroyStack(sqStack *s)
{
  int i, len;
  len = s->stackSize;
  for (int i = 0; i < len; i++)
  {
    free(s->base);
    s->base++;
  }
  s->base = s->top = NULL;
  s->stackSize = 0;
}

/** 获取栈当前容量，和栈的最大容量不一样，栈的最大容量是指该栈占据的内存空间的大小，其值为s.stackSize */
int stackLen(sqStack s)
{
  return s.top - s.base; // 指针之间是不能相加的，你可以说 指针++ 指针--；指针之间是可以相减的。另 top 和 base 的类型要一致，不然相减会出错
}

int main(int argc, char const *argv[])
{
  return 0;
}

/** 二进制转换为十进制 利用栈 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACK_INCREMENT 10

typedef char ElemType;
typedef struct
{
  ElemType *base;
  ElemType *top;
  int stackSize;
}sqStack;

/** 初始化栈 */
void InitStack(sqStack *s)
{
  s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
  if (!s->base)
  {
    exit(0);
  }
  s->top = s->base;
  s->stackSize = STACK_INIT_SIZE;
}

/** 压栈 */
void Push(sqStack *s, ElemType e)
{
  // 防止栈溢出(上溢出)
  if (s->top - s->base >= s->stackSize)
  {
    s->base = (ElemType *)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(ElemType));
    if (!s->base)
    {
      exit(0);
    }
  }

  // 入栈操作
  *(s->top) = e;
  s->top++;
}

/** 弹栈 */
void Pop(sqStack *s, ElemType *e)
{
  // 防止栈溢出(下溢出)
  if (s->top == s->base)
  {
    return;
  }

  *e = *--(s->top);
}

/** 注意：要对栈作修改的要用指针的形式传进来，不会对栈修改的直接传他的数据(结构)，访问指针的成员用 -> ； 访问结构的成员用 . ；*/
/** 栈当前容量 */
int StackLen(sqStack s)
{
  return (s.top - s.base);
}

int main() {
  ElemType c;
  sqStack s;
  int len, i, sum = 0;

  InitStack(&s);

  printf("请输入二进制，输入#表示结束！\n");
  scanf("%c", &c);
  while (c != '#')
  {
    Push(&s, c);
    scanf("%c", &c);
  }

  getchar(); // 把 '\n' 从缓冲器去掉
  len = StackLen(s);
  printf("栈的当前容量为：%d\n", len);

  for (int i = 0; i < len; i++)
  {
    Pop(&s, &c);
    // ASII 码 48 代表数字 0
    sum = sum + (c - 48) * pow(2, i);
  }
  printf("转换为十进制的数据为：%d\n", sum);
  

  return 0;
}

/** 逆波兰表达式 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACK_INCREMENT_SIZE 10
#define MAX_BUFFER 10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} sqStack;

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

void Push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACK_INCREMENT_SIZE) * sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACK_INCREMENT_SIZE;
    }
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        return;
    }

    *e = *--(s->top); // 将栈顶元素弹出并修改栈顶指针
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    sqStack s;
    char c;
    double d, e;
    char str[MAX_BUFFER]; //输入的字符串，字符串自带最大缓冲区
    int i = 0;

    InitStack(&s);

    printf("请按照逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以#作为结束标志: \n");
    scanf("%c", &c);

    while (c != '#')
    {
        // 过滤数字，包括小数
        while (isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i] = '\0';
            if (i > MAX_BUFFER)
            {
                printf("出错：输入的单个数据过大！\n");
                return -1;
            }
            scanf("%c", &c);
            
            // 如果遇到空格
            if (c == ' ')
            {
                d = atof(str); // 字符类型转为浮点类型
                Push(&s, d);
                i = 0;
                break;
            }
        }
        
        switch (c)
        {
        case '+':
            Pop(&s, &e);
            Pop(&s, &d);
            Push(&s, d + e);
            break;
        case '-':
            Pop(&s, &e);
            Pop(&s, &d);
            Push(&s, d - e);
            break;
        case '*':
            Pop(&s, &e);
            Pop(&s, &d);
            Push(&s, d * e);
            break;
        case '/':
            Pop(&s, &e);
            Pop(&s, &d);
            if (e == 0)
            {
                printf("\n出错：除数不能为 0！\n");
                return -1;
            }
            else
            {
                Push(&s, d / e);
            }
            break;
        }

        scanf("%c", &c);
    }

    Pop(&s, &d);
    printf("\n最终的计算结果是：%f\n", d);
    
    return 0;
}

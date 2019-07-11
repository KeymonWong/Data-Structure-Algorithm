#include <stdio.h>

/** 斐波那契数列的递归实现 */
int Fib(int i)
{
    if (i < 2)
    {
        return i == 0 ? 0 : 1;
    }
    return Fib(i - 1) + Fib(i - 2);
}

void print()
{
    char a;
    scanf("%c", &a);
    if (a != '#')
    {
        print();
    }
    if (a != '#')
    {
        printf("%c", a);
    }
}

int main(int argc, char const *argv[])
{
    int res;
    res = Fib(10);
    printf("%d\n", res);

    print();
    
    return 0;
}

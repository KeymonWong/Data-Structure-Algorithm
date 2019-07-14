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

/** 汉诺塔 */
// 将 n 个盘子从 x 借助 y 移动到 z
void move(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("%c --> %c\n", x, z);
    }
    else
    {
        move(n - 1, x, z, y); // 将 n-1 个盘子从 x 借助 z 移动到 y 上
        printf("%c --> %c\n", x, z); // 将第 n 个盘子从 x 移动到 z 上
        move(n - 1, y, x, z); //将 n-1 个盘子从 y 借助 x 移动到 z 上
    }
}

/** 八皇后 */

int main(int argc, char const *argv[])
{
    int res;
    res = Fib(10);
    printf("%d\n", res);

    int n;
    printf("请输入汉诺塔的层数：");
    scanf("%d", &n);
    printf("移动的步骤如下：\n");
    move(n, 'X', 'Y', 'Z');

    // print();
    
    return 0;
}

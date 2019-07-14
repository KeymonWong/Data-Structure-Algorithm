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

/** 八皇后 
 * 8x8 格的棋盘上摆放 8 个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上
 * 问：共有多少种摆法
 *
 * rowIndex：起始行下标
 * n：总列数 8
 * (*chess)[8]：表示指向棋盘每一行的指针
 * 
 * 如下图棋盘，1 代表放皇后，0 代表不放皇后
 * 
 *        0   1   2   3   4   5   6   7   
 *      ┌┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┬┈┈┈┐
 *  0   ┆ 1 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  1   ┆ 0 ┆ 0 ┆ 1 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  2   ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 1 ┆ 0 ┆ 0 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  3   ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 1 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  4   ┆ 0 ┆ 1 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  5   ┆ 0 ┆ 0 ┆ 0 ┆ 1 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  6   ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 1 ┆ 0 ┆ 0 ┆
 *      ├┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┼┈┈┈┤
 *  7   ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 0 ┆ 1 ┆
 *      └┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┴┈┈┈┘
 *  
 */

int count = 0;
int IsNotDanger(int, int, int (*)[]); // 函数声明，这里也可以不指定参数

void EightQueen(int rowIndex, int n, int (*chess)[8])
{
    int tempChess[8][8]; //临时二维数组
    int i; //行
    int j; //列

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tempChess[i][j] = chess[i][j];
        }
    }
    
    if (rowIndex == 8)
    {
        printf("第 %d 种", (count + 1));
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", *(*(tempChess + i) + j));
                printf("\n");
            }
        }
        printf("\n");
        count++;
    } 
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (IsNotDanger(rowIndex, j, chess))
            {
                // 先把 当前行 的每一列都置为 0
                for (int k = 0; k < 8; k++)
                {
                    *(*(tempChess + rowIndex) + k) = 0;
                }
                // 再把当前行没有危险的这一列置为 1
                *(*(tempChess + rowIndex) + j) = 1;

                // 迭代
                EightQueen(rowIndex + 1, n, tempChess);
            }
        }
    }
}

int IsNotDanger(int rowIndex, int columnIndex, int (*chess)[8])
{

    return 1;
}

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

#include <stdio.h>

/**
 * KMP 算法核心：避免不必要的回溯
 * 问题由模式串决定，不是由目标串决定的
 * 
 * 如下 s 串，是一个数组，i 为下标，其中数组第 0 个元素存放的是 T 串长度
 *  T   9  a   b   a   b   a   a   a   b   a
 *  i   0  1   2   3   4   5   6   7   8   9
 * next -  0   1   1   2   3   4   2   2   3
 */

typedef char * String;

void getNext(String T, int *next) 
{
    int j = 0; //前缀
    int i = 1; //后缀
    next[1] = 0; //永远为 0

    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            i++;
            j++;
            next[i] = j;

            // //优化 之后 和 之前不一样了，莫名
            // if (T[i] != T[j]) {
            //     next[i] = j;
            // } else { //特殊情况
            //     next[i] = next[j];
            // }
        } else {
            //回溯
            j = next[j];
        }
    } 
}

//返回子串 T 在主串 S 第 pos 个字符之后的位置
//若不存在，则返回 0
int index_KMP(String S, String T, int pos)
{
    int i = pos;
    int j = 1;
    int next[255];

    getNext(T, next);

    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        } 
    }

    if (j > T[0]) {
        return i - T[0];
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char str[255] = " ababaaaba";
    int next[255];
    int i = 1;

    str[0] = 9;

    getNext(str, next);

    for (i = 1; i < 10; i++) {
        printf("%d ", next[i]);
    }

    return 0;
}




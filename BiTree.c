#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//创建一棵二叉树，约定用户遵循前序遍历的方式输入数据
void BuildBiTree(BiTree *T)
{
    char c;

    scanf("%c", &c);

    if (c == ' ') {
        *T = NULL;
    } else {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        BuildBiTree(&(*T)->lchild);
        BuildBiTree(&(*T)->rchild);
    }
}

//访问二叉树结点的具体操作
void visit(ElemType c, int level)
{
    printf("%c 位于第 %d 层\n", c, level);
}

//前序遍历
void PreOrderTraverse(BiTree T, int level)
{
    if (T) {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level + 1);
        PreOrderTraverse(T->rchild, level + 1);
    }
}

int main(int argc, char const *argv[])
{
    int level = 1;
    BiTree T = NULL;

    BuildBiTree(&T);
    PreOrderTraverse(T, level);
    
    return 0;
}

//线索二叉树

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位
//Link 0 ：表示指向左右孩子的指针，指针标志
//Thread 1 ：表示指向前驱、后继的线索，线索标志
//结点的child域类型，link表示是指针，指向孩子结点，thread表示是线索，指示前驱或后继结点 
typedef enum {
    Link, 
    Thread
} PointerTag;

typedef struct BiThrTNode
{
    ElemType data;
    struct BiThrTNode *lchild, *rchild;
    PointerTag ltag, rtag;
} BiThrTNode, *BiThrTree;

//创建一个二叉树，约定用户遵循前序遍历的方式输入数据
void CreateBiThrTree(BiThrTree *T)
{
    char c;
    scanf("%c", &c);
    if (c == ' ') {
        *T = NULL;
    } else {
        *T = (BiThrTNode *)malloc(sizeof(BiThrTNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
    
    
}
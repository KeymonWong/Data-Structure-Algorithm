/****** 树的存储结构 ******/

//树的双亲表示法 结点结构定义
#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct PTNode
{
    ElemType data; //结点数据
    int parent; //双亲位置
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int root; //根的位置
    int count; //结点数目
} PTree;

//

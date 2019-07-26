/****** 树的存储结构 ******/

//树的双亲表示法 结点结构定义
#define MAX_TREE_SIZE 100

typedef char ElemType;

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


//孩子表示法


//双亲孩子表示法
//孩子结点
typedef struct CTNode
{
    int child; //孩子结点的下标
    struct CTNode *next; //指向下一个孩子结点的指针
} *ChildPtr;

//表头结构
typedef struct
{
    ElemType data; //存放在树中的结点的数据
    int parent; //存放双亲的下标
    ChildPtr firstChild; //指向第一个孩子的指针
} CTBox;

//树的结构
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE]; //结点数组
    int r; //根的位置
    int n; //结点数目
} PCTree;

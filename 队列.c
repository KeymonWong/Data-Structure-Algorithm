#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct QNode 
{
  ElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct 
{
  QueuePtr front, rear; // 队头、队尾指针
} LinkQueue;

/*************** --- 队列的链式存储结构 begin --- *******************/

/**
 * @brief 创建一个队列
 * 
 * 步骤：
 * 1.在内存中创建一个头结点
 * 2.将队列的头指针和尾指针都指向这个生成的头结点
 */
void InitQueue(LinkQueue *q)
{
  q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
  if (!q->front)
  {
    exit(0);
  }
  q->front = q->rear = NULL;
}

/**
 * @brief 入队列操作
 */
void InsertQueue(LinkQueue *q, ElemType e)
{
  QueuePtr p;
  p = (QueuePtr)malloc(sizeof(QNode));
  if (p == NULL)
  {
    exit(0);
  }
  p->data = e;
  p->next = NULL;
  q->rear->next = p;
  q->rear = p;
}

/**
 * @brief 出队列操作
 * 将队列中的第一个元素移出，队头指针不发生改变，改变头结点的 next 指针即可
 * 若原队列只有一个元素，那么我们就应该处理一下队尾指针
 */
void DeleteQueue(LinkQueue *q, ElemType *e)
{
  QueuePtr p;
  // 空队列
  if (q->front == q->rear)
  {
    return;
  }
  p = q->front->next;
  *e = p->data;
  q->front->next = p->next;
  // 队列只有一个元素
  if (q->rear == p)
  {
    q->rear = q->front;
  }
  free(p);
}

/**
 * @brief 销毁队列操作
 */
void DestroyQueue(LinkQueue *q)
{
  while (q->front)
  {
    q->rear = q->front->next;
    free(q->front);
    q->front = q->rear;
  }
}

/*************** --- 队列的链式存储结构 end --- *******************/


/*************** --- 队列的顺序存储结构 begin --- *******************/

/**
 * @brief 定义一个循环队列
 */
#define MAX_SIZE 100
typedef struct
{
  ElemType *base; // 用于存放内存分配基地址，这里也可以用数组存放
  int front;
  int rear;
} cycleQueue;

/**
 * @brief 初始化一个循环队列
 */
void InitCycleQueue(cycleQueue *q)
{
  q->base = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
  if (!q->base)
  {
    exit(0);
  }
  q->front = q->rear = 0;
}

/**
 * @brief 入循环队列
 */
void InsertCycleQueue(cycleQueue *q, ElemType e)
{
  if ((q->rear + 1) % MAX_SIZE == q->front)
  {
    return; // 队列已经满了
  }
   q->base[q->rear] = e;
   q->rear = (q->rear + 1) % MAX_SIZE;
}

/**
 * @brief 出循环队列
 */
void DeleteCycleQueue(cycleQueue *q, ElemType *e)
{
  if (q->front == q->rear)
  {
    return; // 队列为空
  }
  *e = q->base[q->front];
  q->front = (q->front + 1) % MAX_SIZE;
}

/*************** --- 队列的顺序存储结构 end --- *******************/


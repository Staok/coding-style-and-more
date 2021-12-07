/* 以下概念介绍引自 xxx */
/*
    单链表 概念
    使用多个链表节点来存储本节点的存储数据（使用任意存储单元来存储线性表中的数据元素）以及下一个节点的地址，
    通过每个节点的指向下一个节点的地址来将多个节点串起来，即通过指针遍历整个链表
    把第一个拎到哪后面都全跟着走
    
    基本功能：增、删、改、查、判（判空，判满）、排（排序）、复（复位）
    节点的插入和删除，要点是先断后连，不要断链
    单链表节点的缺点是只有一个后继节点，访问前驱节点只能从头遍历（如插入、删除），时间复杂度为O(n)。
    
    ll 表示 linked list（链表）
    
    一个不错的对于 各种面试/笔试 链表题的 总结 https://mp.weixin.qq.com/s/t2nRaRfbQv6X3uSJe2_Mmw
    
    要时刻注意最后一个节点的指向下一个节点地址的变量一定要设 Null。
    一个节点的地址可以作为全局唯一识别标志，可以用来判断环什么的。
    快、慢指针，即定义两个节点指针，一个每次走两个及两个以上节点，一个每次只走一个节点。
*/

#include <stdio.h>
#include <stdlib.h>

/* 串起来的链表数 */
#define LL_NUM 5

struct simple_ll_struct
{
    int data;                       /* 可以为任意变量，包括结构体、联合等 */
    struct simple_ll_struct* next;  /* 赋值为下一个节点结构体的地址 */
}

/* 链表是链式的线性表，线性表的扩展，就是广义表，即节点上的数据元素可以为另一个广义表（的地址） */
#define ll_node_dataType int
#define ll_node_ll_ptrType struct simple_llplus_struct*
struct simple_llplus_struct
{
    unsigned char data_n_or_ptr;    /* 1 表示 本节点的数据为一个广义表的地址；0 表示 本节点的数据为普通数据 */
    union
    {
        ll_node_dataType data;      /* 可以为任意变量，包括字符串、结构体、联合等 */
        ll_node_ll_ptrType ll_ptr   /* 另一个广义表的头地址（或某个地址） */
    }
    struct simple_llplus_struct* next;  /* 赋值为下一个节点结构体的地址 */
}

/* 有关于基本操作的步骤，画画图更好理解，梳理出来并不算难 */

/* 向后串，将输入的节点结构体的地址写到上一个节点的next指针上 */
void ll_link_tail(struct simple_ll_struct* in)
{
    static struct simple_ll_struct* last = NULL;
    
    if(!last)
    {
        last = in;
    }else
    {
        last->next = in;
    }
    
    in->next = NULL;
    last = in;
    /*
        in1->next为in2首地址，
        in2->next为in3首地址，
        一直到in4->next为in5首地址，
        in5->next为NULL，最后应挂空，
        穿成一串，把第一个拎到哪后面全跟着走。
    */
}

void ll_link_front(struct simple_ll_struct* in)
{
    /* 略 */
}

int main(int argc, char *argv[])
{
    struct simple_ll_struct* ll_pos; 
    
    /* 循环以下步骤：申请一个节点的空间，填入数据，串到尾部 */
    for(unsigned int i = 0;i < LL_NUM;i++)
    { 
       ll_pos = (struct simple_ll_struct*)malloc(sizeof(struct simple_ll_struct));
       ll_pos->data = i * 2;
       ll_link_tail(ll_pos);
    }

}



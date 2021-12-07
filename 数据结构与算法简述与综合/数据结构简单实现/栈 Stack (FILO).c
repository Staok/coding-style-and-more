#include <stdio.h>
#include <stdlib.h>

/* 以下概念介绍引自 https://www.cnblogs.com/accper/p/9149659.html */
/*  概念
    栈是一种特殊的线性表，
    栈中的数据元素以及数据元素间的逻辑关系和线性表相同，
    两者之间的差别在于：线性表的插入和删除操作可以在表的任意进行，
    而栈的插入和删除操作只允许在表的尾端进行。
    
    其中，栈中只允许进行插入和删除操作的一端称为栈顶，另一端称为栈底。
    通常，将栈的插入操作称为入栈（push），而将删除操作称为出栈（pop）。
    
    从栈的概念可知，每次最先入栈的数据元素总是被放在栈的底部，成为栈底元素；
    而每次最先出栈的总是那个放在栈顶位置的数据元素，即栈顶元素。
    因此，栈是一种后进先出（Last In First Out，LIFO）或先进后出（First In Last Out，FILO）的线性表。
*/

/*  栈也是由n（n≥0）个数据元素所构成的有限序列，其数据元素的类型可以任意，
    但只要是同一中类型即可。根据栈的特性，定义在栈的抽象数据类型中的基本操作如下：
    
    置栈空操作clear()：将一个已经存在的栈置成空栈。
    判栈空操作isEmpty()：判断一个栈是否为空，若栈为空，则返回true；否则，返回false。
    求栈中数据元素个数操作length()：返回栈中数据元素的个数。
    取栈顶元素操作peek()：读取栈顶元素并返回其值，若栈为空，则返回null。
    入栈操作push(x)：将数据元素x压入栈顶。
    出栈操作pop()：删除并返回栈顶元素。
*/

/* 设定 栈 的有多少个单位 */
#define STACK_SIZE 100 

int* stack_ptr /* 栈 指针，基本单位为 int 数据类型 */
/* stack_ptr_ori 记录 申请到内存的头地址，
用于与 移动指针 stack_ptr 做比较防止指针移出申请的空间 */
int* const stack_ptr_ori;

/* 记录 栈 的大小，字节数，在下面计算 */
int stack_max_size = 0;

/* 入栈 */
unsigned char push(int push_value)
{
    if(((stack_ptr - stack_ptr_ori) + sizeof(int)) >= stack_max_size) return 1;
    
    *stack_ptr++ = push_value;
}

/* 出栈 */
int* pop(void)
{
    if(((stack_ptr - stack_ptr_ori) - sizeof(int)) < 0) return 1;
    
    return (--stack_ptr);
}

int main(int argc, char *argv[])
{
    stack_max_size = STACK_SIZE * sizeof(int);
    stack_ptr = (int*)malloc(stack_max_size);
    if(!stack_ptr) printf("malloc failed"),exit(0);
    
    stack_ptr_ori = stack_ptr;
    
    for(unsigned int i = 0;i < 10;i++)
        push(i*2);
    
    /* 根据打印信息，体现 栈的 后进先出（Last In First Out，LIFO）性 */
    for(i = 0;i < 10;i++)
        printf("pop %d: %d\n",i,*pop());
}


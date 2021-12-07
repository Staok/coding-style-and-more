/* 以下概念介绍引自 https://blog.csdn.net/daaikuaichuan/article/details/80315834
                    https://zhuanlan.zhihu.com/p/37656546  可详看这两个网址文章来入门 */
/*  概念
    队列中的数据元素遵循“先进先出”（First In First Out）的原则，简称FIFO结构。
    我个人感觉队列是一种数据缓冲/缓存 的方法，其可以使用不同的基本数据结构来实现，而本身并非一种新的基本数据结构。
    队列在计算机中应用相当广泛，包括广度优先搜索、CPU的任务调度、数据缓冲区实现等等。
    
    又分为普通队列和环形队列，后者，环形队列、环形缓冲、Ring buf 都一样，即一个 FIFO 队列首尾相连，内存的空间利用率更高。
    
*/

/* FIFO buf / FIFO Ring buf（或叫 FIFO缓冲 / FIFO环形缓冲） 的实现 在 Github 上有许多轮子 
    https://github.com/search?q=FIFO
    https://github.com/search?q=ringbuf
*/



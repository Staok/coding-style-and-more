#include<iostream>
using namespace std;

void display(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int array[], int x, int y) {
	int key = array[x];
	array[x] = array[y];
	array[y] = key;
}

// 从大到小排序
// void Down(int array[], int i, int n) {
//     int child = 2 * i + 1;
//     int key   = array[i];
//     while (child < n) {
//         if (child + 1 < n && array[child] > array[child + 1]) {
//             child++;
//         }
//         if (key > array[child]) {
//             swap(array, i, child);
//             i = child;
//         } else {
//             break;
//         }
//         child = child * 2 + 1;
//     }
// }

// 从小到大排序
void Down(int array[], int i, int n) { // 最后结果就是大顶堆
	int parent = i;                    // 父节点下标
	int child = 2 * i + 1;            // 子节点下标
	while (child < n) {
		if (child + 1 < n && array[child] < array[child + 1]) { // 判断子节点那个大，大的与父节点比较
			child++;
		}
		if (array[parent] < array[child]) { // 判断父节点是否小于子节点
			swap(array, parent, child);     // 交换父节点和子节点
			parent = child;                 // 子节点下标 赋给 父节点下标
		}
		child = child * 2 + 1; // 换行，比较下面的父节点和子节点
	}
}

void BuildHeap(int array[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
		Down(array, i, size);                 // 否则有的不符合大顶堆定义
	}
}

void HeapSort(int array[], int size) {
	printf("初始化数组：");
	BuildHeap(array, size); // 初始化堆
	display(array, size);   // 查看初始化结果
	for (int i = size - 1; i > 0; i--) {
		swap(array, 0, i); // 交换顶点和第 i 个数据
						   // 因为只有array[0]改变，其它都符合大顶堆的定义，所以可以从上往下重新建立
		Down(array, 0, i); // 重新建立大顶堆

		printf("排序的数组：");
		display(array, size);
	}
}

int main07() {
	int array[] = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
	int size = sizeof(array) / sizeof(int);

	// 打印数据
	printf("%d \n", size);
	printf("排序前数组：");
	display(array, size);
	HeapSort(array, size);

	return 0;
}

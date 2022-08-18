#include<iostream>
using namespace std;

void quicksort(int a[],int left, int right) {
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j) { //顺序很重要，要先从右边开始找
		while (a[j] >= temp && i < j)
			j--;
		while (a[i] <= temp && i < j)//再找右边的
			i++;
		if (i < j)//交换两个数在数组中的位置
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位
	a[left] = a[i];
	a[i] = temp;
	quicksort(a,left, i - 1);//继续处理左边的，这里是一个递归的过程
	quicksort(a,i + 1, right);//继续处理右边的 ，这里是一个递归的过程
}
int main() {
	int i;
	int array[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
	int n = sizeof(array) / sizeof(int);
	quicksort(array,0, n-1); //快速排序调用
	//输出排序后的结果
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	return 0;
}

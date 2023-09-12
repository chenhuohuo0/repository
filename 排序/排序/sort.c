#define _CRT_SECURE_NO_WARNINGS

#include "sort.h"

//遍历表
void print_list(list* L)
{
	for (int i = 1; i <= L->length; i++)
	{
		printf("%d ", L->arr[i]);
	}
	printf("\n");
}

//直接插入排序
void straight_insert_sort(list* L)
{
	for (int i = 2; i <= L->length; i++)
	{
		L->arr[0] = L->arr[i];//暂存到前哨战
		int j;
		for (j = i - 1; j >= 1; j--)
		{
			if (L->arr[j] > L->arr[0])
			{
				L->arr[j + 1] = L->arr[j];//如果比当前元素大就往后移动一位
			}
			else
			{
				break;
			}
		}
		L->arr[j + 1] = L->arr[0];
	}
}

//折半插入排序
void binary_insert_sort(list* L)
{
	int i, j; 
	int left, right, mid;
	for (i = 2; i <= L->length; i++)
	{
		L->arr[0] = L->arr[i];//暂存到前哨战
		left = 1; right = i - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (L->arr[mid] > L->arr[0])
			{
				right = mid - 1;
			}
			else if(L->arr[mid] < L->arr[0])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
				break;
			}
		}
		j = i - 1;
		while (j>right)
		{
			L->arr[j + 1] = L->arr[j];
			j--;
		}
		L->arr[right+1] = L->arr[0];
	}
}

//希尔排序
void shell_insert(list* L, int gap)
{
	int i, j;
	for (i = 1 + gap; i <= L->length; i++)
	{
		//对子表进行直接插入排序
		L->arr[0] = L->arr[i];
		j = i - gap;
		while (L->arr[j] > L->arr[0])
		{
			L->arr[j + gap] = L->arr[j];
			j = j - gap;
		}
		L->arr[j + gap] = L->arr[0];
	}
}

void shell_sort(list* L, int gaps[],int n)
{
	for (int k = 0; k < n; k++)
	{
		shell_insert(L, gaps[k]);
	}
}

//冒泡排序
void bubble_sort(list* L)
{
	int i, j, flag;
	for (i = 1; i <= L->length - 1; i++)
	{
		flag = 0;//假设这一趟已经有序
		for (j = 1; j <= L->length - i; j++)
		{
			if (L->arr[j] > L->arr[j + 1])
			{
				int t = L->arr[j];
				L->arr[j] = L->arr[j + 1];
				L->arr[j + 1] = t;
				flag = 1;//如果发生了交换就改变flag
			}
		}
		if (!flag)
		{
			return;//没有发生交换说明已经有序
		}
	}
}

//快速排序
int quick_sort1(list* L, int left, int right)
{
	L->arr[0] = L->arr[left];
	while (left < right)
	{
		while (left < right&&L->arr[right] >= L->arr[0])//从右找比arr[0]更小的元素
		{
			right--;
		}
		L->arr[left] = L->arr[right];
		while (left < right&&L->arr[left] <= L->arr[0])//从左找比arr[0]更大的元素
		{
			left++;
		}
		L->arr[right] = L->arr[left];
	}
	L->arr[left] = L->arr[0];
	return left;
}
void quick_sort(list* L, int left, int right)
{
	if (left < right)
	{
		int ret = quick_sort1(L, left, right);
		quick_sort(L, left, ret - 1);
		quick_sort(L, ret + 1, right);
	}
}

//简单选择排序
void select_sort(list* L)
{
	int i, j;
	for (i = 1; i <= L->length - 1; i++)
	{
		int t = i;
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->arr[j] < L->arr[t])
			{
				t = j;
			}
		}
		L->arr[0] = L->arr[i];
		L->arr[i] = L->arr[t];
		L->arr[t] = L->arr[0];
	}
}

//堆排序
void heap_sort(list* L)
{
	int i;
	for (i = L->length / 2; i > 0; i--)
	{
		maxheap_adjust(L, i, L->length);
	}
	for (i=L->length;i>0;i--)
	{
		L->arr[0] = L->arr[i];
		L->arr[i] = L->arr[1];
		L->arr[1] = L->arr[0];
		maxheap_adjust(L, 1, i - 1);
	}
}
//从第i个结点往下构造大根堆
void maxheap_adjust(list* L, int i, int n)
{
	int j;
	L->arr[0] = L->arr[i];
	for (j = 2 * i; j <= n; j = 2 * j)
	{
		if (j<n&&L->arr[j + 1] > L->arr[j])
		{
			j = j + 1;
		}//j为两个孩子值更大的元素序列
		if (L->arr[j] <= L->arr[0])break;//堆已经构造好
		L->arr[j / 2] = L->arr[j];
	}
	L->arr[j / 2] = L->arr[0];
}
//归并排序
void merge_sort(list* L, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(L, 1, mid);
		merge_sort(L, mid + 1, right);
		merge(L, left, right);
	}
}
void merge(list* L, int left, int right)
{
	int n = right - left + 1;
	int* L1 = (int*)malloc(n * sizeof(int));//辅助空间
	for (int i = 0; i < n; i++)//把元素复制到辅助空间
	{
		L1[i] = L->arr[left + i];
	}
	//归并
	int i, j, k;
	int mid = (n - 1) / 2;
	for (i = 0, j = mid + 1, k = left; i <= mid && j <= n - 1; k++)
	{
		if (L1[i] <= L1[j])
		{
			L->arr[k] = L1[i++];
		}
		else
		{
			L->arr[k] = L1[j++];
		}
	}
	//复制某边剩余的元素
	while (i <= mid) L->arr[k++] = L1[i++];
	while (j <= n - 1)L->arr[k++] = L1[j++];
	free(L1);
}
#ifndef MERGE_H
#define MERGE_H
#include "InsetionSort.h"


int __merge(int arr[], int l, int l_middle, int r);

void __mergeSort(int arr[], int l, int r);

void MergeSort(int arr[], int n);

//////////////////////////////////////////////////////////

int __merge(int arr[], int l, int l_middle, int r)
{
	//1.���������ռ�
	int* aux = new int[r - l + 1];
	for(int i = 0; i <= r - l; i++)
	{
		aux[i] = arr[l + i];
	}
	//2.��������:i��j�ֱ���aux[]����ߵ�һ�����ұߵ�һ��;
	//k����arr��ʼ��εĹ鲢,ע��[i, j]��[l, r]�����λ�ù�ϵ
	int i = 0;
	int j = l_middle - l + 1;
	for(int k = l; k <= r; k++)
	{
		//3.ע��鲢������Խ������Ĵ���
		if(i > l_middle - l)
		{
			arr[k] = aux[j];
			j++;
		}
		else if(j > r - l)
		{
			arr[k] = aux[i];
			i++;
		}
		//4.�鲢��������������Ĵ���
		else if(aux[i] > aux[j])
		{
			arr[k] = aux[j];
			j++;
		}
		else
		{
			arr[k] = aux[i];
			i++;
		}
	}
	return 0;
}

void __mergeSort(int arr[], int l, int r)
{
	//1.����ݹ��ٽ��������ָ����鲻���ٽ�������
	if( l >= r )
		return;
// 	if( r - l < 15 )
// 	{
// 		__portionInsertionSort(arr, l, r);
// 		return;
// 	}
	int l_middle = (l + r) / 2;
	__mergeSort(arr, l, l_middle);
	__mergeSort(arr, l_middle + 1, r);

//	if(arr[l_middle] > arr[l_middle + 1])
	__merge(arr, l, l_middle, r);
}

void MergeSort(int arr[], int n)
{
	__mergeSort(arr, 0, n-1);
}

void MergeSortBTU(int arr[], int n)//��forѭ�����Ե����ϵĵ���
{
	for(int sz = 1; sz <=n; sz += sz)
	{
		for(int i = 0; i < n - sz + 1; i += 2*sz)
		{
			//��[i, i + sz - 1]�� [i + sz, i + 2sz - 1]���й鲢
			__merge(arr, i, i + sz - 1, min((i + 2*sz -1), n - 1));
		}
	}
}


#endif //MERGE_H

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "InsetionSort.h"
#include <time.h>
// part����ʵ��
// ��arr[l...r]���ֽ���partition����
// ����p,ʹarr[l, p-1] < arr[p] ; arr[p+1, r] > arr[p]
int __partition(int arr[], int l, int r);
void __quicksort(int arr[], int l, int r);
void quickSort(int arr[], int n);

int __partition2(int arr[], int l, int r);
void __quicksort2(int arr[], int l, int r);
void quickSort2(int arr[], int n);

int __partition3(int arr[], int l, int r);
void __quicksort3(int arr[], int l, int r);
void quickSort3(int arr[], int n);


//////////////////////////////////////////////////////////
int __partition(int arr[], int l, int r){
	int v = arr[l];
	int i = l;
	int j = r + 1;
	while(1)
	{
		while(arr[++i] < v)if(i == r) break;
		while(v < arr[--j])if(j == l) break;
		if(i >= j) break;
		swap( arr[i] , arr[j]);
	}
		swap( arr[l] , arr[j]);
		return j;
}
void __quicksort(int arr[], int l, int r)
{
	//1.����ݹ��ٽ��������ָ����鲻���ٽ�������
	if( l >= r )
		return;

	int l_partpos = __partition(arr, l, r);
	__quicksort(arr, l, l_partpos - 1);
	__quicksort(arr, l_partpos + 1, r);
}
void quickSort(int arr[], int n)
{
	__quicksort(arr, 0, n-1);
}

////////////////////////////////////////////////////////////
int __partition2(int arr[], int l, int r)
{
	int ref = arr[l];
	int i = l + 1;
	int j = r;
	while(1)
	{
		while((i <= r) && (arr[i] < ref)) i++;
		while((j >= l + 1) && (arr[j] > ref)) j--;
		if(i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap( arr[l] , arr[j]);   
	return j;
}
void __quicksort2(int arr[], int l, int r)
{
	if( l >= r )
		return;

	int l_partpos = __partition2(arr, l, r);
	__quicksort2(arr, l, l_partpos - 1);
	__quicksort2(arr, l_partpos + 1, r);
}
void quickSort2(int arr[], int n)
{
	__quicksort2(arr, 0, n-1);
}

////////////////////////////////////////////////////
void __quicksort3(int arr[], int l, int r)
{
	if( l >= r )
		return;
	//partitionǰ
	//(v\l\lt)i...............................(r\gt)
	//l....<v.....|lt...=v...|i...?v...gt|...>v...r
	int v = arr[l];
	int lt = l;      
	int gt = r;  
	int i = l+1;
	while( i <= gt ){
		if(arr[i] < v)	swap(arr[i++], arr[lt++]);
		else if(arr[i] > v)	swap(arr[i], arr[gt--]);
		else i++;
	}
	//partition��
	//l....<v.....|lt...=v....(gt/i)|...>v...r	[lt, gt]��Χ�ڶ����ظ��Ļ�׼Ԫ��,��������ٽ�������
	__quicksort3(arr, l, lt - 1);
	__quicksort3(arr, gt + 1, r);
}

void quickSort3(int arr[], int n)
{
	__quicksort3(arr, 0, n-1);
}







#endif //QUICKSORT_H
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "InsetionSort.h"
#include "SortTestHelper.h"
#include <time.h>
#include <vector>

//��������ѧϰ���㷨��˳�����صĶ��������Լ������ϣ�����һ���ظ�������һ��Ƭ����������ȷ���Ǵ���Ķ����źܶ����ۿ���������д�������Ϊ�˳�Ϊ�ο����ϣ�ֻΪ�������Լ���˼·���������������·�ϵ�ͬѧ�Ǽ�������ϣ������ܹ��Լ�������кû���������ĵط���Ҳϣ���ܹ��������ҹ�ͬѧϰ��
//����ӿ�������͹鲢����ʼ����Ϊ���������е�ͬѧ���������������������ݹ��һ���ܺõ�����㡣



//ֱ�ӽ������⣬����˼�룬���ǰ�������λ����v������������ʱ���ô���λ�ã�ͬʱʹ��������������������������:
//[|v|..................] ==> [....<v....|v|....>v.....]
//��������֮Ϊpartition�����Է��־���һ��partition��v������λ��������,ͬʱ������������Ȼû���ź��򣬵������ٴ������ô������䡣
//Ȼ���<v��>v�������ٴν���partition���ݹ飩������Ԥ�����䱻���ֵ�Խ��Խ��ҲԽ��ԽС�����ݱ��ָ��Խ��Խ��ȷ���ӽ���������λ��
//�����ȫͣ������������λ�ϣ���ʱ������������
//�����ڶ��ַ�����������������±��ָ�Ĵ�����logN��ÿ�ηָ�󣬱���������ΪN��ʱ�临�Ӷ�NlogN��
//��ʱ����д������α���룺

int _partition(int a[], int lo, int hi);
void _quicksort(int a[], int lo, int hi){
	if (lo >= hi)
		return;
	int j = _partition(a, lo, hi);
	_quicksort(a, lo, j - 1);
	_quicksort(a, j + 1, hi);
}
//����������ܼ��ǲ��ǣ�����ֻ��Ҫʵ�ֺ����㷨partition�Ϳ����ˣ�partition���������䴦������״̬��
//[(v, lo) | .....<v..... | i......j | .....>v.....hi]
//����������i��j������Ҫ��ȷ���ǵĺ��壺
//i���ұ���ָ�룬����[lo, i) < v
//j�������ָ�룬����(j, hi] > v
//��i��j���ҳ�v������λ

//��ô�������ˣ������ݹ�ṹ������������ǰ������partition������������ʼֵ�������˳�partition���˳�����������������η�����
int _partition(int a[], int lo, int hi){
	int i = lo;
	int j = hi + 1;
	int v = a[lo];
	while(true){
		while(a[++i] < v){ 
			if (i >= hi) break;
		}
		while(a[--j] > v){
			if (j <= lo) break;
		}
		if (i >= j)		// ">=" ���� ">" ��
			break;
		swap(a[i], a[j]);
	}
	swap(a[lo], a[j]);
	return j;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
void quicksort(int a[], int n){
	_quicksort(a, 0, n - 1);
}
void testQuickSort(){
	int n = 10000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("Quick Sort", quicksort, arr, n);
}
// part����ʵ��
// ��arr[l...r]���ֽ���partition����
// ����p,ʹarr[l, p-1] < arr[p] ; arr[p+1, r] > arr[p]
int __partition1(int arr[], int l, int r);
void __quicksort1(int arr[], int l, int r);
void quickSort1(int arr[], int n);

int __partition2(int arr[], int l, int r);
void __quicksort2(int arr[], int l, int r);
void quickSort2(int arr[], int n);

int __partition3(int arr[], int l, int r);
void __quicksort3(int arr[], int l, int r);
void quickSort3(int arr[], int n);


//////////////////////////////////////////////////////////
int __partition1(int arr[], int l, int r){
	int v = arr[l];
	int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
	for( int i = l + 1 ; i <= r ; i ++ )
		if( arr[i] < v ){
			j ++;
			swap( arr[j] , arr[i] );
		}

		swap( arr[l] , arr[j]);

		return j;
}
void __quicksort1(int arr[], int l, int r)
{
	//1.����ݹ��ٽ��������ָ����鲻���ٽ�������
	if( l >= r )
		return;

	int l_partpos = __partition1(arr, l, r);
	__quicksort1(arr, l, l_partpos - 1);
	__quicksort1(arr, l_partpos + 1, r);
}
void quickSort1(int arr[], int n)
{
	__quicksort1(arr, 0, n-1);
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
	//partition��ʼ״̬
	//(v\l\lt)i...............................(r\gt)
	//partition��
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
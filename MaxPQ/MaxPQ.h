#ifndef MAXPQ_H
#define MAXPQ_H
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;


template<typename T>
class MaxPQ
{
public:
	MaxPQ();							//create a priority queue
	MaxPQ(int max);						//create a priority queue of initial capacity max//构造空pq，固定容量
	MaxPQ(T a[], int n);				//create a priority queue from the keys in a[],使用数组a[]构造pq，固定容量

	void insert(T v);					//insert a key into the priority queue	
	
	T delMax();							//return and remove the largest key
	
	bool isEmpty();						//is the priority queue empty?
	
	int size();							//number of keys in the priority queue
	
	T max();							//return the largest key
	
	vector<int> heapSort();				//从pq中输出有序数组


private:
	void swim(int k);					//尾部新数据重排
	void sink(int k);					//头部新数据重排
	void printTest();					//打印堆数据
	 T* pq;								// heap-ordered complete binary tree
	 int N;								// in pq[1..N] with pq[0] unused 当前容量
	 int C;								// 容量上限
};

template<typename T>
MaxPQ<T>::MaxPQ(){
}

template<typename T>
MaxPQ<T>::MaxPQ(int max):N(0),C(max){		
	pq = new T[max + 1];		
}

template<typename T>
MaxPQ<T>::MaxPQ(T a[], int n):N(n),C(n){	
	pq = new T[n + 1];			
	for(int i = 0; i < n; i++){						
		pq[i+1] = a[i];
	}
	printTest();
	for(int i = N/2; i >= 1; i--){
		sink(i);
	}
	printTest();
}

template<typename T>
void MaxPQ<T>::insert(T v){
	pq[++N] = v;
	swim(N);
}

template<typename T>
T MaxPQ<T>::delMax(){		
	T ret = pq[1];
	swap(pq[1],pq[N]);
	pq[N--] = 0;
	sink(1);
	return ret;
}
template<typename T>
bool MaxPQ<T>::isEmpty(){			
	return N == 0;
}

template<typename T>
int MaxPQ<T>::size(){				
	return N;
}

template<typename T>
T MaxPQ<T>::max(){					
	return T[1];
}

template<typename T>
vector<int> MaxPQ<T>::heapSort(){		
	vector<int> res;
	while(!isEmpty()){
		res.push_back(delMax());
	}
	return res;
}

template<typename T>
void MaxPQ<T>::swim(int k){			
	while( k > 1 && pq[k/2] < pq[k]){
		swap(pq[k/2], pq[k]);
		k /= 2;
	}
}

template<typename T>
void MaxPQ<T>::sink(int k){		
	while(2*k <= N){	
		if((2*k < N) && (pq[2*k] < pq[2*k + 1])){
			swap(pq[k], pq[2*k + 1]);
			k = 2*k + 1;
		}
		else if(pq[k] < pq[2*k]){
			swap(pq[k], pq[2*k]);
			k *= 2;
		}
		else
			break;
	}
}

template<typename T>
void MaxPQ<T>::printTest(){
	int i = 0;
	int j = 0;
	for(i = 1; N >= 0; i *= 2){						
		for(j = i; j < 2*i && j <= N; j++){
			cout << pq[j] << " ";
		}
		cout << endl;
		if(j >= N) return;
	}
}

//////////////////////////////////////////////////////////
//独立的堆排序接口,注意a[]从索引1开始
void sink(int a[], int k, int n){			//头部新数据重排
	while(2*k <= n){						//保证有子节点
		if((2*k < n) && (a[2*k] < a[2*k + 1])){
			swap(a[k], a[2*k + 1]);
			k = 2*k + 1;
		}
		else if(a[k] < a[2*k]){
			swap(a[k], a[2*k]);
			k *= 2;
		}
		else
			break;
	}
}
void heapSort(int a[], int n){			
	//在a[]中使用下沉方式构建堆(从最小树开始往上直到顶点)
	for(int k = n/2; k >= 1; k--){
		sink(a, k, n);
	}
	while(n > 1){
		swap(a[1],a[n--]);//和delMax对比，这里没有屏蔽尾部元素，只进行排序
		sink(a, 1, n);
	}
}
///////////////////////////////////////////////////////
int HeapOpt () {
	int myints[] = {10,20,30,5,15};
	std::vector<int> v(myints,myints+5);

	std::make_heap (v.begin(),v.end());
	std::cout << "initial max heap   : " << v.front() << '\n';

	std::pop_heap (v.begin(),v.end()); v.pop_back();
	std::cout << "max heap after pop : " << v.front() << '\n';

	v.push_back(99); std::push_heap (v.begin(),v.end());
	std::cout << "max heap after push: " << v.front() << '\n';

	std::sort_heap (v.begin(),v.end());

	std::cout << "final sorted range :";
	for (unsigned i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];

	std::cout << '\n';

	return 0;
}
//////////////////////////////////////////////////
class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam=false)
	{reverse=revparam;}
	bool operator() (const int& lhs, const int&rhs) const
	{
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};

int pq_Container()
{
	int myints[]= {10,60,50,20};

	std::priority_queue<int> first;
	std::priority_queue<int> second (myints,myints+4);
	std::priority_queue<int, std::vector<int>, std::greater<int>> third (myints,myints+4);
	// using mycomparison:
	typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

	mypq_type fourth(myints, myints+4);                // less-than comparison
	mypq_type fifth (myints, myints+4,mycomparison(true));   // greater-than comparison

	return 0;
}

#endif //MAXPQ_H

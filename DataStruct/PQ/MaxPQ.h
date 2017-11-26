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
#include<functional>
using namespace std;


template<typename T>
class MaxPQ
{
public:
	MaxPQ();							//���ȶ������ֹ��췽ʽ
	MaxPQ(int max);						//	max�����Ŀ����ȶ���
	MaxPQ(T a[], int n);				//	�������ʼ�����ȶ���

	void insert(T v);					//insert a key into the priority queue	
	
	T delMax();							//return and remove the largest key
	
	bool isEmpty();						//is the priority queue empty?
	
	int size();							//number of keys in the priority queue
	
	T max();							//return the largest key
	
	vector<int> heapSort();				//��pq�������������


private:
	void swim(int k);					//β������������
	void sink(int k);					//ͷ������������
	void printTest();					//��ӡ������
	 T* pq;								// heap-ordered complete binary tree
	 int N;								// in pq[1..N] with pq[0] unused ��ǰ����
	 int C;								// ��������

public:
	 static void sink(int a[], int k, int n);
	 static void heapSort(int a[], int n);
	 static int MaxPQ<T>::pq_Container();
	 static int MaxPQ<T>::HeapOpt();
};

#endif //MAXPQ_H

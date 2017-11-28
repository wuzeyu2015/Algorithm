#ifndef MINPQ_H
#define MINPQ_H
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
class MinPQ
{
public:
public:
	MinPQ();							//Ĭ�Ϲ���ն���
	MinPQ(int n);						//��n����
	MinPQ(T a[], int n);				//�����鹹��

	void insert(T v);					//ĩβ���� 
	T	 delMax();						//ͷ��ɾ�� 
	bool isEmpty();						//�п�
	int  size();						//���д�С
	T	 min();							//������СԪ��


private:
	void swim(int k);					//β������������
	void sink(int k);					//ͷ������������
	void printTest();					//��ӡ������

	T* pq;								//��������
	int N;								//��ǰ������
	int C;								//��������

public:
	static void sink(int a[], int k, int n);
	static void heapSort(int a[], int n);
	static int MinPQ<T>::pq_Container();
	static int MinPQ<T>::HeapOpt();
};

#endif //MINPQ_H

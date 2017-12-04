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
#include <ctime>
using namespace std;

template<typename T>
class MinPQ
{
public:
public:
	MinPQ();							//Ĭ�Ϲ���ն���
	MinPQ(int max);						//��ʼ����Ϊmax
	MinPQ(T a[], int n);				//��a[]���鴴��

	void insert(T v);					//ĩβ���� 
	T	 delMin();						//ͷ��ɾ�� 
	T	 min();							//������СԪ��
	bool isEmpty();						//�п�
	int  size();						//���ض���Ԫ�ظ���


private:
	void swim(int k);					//β������������
	void sink(int k);					//ͷ������������

	void minPQCheck();					//�������Ƿ�������С��

	T* pq;								//��������
	int N;								//��ǰ������\��ǰ��β����
	int C;								//��������

private:
	void printTest();					//��ӡ������

public:
	static int MinPQ<T>::testMinPQ();
};

#endif //MINPQ_H

// MinPQ.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "MinPQ.h"
template<typename T>
MinPQ<T>::MinPQ() {
	//
	//
}

template<typename T>
MinPQ<T>::MinPQ(int max) :N(0), C(max) {
	pq = new T[max + 1];//����Ҫ��1��ʼ
	memset(pq, 0, sizeof(int) *(max + 1));
}

template<typename T>
MinPQ<T>::MinPQ(T a[], int n) : N(n), C(n) {
	//
	//
}

template<typename T>
void MinPQ<T>::insert(T v) {
	pq[++N] = v;
	swim(N);
	minPQCheck();
}

template<typename T>
T MinPQ<T>::delMin() {
	T ret = min();
	pq[1] = pq[N];
	pq[N--] = NULL;
	sink(1);
	minPQCheck();
	return ret;
}
template<typename T>
bool MinPQ<T>::isEmpty() {
	return N == 0;
}

template<typename T>
int MinPQ<T>::size() {
	return N;
}

template<typename T>
T MinPQ<T>::min() {
	return pq[1];
}

template<typename T>
void MinPQ<T>::swim(int k) {
	while ((k > 1) && (pq[k] < pq[k / 2])) {
		swap(pq[k], pq[k / 2]);
		k = k / 2;
	}
}

template<typename T>
void MinPQ<T>::sink(int k) {
	while (2 * k <= N) {
		int s = 2 * k;//s is the final child element in swap
		if ((2 * k < N) && (pq[2 * k + 1] < pq[2 * k])) {
			if (pq[k] > pq[2 * k + 1]) {
				s++;
			}
		}
		if (pq[k] > pq[s]) {
			swap(pq[k], pq[s]);
			k = s;
		}
		else
			break;
	}
}

/////////////////������/////////////////////
template<typename T>
void MinPQ<T>::sink(int a[], int k, int n) {			//ͷ������������
	while (2 * k <= n) {
		int s = 2 * k;//s is the final child element in swap
		if ((2 * k < n) && (a[2 * k] > a[2 * k + 1])) {
			if (a[k] > a[2 * k + 1]) {
				s++;
			}
		}
		if (a[k] > a[s]) {
			swap(a[k], a[s]);
			k = s;
		}
		else
			break;
	}
}
/////////////////������/////////////////////
template<typename T>
void MinPQ<T>::heapSort(int a[], int n) {
	//��a[]��ʹ���³���ʽ������(����С����ʼ����ֱ������)
	for (int k = n / 2; k >= 1; k--) {
		sink(a, k, n);
	}
	while (n > 1) {
		swap(a[1], a[n--]);//��delMax�Աȣ�����û������β��Ԫ�أ�ֻ��������
		sink(a, 1, n);
	}
}
template<typename T>
void MinPQ<T>::minPQCheck(void) {
	for (int i = 1; i <= N / 2; i++) {
		if ((2 * i + 1 <= N) && (pq[i] > pq[2 * i] || pq[i] > pq[2 * i + 1])) {
			assert(false);
		}
	}
}


template class MinPQ<int>;
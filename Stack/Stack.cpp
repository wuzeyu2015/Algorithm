// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <stack>
using namespace std;


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		curIdx = -1;//��ʼ��arrջ������
		curMin = -1;//��ʼauxջ������
		maxCap = 10;
		arr = new int[maxCap];
		memset(arr, 0, maxCap);
		aux = new int[maxCap];
		memset(aux, 0, maxCap);
	}

	void push(int x) {
		if(curIdx + 1 >= maxCap){
			int* arrtmp = new int[maxCap*2];
			memset(arrtmp, 0, maxCap*2);
			memcpy(arrtmp, arr, maxCap*sizeof(int));
			delete arr;
			arr = arrtmp;

			int* auxtmp = new int[maxCap*2];
			memset(auxtmp, 0, maxCap*2);
			memcpy(auxtmp, aux, maxCap*sizeof(int));
			delete aux;
			aux = auxtmp;

			maxCap *= 2;
		}
		arr[++curIdx] = x;
		if(curMin == -1)
			aux[++curMin] = x;
		else if(x <= aux[curMin])
			aux[++curMin] = x;
	}
	void pop() {

		if(curIdx > -1)//�ǿյ�ʱ���pop
		{
			if(arr[curIdx] == aux[curMin]){
				aux[curMin] = 0;
				if(curMin  > -1)//�ǿյ�ʱ���pop
					curMin--;				
			}
			arr[curIdx] = 0;
			curIdx--;
		}

	}

	int top() {
		if(curIdx > -1)//�ǿյ�ʱ���top
			return arr[curIdx];
		else
			return -1;
	}

	int getMin() {
		return aux[curMin];
	}
private:
	/* data structure */
	int* arr;	//��ǰջ
	int maxCap; //arrջ���������
	int curIdx; //arr��ǰջ������
	int* aux;	//����ջ
	int curMin; //auxջ��������arr�������С��ֵ��
};


int _tmain(int argc, _TCHAR* argv[])
{
	int test[] = {1,2,1};
	vector<int> vtest(test, test + 3);
	MinStack minStack =  MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	int i = minStack.getMin();
	minStack.pop();
	i = minStack.top();
	i = minStack.getMin();
	return 0;
}


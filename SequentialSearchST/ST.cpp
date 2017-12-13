// SequentialSearchST.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SequentialSearchST.h"

void testSequentialSearchST(int minLen) {

	SequentialSearchST<string, int>* st = new SequentialSearchST<string, int>();

	ifstream ifs("tale.txt");//��ʼ��һ��������
	string read;
	while (getline(ifs, read, ' ')) //�ԡ� ��Ϊ�ָ��ȡ���ʣ�  
	{
		if (read.length() < minLen) continue;
		if (st->contains(read)) {
			st->put(read, st->get(read) + 1);
		}
		else {
			st->put(read, 1);
		}
		//cout << read << endl;
	}
	// find a key with the highest frequency count
	string maxword = " ";
	st->put(maxword, 0);
	for(string word : *st->keys()){
		if (st->get(word) > st->get(maxword))
			maxword = word;
	}
	cout << maxword << st->get(maxword);
}

int main()
{
	testSequentialSearchST(8);
	system("pause");
    return 0;
}


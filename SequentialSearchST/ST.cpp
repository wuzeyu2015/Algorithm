// SequentialSearchST.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SequentialSearchST.h"

void testSequentialSearchST(int minLen) {

	SequentialSearchST<string, int>* st = new SequentialSearchST<string, int>;

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
		cout << read << endl;
	}
	// find a key with the highest frequency count
	string max = " ";
	st->put(max, 0);
	for (string word : st->keys) {
		if (st->get(word) > st->get(max))
			max = word;
	}
	cout << (max + " " + st->get(max));
}
}

int main()
{
	testSequentialSearchST();
	system("pause");
    return 0;
}


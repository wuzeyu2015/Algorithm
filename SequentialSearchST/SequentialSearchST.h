#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class SequentialSearchST
{
public:
	SequentialSearchST();
	~SequentialSearchST();

private:
	class Node
	{
	public:
		Node(Key key, Value val, Node* next){
			this->key = key;
			this->val = val;
			this->next = next;
		}
		Key key;
		Value val;
		Node* next;
	};
	Node* pfirst;
public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	vector<Key>* keys();//����key�ļ��ϣ���vector

	static void testmain(int minLen) {

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
		for (string word : *st->keys()) {
			if (st->get(word) > st->get(maxword))
				maxword = word;
		}
		cout << maxword << st->get(maxword);
	}
};



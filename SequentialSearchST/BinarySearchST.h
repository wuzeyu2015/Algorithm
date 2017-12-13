#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class BinarySearchST
{
public:
	BinarySearchST(int cap);
	~BinarySearchST();

private:
	Key* key;
	Value* val;
public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	vector<Key>* keys();//����key�ļ��ϣ���vector

};



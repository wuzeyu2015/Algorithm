#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class BST
{
public:
	BST();
	~BST();
private:
	class TreeNode
	{
	public:
		TreeNode(Key key, Value val, int N)
		{
			this->key = key; this->val = val; this->N = N;
			this->left = NULL;
			this->right = NULL;
		}
		Key key;
		Value val;
		TreeNode* left;
		TreeNode* right;
		int N; //nodes in subtree rooted here
	};
//api
public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	int size();
	bool isEmpty();
	vector<Key>* keys();//��ȡkeys

	//orderd st can extend these api as follows
	Key min();
	Key max();
	Key floor(Key key);
	Key ceiling(Key key);
	Key select(int k);// key of rank k
	int rank(Key key);
	void deleteMin();
	void deleteMax();
	void del(Key key);
	int size(Key lo, Key hi); //number of keys in[lo..hi]
	vector<Key>* keys(Key lo, Key hi); //keys in[lo..hi], in sorted order

private:
	Key min(TreeNode* proot);
	Key max(TreeNode* proot);
	int size(TreeNode* proot);
	Value get(TreeNode* proot, Key key);
	TreeNode*& put(TreeNode*& pnode, Key key, Value val);
	void keys(TreeNode* proot, vector<Key>* pkeyarr);
	TreeNode* floor(TreeNode* pNode, Key key);
	TreeNode* ceiling(TreeNode* pNode, Key key);
	int rank(TreeNode* proot, Key key);

	TreeNode* deleteMin(TreeNode* proot);
	TreeNode* deleteMax(TreeNode* proot);
	TreeNode* del(TreeNode* proot, Key key);

public:
	//test entrance
	static void main(int minLen);
	static void main2();//С��ģ���ݲ��� extended api as shown above
private:
	TreeNode* proot; // root of BST

};



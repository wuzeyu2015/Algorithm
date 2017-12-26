// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>




// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;


template<class Key, class Value>
class TreeNode
{
public:
	TreeNode(Key key, Value val, int N)
	{
		this->key = key; this->val = val; this->N = N;
	}
	Key key;
	Value val;
	TreeNode* left;
	TreeNode* right;
	int N; //nodes in subtree rooted here
};
template<class Key, class Value>
class BST
{
public:
	BST();
	~BST();

public:
	void put(Key key, Value val);
private:

	TreeNode* put(TreeNode* root, Key key, Value val);

public:
	//test entrance
	static void main(int minLen);

private:
	int N;
	TreeNode* proot; // root of BST

};

template<class Key, class Value>
BST<Key, Value>::BST()
{
	proot = NULL;
}

template<class Key, class Value>
BST<Key, Value>::~BST()
{
}

template<class Key, class Value>
void BST<Key, Value>::put(Key key, Value val)
{
	proot = put(proot, key, val);
}

template<class Key, class Value>
TreeNode* BST<Key, Value>::put(TreeNode* pnode, Key key, Value val)
{
	if (pnode == NULL)
		return new TreeNode(key, val, 1);
	if (pnode->key == key) {
		pnode->val = val;
		return pnode;
	}
	else if (pnode->key < key)
		pnode->right = put(pnode->right, key, val);
	else if (pnode->key > key)
		pnode->left = put(pnode->left, key, val);
}
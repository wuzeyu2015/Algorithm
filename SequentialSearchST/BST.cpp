#include "stdafx.h"
#include "BST.h"


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
Value BST<Key, Value>::get(Key key)
{
	return get(proot, key);
}

template<class Key, class Value>
Value BST<Key, Value>::get(TreeNode* root, Key key)
{
	if (root == NULL)
		return NULL;
	if (root->key == key)
		return root->val;
	else if (root->key < key)
		return get(root->right, key);
	else if (root->key > key)
		return get(root->left, key);
}

template<class Key, class Value>
void BST<Key, Value>::put(Key key, Value val)
{
	put(proot, key, val);
}

template<class Key, class Value>
typename BST<Key, Value>::TreeNode*& BST<Key, Value>::put(TreeNode* &pnode, Key key, Value val)
{
	if (pnode == NULL)
		return (pnode = new TreeNode(key, val, 1));
	if (pnode->key == key) {
		pnode->val = val;
		return pnode;
	}

	else if (pnode->key < key)
		put(pnode->right, key, val);
	else if (pnode->key > key)
		put(pnode->left, key, val);
	else
		pnode->val = val;

}
template<class Key, class Value>
bool BST<Key, Value>::contains(Key key) {
	return get(key) != NULL;
}
template<class Key, class Value>
int BST<Key, Value>::size() {
	return N;
}
template<class Key, class Value>
bool BST<Key, Value>::isEmpty() {
	return N == 0;
}
template<class Key, class Value>
vector<Key>* BST<Key, Value>::keys() {
	vector<Key>* pkeyarr = new vector<Key>();
	keys(proot, pkeyarr);
	return pkeyarr;
}
template<class Key, class Value>
void BST<Key, Value>::keys(TreeNode* proot, vector<Key>* pkeyarr) {
	if (proot == NULL)
		return;
	pkeyarr->push_back(proot->key);
	keys(proot->left, pkeyarr);
	keys(proot->right, pkeyarr);
}
template class BST<string, int>;



//������ں���
template<class Key, class Value>
void BST<Key, Value>::main(int minLen) {

	BST<string, int>* st = new BST<string, int>();

	ifstream ifs("tale.txt");//��ʼ��һ��������
	string read;
	while (ifs >> read)
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
	string maxfreqstring = " ";
	st->put(maxfreqstring, 0);
	vector<Key>* vp = st->keys();
	for (string cur : *vp) {
		if (st->get(cur) > st->get(maxfreqstring))
			maxfreqstring = cur;
	}
	cout << "there are:" << st->size() << " different words" << endl;
	cout << "highest frequency:" << maxfreqstring << endl;
	cout << "count:" << st->get(maxfreqstring) << endl;
}
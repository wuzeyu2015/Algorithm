#include "stdafx.h"
#include "math.h"

//��ʱ
// int countNodes(TreeNode* root) {
// 	if (root == NULL)
// 		return 0;
// 	return 1 + countNodes(root->left) + countNodes(root->right);
// }


//����İ汾���������������ڵ���Ϊ2^h - 1���Ż�����������������ʱ��Ч��
int leftH(TreeNode* root) {
	int lh = 0;
	while(root){
		lh++;
		root = root->left;
	}
	return lh;
}	
int rightH(TreeNode* root) {
	int rh = 0;
	while(root){
		rh++;
		root = root->right;
	}
	return rh;
}

int countNodes(TreeNode* root) {
	int l = leftH(root);
	int r = rightH(root);
	if(l == r)	return pow((double)2, l) - 1;
	else{
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
}

//������һ��ȥ�������������������������ټ������һ��ı�����


void test_222(){
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	bool i = countNodes(NULL);
}
#include "stdafx.h"


//��Ҫ�������⺯��ִ�����̣��Զ�����������λ�õ������ڵ�������
int minDepth(TreeNode* root) {

	if(!root) return 0;
	if(!root->left) return 1 + minDepth(root->right);
	if(!root->right) return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left),minDepth(root->right));
}



void test_111(){

	int i = minDepth(NULL);
}
#include "stdafx.h"


//1��ע��ݹ���ֹ����

bool hasPathSum(TreeNode* root, int sum) {
	if(!root)
		return false;	
	else if(root->val == sum && !root->left && !root->right)//���������Ҷ�ӽ���ʱ��������ж�
		return true;
	else
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}



void test_112(){
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	bool i = hasPathSum(NULL, 22);
}
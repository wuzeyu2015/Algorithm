#include "stdafx.h"

vector<vector<int> > levelOrderBottom(TreeNode *root) {

	vector<vector<int>> vresult(0,vector<int>());
	queue<TreeNode*> iqueue;
	vector<int> ilevel;

	if(!root)
		return vresult;

	iqueue.push(root);						//������һ��
	iqueue.push(NULL);

	while(!iqueue.empty()){
		TreeNode* node = iqueue.front();
		iqueue.pop();
		if(node == NULL){
			vresult.push_back(ilevel);		//���������Ѿ�ȫ�����ӽ���ilevel
			ilevel.clear();
			if(!iqueue.empty())
				iqueue.push(NULL);				//��һ�������Ѿ�ȫ��������У�����ָ���null
		}
		else{								//������ilevel������һ�������
			ilevel.push_back(node->val);
			if(node->left)
				iqueue.push(node->left);
			if(node->right)
				iqueue.push(node->right);
		}
	}
	reverse(vresult.begin(), vresult.end());
	return vresult;
}

void test_107(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	levelOrderBottom(root);
}
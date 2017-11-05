#include "stdafx.h"


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

	vector<vector<int>> vresult(0,vector<int>());
	queue<TreeNode*> iqueue;
	vector<int> ilevel;
	bool rFlag = false;
	if(!root)
		return vresult;

	iqueue.push(root);						//������һ��
	iqueue.push(NULL);

	while(!iqueue.empty()){
		TreeNode* node = iqueue.front();
		iqueue.pop();
		if(node == NULL){						//���������Ѿ�ȫ�����ӽ���ilevel
			if(rFlag) reverse(ilevel.begin(), ilevel.end());
			vresult.push_back(ilevel);	
			ilevel.clear();

			if(!iqueue.empty())
				iqueue.push(NULL);				//��һ�������Ѿ�ȫ��������У�����ָ���null
			rFlag = !rFlag;
		}
		else{								//������ilevel������һ�������
			ilevel.push_back(node->val);
			if(node->left)
				iqueue.push(node->left);
			if(node->right)
				iqueue.push(node->right);
		}
	}
	return vresult;
}

void test_103(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	zigzagLevelOrder(root);
}
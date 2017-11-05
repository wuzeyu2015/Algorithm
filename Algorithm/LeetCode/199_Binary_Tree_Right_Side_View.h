#include "stdafx.h"


vector<int> rightSideView(TreeNode* root) {

	vector<vector<int>> vresult(0,vector<int>());
	queue<TreeNode*> iqueue;
	vector<int> ilevel;

	if(!root)
		return ilevel;

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
	for(vector<vector<int>>:: iterator it = vresult.begin(); it != vresult.end(); it++){
		ilevel.push_back(it->back());
	}
	return ilevel;
}


void test_199(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	rightSideView(root);
}




/*leetcode discuss�ݹ�ⷨ*/

// class Solution {
// public:
// 	void recursion(TreeNode *root, int level, vector<int> &res)
// 	{
// 		if(root==NULL) return ;
// 		if(res.size()<level) res.push_back(root->val);
// 		recursion(root->right, level+1, res);
// 		recursion(root->left, level+1, res);
// 	}
// 
// 	vector<int> rightSideView(TreeNode *root) {
// 		vector<int> res;
// 		recursion(root, 1, res);
// 		return res;
// 	}
// };
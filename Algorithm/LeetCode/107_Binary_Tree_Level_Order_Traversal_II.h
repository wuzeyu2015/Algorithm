#include "stdafx.h"

vector<vector<int> > levelOrderBottom(TreeNode *root) {

	vector<vector<int>> vresult(0,vector<int>());
	queue<TreeNode*> iqueue;
	vector<int> ilevel;

	if(!root)
		return vresult;

	iqueue.push(root);						//构建第一层
	iqueue.push(NULL);

	while(!iqueue.empty()){
		TreeNode* node = iqueue.front();
		iqueue.pop();
		if(node == NULL){
			vresult.push_back(ilevel);		//本层数据已经全部出队进入ilevel
			ilevel.clear();
			if(!iqueue.empty())
				iqueue.push(NULL);			//下一层数据已经全部进入队列，插入分割标记null
		}
		else{								//继续往ilevel放入下一层的数据
			ilevel.push_back(node->val);
			if(node->left)
				iqueue.push(node->left);
			if(node->right)
				iqueue.push(node->right);
		}
	}
	reverse(vresult.begin(), vresult.end());//反转顺序
	return vresult;
}

void test_107(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	levelOrderBottom(root);
}
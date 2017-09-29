#include "stdafx.h"

vector<int> postorderTraversal(TreeNode* root) {
	if(root == NULL)
		return vector<int>();

	vector<int> ivector;
	stack<TreeNode *> stack;
	TreeNode* curroot = root;
	while (!stack.empty() || curroot != NULL){
		//��������Ҷ�ӽڵ㣬��ӡ���ջ���ٰ��������ʽ����������ڵ�
		while(curroot){
			stack.push(curroot);
			curroot = curroot->left;
		}
		//��Ҷ�ӽڵ�
		curroot = stack.top();
		ivector.push_back(curroot->val);
		stack.pop();

		curroot = stack.top()->right;

	}
	return ivector;
}

void test_145(){
	string sarray[] = {"2", "1", "+", "3", "*"};
	vector<string> svector(sarray, sarray + 5);
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	postorderTraversal(root);
}


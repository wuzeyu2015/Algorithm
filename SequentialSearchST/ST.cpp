// SequentialSearchST.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SequentialSearchST.h"
#include "BinarySearchST.h"
#include "BST.h"


int main()
{
	//SequentialSearchST<string, int>::main(1);
	//BinarySearchST<string, int>::main(1);
	BST<string, int>::main(1);
	system("pause");
    return 0;
}

//1.string a == NULL ������
// string testdemo1(string a){
// 	if (a == NULL);
// 	return NULL;
// }
// string testdemo2(int a) {
// 	if (a == NULL);
// 	return NULL;
// }
//2.ģ��ʵ����������
//3.�õ���string��������keyarry���������Ĳ������Ժ�����������ͬ
//4.while (getline(ifs, read, ' ')) //�ԡ� ��Ϊ�ָ��ȡ���ʣ� �����ļ�����ʱ������"\nlpp"
//5.������������ָ��TreeNode*ע����������
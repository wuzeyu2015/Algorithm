// SequentialSearchST.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SequentialSearchST.h"
#include "BinarySearchST.h"
#include "BST.h"


int main()
{
	//���������˳�����
	//SequentialSearchST<string, int>::main(1);

	//��������Ķ��ֲ���
	//BinarySearchST<string, int>::main(1);

	//���������
	BST<string, int>::main(1);
	//BST�ӿڲ���
	BST<string, int>::main2();
	system("pause");
    return 0;
}

//1.string a == NULL ������ ex: string test(){return NULL;}���ش������Դ���

//2.ģ��ʵ���������⣬ģ�����obj�����û��ʵ���ĵ��ã��򲻻�������ʵ�ִ��룬����main.obj���Ҳ�����ʵ�֡�
//2.ģ���෽���е���ģ����������ڵķ����������ͨ�����������û��ʵ����ģ���������£�
// Value BST<Key, Value>::get(TreeNode* root, Key key)
// {
// 	key.teset();

//3.�õ���string��������keyarry���������Ĳ������Ժ�����������ͬ
//3.sizeof(keys)/sizeof(string)���ã�keysΪstring����

//4.while (getline(ifs, read, ' ')) //�ԡ� ��Ϊ�ָ��ȡ���ʣ� �����ļ�����ʱ������"\nlpp"

//5.������������ָ��TreeNode*ע����������
//6.��Ҫ���������д��һ��ex:Key BST<Key, Value>::ceiling(Key key)�� if (pNode == NULL) return "NULL"��string���Ͳ�����NULLת��;
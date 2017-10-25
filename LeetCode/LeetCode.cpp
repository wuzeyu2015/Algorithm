// LeetCode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

//ջӦ��
#include "20_Valid_Parentheses.h"
#include "150_Evaluate_Reverse_Polish_Notation.h"
#include "71_Simplify_Path.h"

#include "144_Binary_Tree_Preorder_Traversal.h"
#include "94_Binary_Tree_Inorder_Traversal.h"
//#include "145_Binary_Tree_Preorder_Traversal.h"��ջʵ�ֺ�������û�п����ף���

//����Ӧ��
#include "102_Binary_Tree_Level_Order_Traversal.h"//BFS��Queue
#include "103_Binary_Tree_Zigzag_Level_Order_Traversal.h"
#include "107_Binary_Tree_Level_Order_Traversal_II.h"
#include "199_Binary_Tree_Right_Side_View.h"
#include "279_Perfect_Squares.h"//ֻ��dp�ⷨ��BFS��Queueû�����������⻹����ͼ����
#include "127_Word_Ladder.h"//BFS��Queue��ֻҪ�󷵻ز�����
#include "126_Word_LadderII.h"//BFS��Queue��������·������

//���ȶ���Ӧ��
#include "347_Top_K_Frequent_Elements.h"
#include "23_Merge_k_Sorted_Lists.h"

//�������������⣨�ݹ飩
#include "104_Maximum_Depth_of_Binary_Tree.h"
#include "111_Minimum_Depth_of_Binary_Tree.h"
#include "226_Invert_Binary_Tree.h"
#include "100_Same_Tree.h"
#include "101_Symmetric_Tree.h"
#include "222_Count_Complete_Tree_Nodes.h"
#include "110_Balanced_Binary_Tree.h"

//��ֹ����Ӧ�ã��ݹ飩
#include "112_Path_Sum.h"

//����
#include "125_Valid_Palindrome.h"//�ݹ��жϻ���
#include "43_Multiply_Strings.h"//�������
class Ctest {

public:
	Ctest& operator + (Ctest& cc) {
		int i = cc.a;
		return *this;
	}
private:
	int a;

};

int _tmain(int argc, _TCHAR* argv[])
{
	test_20();
	test_71();

	test_144();
	test_94();

	test_102();
	test_103();
	test_107();
	test_199();
	test_279();
	test_127();

	test_347();
	test_23();

	test_104();
	test_111();
	test_226();
	test_100();
	test_222();
	test_110();
	test_101();
	test_112();

	test_125();
	test_043();


	return 0;
}


#include "stdafx.h"

//1��ע�⸴�Ӷȵķ���
//2��ע�����³����

struct compare {
	bool operator()(const ListNode* l, const ListNode* r) {
		return l->val > r->val;
	}
};

ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue

	priority_queue<ListNode *, vector<ListNode *>, compare> q;
	for(auto it = lists.begin(); it != lists.end(); it++){
		if(*it) q.push(*it);//�ر�ע��if(*it)�ж��Ƿ�Ϊ�գ���ֵ����pq���ҵ�
	}
	if(q.empty()) return NULL;
	ListNode * res = q.top();//k������ͷ����С��һ��
	ListNode * itor = res;
	q.pop();
	while(!q.empty()){
		if(itor->next)
			q.push(itor->next);
		itor->next = q.top();
		q.pop();
		itor = itor->next;
	}
	return res;
}


void test_23()
{
	ListNode* PNode1 = new ListNode(0);
	PNode1->next = NULL;
	ListNode* Phead1 = PNode1;

	ListNode* PNode2 = new ListNode(3);
	PNode1->next = NULL;
	ListNode* Phead2 = PNode2;
	for(int i = 1; i < 3; i++){
		PNode1->next = new ListNode(i);
		PNode1 = PNode1->next;
		PNode1->next = NULL;

		PNode2->next = new ListNode(i + 3);
		PNode2 = PNode2->next;
		PNode2->next = NULL;
	}
	vector<ListNode *> v(2,0);//null������Գ���³����
	// 	v.push_back(Phead1);
	// 	v.push_back(Phead2);
	mergeKLists(v);
}

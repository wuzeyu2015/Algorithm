#include "stdafx.h"

//1��map��ֵ����PQ
vector<int> topKFrequent(vector<int>& nums, int k) {

	map<int, int> freqMap;//first->num second->freq
	vector <int> res(0,0);
	for(auto it = nums.begin(); it != nums.end(); it++){
		freqMap[*it]++;
	}
	priority_queue<pair<int,int>> MaxPQ;//first->freq second->num,�Լ�ֵ����
	for(auto it = freqMap.begin(); it != freqMap.end(); it++){
		MaxPQ.push(make_pair(it->second,it->first));
		if( MaxPQ.size() >  (int)freqMap.size() - k){//�˴��Ż���ʹMaxPQ��sizeά����n-k
			res.push_back(MaxPQ.top().second);
			MaxPQ.pop();
		}
	}
	return res;
}


void test_347()
{
	int a[] = {1,1,1,1,2,2,3,3,3,4};
	vector<int> b(a, a+10);
	topKFrequent(b, 3);
}

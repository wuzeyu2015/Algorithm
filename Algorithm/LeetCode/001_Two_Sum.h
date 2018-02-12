#include "stdafx.h"
#pragma once
//1��Add Two Number����������ļӷ���
//ѭ����������ͬʱ��������ͬ����������б��������жϵ�ĳ�������Ѿ�������ĩ��ʱ���̶�����ָ�룬��ӿ�����ģ����������ڵĽ��valȫ��Ϊ0 ��ֱ����������������ĩ��ʱ������ѭ����
int* twoSum(int* nums, int numsSize, int target) {
	int* result = 0;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result = (int*)malloc(sizeof(int) * 2);
				result[0] = i;
				result[1] = j;
			}
		}
	}
	return result;
}

//2��hashtable
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> imapIn;
		for (int i = 0; i < nums.size(); i++) {
			imapIn.insert(make_pair(nums[i], i));
		}
		for (int i = 0; i < nums.size(); i++) {
			int ifind = target - nums[i];
			if (imapIn.find(ifind) != imapIn.end() && imapIn[ifind] != i) {
				int arr[] = { i, imapIn[ifind] };
				return vector<int>(arr, arr + 2);
			}
		}
	}
};

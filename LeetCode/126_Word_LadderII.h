#include "stdafx.h"

// 0��ע�����ѭ��֮ǰ��һ��Ԫ�صĹ�����
// 1��BFS��queue�Ǳ�������ݽṹ��
// 2��BFSѭ����Զ�ǣ��ⲿѭ����ÿ�㣩 + �ڲ�ѭ����ѭ�������Ǳ����������ʶ���Ԫ�ء�ѹ�����Ԫ�أ�
// 3��ע��ʱ�临�Ӷȷ����Լ�15�е��Ż��Ը��Ӷȵ�Ӱ�죻
// 4��resΪ���·����

void NextLevel(string beginWord, set<string>& wordDict, queue<string>& toVisit) {
	string strtemp = beginWord;
	wordDict.erase(beginWord);
	
	for (int i = 0; i < strtemp.size(); i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			beginWord[i] = c;				//��ٿ��ܵ��ַ���
			if(wordDict.find(beginWord) != wordDict.end()){
				toVisit.push(beginWord);	//Ѱ����beginWord���ڵ��ַ�����Ȼ������ǷŽ�����toVisit
				wordDict.erase(beginWord);	//����������Ż�������ʱ
			}		
		}
		beginWord = strtemp;			    //��ԭbeginWord
	}
}

vector <vector <string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	set<string> wordDict(wordList.begin(), wordList.end());
	vector <vector <string>> res(0, vector <string>());
	int iLevel = -1;
	queue<string> toVisit;
	toVisit.push(beginWord);				//������һ��
	while (!toVisit.empty())
	{
		iLevel++;
		int curLevel = toVisit.size();
		for(int i = 0; i < curLevel; i++){
			beginWord = toVisit.front();
			toVisit.pop();
			if(beginWord == endWord)
				return res;
			NextLevel(beginWord, wordDict, toVisit);
		}
	}
	return res;
}



void test_127(){
	vector<string> wordDict;
	wordDict.push_back("hot");
	wordDict.push_back("dot");
	wordDict.push_back("dog");
	wordDict.push_back("lot");
	wordDict.push_back("log");
	wordDict.push_back("cog");
	int i = ladderLength("hit", "cog", wordDict);
}


#include "stdafx.h"


string simplifyPath(string path) {
	stack<string> sstack;
	stack<string> sstacktmp;
	string tmp;
	string sret;
	stringstream ss(path);
	while(getline(ss, tmp, '/')){
		//�����ַ������"/a//b/c"
		if(tmp == "." || tmp == "")
			continue;
		else if(tmp == ".."){
			//�Ѿ����˸�Ŀ¼�����
			if(!sstack.empty())
				sstack.pop();
		}
		else //�����̷���ջ
			sstack.push(tmp);
	}
	//ʹ��c++ 11��for range�Ϳ���ֱ�Ӵ�ջ�ײ����ʲ���Ҫsstacktmp
	while(!sstack.empty()){
		sstacktmp.push(sstack.top());
		sstack.pop();
	}
	while(!sstacktmp.empty()){
		sret += "/" + sstacktmp.top();
		sstacktmp.pop();
	}
	return sret.empty()? "/" : sret;
}

void test_71(){
	simplifyPath("/..");
}
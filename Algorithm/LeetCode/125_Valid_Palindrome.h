#include "stdafx.h"


//�ݹ�ʵ�֣�û�п���ʡ�Բ�����ַ��ʹ�Сд����
bool isPalindrome(string s) {
	if (s.size() <= 1)
	{
		return true;
	}
	else if (s[0] == s[s.size() - 1])
	{
		s.pop_back();
		s.erase(0, 1);
		return isPalindrome(s);
	}
	else
		return false;
}

void test_125(){
 
	bool i = isPalindrome("a.");
}
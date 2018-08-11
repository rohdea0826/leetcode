// leetcode_string.cpp: 定义控制台应用程序的入口点。
// leetcode 初级算法_字符串     环境VS2017

#include "stdafx.h"
#include<string>

using namespace std;

class Solution {
public:
	//反转字符串
	string reverseString(string s) {
		int lenth = s.length();
		char tmp;
		//简单的首尾交换
		for (int i = 0; i < lenth / 2; i++)
		{
			tmp = s[i];
			s[i] = s[lenth - i - 1];
			s[lenth - i - 1] = tmp;
		}
		//测试时通过printf无法正确输出，查阅互联网得知应使用s.c_str来获取string字符串的首地址
		return s;
	}

	//颠倒数组
	int reverse(int x) {
		//printf("%d", INT_MIN);
		//用long long int是因为当数字倒过来后超过int最大值得很多倍时，数字也可以存起来判断是否溢出
		//不然两个int值相加可以通过正负来判断是否溢出
		//然而反转有可能超过INT_MAX几倍，从而无法简单的通过正负判断是否溢出
		long long int result = 0, tmp = x;
		while (x != 0)
		{
			result = result * 10 + (x % 10);
			x /= 10;
		}
		//一开始使用判断正负的方式，无法AC
		//if ((tmp > 0 && result < 0) || (tmp < 0 && result > 0))
		//	return 0;
		if (result > INT_MAX || result < INT_MIN)
			return 0;
		return result;
	}


};

int main()
{
	Solution x;
	//printf("%s\n", x.reverseString("hello").c_str());
	//printf("%d\n", x.reverse(1534236469));
	


    return 0;
}


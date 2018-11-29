// leetcode_string.cpp: 定义控制台应用程序的入口点。
// leetcode 初级算法_字符串     环境VS2017

//#include "stdafx.h"
#include <iostream>
#include <string>

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

	//第一个唯一字符
	int firstUniqChar(string s) {
		size_t count[255] = { 0 };
		for (size_t i = 0; i < s.size(); i++)
			count[s[i]]++;
		for (size_t i = 0; i < s.size(); i++)
			if (count[s[i]] == 1) return i;
		return -1;
	}

	//字母异位词
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		size_t count[256] = { 0 };
		for (size_t i = 0; i < s.size(); i++)
			count[s[i]]++;
		for (size_t i = 0; i < s.size(); i++)
			count[t[i]]--;
		for (size_t i = 0; i < 256; i++)
			if (count[i] != 0) return false;
		return true;
	}

	bool isBigAlpha(const char& c)
	{
		if (c >= 'A'&&c <= 'Z') return true;
		return false;
	}
	bool isAlphaNum(const char& c)
	{
		if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || isBigAlpha(c))
			return true;
		return false;
	}
	//判断回文串
	bool isPalindrome(string s) {
		if (s.size() == 0) return true;
		size_t left = 0;
		size_t right = s.size() - 1;
		
		while (left < right)
		{
			while (!isAlphaNum(s[left]) && left < s.size())
				left++;
			while (!isAlphaNum(s[right]) && right != 0)
				right--;

			if (left >= right || right == 0) break;

			if (isBigAlpha(s[left])) s[left] += 32;
			if (isBigAlpha(s[right])) s[right] += 32;
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}

	int myAtoi(string str) {

	}

};

int main()
{
	Solution x;
	//printf("%s\n", x.reverseString("hello").c_str());
	//printf("%d\n", x.reverse(1534236469));
	//cout << x.firstUniqChar(string("helloh")) << endl;
	//cout << x.isAnagram("hello", "olelh") << endl;
	//cout << x.isPalindrome(".,") << endl;


    return 0;
}


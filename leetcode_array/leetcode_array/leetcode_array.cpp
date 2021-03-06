#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:

	//从排序数组中删除重复项
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0) return 0;
		for (std::vector<int>::iterator i = nums.begin(); i != nums.end() - 1;)
		{
			if (*i == *(i + 1))
				i = nums.erase(i);
			else
				i++;
		}
		return (int)nums.size();
	}

	//买卖股票的最佳时机Ⅱ
	int maxProfit(std::vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int min = prices[0], sum = 0;
		for (std::vector<int>::iterator i = prices.begin(); i != prices.end() - 1; i++)
		{
			if (*(i + 1) > min)
			{
				sum += *(i + 1) - min;
				min = *(i + 1);
			}
			else
				min = *(i + 1);
		}
		return sum;
	}

	//旋转数组
	void rotate(std::vector<int>& nums, int k) {
		int len = nums.size();
		k %= len;
		for (int i = 0; i<len / 2; i++)
		{
			rotate_swap(&nums[i], &nums[len - i - 1]);
			/*int tmp = nums[i];
			nums[i] = nums[len - i-1];
			nums[len - i-1] = tmp;*/
		}
		for (int i = 0; i < k / 2; i++)
		{
			rotate_swap(&nums[i], &nums[k - i - 1]);
			/*	int tmp = nums[i];
			nums[i] = nums[k - i-1];
			nums[k - i-1] = tmp;*/
		}
		for (int i = 0; i < (len - k) / 2; i++)
		{
			rotate_swap(&nums[i + k], &nums[len - i - 1]);
			/*int tmp = nums[i + k];
			nums[i + k] = nums[len - i-1];
			nums[len - i-1] = tmp;*/
		}
	}
	void rotate_swap(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	//存在重复
	bool containsDuplicate(std::vector<int>& nums)
	{
		//TLE时间超限
		//for (int i = 0; i < nums.size(); i++)
		//{
		//	for (int j = i+1; j < nums.size(); j++)
		//	{
		//		if (nums[i] == nums[j])
		//		{
		//			return true;
		//		}
		//	}
		//}
		//return false;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1]) return true;
		}
		return false;

	}

	//只出现一次的数字
	int singleNumber(std::vector<int>& nums) {
		//排序后通过判断前后有无相同值判断是否只出现一次，效率较低，需要排序。
		
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[0] != nums[1]) return nums[0];
			if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) return nums[i];
		}
		return *(nums.end() - 1);
	}

	//两个数组的交集Ⅱ
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> result;
		if (nums1.size() == 0 || nums2.size() == 0)	return result;
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());

		for (int i = 0, j = 0; i < nums1.size();)
		{
			if (j == nums2.size()) break;
			if (nums1[i] == nums2[j])
			{
				result.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])	i++;
			else if (nums1[i] > nums2[j])	j++;
		}
		return result;
	}

	//加一（数组存储各位数带进位）
	std::vector<int> plusOne(std::vector<int>& digits) {
		std::vector<int> result = digits;
		int len = result.size();
		if (*(result.end() - 1) == 9)		//数组等于***9...9
		{
			int i;
			for (i = len - 1; i >= 0; i--)
			{
				if (result[i] != 9)
				{
					result[i]++;
					break;
				}
			}
			if (i < 0)
			{
				result.insert(result.begin(), 1);
				len = len + 1;
				i++;
			}
			for (i++; i < len; i++)
			{
				result[i] = 0;
			}
		}
		else									//数组最后一位不等于9
		{
			result[len - 1]++;
		}
		return result;
	}

	//移动零
	void moveZeroes(std::vector<int>& nums) {
		if (nums.size() == 0) return;
		int count = 0;
		for (std::vector<int>::iterator it = nums.begin(); it != nums.end();)
		{
			if (*it == 0)
			{
				it = nums.erase(it);
				count++;
			}
			else
				it++;
		}
		for (int i = 0; i < count; i++)
		{
			nums.push_back(0);
		}
	}

	//两数之和
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> ret;
		if (nums.size() == 0) return ret;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
				}
			}
		}
		return ret;
	}

	//遍历数组并显示
	void Traversal(std::vector<int>& nums)
	{
		for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}

	//判断是否为有效数独
	bool isValidSudoku(vector<vector<char>>& board) {
		int count_row[10] = { 0 };
		int count_col[10] = { 0 };
		//循环遍历行和列
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				//判断每一行和每一列是否有重复
				//这里一定要记得判断是否为'.' 否则会造成数组越界
				if (board[i][j] != '.')
					count_row[board[i][j] - '0']++;
				if (board[j][i] != '.')
					count_col[board[j][i] - '0']++;
			}
			for (int k = 1; k < 10; k++)
			{
				if (count_row[k] > 1 || count_col[k] > 1)
					return false;
			}
			memset(count_row, 0, sizeof(count_row));
			memset(count_col, 0, sizeof(count_col));
		}
		int count[10] = { 0 };
		//外两层控制9个3*3的格子
		for (int raw = 0; raw < 3; raw++)
		{
			for (int col = 0; col < 3; col++)
			{
				//内两层控制一个3*3的小格子
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (board[i + 3 * raw][j + 3 * col] != '.')
							count[board[i + 3 * raw][j + 3 * col] - '0']++;
					}
				}
				for (int k = 0; k < 10; k++)
				{
					if (count[k] > 1) return false;
				}
				memset(count, 0, sizeof(count));
			}
		}
		return true;
	}

	void rotate(vector<vector<int>>& matrix)
	{

	}

private:

};

int main()
{
	//int k = 3;
	//int a[] = { 3,0,1,2,0 };
	//int b[] = { 9,9 };
	//std::vector<int> nums(a, a + 5);
	//std::vector<int> nums1(b, b + 2);
	//std::vector<int> tmp;
	Solution x;
	//x.maxProfit(nums);
	//x.removeDuplicates(nums);
	//x.rotate(nums,k);
	//tmp = x.intersect(nums, nums1);
	//tmp = x.plusOne(nums1);
	//std::cout << x.singleNumber(nums) << std::endl;
	//x.moveZeroes(nums);

	vector<vector<char>> test = {
	{ '.','.','4','.','.','.','6','3','.' },
	{ '.','.','.','.','.','.','.','.','.' },
	{ '5','.','.','.','.','.','.','9','.' },
	{ '.','.','.','5','6','.','.','.','.' },
	{ '4','.','3','.','.','.','.','.','1' },
	{ '.','.','.','7','.','.','.','.','.' },
	{ '.','.','.','5','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.' },
	{ '.','.','.','.','.','.','.','.','.' }
	};

	cout << x.isValidSudoku(test) << endl;;
	//x.Traversal(nums);
	cout << (int)'.'-(int)'0' << endl;
	return 0;
}

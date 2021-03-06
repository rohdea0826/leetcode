#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//删除链表中的节点
	void deleteNode(ListNode* node) {
		int tmp = node->next->val;
		node->val = tmp;
		node->next = node->next->next;
	}
	//删除链表的倒数第N个节点
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr) return head;
		if (head->next == nullptr)
		{
			if (n == 1) return nullptr;
			else
				return head;
		}
		ListNode *fast = head;
		ListNode *slow = head;
		while (n--)
		{
			fast = fast->next;
		}
		if (fast == nullptr) return head->next;
		fast = fast->next;
		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		if (slow != nullptr && slow->next != nullptr)
			slow->next = slow->next->next;
		else
			slow->next = nullptr;
		return head;
	}
	//反转链表
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *left = nullptr;
		ListNode *right = head;
		ListNode *tmp = nullptr;
		while (right != nullptr)
		{
			tmp = right;
			right = right->next;
			tmp->next = left;
			left = tmp;
		}
		return left;
	}
	//合并两个有序链表
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode *ret = nullptr;
		ListNode *cur = ret;
		if (l1->val < l2->val)
		{
			ret = l1;
			l1 = l1->next;
		}
		else
		{
			ret = l2;
			l2 = l2->next;
		}
		cur = ret;
		while (l1 != nullptr && l2!= nullptr)
		{
			if (l1->val <= l2->val)
			{
				cur->next = l1;
				cur = cur->next;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				cur = cur->next;
				l2 = l2->next;
			}
		}
		while (l1 != nullptr)
		{
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
		cur->next = nullptr;
		return ret;
	}
	//回文链表
	bool isPalindrome(ListNode* head) {
		//要求时间复杂度O（n），空间复杂度O（1）  ？？？
		//通过快慢指针找到中间节点，其间将前半部分逆置
		//之后分别遍历两个链表依次判断
		if (head == nullptr || head->next == nullptr) return true;
		ListNode *left = nullptr;
		ListNode *cur = left;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr)
		{
			if (fast->next != nullptr)
				fast = fast->next->next;
			else
			{
				//若链表节点数为奇数，将中间值跳过
				slow = slow->next;
				break;
			}
			cur = slow;
			slow = slow->next;
			cur->next = left;
			left = cur;
		}
		while (left != nullptr)
		{
			if (slow == nullptr) return false;
			if (left->val != slow->val) return false;
			left = left->next;
			slow = slow->next;
		}
		return true;

	}
	//环形链表
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return false;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr)
		{
			if (fast->next != nullptr)
				fast = fast->next->next;
			else break;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

int main()
{
	ListNode *head = &ListNode(1);
	head->next = &ListNode(0);
	head->next->next = &ListNode(1);
	head->next->next->next = &ListNode(1);
	//head->next->next->next->next = head;
	ListNode *list2 = &ListNode(2);
	Solution x;
	//ListNode *ret = x.removeNthFromEnd(head, 3);
	//ListNode *ret = x.reverseList(head);
	//ListNode *ret = x.mergeTwoLists(head, list2);
	//bool ret = x.hasCycle(head);
	bool ret = x.isPalindrome(head);
	return 0;
}
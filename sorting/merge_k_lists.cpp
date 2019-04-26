#include "algo.h"

struct ListNode
{
	int data;
	ListNode *next;
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *result = nullptr;

	if (l1 == nullptr)
	{
		return l2;
	}

	if (l2 == nullptr)
	{
		return l1;
	}

	if (l1->data <= l2->data)
	{
		result = l1;
		result->next = mergeTwoLists(l1->next, l2);
	}
	else
	{
		result = l2;
		result->next = mergeTwoLists(l1, l2->next);
	}
	return result;
}

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
	if (lists.empty())
		return nullptr;

	int end = lists.size() - 1;
	while (end > 0)
	{
		int begin = 0;
		while (begin < end)
		{
			lists[begin] = mergeTwoLists(lists[begin], lists[end]);
			begin++, end--;
		}
	}
	return lists[0];
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead,*next1;
		newhead = NULL;
		while (head)
		{
			next1 = head->next;
			head->next = newhead;
			newhead = head;
			head = next1;
		}
		return newhead;
    }
};
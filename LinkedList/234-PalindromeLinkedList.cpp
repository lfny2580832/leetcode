#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//快慢指针了解一下，还应用在求链表环的交点
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(head == NULL || head->next == NULL) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
        	slow = slow->next;
        	fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow){
        	if(head->val != slow->val) return false;
        	head = head->next;
        	slow = slow->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head){
        ListNode *new_head = NULL;
        //此时3(head)->4->5,2(new_head)->1
        while(head){
        	//备份4
            ListNode *backupNext = head->next;
            //3指向2
            head->next = new_head;
            //新头指向旧头指向的3
            new_head = head;
            //旧头指向已备份的4
            head = backupNext;
        }
        return new_head;
    }
};
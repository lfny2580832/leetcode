#include <stdio.h>
 // * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
   	ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
public:
	// 2*(a+b) = a + b + c + b --> a = c
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        while(fast){
        	slow = slow->next;
        	fast = fast->next;
        	if(!fast) return NULL;
        	fast = fast->next;
        	if(slow == fast){
        		meet = fast;
        		break;
        	}
        }
        if(meet == NULL) return NULL;
        while(head && meet){
        	if(meet == head) return head;
        	meet = meet->next;
        	head = head->next;
        }
        return NULL;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycle(&a);
	if(node){
		printf("%d\n", node->val);
	}else{
		printf("NULL");
	}

    printf("fff %d\n", -1&1);
	return 0;
}
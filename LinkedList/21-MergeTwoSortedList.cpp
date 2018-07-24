#include<stdio.h>
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode temp_head(0);
    	ListNode *head_ptr = &temp_head;
    	while(l1 && l2){
    		if(l1->val > l2->val){
    			head_ptr->next = l2;
    			l2 = l2->next;
    		}else{
    			head_ptr->next = l1;
    			l1 = l1->next;
    		}
    		head_ptr = head_ptr->next;
    	}
    	if(l1){
    		head_ptr->next = l1;
    	}
    	if(l2){
    		head_ptr->next = l2;
    	}
        return temp_head.next;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(4);
	ListNode d(1);
	ListNode e(3);
	ListNode f(4);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	Solution solve;
	ListNode *result = solve.mergeTwoLists(&a,&d);
	while(result){
		printf("%d->", result->val);
		result = result->next;
	}

}
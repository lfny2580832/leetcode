#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return NULL;
    	if(!head->next) return head;
        ListNode *pre = head;
        ListNode *ptr = head->next;
        while(ptr){
        	if(pre->val == ptr->val){
        		pre->next = (ptr->next)? ptr->next:NULL;
				ptr = ptr->next;
        	}else{
        		pre = pre->next;
        		ptr = ptr->next;
        	}
        }
        return head;
    }
};

int main(){
	ListNode a(1);
	ListNode b(1);
	ListNode c(1);
	ListNode d(2);
	ListNode e(3);
	ListNode f(3);
	ListNode g(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	Solution solve;
	ListNode *result = solve.deleteDuplicates(&a);
	while(result){
		printf("%d->", result->val);
		result = result->next;
	}
	return 0;
}
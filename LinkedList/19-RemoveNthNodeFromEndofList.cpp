#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *end_ptr = head, *pre_ptr = head;
        while(n--) {
        	end_ptr = end_ptr->next;
        	if(!end_ptr) return head->next;
        }
        while(end_ptr){
        	if(!end_ptr->next) break;
        	end_ptr = end_ptr->next;
        	pre_ptr = pre_ptr->next;
        }
        pre_ptr->next = pre_ptr->next->next;
        return head;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(4);
	ListNode d(3);
	ListNode e(6);
	ListNode f(5);
	ListNode g(7);
	ListNode h(8);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	Solution solve;
	ListNode *result = solve.removeNthFromEnd(&a,7);
	while(result){
		printf("%d->", result->val);
		result = result->next;
	}
	return 0;
}
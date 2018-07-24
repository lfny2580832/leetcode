#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
    	if(!head) return false;
    	if(!head->next) return false;
        ListNode *low_ptr = head;
        ListNode *fast_ptr = head;
        while(fast_ptr){
        	low_ptr = low_ptr->next;
        	fast_ptr = (fast_ptr->next)?fast_ptr->next->next:NULL;
        	if(fast_ptr == low_ptr) return true;
        }
        return false;
    }
};

int main(){
	ListNode a(1);

	// ListNode b(1);
	// a.next = &b;
	// b.next = &a;
	Solution solve;
	printf("%d\n", solve.hasCycle(&a));
	return 0;
}
#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

    	if(head == NULL) return head;

        // if(head->val == val) {
        // 	head = head->next;
        // }
    	while(head->val == val){
    		head = head->next;
			if(head == NULL) return NULL;
    	}


        ListNode *ptr = head;
        while(ptr->next){
        	if(ptr->next->val == val){
        		ptr->next = ptr->next->next;
        	}else{
        		ptr = ptr->next;
        	}
        }

        return head;
    }
};

int main(){
	ListNode a(1);
	ListNode b(1);
	a.next = &b;
	Solution solve;
	ListNode *result = solve.removeElements(&a,1);
	// while(result){
	// 	printf("输出--%d\n", result->val);
	// 	result = result->next;
	// }	
	return 0;
}
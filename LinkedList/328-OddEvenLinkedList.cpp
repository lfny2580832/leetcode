#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
  //   	if(!head) return NULL;
		// ListNode odd_head(0);//奇数
		// ListNode *odd_ptr = &odd_head;
		// ListNode even_head(0);
		// ListNode *even_ptr = &even_head;
		// ListNode *backup_head = head;
		// while(head){
		// 	if(head->val%2){
		// 		odd_ptr->next = head;
		// 		odd_ptr = odd_ptr->next;
		// 	}else{
		// 		even_ptr->next = head;
		// 		even_ptr = even_ptr->next;
		// 	}
		// 	head = head->next;
		// }
		// if(backup_head->val%2){
		// 	odd_ptr->next = even_head.next;
		// 	even_ptr->next = NULL;
		// 	return odd_head.next;
		// }else{
		// 	even_ptr->next = odd_head.next;
		// 	odd_ptr->next = NULL;	
		// 	return even_head.next;
		// }
		if(!head) return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

int main(){
	ListNode a(2);
	ListNode b(1);
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
	ListNode *result = solve.oddEvenList(&a);
	while(result){
		printf("%d->", result->val);
		result = result->next;
	}
	return 0;
}
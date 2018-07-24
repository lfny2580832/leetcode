#include <stdio.h>
 // * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
   	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A = 0;
        int len_B = 0;
        int len_move = 0;
        ListNode *backupA = headA;
        ListNode *backupB = headB;
		while(backupA){
			len_A++;
			backupA = backupA->next;
		}
		while(backupB){
			len_B++;
			backupB = backupB->next;
		}
		if(len_A >= len_B){
			len_move = len_A - len_B;
			while(headA && len_move--){
				headA = headA->next;
			}
		}else{
			len_move = len_B - len_A;			
			while(headB && len_move--){
				headB = headB->next;                
			}
		}
		while(headA && headB){
			if(headA == headB){
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}

};

int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode b1(3);
	ListNode b2(4);
	ListNode b3(5);
	ListNode c1(6);
	ListNode c2(7);
	ListNode c3(8);
	a1.next = &a2;
	a2.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;
	Solution solve;
	ListNode *result = solve.getIntersectionNode(&a1,&b1);
	printf("%d\n", result->val);
	return 0;
}
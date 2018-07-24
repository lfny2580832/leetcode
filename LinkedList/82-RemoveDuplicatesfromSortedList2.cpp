#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//pre_ptr->head->following_ptr，三指针
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode pre_head(0);
        ListNode *pre_ptr = &pre_head;
        pre_ptr->next = head;
        ListNode *following_ptr = head->next;
        //pre_ptr停在要删除的子链表前，head停留在删除子链表头
        //following_ptr要停留在要删除子串的尾结点
        while(following_ptr){
            if(head->val == following_ptr->val){
                while(following_ptr->val == head->val){
                    if(!following_ptr->next) {
                        pre_ptr->next = NULL;
                        return pre_head.next;
                    }
                    if(following_ptr->next->val != following_ptr->val) break;
                    following_ptr = following_ptr->next;
                }
                //delete
                pre_ptr->next = following_ptr->next;
                head = following_ptr->next;
                following_ptr = head->next;
            }else{
                pre_ptr = pre_ptr->next;
                head = head->next;
                following_ptr = following_ptr->next;
            }
        }
        return pre_head.next;
    }

    //递归
    ListNode* deleteDuplicates_recursion(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        int val = head->val;
        ListNode *p = head->next;
        
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};

//1-1-1-2-3-3-4-5
int main(){
	ListNode a(1);
	ListNode b(1);
	ListNode c(1);
	ListNode d(2);
	ListNode e(3);
	ListNode f(3);
	ListNode g(4);
	ListNode h(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	Solution solve;
	ListNode *result = solve.deleteDuplicates(&a);
	while(result){
		printf("%d-->", result->val);
		result = result->next;
	}
	return 0;
}
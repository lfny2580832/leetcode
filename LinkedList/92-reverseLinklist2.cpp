
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;
        //第一个关键节点
        ListNode *pre_head = NULL;
        //最终链表头结点
        ListNode *result_head = head;
        //将head沿指针方向移动m-1个位置
        while(head && --m){
        	//记录head前驱
        	pre_head = head;
        	head = head->next;
        }
        //逆置后的链表尾指向当前head
        ListNode *modify_list_tail = head;
        ListNode *new_head = NULL;
        //逆置
        while(head && change_len){
        	ListNode *next = head->next;
        	head->next = new_head;
        	new_head = head;
        	head = next;
        	change_len--;
        }
        //连接逆置后的链表尾
        modify_list_tail->next = head; 
        //不空说明不是从第一个结点开始逆置
        if(pre_head){
        	pre_head->next = new_head;
        }
        else{
        	result_head = new_head;
        }
        return result_head;
    }
};
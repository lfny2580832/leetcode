
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = NULL;
        //此时3(head)->4->5,2(new_head)->1
        while(head){
        	//备份4
            ListNode *backupNext = head->next;


            //3指向2
            head->next = new_head;
            //新头指向旧头指向的3
            new_head = head;


            //旧头指向已备份的4
            head = backupNext;
        }
        return new_head;
    }
};
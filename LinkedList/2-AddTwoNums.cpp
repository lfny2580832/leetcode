// #include <stdio.h>
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// class solution:{
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//         ListNode preHead(0), *p = &preHead;
//         int extra = 0;
//         while (l1 || l2 || extra) {
//             int a = l1 ? l1->val:0;
//             int b = l2 ? l2->val:0;
//             int s = a + b + extra; 
//             //求进位
//             extra = sum / 10;   
//             p->next = new ListNode(sum % 10);
//             p = p->next;
//             l1 = l1 ? l1->next : l1;
//             l2 = l2 ? l2->next : l2;
//         }
//         return preHead.next;
//     }
// };

int main(){
    printf("shit%d\n",-1&1);
    return 0;
}

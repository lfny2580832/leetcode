#include<stdio.h>
#include<vecotr>
#include<algorithm>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//分治法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
   	ListNode temp_head(0);
    ListNode *head_ptr = &temp_head;
    while(l1 && l2){
    	if(l1->val > l2->val){
    		head_ptr->next = l2;
    		l2 = l2->next;
    	}else{
   			head_ptr->next = l1;
    		l1 = l1->next;
    	}
    	head_ptr = head_ptr->next;
    }
    if(l1){
    	head_ptr->next = l1;
    }
    if(l2){
    	head_ptr->next = l2;
    }
    return temp_head.next;
}

class Solution_One {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);
        int mid = lists.size()/2;    
        std::vector<ListNode *> sub1_lists;
        std::vector<ListNode *> sub2_lists;
        for(int i = 0; i < mid ; i++){
        	sub1_lists.push_back(lists[i]);
        }
        for (int i = mid; i < lists.size(); i++){	
        	sub2_lists.push_back(lists[i]);
        }
        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);
        return mergeTwoLists(l1, l2);
    }
};


//先排序后连接
bool cmp(const ListNode *a, const ListNode *b){
	return a->val < b->val;
}

class Solution_Two{
public:
	ListNode *mergeKlists(std::vector<ListNode *> lists;){
		std::vector<ListNode *> node_vec;
		for(int i = 0; i < lists.size(); i++){
			ListNode *head = lists[i];
			while(head){
				node_vec.push_back(head);
				head = head->next;
			}
		}
		if(node_vec.size() == 0){
			return NULL;
		}
		std::sort(node_vec.begin(), node_vec.end(), cmp);
		for(int i = 1; i < node_vec.size(); i++){
			node_vec[i-1]->next = node_vec[i];
		}
		node_vec[node_vec.size()-1]->next = NULL;
		return node_vec[0];
	}
};










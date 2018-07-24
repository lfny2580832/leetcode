#include<vector>
#include<queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>, std::greater<int> > Q;
        for(int i = 0; i<nums.size(); i++){
        	if(Q.size() < k){
        		Q.push(nums[i]);
        	}else if(nums[i] > Q.top()){
        		Q.pop();
        		Q.push(nums[i]);
        	}
        }
        return Q.top();
    }
};
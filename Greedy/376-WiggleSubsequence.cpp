#include<vector>

//贪心策略是保留连续递增/递减的首尾元素
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
    	if(nums.size() < 2) return nums.size();
    	static const int BEGIN = 0;
    	static const int UP = 1;
    	static const int DOWN = 2;
    	int STATE = BEGIN;
    	int max_lenth = 1;
    	for(int i = 1; i < nums.size(); i++){
    		switch(STATE){
    			case BEGIN:
    			if(nums[i-1] < nums[i]){
    				STATE = UP;
    				max_lenth++;
    			}else if(nums[i-1] > nums[i]){
    				STATE = DOWN;
    				max_lenth++;
    			}
    			break;
    			case UP:
    			if(nums[i-1] > nums[i]){
    				STATE = DOWN;
    				max_lenth++;
    			}
    			break;
    			case DOWN:
    			if(nums[i-1] < nums[i]){
    				STATE = UP;
    				max_lenth++;
    			}
    			break;
    		}
    	}
    	return max_lenth;

    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(3);

	Solution solve;
	int result = solve.wiggleMaxLength(nums);
	printf("%d\n", result);
	return 0;
}
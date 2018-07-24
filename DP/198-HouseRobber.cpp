#include<stdio.h>
#include<vector>
#include<algorithm>

//状态转移方程：dp[i] = max{dp[i-1], dp[i-2]+nums[i]}  i >= 3
class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        std::vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i ++){
        	dp[i] = std::max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};

int main(){
	Solution solve;
	int nums[] = {5,2,6,3,1,7};
	std::vector<int> nums_vec;
	for(int i = 0; i < 6; i ++){
		nums_vec.push_back(nums[i]);
	}
	printf("%d\n", solve.rob(nums_vec));
	return 0;
}
#include<stdio.h>
#include<vector>

/*
dp[i]以第i个数字结尾的最大子段和 
若dp[i-1] > 0:	dp[i] = dp[i-1] + nums[i]
否则：	dp[i] = nums[i]

故：dp[i] = max{dp[i-1]+nums[i],nums[i]}
*/
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for(int i = 1; i < nums.size(); i ++){
        	dp[i] = std::max(dp[i-1]+nums[i],nums[i]);
        	if(max_res < dp[i]) max_res = dp[i];
        }
        return max_res;
    }
};

int main(){
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
	std::vector<int> nums_vec;
	for(int i = 0 ; i < 9;i++){
		nums_vec.push_back(nums[i]);
	}
	Solution solve;
	printf("%d\n", solve.maxSubArray(nums_vec));
	return 0;
}
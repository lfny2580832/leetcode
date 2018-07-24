#include<stdio.h>
#include<vector>
#include<algorithm>

class Solution {
public:	
    bool makesquare(std::vector<int>& nums) {
    	if(!nums.size()) return false;
    	int sum = 0;
    	for(int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    	}
    	if(sum % 4 != 0)  return false;
    	int side_length = sum/4;
    	std::sort(nums.rbegin(),nums.rend());//大到小排序
    	int side[4] = {0};
    	return generate(0,nums,side_length,side);
    }

private:
	//i是从大到小第i根火柴
	bool generate(int i , std::vector<int> &nums, int side_length,int side[]){
		if(i >= nums.size()){ //火柴放完了，该比较了
			return side[0] == side_length && side[1] == side_length 
				&& side[2] == side_length && side[3] == side_length;
		}
		for(int j = 0; j < 4; j++){
			//把i放到第j个桶
			if(side[j] + nums[i] > side_length) continue;
			side[j] += nums[i];
			//继续放第i+1根
			if(generate(i+1,nums,side_length,side)){
				return true; //每一根火柴都能放下，每次回溯都返回true之后，进行最终判断↑
			}
			side[j] -= nums[i];
		}
		return false;
	}
};

int main(){
	//4 3 3 2 2 1 1
	int nums[] = {1,1,2,4,3,2,3};
	std::vector<int> nums_vec;
	for(int i = 0; i < 7; i ++){
		nums_vec.push_back(nums[i]);
	}
	Solution solve;
	printf("---%d\n", solve.makesquare(nums_vec));
	return 0;
}
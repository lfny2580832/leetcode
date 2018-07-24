#include<stdio.h>
#include<vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int pivot = 0;
        int begin = 0;
        int end = nums.size()-1;
        if(!nums.size()) return -1;
        for(int i = 0; i < nums.size()-1; i ++){
            if(nums[i] > nums[i+1]) {
                pivot = i+1;
                break;
            }
        }
        if(target == nums[begin]) return begin;
        if(target == nums[end]) return end;
        if(target >= nums[pivot] && target <= nums[end]){
        	return BianrySearch(nums,target,pivot,end);
        }else if(target <= nums[pivot-1] && target >= nums[begin]){
        	return BianrySearch(nums,target,begin,pivot);
        }
        return -1;
    }

 private:
	int BianrySearch(std::vector<int> &nums, int target, int begin, int end){
		int mid;
		while(begin <= end){
			mid = (begin + end)/2;
			if(target == nums[mid]) return mid;
			else if(target < nums[mid]){
				end = mid - 1;
			}else{
				begin = mid + 1;
			}
		}
		return -1;
	}
};

int main(){
	int test[] = {4,5,6,7,0,1,2};
	std::vector<int> nums;
	for(int i = 0; i < 7; i ++){
		nums.push_back(test[i]);
	}
	Solution solve;
    int result = solve.search(nums,2);
	printf("output: %d\n", result);
	return 0;
}






#include<stdio.h>
#include<vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int a=-1,b=-1;//【a,b】【起点，终点】
        int begin = 0;
        int end = nums.size()-1;
        int mid;
		std::vector<int> result;

        //找a

        while(begin <= end)
        {
        	if(target < nums[begin] || target > nums[end])	 {break;}
        	mid = (begin + end)/2; 
        	if(target == nums[mid] && target != nums[mid-1])	{a = mid; break;}
        	else if(target <= nums[mid])
        	{
        		if(target == nums[begin])	{a = begin; break;}
        		end = mid - 1;
        	}
        	else if(target > nums[mid])
        	{
        		if(target == nums[mid+1]){a = mid+1;break;}
        		begin = mid + 1;
        	}
        }
        b = a;
        for(int i = a+1; i < nums.size(); i ++){
        	if(target == nums[i]){
        		b = i;
        	}
        }
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};

int main(){
	int test[] = {1,3,3,3,4,4,4,4,4,4,4,5};//a=11
	int test1[] = {1,3,3,5,5,5,5,5,5,6,6,6};//a=3
	int test2[] = {1,3,3,4,4,4,5,5,5,5,5,5};//a=6
	int test3[] = {5,5,5,6,6,6,6,6,6,6,6,6};//a=0
	std::vector<int> nums;
	for(int i = 0 ; i < 12; i ++){
		nums.push_back(test3[i]);
	}
	Solution solve;
	std::vector<int> result = solve.searchRange(nums, 5);

}
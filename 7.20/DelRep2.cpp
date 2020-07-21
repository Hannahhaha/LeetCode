#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    int DelRep(vector<int>& nums)
    {
        int slow=1;
        int n=nums.size();

        if(n<=2)
         return n;
        
        for(int fast=2;fast<n;fast++)
        {
            if(nums[fast]!=nums[slow-1])
            {
                nums[++slow]=nums[fast];
            }
        }
        return slow+1;
    }

};
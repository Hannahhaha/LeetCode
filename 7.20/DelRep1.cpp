#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int DelRep(vector<int>& nums)
    {
        int i=0;
        int n=nums.size();
        
        if(n==0)
         return 0;
        
        for(int j=1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[++i]=nums[j];
            }
        }
        return i+1;
    }
};
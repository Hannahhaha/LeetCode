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
        //慢指针从第2位开始，快指针从第三位开始，如果快指针不等于慢指针的前一位元素（保证中间空一个元素，可以保证元素最多出现两次）
        //那么那么慢指针的下一位就要赋上快指针的值，此时将快指针向下一位移动，重复上面的逻辑，直到快指针到达数组的最后 
        for(int fast=2;fast<n;fast++)
        {
            if(nums[fast]!=nums[slow-1])
            {
                nums[++slow]=nums[fast];
            }
        }
        return slow+1;//慢指针长度+1，即处理后数组的长度
    }

};
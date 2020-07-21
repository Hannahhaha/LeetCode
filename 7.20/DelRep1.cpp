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
         //j快指针从第二个数开始向下比遍历，并且与当前慢指针i进行比较，如果不同就会把快指针当前的数赋值给慢指针的下一个元素，
        //这样就保证了数字不重复，此时慢指针已经向后移动了一个单位，快指针继续向后移动，重复上一步不的逻辑。直至快指针到达数组的尽头
        for(int j=1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[++i]=nums[j];
            }
        }
        return i+1;//最后返回的是操作结束之后的数组的长度，及慢指针的长度+1
    }
};
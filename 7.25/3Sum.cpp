#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {vector<vector<int>> res;
        int len = nums.size();
        if (len < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int k = 0;
        while(k < len - 2 && nums[k] <= 0) {
            int l = k + 1;
            int r = len - 1;
            while (l < r) {
                int sum = nums[k] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[k], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++ l]) { }
                    while (l < r && nums[r] == nums[-- r]) { }
                }
                else if (sum < 0) {
                    ++ l;
                }
                else {
                    -- r;
                }
            }
            while (k < len - 2 && nums[k] == nums[++ k]) { }
        }
        return res;
    }
};

/*
vector<vector<int>> ans;
        int i,j,k,n=nums.size();
        sort(nums.begin(),nums.end());
        for(i=0; i<n-2; i++){		//令a=nums[i]
            j=i+1;k=n-1;
            while(j<k){		//二分查找，确定b和c
                if(nums[j]+nums[k] == -nums[i]){
                    if(j==i+1 || nums[j-1]!=nums[j]){		//j==i+1的作用是允许a和b相同，但我们不允许，连续取相同的b
                        vector<int> num{nums[i],nums[j],nums[k]};
                        ans.push_back(num);
                    }
                    j++;
                    k--;
                }else if(nums[j]+nums[k]<-nums[i]){
                    j++;
                }else{
                    k--;
                }
            }
            if(nums[i]>0)    break;
            while(i+1<n-2 && nums[i+1]==nums[i])   i++;		//避免连续取相同的a
        }
        return ans;

*/


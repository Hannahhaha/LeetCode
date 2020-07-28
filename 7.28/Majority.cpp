#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
//所有的元素放入到map中去，（值，出现的次数）对每个值进行count操作，时间复杂度为O[n].
//最后选择count数最大的值.
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) 
        {
            ++counts[num];
            if (counts[num] > cnt) 
            {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    
    }
};
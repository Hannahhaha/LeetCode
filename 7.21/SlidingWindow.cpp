#include<iostream>
#include<vector>
#include<deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> res;
        deque<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            //先判断window队首元素是否需要弹出
            if(!window.empty() && window.front() == i - k)
                window.pop_front();
            //插入新元素时，弹出队列中比新元素小的值
            while(!window.empty() && nums[window.back()] < nums[i]) 
                window.pop_back();
            window.push_back(i);
            //滑动窗口时，添加结果到目标容器中
            if (i >= k - 1)
                res.push_back(nums[window.front()]);
        }
    return res;
    }
};
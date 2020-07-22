#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
    {
        m=k;
        for(auto it:nums)//c++11的新特性，范围for。nums是一个可遍历的容器,vector类型，it就用来在遍历过程中获得容器里的每一个元素。
        {
            que.push(it);
            if(que.size()>k)
            {
                que.pop();
            }
        }
    }
    //更新最小堆
    int add(int val) {
        que.push(val);
        if(que.size()>m)
        {
            que.pop();
        }
        return que.top();

    }
    int m;
    priority_queue<int,vector<int>,greater<int>> que;
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
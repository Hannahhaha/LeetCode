#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //leetcode242题，有效数字的异位数，使用map,O(1).
        //List(数组，链表) vs Map(映射) vs Set(集合/不重复(哈希，树)).
        //Map:表单上相同的元素计数，一一对应，s计数后，若t在相同位置上减少的数量不相同
        //两个string异位.

        if(s.size() != t.size())
            return false;
        map<char,int> sMap;
        for(int i = 0; i < s.size(); i++)
        {
            sMap[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            sMap[t[i]]--;            
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(sMap[t[i]] != 0)
                return false;
        }
        return true;
    }
};
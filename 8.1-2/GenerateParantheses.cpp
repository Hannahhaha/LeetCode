#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string> result;
        CreatStr( n, result,"",0,0);
        return result;
        
    }
    void CreatStr(int n,vector<string> &result,
            string item,int left ,int right)
            {
                if(left + right ==2 *n && left == right)
                {
                    result.push_back(item);
                }
                if(left < n) CreatStr(n,result,item + '(',left + 1,right);
                if(right < left)CreatStr(n,result,item + ')',left,right + 1);

            }
};
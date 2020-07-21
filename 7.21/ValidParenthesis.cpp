#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution{
public:
    bool isValid(string s)
    {
        //unordered map 哈希，便于查找，O(1)
       unordered_map<char,char> m={{'{','}'},{'(',')'},{'[',']'}};
       stack <char>t;
       for(char n:s)//遍历字符串
       {
           if(n=='('||n=='{'||n=='[')//如果是左括号，入栈
              t.push(n);
           else//不是左括号
           {//如果是空的或者不属于对应map
               if(t.empty()||t.top()!=m[n])
                 return false;
               else//将先前的左括号pop出来
                   t.pop();    
           }   
       }
       return t.empty();
    }
};

/*
bool isValid(string s) {
        stack<char> t;
        //遍历
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                t.push(s[i]);//左括号push
            else{
                
                if(t.size() == 0)
                    return false;
                //括号可以匹配的三种情况
                char match;
                if(s[i] == ')')
                    match = '(';
                else if(s[i] == ']')
                    match = '[';
                else if(s[i] == '}')
                    match = '{';
                char c = t.top();
                t.pop();
                //不能匹配的情况
                if(c != match)
                    return false;
            }

        }
        if(t.size() != 0)
            return false;

        return true;
    }
};
*/
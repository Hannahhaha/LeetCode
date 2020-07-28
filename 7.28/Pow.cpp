#include<iostream>
using namespace std;

class Solution {
public:
//在n为偶数的情况下，可以将X^n变成X^(n/2)*X^(n/2);
//在n为奇数的情况下，可以将X^n变成X^(n/2)*X^(n/2)*X；
//在n为0的情况下，直接返回,跳出递归。
    double  Recursion(double x, long long n) 
    {
        if (n == 0) 
        {
           return 1.0;
        }
        double half = Recursion(x, n / 2);//先计算出half的值。
        if (n % 2 == 0)
        {
           return half * half;
        }
        else 
        {
           return half * half * x;
        }
    }      
    double myPow(double x, int n) 
    {
        long long i = n;
        if (i < 0) 
        {
            x = 1 / x;
            i = abs(i);
        }
        return Recursion(x, i);
    }

  
};
#include <bits/stdc++.h>
using namespace std;
vector<string> vv;
void bal(int open, int close, string op)
{

    if (open == 0 and close == 0)
    {
        vv.push_back(op);
        return ;
    }
    if (open!=0)
    {
        string op1=op;
        op1.push_back('(');
        bal(open-1, close, op1);
    }
    if (close > open)
    {
        string op2=op;
        op2.push_back(')');
        bal(open, close-1, op2);
    }
    return ;
}
int main()
{

    int n;
    cin >> n;
    bal(3,3,"");
    for (string x : vv)
    {
        cout << x;
        cout << endl;
    }
    return 0;
}
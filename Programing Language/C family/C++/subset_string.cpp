#include<bits/stdc++.h>
using namespace std;
void sub(string ip,string op){
    if(ip.size()==0)
    {
        cout<<op;
        cout<<endl;
        return ;
    }
    op+="_";
    char t=ip[0];
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    sub(ip,op);
    op.pop_back();
    op.pop_back();
    op.push_back(t);
    sub(ip,op);
    
}
int main()
{
    string a,b;
    cin>>a;
    b="";
    b.push_back(a[0]);
    a.erase(a.begin()+0);
    sub(a,b);
return 0;
}
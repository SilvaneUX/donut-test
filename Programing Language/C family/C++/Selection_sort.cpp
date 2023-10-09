#include<iostream>
using namespace std;
int main()
{
           int count_cmp=0;
           int n,a[20];
           cout<<"Enter the number of elements:";
           cin>>n;
           cout<<"Enter the elements of the array:\n";
           for(int i=0;i<n;i++)
                      cin>>a[i];
           char flag;
           cout<<"Enter the order:";
           cin>>flag;
           if(flag=='a' || flag=='A')
           {
                      for(int i=0;i<n-1;i++)
                      {
                                 int x=i;
                                 for(int j=i+1;j<n;j++)
                                 {
                                            if(a[x]>=a[j])
                                            {
                                                       count_cmp++;
                                                       x=j;
                                            }
                                 }
                                 if(x!=i)
                                 {
                                            int temp=a[i];
                                            a[i]=a[x];
                                            a[x]=temp;
                                 }
                      }
           }
           else if(flag=='d' || flag=='D')
           {
                      for(int i=0;i<n-1;i++)
                      {
                                 int x=i;
                                 for(int j=i+1;j<n;j++)
                                 {
                                            if(a[j]>=a[x])
                                            {
                                                       count_cmp++;
                                                       x=j;
                                            }
                                 }
                                 if(x!=i)
                                 {
                                            int temp=a[i];
                                            a[i]=a[x];
                                            a[x]=temp;
                                 }
                      }
           }
           cout<<"\nElements after selection sort:";
           for(int i=0;i<n;i++)
                      cout<<a[i]<<" ";
           cout<<"\nTotal no of comparisons:"<<count_cmp;
           return 0;
}

KagglesTitanic
==============
#include<iostream>
#include<algorithm>
using namespace std;
int cmp( const int &a, const int &b ){
    if( a < b )
       return 1;
    else
       return 0;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i-1];
    }
    sort(a,a+n,cmp);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i-1];
    }
}

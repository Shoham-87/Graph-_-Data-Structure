#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int f(int i,int j)
{
    if(i==j) return 0;
    if(i<0) return 1e9;
    if(i-j > j) return 0;
    int blue=1+f(i-1,j);
    int red=1+f(i*2,j);
    return min(red,blue);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    cout<<f(n,m);
    return 0;
}
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" ";
        for(auto j:adj[i])
        cout<<j<<"->";
        cout<<endl;
    }
    return 0;
}
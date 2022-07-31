#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int findparent(int node,vector<int>&parent)
{
    if(parent[node]!=node)
    {
        parent[node]=findparent(parent[node],parent);
    }
    return parent[node];
}
void Union(int u,int v,vector<int>&rank,vector<int>&parent)
{
    int a=findparent(u,parent);
    int b=findparent(v,parent);
    if(rank[a]==rank[b])
    {
        parent[b]=a;
        rank[a]++;
    }
    else if(rank[a]>rank[b])
    {
        parent[b]=a;
    }
    else if(rank[a]<rank[b])
    {
        parent[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1,0),rank(n+1,0);
    for (int i = 1; i <=n; i++)
        parent[i]=i;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v,rank,parent);
    }
    for(auto i:parent)
    cout<<i<<" "<<endl;
    if(findparent(2,parent)==findparent(5,parent))
    cout<<"Yes";
    else
    cout<<"NO";
    return 0;
}
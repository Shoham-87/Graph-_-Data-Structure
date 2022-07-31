#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct nodes
{
    int u,v,wt;
    nodes(int u,int v,int wt):u(u),v(v),wt(wt){}
};
bool shorter(nodes u,nodes v)
{
    return u.wt<v.wt;
}
int findparent(int node,vector<int>&parent)
{
    if(parent[node]==node)
    return node;
    return parent[node]=findparent(parent[node],parent);
}
void Union(int u,int v,vector<int>&rank,vector<int>&parent)
{
    int a=findparent(u,parent);
    int b=findparent(v,parent);
    if(rank[a]<rank[b])
    {
        parent[a]=b;
    }
    else if(rank[a]>rank[b])
    {
        parent[b]=a;
    }
    else 
    {
        parent[b]=a;
        rank[a]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<nodes> arr;
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        arr.push_back(nodes(u,v,wt));
    }
    sort(arr.begin(),arr.end(),shorter);
    vector<int>parent(n,0),rank(n,0);
    for(int i=0;i<n;i++)
    parent[i]=i;
    vector<pair<int,int>> mst;
    int cost=0;
    for(auto i:arr)
    {
        if(findparent(i.u,parent) != findparent(i.v,parent))
        {
            cout<<findparent(i.u,parent)<<" u "<<i.u<<endl;
            cost+=i.wt;
            mst.push_back(make_pair(i.u,i.v));
            Union(i.u,i.v,rank,parent);
        }
    }
    cout<<cost<<endl;
    for(auto i:mst)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
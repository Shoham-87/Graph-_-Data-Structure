#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct nodes
{
    int u,v,wt;
    nodes(int u,int v,int wt):u(u),v(v),wt(wt){}
};
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
    vector<int> dist(n,1e9);
    dist[0]=0;
    for(int ii=1;ii<=n-1;ii++)
    {
        for(auto i:arr)
        {
            if(dist[i.u]+i.wt < dist[i.v])
            dist[i.v]=dist[i.u]+i.wt;
        }
    }
    for(auto i:dist)
    cout<<i<<" ";
    for(auto i:arr)
    {
        if(dist[i.u]+i.wt < dist[i.v])
        {
            cout<<"Negative Cycle";
            break;
        }
    }
    cout<<"No Negative Cycle";
    return 0;
}
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void BFS(int src,int n,int e,vector<bool> &visited,vector<int> Graph[])
{
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:Graph[node])
        {
            if(!visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<int> Graph[n+1];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<bool>visited(n+1,false);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<"-> ";
    //     for(auto j:Graph[i])
    //     cout<<j<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            BFS(i,n,e,visited,Graph);
        }
    }
    return 0;
}
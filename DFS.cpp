#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void DFS(int i,vector<int>&dfs,vector<int>&visited,vector<int> adj[])
{
    dfs.push_back(i);
    visited[i]=1;
    for(auto node:adj[i])
    {
        if(!visited[node])
        {
            DFS(node,dfs,visited,adj);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 1], bfs;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> visited(n+1,0),dfs;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            DFS(i,dfs,visited,arr);
            for (auto m : dfs)
                cout << m << " ";
            dfs.clear();
            cout<<endl;
        }
    }
    return 0;
}
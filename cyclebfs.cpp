#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cycleBFS(int node,vector<bool>&visited,vector<int>graph[])
{
    queue<pair<int,int>> q;
    visited[node]=true;
    q.push({node,-1});
    while(!q.empty())
    {
        int cur_node=q.front().first;
        int cur_node_paren=q.front().second;
        q.pop();
        for(auto i:graph[cur_node])
        {
            if(!visited[i])
            {
                visited[i]=true;
                q.push({i,cur_node});
            }
            else if(cur_node_paren != i)
            return true;
        }
    }
    return false;
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
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(cycleBFS(i,visited,arr)){
            cout<<"CYCLE";
            return 0;
            }
        }
    }
    cout<<"No cycle";
    return 0;

}
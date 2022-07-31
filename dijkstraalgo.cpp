#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void dijkstra(int src,int n,int m,vector<pair<int,int>> graph[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto i:graph[node])
        {
            int nd=i.first;
            int wt=i.second;
            if(dist[node]+wt < dist[nd])
            {
                dist[nd]=dist[node]+wt;
                pq.push(make_pair(dist[nd],nd));
            }
        }
    }
    for(auto i:dist)
    if(i==1e9) continue;
    else
    cout<<i<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr[n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        arr[u].push_back({v, wt});
        arr[v].push_back({u, wt});
    }
    dijkstra(1,n,m,arr);
    return 0;
}
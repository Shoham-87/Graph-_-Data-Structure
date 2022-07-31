#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void toposortDFS(int node, vector<int> &visited, stack<int> &s, vector<pair<int, int>> graph[])
{
    visited[node] = 1;
    for (auto i : graph[node])
    {
        if (!visited[i.first])
        {
            toposortDFS(i.first, visited, s, graph);
        }
    }
    s.push(node);
}
vector<int> shotestpath(int src, vector<pair<int, int>> graph[], int n)
{
    stack<int> s;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            toposortDFS(i, visited, s, graph);
    }
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop(); 
        if (dist[node] != INT_MAX)
        {
            for (auto i : graph[node])
            {
                dist[i.first] = min(dist[i.first], dist[node] + i.second);
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        arr[u].push_back({v, wt});
    }
    // for(int i=0;i<n;i++)
    // for(auto j:arr[i])
    // {
    //     cout<<i<<" "<<j.first<<" "<<j.second<<endl;
    // }
    vector<int> dist = shotestpath(0, arr, n);
    for (auto i : dist)
        cout << i << " ";
    return 0;
}
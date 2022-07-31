#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void shotestpath(int src, vector<int> graph[], vector<int> &dist)
{
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // cout << node << " " << endl;
        for (auto i : graph[node])
        {
            if (dist[node] + 1 < dist[i])
            {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 1], dist(n, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    // for(int i=0;i<n;i++)
    // {
    //     if(dist[i]==INT_MAX)
    //     {
    shotestpath(0, arr, dist);
    //     }
    // }
    for (auto i : dist)
        cout << i << " ";
    return 0;
}
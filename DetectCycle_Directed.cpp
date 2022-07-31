#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool detectcycle(int node, vector<int> &visited, vector<int> &dfsvis, vector<int> graph[])
{
    visited[node] = 1;
    dfsvis[node] = 1;
    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            if (detectcycle(i, visited, dfsvis, graph))
                return true;
        }
        else if (dfsvis[i] == 1)
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> visited(n + 1, 0), dfsvis(n + 1, 0);
    for (int node = 1; node <= n; node++)
    {
        if (!visited[node])
        {
            if (detectcycle(node, visited, dfsvis, graph))
            {
                cout << "Cycle detected";
                return 0;
            }
        }
    }
    cout << "Cycle Not detected";
    return 0;
}
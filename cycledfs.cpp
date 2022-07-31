#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cycleDFS(int node, int parent, vector<bool> &visited, vector<int> graph[])
{
    visited[node] = true;
    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            if (cycleDFS(i, node, visited, graph))
                return true;
        }
        else if (parent != i)
            return true;
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
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (cycleDFS(i, -1, visited, arr))
            {
                cout << "CYCLE";
                return 0;
            }
        }
    }
    cout << "No cycle";
    return 0;
}
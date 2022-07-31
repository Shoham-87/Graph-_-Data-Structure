#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void toposortDFS(int node, vector<int> &visited, stack<int> &s, vector<int> graph[])
{
    visited[node] = 1;
    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            toposortDFS(i, visited, s, graph);
        }
    }
    s.push(node);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr[n], visited(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            toposortDFS(i, visited, s, arr);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
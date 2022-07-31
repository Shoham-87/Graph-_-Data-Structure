#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void BFS(int f, vector<int> &bfs, vector<int> &visited, vector<int> arr[])
{
    queue<int> q;
    visited[f] = 1;
    q.push(f);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto i : arr[node])
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
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
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            BFS(i, bfs, visited, arr);
            for (auto i : bfs)
                cout << i << " ";
            bfs.clear();
            cout<<endl;
        }
    }
    return 0;
}
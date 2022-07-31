#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void toposort(int n, vector<int> arr[], vector<int> &bfs)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
        for (auto j : arr[i])
            indegree[j]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!indegree[i])
            q.push(i);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto i : arr[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
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
    vector<int> arr[n], bfs;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }
    toposort(n,arr,bfs);
    for(auto i:bfs)
    cout<<i<<" ";
    return 0;
}
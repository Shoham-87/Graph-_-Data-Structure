#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void prims(int n, int m, vector<pair<int, int>> arr[])
{
    vector<int> key(n, 1e9), parent(n, -1);
    vector<bool> mst(n, false);
    key[0] = 0;
    for (int ii = 0; ii < n; ii++)
    {
        int mini = 1e9, node;
        for (int i = 0; i < n; i++)
        {
            if (!mst[i] && key[i] < mini)
            {
                mini = key[i];
                node=i;
            }
        }
        mst[node]=true;
        for(auto i:arr[node])
        {
            int nd=i.first;
            int wt=i.second;
            if(!mst[nd] && key[nd]>wt)
            {
                key[nd]=wt;
                parent[nd]=node;
            }
        }
    }
    for(auto i: key)
        cout<<i<<" ";
    for(auto i: parent)
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
    prims(n+1,m,arr);
    return 0;
}
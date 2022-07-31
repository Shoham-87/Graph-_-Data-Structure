#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void printgraph(int n, vector<int> arr[])
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << "(";
        for (auto j : arr[i])
            cout << j << "->";
        cout << ")"<<endl;
    }
}
// class Graph{
//     public:
//     int n=10,m;
//     Graph(int n,int m):n(n),m(m){
//     }
//     vector<int>adj[n];
//     void add_Elements()
//     {
//         for(int i=0;i<m;i++)
//         {
//             int u,v;
//             cin>>u>>v;
//             adj[u].push_back(v);
//         }
//     }
// };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (auto j : arr[i])
            cout << j << "->";
        cout << endl;
    }
    vector<int> visited(n + 1, 0);
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;

            count++;
        }
    }
    cout << count;
    return 0;
}
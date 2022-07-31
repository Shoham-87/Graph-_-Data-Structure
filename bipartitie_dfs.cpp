#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
bool is_bipartite(int node,vector<int>&color,vector<int> graph[])
{
    if(color[node] == -1) color[node]=1;
    for(auto i:graph[node])
    {
        if(color[i] == -1)
        {
            color[i]=1-color[node];
            if(!is_bipartite(i,color,graph))
            return false;
        }
        else if(color[i] == color[node])
            return false;
    }
    return true;
}
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
    vector<int> color(n + 1, -1);
    for(int i=1;i<=n;i++)
    {
        if(color[i] == -1)
        {
            //cout<<i<<" ";
            if(!is_bipartite(i,color,arr)){
                cout<<"Not Possible";
                return 0;
            }
        }
    }
    cout<<"Possible";
    return 0;
}
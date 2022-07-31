#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
bool isBipirate(int i,vector<int>&color,vector<int> graph[])
{
    queue<int> q;
    q.push(i);
    color[i]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto j: graph[node])
        {
            if(color[j] == -1)
            {
                color[j]=1-color[node];
                q.push(j);
            }
            else if(color[j]==color[node])
                return false;
        }
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
            if(!isBipirate(i,color,arr)){
                cout<<"Not Possible";
                return 0;
            }
        }
    }
    cout<<"Possible";
    return 0;
}
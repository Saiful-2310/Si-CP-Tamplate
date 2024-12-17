#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mkp make_pair
#define vc vector
#define vi vc<int>
#define vl vc<ll>
using namespace std;
const int N = 1e5+10;
vi graph[N];
int vis[N];
int level[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child: graph[cur_v])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }

    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i =0; i<n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    bfs(1);
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
}

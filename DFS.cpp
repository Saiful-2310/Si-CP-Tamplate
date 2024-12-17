#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pop pop_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define mkp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define tc int t;cin>>t;while(t--)
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define F first
#define S second
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define nl '\n'
using namespace std;
const int N=1e5;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex)
{
//int child;
//    cout<<"par "<<vertex<<" child "<<child<<endl;
cout<<vertex<<endl;

/* Take action on vertex after entering the vertex*/

    vis[vertex]=true;
    for(int child: graph[vertex])
    {
/* Take action on child before entering the child node */

       // cout<<"par "<<vertex<<" child "<<child<<endl;
        if(vis[child])continue;
        dfs(child);
        /* Take action on child after exiting child node*/

    }
    /* Take action on vertex before exiting the vertex*/
//    cout<<endl;
//    cout<<vertex<<endl;




}

int main()
{
    int v,e;
    cin>>v>>e;
    while(e--)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);

    }
    for(int i=1;i<=v;i++)
    {
        cout<<i<< "= ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    dfs(1);

    return 0;

}



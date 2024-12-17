
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define pp pop_back
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
const int N = 1e6+10;
const int M = 1e9+7;
int parent[N];
int Size[N];
void make(ll v)
{
    parent[v]=v;
    Size[v]=1;
}
ll Find(ll v)
{
    if(v==parent[v])return v;
    return parent[v]=Find(parent[v]);
}
void Union(ll a,ll b)
{
    a = Find(a);
    b= Find(b);
    if(a!=b)
    {
        if(Size[a]<Size[b])
            swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }
}


void solve()
{
    ll n,m=-1,i,j,cnt=0,sum=0,ans=0,cnt1=0;
    ll f,k,l,r,x,y;
    cin>>n>>m;

    for(i=1; i<=n; i++)
    {
        make(i);

    }
    while(m--)
    {
        int u, v;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_count =0;

    for(i=1; i<=n; i++)
    {
        if(Find(i)==i)
            connected_count++;
            cout<<Size[i]<<endl;
    }
    cout<<connected_count<<endl;


}
int main()
{
    //tc
    solve();
}

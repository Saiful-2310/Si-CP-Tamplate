#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpp;

typedef double dl;

#define pb push_back
#define F first
#define S second
#define mkp make_pair
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()
#define mid(l, r) ((r + l) / 2)

const double PI = acos(-1);
// const double eps = 1e-9;
const int inf = 2000000000;
const ll inff = 1000000000000000;

#define MOD 1000000007
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define sqr(a) ((a) * (a))
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define cinv(v)        \
    for (auto &it : v) \
        cin >> it;
#define coutv(v)           \
    for (auto it : v)      \
        cout << it << ' '; \
    cout << endl;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
// cout<<__builtin_popcount(16)<<endl;
// cout<<bitset<10>(15).to_string()<<endl;

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction(a)               \
    cout.unsetf(ios::floatfield); \
    cout.precision(a);            \
    cout.setf(ios::fixed, ios::floatfield);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

struct segtree
{
    int size;
    //  vector<long long> sums;
    vpp sums;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2 * size, {0LL, 0LL});
    }
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x].F = v;
            sums[x].S = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        // sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        sums[x].F = min(sums[2 * x + 1].F, sums[2 * x + 2].F);
        if (sums[2 * x + 1].F == sums[2 * x + 2].F)
        {
            sums[x].S = sums[2 * x + 1].S + sums[2 * x + 2].S;
        }
        else if (sums[2 * x + 1].F < sums[2 * x + 2].F)
        {
            sums[x].S = sums[2 * x + 1].S;
        }
        else
            sums[x].S = sums[2 * x + 2].S;
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    pll sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            // return 0;
            return {LONG_MAX, 0};
        }
        if (lx >= l && rx <= r)
            return sums[x];
        int m = (lx + rx) / 2;
        pll s1 = sum(l, r, 2 * x + 1, lx, m);
        pll s2 = sum(l, r, 2 * x + 2, m, rx);
        pll res;
        res.F = min(s1.F, s2.F);
        if (s1.F == s2.F)
        {
            res.S = s1.S + s2.S;
        }
        else if (s1.F < s2.F)
        {
            res.S = s1.S;
        }
        else
            res.S = s2.S;
        return res;
    }
    pll sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.set(i, x);
    }
    while (m--)
    {
        ll id;
        cin >> id;
        if (id == 1)
        {
            ll i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            pll ans = st.sum(l, r);
            cout << ans.F << ' ' << ans.S << endl;
        }
    }
}

int main()
{
    optimize();

#ifndef ONLINE_JUDGE
    file();
#endif
    // fraction(10)
    //  sieve();

    //  tc
    solve();

    return 0;
}
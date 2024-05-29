#include <bits/stdc++.h>
using namespace std;

// defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll, ll>
#define shunno cout << 0 << endl;
#define ek cout << 1 << endl;
#define pi 2 * acos(0.0)
#define hobena cout << -1 << endl;
ll mod = 998244353;
inline void norm(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
} // positive mod value
inline ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a + b) % mod;
} // modular addition
inline ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a - b) % mod;
} // modular subtraction
inline ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a * b) % mod;
} // modular multiplication
inline ll bigMod(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1LL)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}
inline ll modInverse(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

// typedefs...
// typedef pair<ll,ll>pll;

// const..
const ll fx[] = {0, 1, 0, -1};
const ll fy[] = {1, 0, -1, 0};

//...Custom_sort.......
bool cmp(string a, string b)
{
    return a + b < b + a;
}
ll n;
ll vis[200009];
vec v[200009];
ll ans[200009] = {0};
ll leaf[200009] = {0};
void dfs(ll u)
{
    ll cn = 0;
    vis[u] = 1;
    for (auto x : v[u])
    {
        if (vis[x] == 0)
        {
            if (leaf[x] == 0)
            {
                ans[u]++;
            }

            dfs(x);
            ans[u] += ans[x];
        }
    }
}
void f()
{
    cin >> n;
    ll i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cin >> k;

    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : v[u])
        {
            if (vis[x] == 0)
            {

                leaf[u]++;

                vis[x] = 1;
                q.push(x);
            }
        }
    }

    for (i = 1; i <= n; i++)
    {

        vis[i] = 1;
    }

    dfs(1);
    // for(i=1;i<=n;i++)
    // {
    //     cout<<i<<" "<<ans[i]<<endl;
    // }
    for (i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            ans[i] = 1;
    }

    for (i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << ans[x] * ans[y] << endl;
    }

    for (i = 1; i <= n; i++)
        v[i].clear();
    for (i = 1; i <= n; i++)
    {
        leaf[i] = 1;
        ans[i] = 1;
        vis[i] = 1;
    }
}
void oka()
{
    f();
}
int main()
{
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);
    //#endif

    run

        ll t = 1,
           i, j, k;
    ll ans = 1;

    cin >> t;

    char c;

    while (t--)
    {

        // cout<<"Case "<<ans++<<": ";

        oka();
    }
}

#include <bits/stdc++.h>
using namespace std;

// defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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
vector<vector<ll>> v;
ll vis[200009];
ll ans = 0;
void dfs(ll u, ll p)
{
    vis[u] = 1;
    for (auto x : v[u])
    {
        if (x == p)
            continue;

        if (vis[x] == 1 && p != -1)
        {
            vis[x] = 1;
            //  cout<<x<<" "<<p<<endl;
            ans++;
            break;
        }
        dfs(x, u);
    }
}
void f()
{
    ll i, j;
    cin >> n;
    ans = 0;
    v.clear();
    v.resize(n);
    for (i = 0; i < n; i++)
    {

        ll x;
        cin >> x;
        x--;
        v[x].pb(i);
        v[i].pb(x);
    }
    memset(vis, 0, sizeof(vis));
    ll cn = 0;
    ll mn = 0;
    for (i = 0; i < n; i++)
    {
        set<ll> p(v[i].begin(), v[i].end());
        v[i] = vector<ll>(p.begin(), p.end());
    }
    for (i = 0; i < n; i++)
    {
        ans = 0;
        if (vis[i] == 0)
        {
            ans = 0;
            dfs(i, -1);

            if (ans)
                mn++;
            else
                cn++;
        }
    }
    ll f = 0;
    if (cn > 0)
        f = 1;

    // cout<<cn<<" "<<mn<<endl;
    cout << mn + f << " " << mn + cn << endl;
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

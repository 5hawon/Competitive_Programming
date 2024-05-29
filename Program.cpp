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
// Let not the grief kill you.
ll m;
ll a[200009];
ll tree[700004];
ll tree2[700004];
void init(ll n, ll l, ll r)
{
    if (l == r)
    {
        tree[n] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    init(2 * n, l, mid);
    init(2 * n + 1, mid + 1, r);
    tree[n] = max(tree[2 * n], tree[2 * n + 1]);
}
void init2(ll n, ll l, ll r)
{
    if (l == r)
    {
        tree2[n] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    init2(2 * n, l, mid);
    init2(2 * n + 1, mid + 1, r);
    tree2[n] = min(tree2[2 * n], tree2[2 * n + 1]);
}
ll query(ll n, ll l, ll r, ll i, ll j)
{
    if (i <= l && j >= r)
    {
        return tree[n];
    }
    if (i > r || j < l)
    {
        return -10000000;
    }
    ll mid = (l + r) / 2;
    return max(query(2 * n, l, mid, i, j), query(2 * n + 1, mid + 1, r, i, j));
}
ll query2(ll n, ll l, ll r, ll i, ll j)
{
    if (i <= l && j >= r)
    {
        return tree2[n];
    }
    if (i > r || j < l)
    {
        return 10000000;
    }
    ll mid = (l + r) / 2;
    return min(query2(2 * n, l, mid, i, j), query2(2 * n + 1, mid + 1, r, i, j));
}
void f()
{
    ll n;
    cin >> n >> m;
    string s;
    cin >> s;
    vec v;
    v.pb(0);
    ll i;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '+')
            v.pb(1);
        else
            v.pb(-1);
    }
    a[0] = 0;
    for (i = 1; i <= n; i++)
    {
        a[i] = a[i - 1];
        a[i] += v[i];
    }
    a[n + 1] = a[n];
    ll cur = 0;
    init(1, 0, n + 1);
    init2(1, 0, n + 1);
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        ll x = 0, y = 0;
        x = min(x, query2(1, 0, n + 1, 0, l - 1));
        x = min(x, a[l - 1] + (query2(1, 0, n + 1, r + 1, n + 1) - a[r]));

        y = max(y, query(1, 0, n + 1, 0, l - 1));
        y = max(y, a[l - 1] + (query(1, 0, n + 1, r + 1, n + 1) - a[r]));
        cout << y - x + 1 << endl;
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

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
string s;
ll n;
map<pair<ll, pair<ll, char>>, ll> m;
map<char, ll> val;
ll DP(ll pos, ll f, char mx)
{
    if (pos < 0)
        return 0;
    if (m.find({pos, {f, mx}}) != m.end())
        return m[{pos, {f, mx}}];
    ll ans = -1e9;
    if (f == 0)
    {
        for (char c = 'A'; c <= 'E'; c++)
        {
            ll req = val[c];
            if (c < mx)
            {
                req *= -1;
            }
            if (s[pos] == c)
            {
                ans = max(ans, req + DP(pos - 1, 0, max(mx, c)));
            }
            else
            {
                ans = max(ans, req + DP(pos - 1, 1, max(mx, c)));
            }
        }
    }
    else
    {
        ll req = val[s[pos]];
        if (s[pos] < mx)
        {
            req *= -1;
        }
        ans = max(ans, req + DP(pos - 1, 1, max(mx, s[pos])));
    }
    return m[{pos, {f, mx}}] = ans;
}
void f()
{
    cin >> s;
    n = s.size();
    val['A'] = 1;
    val['B'] = 10;
    val['C'] = 100;
    val['D'] = 1000;
    val['E'] = 10000;
    m.clear();
    cout << DP(n - 1, 0, 'A') << endl;
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

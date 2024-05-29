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
ll n;
ll fact[65];
void factorial()
{
    ll i;
    fact[0] = 1;
    for (i = 1; i <= 60; i++)
        fact[i] = modMul(fact[i - 1], i);
}
ll ncr(ll x, ll r)
{
    if (x < 0 || r < 0 || x < r)
        return 0;
    if (r == 0 || x == r)
        return 1;
    ll ans = fact[x];
    ans = modDiv(ans, fact[r]);
    ans = modDiv(ans, fact[x - r]);
    return ans;
}
ll dp[70][3];
void DP(ll x)
{
    if (x == 2)
        tata
            DP(x - 2);
    dp[x][0] = modAdd(ncr(x - 1, x / 2), dp[x - 2][1]);
    dp[x][1] = modAdd(ncr(x - 2, x / 2), dp[x - 2][0]);
    dp[x][2] = dp[x - 2][2];
}
void f()
{
    cin >> n;
    ll i, j, k;
    dp[2][0] = 1;
    dp[2][1] = 0;
    dp[2][2] = 1;
    factorial();
    DP(n);
    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;
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

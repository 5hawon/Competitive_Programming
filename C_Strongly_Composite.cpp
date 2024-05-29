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
ll f(ll x, ll n, ll m)
{
    ll i, j;
    ll ans = 0;
    x--;
    for (i = 0; i < n; i++)
    {
        ans += min(m, (x / (i + 1)));
        // cout<<ans<<endl;
    }
    // cout<<ans<<endl;
    return ans;
}
unordered_map<ll, ll> m;
void f(ll n)
{
    ll i;
    while (n % 2 == 0)
    {
        m[2]++;
        n /= 2;
    }
    if (n == 1)
        tata for (i = 3; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                m[i]++;
                n /= i;
            }
        }
    if (n > 1)
        m[n]++;
}
void oka()
{
    ll n, i, j, k;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0, res = 0;
    for (i = 0; i < n; i++)
    {
        f(a[i]);
    }
    for (auto x : m)
    {
        ans += x.second / 2;
        res += x.second % 2;
    }
    cout << ans + (res / 3) << endl;
    m.clear();
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

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
typedef pair<ll, ll> pll;

// const..
const ll fx[] = {0, 1, 0, -1};
const ll fy[] = {1, 0, -1, 0};

//...Custom_sort.......
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
    {
        return a.first < b.first;
    }
    else
        return a.second > b.second;
}
mapl m;
ll f(ll n)
{
    ll ans = 0, i;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans += m[i];
            if (i != n / i)
            {
                ans += m[n / i];
            }
        }
    }
    return ans;
}

void oka()
{
    ll n, i, j, k;
    cin >> n;
    n = n * 2;
    ll a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<ll>());
    vector<pair<ll, ll>> v;
    j = n - 1;
    for (i = 0; i < j; i++)
    {
        v.pb({a[i], a[j]});
        j--;
    }
    ll ans = 0;
    for (i = 0; i < (ll)v.size() - 1; i++)
    {
        ans += abs(v[i].first - v[i + 1].first);
        ans += abs(v[i].second - v[i + 1].second);
    }
    cout << ans << endl;
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
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

        oka();
    }
}

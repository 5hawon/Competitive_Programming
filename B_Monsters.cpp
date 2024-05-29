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
    cin >> n >> k;
    ll a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    priority_queue<pair<ll, ll>> pq;
    vec v;
    for (i = 0; i < n; i++)
    {
        a[i] %= k;
        if (a[i] == 0)
            a[i] = k;
    }
    for (i = 0; i < n; i++)
    {

        pq.push({a[i], -i});
    }

    if (n == 1)
    {
        cout << 1 << endl;
        tata
    }

    while (!pq.empty())
    {
        auto x = pq.top();
        // cout<<x.first<<" "<<x.second<<endl;
        j = x.second;

        pq.pop();

        v.pb(-j);
    }
    for (auto x : v)
    {
        cout << x + 1 << " ";
    }
    cout << endl;
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

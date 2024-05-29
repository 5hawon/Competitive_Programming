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

void f()
{
    ll n, i, j, k;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1)
    {
        hobena
            tata
    }
    map<char, ll> m;
    for (auto x : s)
    {
        m[x]++;
    }
    for (auto x : s)
    {
        if (m[x] > n / 2)
        {
            hobena
                tata
        }
    }
    m.clear();
    for (i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            m[s[i]]++;
        }
    }
    multiset<ll> ms;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (m[c])
        {
            ms.in(m[c]);
        }
    }
    ll ans = 0;
    // cout<<ms.size()<<endl;
    while (ms.size() > 1)
    {
        auto x = ms.begin();
        auto y = ms.end();
        y--;
        ll l, r;
        l = *x - 1;
        r = *y - 1;
        ms.erase(x);
        ms.erase(y);
        if (l)
            ms.in(l);
        if (r)
            ms.in(r);
        ans++;
    }
    if (ms.size() == 1)
    {
        ans += *(ms.begin());
    }
    cout << ans << endl;
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

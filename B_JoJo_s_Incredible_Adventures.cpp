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

void oka()
{
    ll n, i, j, k;
    string s;
    cin >> s;
    ll mx = 0;
    ll cn = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            cn++;
        else if (cn > 0)
        {
            mx = max(mx, cn);
            cn = 0;
        }
    }
    mx = max(mx, cn);
    n=s.size();
    ll a = 0, b = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            a++;
        else
            break;
    }
    for (i = (ll)s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            a++;
        else
            break;
    }
    cn = min(a + b, (ll)s.size());
    mx = max(cn, mx);
    // cout<<mx<<endl;
    if (mx == 0)
    {
        shunno
            tata
    }
    if (mx == n)
    {
        cout << n * n << endl;
        tata
    }
    if (mx == 1)
    {
        cout << 1 << endl;
        tata
    }
    if (mx % 2 == 0)
    {
        ll p = mx / 2;
        cout << p * (p + 1) << endl;
    }
    else
    {
        ll p = (mx + 1) / 2;
        cout << p * p << endl;
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

        // cout<<"Case "<<ans++<<": ";

        oka();
    }
}

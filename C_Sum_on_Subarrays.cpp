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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
    {
        return a.first < b.first;
    }
    else
        return a.second > b.second;
}

void oka()
{

    ll n, i, j, k, x;
    cin >> n;
    cin >> k;
    ll a[n + 4];
    for (i = 1; i <= n; i++)
        a[i] = -1;
    if (k < n)
    {
        a[k] = 200;
        a[k + 1] = -400;
    }

    if (k >= n)
    {
        for (i = 1; i <= n; i++)
        {
            if (i * (i + 1) / 2 <= k)
                x = i;
            else
                break;
        }
        ll baki = k - x * (x + 1) / 2;
        // cout<<baki<<" w"<<endl;
        for (i = 1; i <= n; i++)
        {
            if (i == x + 1)
            {
                if (baki == 0)
                {
                   a[i]=-1000;
                }
                else
                {
                    a[i] = -(((x - baki + 1) * 2) - 1);
                }
            }
            else if (i <= x)
            {
                a[i] = 2;
            }
            else if (i > x + 1)
            {
                a[i] = -1000;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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

        // cout<<"Case "<<ans++<<": ";

        oka();
    }
}

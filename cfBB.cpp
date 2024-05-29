#include <bits/stdc++.h>
using namespace std;

// defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run

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

void f()
{
    ll n, i, j, k;
    cin >> n;
    ll a[n], b[n], c[n];
    ll x;
    cin >> x;
    map<ll, ll> m;
    for (i = 0; i < 32; i++)
    {
        m[i] = x & (1 << i);
        if (m[i])
            m[i] = 1;
    }
    map<ll, ll> m1;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    for (i = 0; i < n; i++)
        cin >> c[i];
    i = 0, j = 0, k = 0;
    ll f = 0;
     ll cc=0;
    while (1)
    {
        f=0;
        if (i < n)
        {
            for (ll ii = 0; ii < 32; ii++)
            {
               
                ll p = a[i] & (1 << ii);
                if (m[ii]!=p)
                {
                    cc=1;
                }
            }
            if(cc==0)
            {
                 m1[ii] = 1;
                    i++;
                    f = 1;
                    break;
            }
            
        }
        if (j < n)
        {
            for (ll ii = 0; ii < 32; ii++)
            {
                ll p = b[j] & (1 << ii);
                if (m[ii])
                {
                    m1[ii] = 1;
                    j++;
                    f = 1;
                }
            }
        }
        if (k < n)
        {
            for (ll ii = 0; ii < 32; ii++)
            {
                ll p = c[k] & (1 << ii);
                if (m[ii])
                {
                    m1[ii] = 1;
                    k++;
                    f = 1;
                }
            }
        }
        ll ff = 1;
        for (i = 0; i < 32; i++)
        {
            if (m[i] == m1[i])
            {
                continue;
            }
            else
                ff = 0;
        }
        if (ff == 1)
        {
            YES
                tata
        }
        if (f == 0)
        {
            NO
                tata
        }
    }
    NO
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

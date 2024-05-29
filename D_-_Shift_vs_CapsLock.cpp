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

void f()
{

    ll x, y, z, i, j;
    string s;
    cin >> x >> y >> z;
    cin >> s;
    ll ans = -1e9;
    ll mx = 0;

    ll f = 0;
    ans = 0;
    ll cn = 0, cnA = 0;
    for (i = 0; i < s.size(); i++)
    {

        if (s[i] == 'a')
        {
            if (cnA)
            {
                if (f == 1)
                {
                    if (z + y * cnA <= x * cnA)
                    {
                        f = 0;
                        ans += z + (y * cnA);
                    }
                    else
                    {
                        ans += x * cnA;
                    }
                    cnA = 0;
                }
                else
                {
                    if (z + x * cnA <= y * cnA)
                    {
                        ans += z + (x * cnA);
                        f = 1;
                    }
                    else
                    {
                        ans += y * cnA;
                    }
                    cnA = 0;
                }
            }
            cn++;
        }
        else if (s[i] == 'A')
        {
            if (cn)
            {
                if (f == 0)
                {
                    if (z + y * cn <= x * cn)
                    {
                        f = 1;
                        ans += z + (y * cn);
                    }
                    else
                    {
                        ans += x * cn;
                    }
                    cn = 0;
                }
                else
                {
                    if (z + x * cn <= y * cn)
                    {
                        ans += z + (x * cn);
                        f = 0;
                    }
                    else
                    {
                        ans += y * cn;
                    }
                    cn = 0;
                }
            }
            cnA++;
        }
    }
    if (cn)
    {
        if (f == 0)
        {
            if (z + y * cn <= x * cn)
            {
                f = 1;
                ans += z + (y * cn);
            }
            else
            {
                ans += x * cn;
            }
            cn = 0;
        }
        else
        {
            if (z + x * cn <= y * cn)
            {
                ans += z + (x * cn);
                f = 0;
            }
            else
            {
                ans += y * cn;
            }
            cn = 0;
        }
    }
    if (cnA)
    {
        if (f == 1)
        {
            if (z + y * cnA <= x * cnA)
            {
                f = 0;
                ans += z + (y * cnA);
            }
            else
            {
                ans += x * cnA;
            }
            cnA = 0;
        }
        else
        {
            if (z + x * cnA <= y * cnA)
            {
                ans += z + (x * cnA);
                f = 1;
            }
            else
            {
                ans += y * cnA;
            }
            cnA = 0;
        }
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

    // cin >> t;

    char c;

    while (t--)
    {

        // cout<<"Case "<<ans++<<": ";

        oka();
    }
}

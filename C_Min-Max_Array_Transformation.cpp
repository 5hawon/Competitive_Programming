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
    ll n, i, j, k;
    cin >> n;
    ll a[n];
    ll b[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    ll c[n];
    ll d[n];
    i = 0, j = 0;
    for (; i < n && j < n;)
    {
        if (b[j] >= a[i])
        {
            c[i] = b[j] - a[i];
            i++;
        }
        else
        {
            j++;
        }
    }
    j = n - 1;
    ll temp = j;
    for (i = n - 1; i >= 0;)
    {
        temp = j;

        d[i] = b[j] - a[i];
        if (i == 0)
            break;
        if (a[i] > b[i - 1])
            j = i - 1;
        i--;
    }
    for (i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
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

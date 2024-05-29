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
ll n, k;
string a, b;
set<string> ans;
queue<string> q;
void f2(ll i, ll j)
{
    if (i >= 0 && j < n && i < j && j >= 0)
    {
        swap(a[i], a[j]);
        if (ans.count(a) == 0)
        {
            ans.in(a);
            q.push(a);
        }
        swap(a[i], a[j]);
    }
}

void bfs()
{
    q.push(a);
    ans.in(a);
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            f2(i, i + k);
            f2(i, i + k + 1);
            f2(i - k, i);
            f2(i - k - 1, i);
        }
    }
    if (ans.count(b))
    {
        YES
    }
    else
    {
        NO
    }
}
void f()
{
    cin >> n >> k;
    cin >> a >> b;
    if (n <= 5)
    {
        bfs();
        tata
    }
    set<char> d, e;
    map<char, ll> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
        d.in(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        m[b[i]]--;
        e.in(b[i]);
    }
    for (char l = 'a'; l <= 'z'; l++)
    {
        if (m[l])
        {
            NO
                tata
        }
    }
    YES
}
void oka()
{
    ans.clear();

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

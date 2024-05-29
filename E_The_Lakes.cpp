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
ll a[1009][1009];
ll vis[1009][1009];
ll n, m;
void f()
{
    cin >> n >> m;
    ll i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
            vis[i][j] = 0;
        }
    }

    ll mx = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] > 0 && vis[i][j] == 0)
            {
                ll sum = a[i][j];
                queue<pair<ll, ll>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    ll u, v;
                    u = q.front().first;
                    v = q.front().second;
                    vis[u][v] = 1;
                    q.pop();
                    for (k = 0; k < 4; k++)
                    {
                        ll x, y;
                        x = u + fx[k];
                        y = v + fy[k];
                        if (x < n && x >= 0 && y < m && y >= 0 && vis[x][y] == 0 && a[x][y] > 0)
                        {
                            q.push({x, y});
                            sum += a[x][y];
                            vis[x][y] = 1;
                            // cout<<x<<" "<<y<<endl;
                        }
                    }
                }

                mx = max(mx, sum);
                sum = 0;
            }
        }
    }
    cout << mx << endl;
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

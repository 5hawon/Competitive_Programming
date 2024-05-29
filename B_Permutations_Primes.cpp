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
ll n;
vec a;
ll prime(ll x)
{
    ll i,j;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return 0;
    }
    if(x==1)
        return 0;
    return 1;
}
ll calc()
{
    ll i,j,ans=0;
    for(i=0;i<n;i++)
    {
        ll p=1;
        mapl m;
        for(j=i;j<n;j++)
        {
            for(ll k=i;k<=j;k++)
            m[a[k]]=1;
        }
        while(m[p]==0)
            p++;
        if(prime(p))
            ans++;
    }
    return ans;
}
void f()
{
    ll i,j,k;
    cin>>n;
  
    
    if(n<=2)
    {
        for(i=1;i<=n;i++)
        {
            cout<<i<<" ";

        }
        cout<<endl;
        tata
    }
    cout<<2<<" ";
    ll cn=4;
    for(i=1;i<n-1;i++)
    {
        if(i==n/2)
        {
            cout<<1<<" ";
        }
        else
        {
            cout<<cn<<" ";
            cn++;
        }
    }
    cout<<3<<" ";
    cout<<endl;
   

    
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

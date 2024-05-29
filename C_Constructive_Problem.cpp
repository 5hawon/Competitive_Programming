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
   ll n,i,j,k;
   cin>>n;
   ll a[n];
   vec v;
   mapl m;
   for(i=0;i<n;i++)
        cin>>a[i],v.pb(a[i]),m[a[i]]++;
    sort(v.begin(),v.end());
    ll mex=0;
    for(auto x:v)
    {
        if(x>mex)
        {
            break;
        }
        else if(x==mex) mex++;
    }
    if(mex==0)
    {
        yes
        tata

    }
    ll l=-1,r=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==mex+1)
        {
            l=i;
            break;
        }

    }
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==mex+1)
        {
            r=i;
            break;
        }
    }
    if(l==-1)
    {
        if(v[n-1]>mex+1)
        {
            yes
            tata
        }
    }
    if(l==-1)
        {
            for(auto x:m)
            {
                if(x.first<mex)
                {
                    if(x.second>1)
                    {
                        yes
                        tata
                    }
                }
            }
            no
            tata
        }
    for(i=l;i<=r;i++)
    {
        a[i]=mex;
    }
    ll temp=mex;
    mex=0;
    sort(a,a+n);
    v.clear();
    for(i=0;i<n;i++)
    {
        v.pb(a[i]);
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        if(x>mex)
        {
            break;
        }
        else if(x==mex) mex++;
    }
    if(mex==temp+1)
    {
        yes
    }
    else
        no



    
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

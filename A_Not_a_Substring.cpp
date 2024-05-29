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
typedef pair<ll, ll> pll;

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
    string s;
    cin>>s;
    ll n,i,j,k;
    ll cn=0;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
            cn++;
        else
            cn--;
    }
    
    ll f=0;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(s[i]=='(')
                continue;
            else
            {
                f=1;
                break;
            }
        }
        else
        {
            if(s[i]==')')
                continue;
            else
            {
                f=1;
                break;
            }
        }
    }
     k=0;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(s[i]==')')
                continue;
            else
            {
                k=1;
                break;
            }
        }
        else
        {
            if(s[i]=='(')
                continue;
            else
            {
                k=1;
                break;
            }
        }
    }
     if(f==0&&n==2)
    {
        NO
        tata
    }
    

    if(f==1&&k==1)
    {
        YES
        for(i=0;i<2*n;i++)
        {
            if(i%2==0)
            {
                cout<<"(";
            }
            else
                cout<<")";

        }
        cout<<endl;
        tata

    }
   
    YES
    for(i=0;i<n;i++)
    {
        cout<<"(";
    }
    for(i=0;i<n;i++)
    {
        cout<<")";
    }
    cout<<endl;

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

        oka();
    }
}

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

void f()
{
    ll n,k,i,j;
    vec a,b,c;
    cin>>n>>k;
    ll d[n];
   
    for(i=0;i<n;i++)
    {
        cin>>d[i];
        if(d[i]==-1)
            a.pb(i+1);
        else if(d[i]==-2)
            b.pb(i+1);
        else 
            c.pb(d[i]);
        
    }
   ll m[k+2];
   ll right=b.size();
   ll left=a.size();
   sort(c.begin(),c.end());
   ll ans=0;
   ll temp=0;
   
   for(i=1;i<c.size();i++)
   {
      temp+=c[i]-c[i-1]-1;
   }
   ll xtral=0,xtrar=0;
   if(c.size()>=1)
    {
        
        ans+=min(left,c[0]-1);
        xtral=c[0]-1;
        left-=min(left,c[0]-1);
        xtral-=min(left,c[0]-1);
        
        ll df=(ll)c.size();
        ans+=min(right,k-c[df-1]);
        right-=min(right,k-c[df-1]);
        xtrar=k-c[df-1];
        xtrar-=min(right,k-c[df-1]);

        

    }

  // cout<<temp<<endl;
 
   set<ll>pet;
   for(auto x:c)
        pet.in(x);
    temp=min(right+left,temp);
    temp+=min(xtral,left);
    temp+=min(xtrar,right);
  
   
    ll ans1=min(k,temp+pet.size()+ans);

    //ans2
    ans=0;
    ans+=(ll)a.size();
    i=k-(ll)a.size();
    for(auto x:pet)
    {
        if(x<=i)
        {
            ans++;
        }
        else
            break;
    }
    ll ans2=ans;

    //ans3

    ans=0;
    ans+=(ll)b.size();
    i=(ll)b.size();
    for(auto x:pet)
    {
        if(x>i)
        {
            ans++;
        }
        else
            break;
    }
    ll ans3=ans;
    ans2=min(k,max(ans2,ans3));
    cout<<max(ans2,ans1)<<endl;





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

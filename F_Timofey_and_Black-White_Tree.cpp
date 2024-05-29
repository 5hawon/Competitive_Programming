 #include<bits/stdc++.h>
using namespace std;

//defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run ios_base::sync_with_stdio(false);cin.tie(NULL);
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll,ll>
#define shunno cout<<0<<endl;
#define ek cout<<1<<endl;
#define pi 2*acos(0.0)
#define hobena cout<<-1<<endl;
ll mod =998244353;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p){ll r=1;while(p){if(p&1LL) r=modMul(r,b);b=modMul(b,b); p>>=1LL;}return r;}
inline ll modInverse(ll a){ return bigMod(a,mod-2);}
inline ll modDiv(ll a,ll b){ return modMul(a,modInverse(b));}

//typedefs...
typedef pair<ll,ll>pll;


//const..
const ll fx[]={0,1,0,-1};
const ll fy[]={1,0,-1,0};

//...Custom_sort.......
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
	if(a.first<b.first)
	{
		return a.first<b.first;
	}
	else
		return a.second>b.second;
}

ll dis[1000000];
ll col[1000000];
vec v[1000007];
ll n,co,ans=100303030;
ll a[1000000];
void dfs(ll u,ll parent)
{
    if(dis[u]>=ans)
        return;
    for(auto x:v[u])
    {
        if(x!=parent)
        {
            if(dis[x]>dis[u]+1)
            {
                dis[x]=dis[u]+1;
                dfs(x,u);
            }
            else
            {
                ans=min(ans,dis[x]+dis[u]+1);
            }
        }
    }
}
void oka()
{
    cin>>n>>co;
     ll i,j,k;
    for(i=1;i<=n;i++)
    {
            dis[i]=1e8;
            v[i].clear();
            col[i]=0;
            ans=193883939;
    }
    col[co]=1;
    dis[co]=0;
    for(i=1;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(i=1;i<n;i++)
    {
        dis[a[i]]=0;
        dfs(a[i],-1);//-1 represents parent node
        col[a[i]]=1;//black
        cout<<ans<<" ";
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

    ll t=1,i,j,k;
	ll ans=1;
	
	

	cin>>t;
	
 	char c;
	
	 
 


  while(t--){
	 
 

	oka();


  }
}

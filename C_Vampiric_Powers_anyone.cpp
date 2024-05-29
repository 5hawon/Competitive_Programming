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
struct TrieNode
{
    int value;
    TrieNode *arr[2];
};

TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;

    for (int i = 8; i >= 0; i--)
    {
        bool val = pre_xor & (1 << i);

        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();

        temp = temp->arr[val];
    }

    temp->value = pre_xor;
}

int query(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;
    for (int i = 8; i >= 0; i--)
    {
        bool val = pre_xor & (1 << i);

        if (temp->arr[1 - val] != NULL)
            temp = temp->arr[1 - val];

        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor ^ (temp->value);
}

int maxSubarrayXOR(int arr[], int n)
{
    TrieNode *root = newNode();
    insert(root, 0);

    int result = -1e9, pre_xor = 0;

    for (int i = 0; i < n; i++)
    {
        pre_xor = pre_xor ^ arr[i];
        insert(root, pre_xor);

        result = max(result, query(root, pre_xor));
    }
    return result;
}
void oka()
{

    int n, i, j, k;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << maxSubarrayXOR(a, n) << endl;
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

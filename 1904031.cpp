#include <bits/stdc++.h>
using namespace std;
#define ll long long

// inlines
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

// FInal CODE starts here.............................
// global variables
ll is_safe = 0; // validity check;
bool check[200];
ll n, m;
ll total[207];
ll max_resources[206][206];
ll allocation[206][206];
ll current_need[206][206];
ll available[209];
// bakners on going
void Bankerss()
{
    ll cnt = 0;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll flag = 0, cnt1 = 0, flag1 = 0;
        if (cnt == n)
        {
            cout << "System is safe" << endl;
            cout << "Safe sequence: " << endl;
            for (ll k = 0; k < v.size(); k++)
                cout << "Process" << v[k] << ' ';
            cout << '<<endl';
            break;
        }
        for (ll j = 0; j < n; j++)
        {
            if (check[j] == false)
            {
                for (ll l = 0; l < m; l++)
                {
                    if (current_need[j][l] > available[l])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
                continue;
            if (flag == 0)
            {
                cnt++;
                flag1++;
                v.push_back(j);
                check[j] = true;
                for (ll l = 0; l < m; l++)
                {
                    available[l] += allocation[j][l];
                }
                cout << endl;
            }
            else
            {
                cnt1++, flag = 0;
            }
        }
        if (cnt1 == n - v.size() and flag1 == 0)
        {
            is_safe = 1;
            cout << "System is unsafe" << endl;
            // end of safety check
            break;
        }
    }
}

void solve()
{
    cout << "Number of processes and resources: " << endl;
    cin >> n >> m;
    ll available_resources[m + 5];
    cout << "Number of total instances of each resource: <<endl";
    for (ll j = 0; j < m; j++)
        cin >> total[j], available_resources[j] = total[j];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << "Input MAX and Allocation for process" << i << " and Resources" << j "<<endl;
                    cin >>
                max_resources[i][j] >> allocation[i][j];
            available_resources[j] -= allocation[i][j];
            current_need[i][j] = max_resources[i][j] - allocation[i][j];
        }
    }
    cout << "Number of Request: " << endl;
    ll R;
    cin >> R;
    for (ll i = 1; i <= R; i++)
    {
        cout << "Request for Process: " << endl;
        ll P;
        cin >> P;
        ll req[m + 5];
        for (ll j = 0; j < m; j++)
        {
            cout << "Request value for Resource " << j << ":" << endl;
            cin >> req[j];
            if (req[j] > current_need[P][j])
                is_safe = 1;
            if (req[j] > available_resources[j])
                is_safe = 2;
        }
        if (is_safe == 1)
        {
            cout << "System is unsafe" << endl;
            continue;
        }
        else if (is_safe == 2)
        {
            cout << "The Request is waiting" << endl;
            continue;
        }
        else
        {
            // reset check

            for (ll p = 0; p < 104; p++)
                check[p] = false;
            for (ll j = 0; j < m; j++)
            {
                current_need[P][j] -= req[j];
                available_resources[j] -= req[j];
                allocation[P][j] += req[j];
            }
            for (ll k = 0; k < m; k++)
            {
                available[k] = available_resources[k];
            }
            Bankerss();
            for (ll j = 0; j < m; j++)
            {
                current_need[P][j] += req[j];
                available_resources[j] += req[j];
                allocation[P][j] -= req[j];
            }
        }
    }
}
void oka()
{
    solve();
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
        oka();
}

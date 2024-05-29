#include <bits/stdc++.h>
using namespace std;

// defines...
#define ll long long
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
#define pairvec vector<pair<double, pair<ll, double>>>




ll TQ(pairvec vp)
{
    vector<double> execution;
    double sum = 0;
    for (auto i : vp)
        execution.push_back(i.second.second), sum += i.second.second;
    double ghor = sum / (vp.size());
    double moddhok;
    if (vp.size() % 2)
    {
        moddhok = execution[vp.size() / 2];
    }
    else
        moddhok = (execution[vp.size() / 2] + execution[vp.size() / 2 - 1]) / 2.0;
    return (ll)round(sqrt((moddhok * ghor) / 2.0));
}

void oka()
{
    ll n;
    cout << "Number of Process: ";
    cin >> n;
    pairvec vp;
    pairvec temp;
    double waiting[n + 1] = {0}, turnaroun[n + 1] = {0};
    for (ll i = 0; i < n; i++)
    {
        ll p, a, e;
        cout << "Process :";
        cin >> p;
        cout << "Arrival :";

        cin >> a;
        cout << "Execution time :";

        cin >> e;
        vp.push_back({a, {p, e}});
    }
    temp = vp;

    ll tq = TQ(vp);
    sort(vp.begin(), vp.end());
    ll t = vp[0].first;
    cout << t << ' ';

    double final[n + 1];
    while (1)
    {
        for (int i = 0; i < (ll)vp.size(); i++)
        {
            double x = min(double(tq), vp[i].second.second);
            cout << "P" << vp[i].second.first << ' ' << t + x << ' ';
            final[vp[i].second.first] = t + x;
            vp[i].second.second = max(double(0), vp[i].second.second - tq);
            if (vp[i].second.second == 0)
                vp.erase(vp.begin() + i);
            t += x;
        }
        if (vp.empty())
        {
            break;
        }
        sort(vp.begin(), vp.end());
        tq = TQ(vp);
    }

    for (auto i : temp)
        waiting[i.second.first] = final[i.second.first] - i.second.second - i.first, turnaroun[i.second.first] = final[i.second.first] - i.second.first;

    double w = 0, tt = 0;
    cout << endl;
    for (ll i = 1; i <= n; i++)
        w += waiting[i], tt += turnaroun[i];
    cout << "Average waiting time :" << w / n << endl;
    cout << "Average turnaround time :" << tt / n << endl;
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

    // cin >> t; 

    char c;

    while (t--)
    {

        // cout<<"Case "<<ans++<<": ";

        oka();
    }
}

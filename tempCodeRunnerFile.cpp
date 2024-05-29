#include <bits/stdc++.h>
using namespace std;
double func(int p, int b)
{
    return sqrt((p*p+b*b*1.0)/2);
}
int main(){
    int n;
    cout << "Number of Input: ";
    cin >> n;
    vector<pair<int, pair<int, int>>> vp, dp;
    vector < int > e(n + 1), arrival(n + 1), waiting_time(n + 1), TurnAround_time(n + 1), response_time(n + 1), ep(n + 1);
    int com = 0, waiting = 0, response = 0;
    for (int i = 0; i < n; i++)
    {
        int p, a, pr, en;
        cout << "Process :";
        cin >> p;
        cout << "Arrival :";
        cin >> a;
        arrival[p] = a;
        cout << "Execution time :";
        cin >> en;
        ep[p] = en;
        e[p] = en;
        cout << "Priority: ";
        cin >> pr;
        double x=func(pr,en);
        int y=x;
        vp.push_back({a, {p, y}});
    }
    cout << endl;
    int cnt = 0;
    dp = vp;
    sort(vp.begin(), vp.end());
    int t = vp[0].first;
    int f[n + 1];
    cout << t << ' ';
    e[vp[0].second.first]--;
    if(vp[0].second.first <= 0){
        vp.erase(vp.begin());
        f[vp[0].second.first] = 1;
        cnt++;
    }
    int mn = vp[0].second.second;
    int val = vp[0].second.first;
    response_time[val] = 0;
    cout << "p" << val << ' ';
    int k = 0;
    for(int i = 0; i < n - 1; i++){
        cout << i + 1 << ' ';
        if(mn > vp[i + 1].second.second){
            mn = vp[i + 1].second.second;
            val = vp[i + 1].second.first;
            if(response_time[val] == 0) response_time[val] = i + 1;
        }
        cout << "p" << val << ' ';
        e[val]--;
        if(vp[0].second.first <= 0){
            vp.erase(vp.begin() + k);
            f[val] = i + 1;
            cnt++;
        }
    }
    int finish = n;
    cout << n << ' ';
    map < int, int > mp;
    while(!vp.empty()){
        mn = 10000000;
        for(int i = 0; i < vp.size(); i++){
            if(mn > vp[i].second.second and mp[vp[i].second.first] == 0){
                mn = vp[i].second.second;
                val = vp[i].second.first;
            }
        }
        cout << "p" << val << ' ' << finish + e[val] << ' ';
        response_time[val] = finish;
        finish += e[val];
        mp[val]++;
        f[val] = finish;
        //cout << f[val] << ' ' << val << ' ' << "f " << endl;
        cnt++;
        if(cnt == n) break;
    }
    cout << endl;
    cout<<"Process"<<"\t"<< "burst-t."<<"\t"<<"arrival-t." <<"\t"<<"waiting-t." <<"\t"<<"Turnaround-t."<<"\t"<<"Response-t."<<endl;
    for(int i = 1; i <= n; i++){
        TurnAround_time[i] = f[i] - arrival[i];
        waiting_time[i] = TurnAround_time[i] - ep[i];
        response_time[i] = response_time[i] - arrival[i];
        com += TurnAround_time[i];
        waiting += waiting_time[i];
        response += response_time[i];
        cout << i << '\t' << ep[i] << '\t' << arrival[i] << '\t' <<abs( waiting_time[i]) << '\t' << TurnAround_time[i] << '\t' << response_time[i] << endl;
    }
    cout << "Avg. TurnAround Time " << (double)com / (double) n << endl;
    cout << "Avg. Waiting Time " << (double)waiting / (double) n << endl;
    cout << "Avg. Response Time " << (double)response / (double) n << endl;

}
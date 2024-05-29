#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct data{
    int bur,ari,pri,p,st;
};
bool cmp(data a,data b){
    return a.ari<b.ari;
}
bool cmp1(data a,data b){
    return a.pri<b.pri;
}
void solve()
{
    //Non Premptive Prirority Scheduling Algo.....WeLoveOS
    cout<<"Number of process, n: ";
    int n;
    cin>>n;
    cout<<endl;
    vector<data>v;
    data ob;
    for(int i=1;i<=n;i++){
        cout<<"Enter the burst time of P"<<i<<": ";
        cin>>ob.bur;
        cout<<"Enter the arrival time of P"<<i<<": ";
        cin>>ob.ari;
        cout<<"Enter the priority of P"<<i<<": ";
        cin>>ob.pri;
        ob.p=i,ob.st=0;
        v.push_back(ob);
        cout<<endl;
    }

    sort(v.begin(),v.end(),cmp);

    vector<data>v1,ans;
    int x=v[0].ari;
    for(int i=0;i<v.size();i++){

        if(v[i].ari<=x)v1.push_back(v[i]);
        else{
            sort(v1.begin(),v1.end(),cmp1);
            v1[0].st=x;
            ans.push_back(v1[0]);
            x+=v1[0].bur;
            i--;
            v1.erase(v1.begin());
        }
    }
    sort(v1.begin(),v1.end(),cmp1);
    for(int i=0;i<v1.size();i++){
        v1[i].st=x;
        ans.push_back(v1[i]);
        x+=v1[i].bur;
       
    }
    double tot_w=0.0,tot_turn=0.0,tot_r;
    cout<<"\nGantt Chart : \n";
        cout<<"----------------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i].st<<" P"<<ans[i].p<<" ";
        tot_w+=(ans[i].st-ans[i].ari);
        tot_turn+=(ans[i].st-ans[i].ari)+ans[i].bur;
        if(i==n-1)
        {
            cout<<ans[i].st+ans[i].bur<<endl;
        }
    }
        cout<<"----------------------------------------------------------------"<<endl;
    tot_r=tot_w;
    cout<<endl<<endl;
    cout<<"Process"<<"\t"<<"AT"<<"\t"<<"End Time"<<"\t"<<"RT"<<"\t"<<"WT"<<"\t"<<"TAT"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"P"<<ans[i].p<<" \t"<<ans[i].st<<"\t"<<ans[i].st+ans[i].bur<<"\t"<<"\t"<<(ans[i].st-ans[i].ari)<<"\t"<<(ans[i].st-ans[i].ari)<<"\t"<<(ans[i].st-ans[i].ari)+ans[i].bur<<endl;
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"Average Response time : "<<tot_r/n<<endl;
    cout<<"Average Waiting time : "<<tot_w/n<<endl;
    cout<<"Average Turnaround time : "<<tot_turn/n<<endl;
}
int main()
{
    solve();
}

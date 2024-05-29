#include<bits/stdc++.h>
using namespace std;

struct job {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    
};

bool cmp(const job& p1, const job& p2) {
    return p1.priority < p2.priority;
}


void oka() {
    int n;
     cout << "Enter the number of processes: ";
     cin >> n;
    
     vector<job> processes(n);
    
     cout << "Enter arrival time, burst time, and priority for each process:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Process " << processes[i].id << ":\n";
         cout << "Arrival Time of Process"<<i+1<<": ";
         cin >> processes[i].arrivalTime;
         cout << "Burst Time of Process"<<i+1<<": ";
         cin >> processes[i].burstTime;
         cout << "Priority of Process"<<i+1<<": ";
         cin >> processes[i].priority;
    }
    
    sort(processes.begin(), processes.end(), cmp);
    
    //Calculation Starts Here ---_
     int currentTime = 0;
     vector<int>arekta;
     priority_queue<pair<int,int>>q;
     int cn=0;
    
   
    map<int,int>chk,finalchk;
    int i,j;
    
    for(i=0;i<1000000;i++)
    {
        for(j=0;j<n;j++)
        {
            if(processes[j].arrivalTime==i&&chk[processes[j].id]==0)
            {
                q.push({processes[j].id,j}),chk[processes[j].id]=1;
            }
        }
        if(q.size()==0)
            continue;
        auto u=q.top();
        q.pop();
        finalchk[u.first]=1;
        arekta.push_back(u.first);
        processes[u.second].completionTime = i + processes[u.second].burstTime;
        processes[u.second].turnaroundTime = processes[u.second].completionTime - processes[u.second].arrivalTime;
        processes[u.second].waitingTime = processes[u.second].turnaroundTime - processes[u.second].burstTime;
        i=processes[u.second].completionTime-1;
         
         
            for(j=0;j<n;j++)
            {
                if(processes[j].arrivalTime<=(i+1)&&chk[processes[j].id]==0)
                    q.push({processes[j].id,j}),chk[processes[j].id]=1;
            }
         
        int f=0;
        for(auto x:finalchk)
            f+=x.second;
       
        if(f==n&&q.size()==0)
            break;
    }
     

    //Grant Chart Here we go

    cout << "Gantt Chart"<<endl;
    for (auto x : arekta) {
        cout << "P" << x << " ";
    }
    
    cout <<endl;
    cout <<endl;
    

    //Print Table ---
    int avgta=0;
    int avgwait=0;

    cout << "\nProcess Table:\n";
     cout << "ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : processes) {
         cout << process.id << "\t" << process.arrivalTime << "\t\t" << process.burstTime << "\t\t"
                  << process.priority << "\t\t" << process.completionTime << "\t\t" << process.waitingTime
                  << "\t\t" << process.turnaroundTime << endl;
        avgta+=process.turnaroundTime;
        avgwait+=process.waitingTime;
    }
    
    //Performance Analysis-------
    cout<<"Average Turn Around Time :"<<avgta/n<<endl;
     cout<<"Average Waiting Time :"<<avgwait/n<<endl;



   
   
    
    
}

int main()
{
    oka();
}
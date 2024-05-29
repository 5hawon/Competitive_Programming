#include<bits/stdc++.h>
using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int response_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int finish_time;
};

bool compareProcessNo(const Process& p1, const Process& p2) {
    return p1.process_id < p2.process_id;
}

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

bool compareBurstTime(const Process& p1, const Process& p2) {
    return p1.burst_time < p2.burst_time;
}

bool compareRemainingTime(const Process& p1, const Process& p2) {
    return p1.remaining_time < p2.remaining_time;
}

bool comparePriority(const Process& p1, const Process& p2) {
    return p1.priority < p2.priority;
}

void first_come_first_serve(vector<Process>&processes,int flag=0) {
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    int current_time = 0;
    if(!flag) {
        cout << "Gantt Chart: ";
        cout << 0 << " ";
    }
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
            if(!flag) {
                cout << "idle "<< current_time << " ";
            }
        }

        processes[i].start_time = current_time;
        processes[i].finish_time = current_time + processes[i].burst_time;
        processes[i].response_time= current_time- processes[i].arrival_time;
        processes[i].waiting_time=current_time - processes[i].arrival_time;
        processes[i].turnaround_time=processes[i].finish_time - processes[i].arrival_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;

        current_time = processes[i].finish_time;
        if(!flag) {
            cout << "P" << processes[i].process_id << " " << current_time << " ";
        }
    }
    if(!flag) {

        cout << endl<<endl;

        sort(processes.begin(),processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << processes[i].process_id << " ";
            cout << "Start Time: " << processes[i].start_time << " ";
            cout << "End Time: " << processes[i].finish_time << " ";
            cout << "Response Time: " << processes[i].response_time << " ";
            cout << "Waiting Time: " << processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag) {
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }
    if(flag) {
        cout<<"Algo: FCFS                      "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}

void non_preemptive_sjf(vector<Process>& processes,int flag=0) {
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0 , idle = 0;
    if(!flag){
        cout << "Gantt Chart: ";
        cout << 0 << " ";
    }
    while (completed_processes_count < n) {
        while (idx < n && processes[idx].arrival_time <= current_time) {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty()) {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle) {
            if(!flag) {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), compareBurstTime);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        current_process.start_time = current_time;
        current_process.finish_time = current_time + current_process.burst_time;
        current_process.response_time=current_process.start_time - current_process.arrival_time;
        current_process.waiting_time=current_process.start_time - current_process.arrival_time;
        current_process.turnaround_time=current_process.finish_time - current_process.arrival_time;

        total_waiting_time += current_process.waiting_time;
        total_turnaround_time += current_process.turnaround_time;
        total_response_time += current_process.response_time;

        completed_processes.push_back(current_process);
        current_time = current_process.finish_time;
        completed_processes_count++;
        if(!flag) {
            cout << "P" << current_process.process_id << " " << current_process.finish_time << " ";
        }
    }
    if(!flag) {
        cout << endl << endl;

        sort(completed_processes.begin(),completed_processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << completed_processes[i].process_id << " ";
            cout << "Start Time: " << completed_processes[i].start_time << " ";
            cout << "End Time: " << completed_processes[i].finish_time << " ";
            cout << "Response Time: " << completed_processes[i].response_time << " ";
            cout << "Waiting Time: " << completed_processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag){
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }

    if(flag) {
        cout<<"Algo: Non-Preemptive-SJF        "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}

void preemptive_sjf(vector<Process>& processes,int flag=0) {
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0 , idle = 0;
    if(!flag) {
        cout << "Gantt Chart: ";
        cout << 0 << " ";
    }
    while (completed_processes_count < n) {
        while (idx < n && processes[idx].arrival_time <= current_time) {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty()) {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle) {
            if(!flag) {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), compareRemainingTime);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        if(current_process.response_time==-1) {
            current_process.response_time = current_time - current_process.arrival_time;
            total_response_time += current_process.response_time;
            current_process.start_time = current_time;
        }

        current_time++;

        current_process.remaining_time--;

        if(current_process.remaining_time==0) {
            current_process.finish_time = current_time;
            current_process.waiting_time=current_time - current_process.arrival_time - current_process.burst_time;
            total_waiting_time += current_process.waiting_time;
            current_process.turnaround_time=current_process.finish_time - current_process.arrival_time;
            total_turnaround_time += current_process.turnaround_time;
            completed_processes_count++;
            completed_processes.push_back(current_process);
            if(!flag) {
                cout << "P" << current_process.process_id << " " << current_process.finish_time << " ";
            }
        }
        else {
            while (idx < n && processes[idx].arrival_time <= current_time) {
                ready_queue.push_back(processes[idx]);
                idx++;
            }
            ready_queue.push_back(current_process);
            sort(ready_queue.begin(), ready_queue.end(), compareRemainingTime);
            if(ready_queue.front().process_id!=current_process.process_id) {
                if(!flag) {
                    cout << "P" << current_process.process_id << " " << current_time << " ";
                }
            }
        }
    }

    if(!flag) {
        cout << endl << endl;

        sort(completed_processes.begin(),completed_processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << completed_processes[i].process_id << " ";
            cout << "Start Time: " << completed_processes[i].start_time << " ";
            cout << "End Time: " << completed_processes[i].finish_time << " ";
            cout << "Response Time: " << completed_processes[i].response_time << " ";
            cout << "Waiting Time: " << completed_processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag) {
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }

    if(flag) {
        cout<<"Algo: Preemptive-SJF            "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}

void non_preemptive_priority(vector<Process>& processes,int flag=0) {
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0 , idle = 0;
    if(!flag) {
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }
    while (completed_processes_count < n) {
        while (idx < n && processes[idx].arrival_time <= current_time) {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty()) {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle) {
            if(!flag) {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), comparePriority);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        current_process.start_time = current_time;
        current_process.finish_time = current_time + current_process.burst_time;
        current_process.waiting_time=current_process.start_time - current_process.arrival_time;
        current_process.turnaround_time=current_process.finish_time - current_process.arrival_time;
        current_process.response_time=current_process.start_time - current_process.arrival_time;

        total_waiting_time += current_process.waiting_time;
        total_turnaround_time += current_process.turnaround_time;
        total_response_time += current_process.response_time;

        completed_processes.push_back(current_process);
        current_time = current_process.finish_time;
        completed_processes_count++;
        if(!flag) {
            cout << "P" << current_process.process_id << " " << current_process.finish_time << " ";
        }
    }
    if(!flag) {
        cout << endl << endl;

        sort(completed_processes.begin(),completed_processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << completed_processes[i].process_id << " ";
            cout << "Start Time: " << completed_processes[i].start_time << " ";
            cout << "End Time: " << completed_processes[i].finish_time << " ";
            cout << "Response Time: " << completed_processes[i].response_time << " ";
            cout << "Waiting Time: " << completed_processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag) {
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }

    if(flag) {
        cout<<"Algo: Non-Preemptive-Priority   "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}

void preemptive_priority(vector<Process>& processes,int flag=0) {
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0 , idle = 0;
    if(!flag) {
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }

    while (completed_processes_count < n) {
        while (idx < n && processes[idx].arrival_time <= current_time) {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty()) {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle) {
            if(!flag) {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), comparePriority);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        if(current_process.response_time==-1) {
            current_process.response_time = current_time - current_process.arrival_time;
            total_response_time += current_process.response_time;
            current_process.start_time = current_time;
        }

        current_time++;

        current_process.remaining_time--;

        if(current_process.remaining_time==0) {
            current_process.finish_time = current_time;
            current_process.waiting_time=current_time - current_process.arrival_time - current_process.burst_time;
            total_waiting_time += current_process.waiting_time;
            current_process.turnaround_time=current_process.finish_time - current_process.arrival_time;
            total_turnaround_time += current_process.turnaround_time;
            completed_processes_count++;
            completed_processes.push_back(current_process);
            if(!flag) {
                cout << "P" << current_process.process_id << " " << current_process.finish_time << " ";
            }
        }
        else {
            while (idx < n && processes[idx].arrival_time <= current_time) {
                ready_queue.push_back(processes[idx]);
                idx++;
            }
            ready_queue.push_back(current_process);
            sort(ready_queue.begin(), ready_queue.end(), comparePriority);
            if(ready_queue.front().process_id!=current_process.process_id) {
                if(!flag) {
                    cout << "P" << current_process.process_id << " " << current_time << " ";
                }
            }
        }
    }

    if(!flag) {
        cout << endl << endl;

        sort(completed_processes.begin(),completed_processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << completed_processes[i].process_id << " ";
            cout << "Start Time: " << completed_processes[i].start_time << " ";
            cout << "End Time: " << completed_processes[i].finish_time << " ";
            cout << "Response Time: " << completed_processes[i].response_time << " ";
            cout << "Waiting Time: " << completed_processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag) {
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }

    if(flag) {
        cout<<"Algo: Preemptive-Priority       "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}

void round_robin(vector<Process>& processes, int time_quantum,int flag=0) {
    int n = processes.size();
    vector<Process> ready_queue;
    vector<Process> completed_processes;
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;

    if(!flag) {
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }
    int idle = 0;

    while (!processes.empty() || !ready_queue.empty()) {
        // Check for newly arrived processes
        while (!processes.empty() && processes.front().arrival_time <= current_time) {
            ready_queue.push_back(processes.front());
            processes.erase(processes.begin());
        }

        if (ready_queue.empty()) {
            current_time++;
            idle = 1;
            continue;
        }

        if(idle) {
            if(!flag) {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        if (current_process.response_time == -1) {
            current_process.response_time = current_time - current_process.arrival_time;
            total_response_time += current_process.response_time;
            current_process.start_time = current_time;
        }

        int execution_time = min(time_quantum, current_process.remaining_time);
        current_process.remaining_time -= execution_time;
        current_time += execution_time;

        if(!flag){
            cout << "P" << current_process.process_id << " " << current_time << " ";
        }

        if (current_process.remaining_time == 0) {
            current_process.waiting_time = current_time - current_process.arrival_time - current_process.burst_time;
            current_process.turnaround_time = current_time - current_process.arrival_time;
            total_waiting_time += current_process.waiting_time;
            total_turnaround_time += current_process.turnaround_time;
            current_process.finish_time = current_time;
            completed_processes.push_back(current_process);
        } else {
            while (!processes.empty() && processes.front().arrival_time <= current_time) {
                ready_queue.push_back(processes.front());
                processes.erase(processes.begin());
            }
            ready_queue.push_back(current_process);
        }
    }

    if(!flag){
        cout << endl << endl;

        sort(completed_processes.begin(),completed_processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << completed_processes[i].process_id << " ";
            cout << "Start Time: " << completed_processes[i].start_time << " ";
            cout << "End Time: " << completed_processes[i].finish_time << " ";
            cout << "Response Time: " << completed_processes[i].response_time << " ";
            cout << "Waiting Time: " << completed_processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag) {
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }

    if(flag) {
        cout<<"Algo: Round-Robin               "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}

void own_algorithm(vector<Process>& processes, int time_quantum,int flag=0) {
    int n = processes.size();
    queue<Process> ready_queue;
    int time = 0 , idle = 0;
    vector<Process> completed_processes;

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;

    if(!flag){
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }

    while (!processes.empty() || !ready_queue.empty()) {

        while (!processes.empty() && processes.front().arrival_time <= time) {
            ready_queue.push(processes.front());
            processes.erase(processes.begin());
        }

        if (ready_queue.empty()) {
            time++;
            idle = 1;
            continue;
        }

        if (idle) {
            if(!flag) {
            cout << "idle " << time << " ";
            }
            idle = 0;
        }

        Process current_process = ready_queue.front();
        ready_queue.pop();

        if (current_process.response_time == -1) {
            current_process.response_time = time - current_process.arrival_time;
            total_response_time += current_process.response_time;
            current_process.start_time = time;
        }

        for (int i = 0; i < min(time_quantum, current_process.remaining_time); i++) {
            time++;
            current_process.remaining_time--;

            while (!processes.empty() && processes.front().arrival_time <= time) {
                ready_queue.push(processes.front());
                processes.erase(processes.begin());
            }

            if (current_process.remaining_time == 0) {
                current_process.waiting_time = time - current_process.arrival_time - current_process.burst_time;
                current_process.turnaround_time = time - current_process.arrival_time;
                total_waiting_time += current_process.waiting_time;
                total_turnaround_time += current_process.turnaround_time;

                current_process.finish_time = time;
                completed_processes.push_back(current_process);
                break;
            }
        }

        if(!flag) {
            cout << "P" << current_process.process_id << " " << time << " ";
        }

        if (current_process.remaining_time > 0) {
            ready_queue.push(current_process);
        }
    }

    if(!flag){
        cout << endl <<endl;

        sort(completed_processes.begin(),completed_processes.end(),compareProcessNo);
        for (int i=0;i<n;i++)
        {
            cout << "Process: P" << completed_processes[i].process_id << " ";
            cout << "Start Time: " << completed_processes[i].start_time << " ";
            cout << "End Time: " << completed_processes[i].finish_time << " ";
            cout << "Response Time: " << completed_processes[i].response_time << " ";
            cout << "Waiting Time: " << completed_processes[i].waiting_time << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaround_time << endl;
        }
        cout<<endl;
    }

    double avg_waiting_time = (total_waiting_time*1.0) / n;
    double avg_turnaround_time = (total_turnaround_time*1.0) / n;
    double avg_response_time = (total_response_time*1.0) / n;

    if(!flag) {
        cout << "Average Waiting Time: " << avg_waiting_time << endl;
        cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
        cout << "Average Response Time: " << avg_response_time << endl;
        cout<<endl;
    }

    if(flag) {
        cout<<"Algo: My-Own-Algorithm          "<<"Avg. Response time: "<<avg_response_time<<"\t"<<"Avg. Waiting time: "<<avg_waiting_time<<"\t"<<"Avg. Turnaround time: "<<avg_turnaround_time<<endl;
    }
}


int main()
{
    while(1)
    {
        cout<<"1: FCFS"<<endl;
        cout<<"2: Non-Preemptive-SJF"<<endl;
        cout<<"3: Preemptive-SJF"<<endl;
        cout<<"4: Non-Preemptive-Priority"<<endl;
        cout<<"5: Preemptive-Priority"<<endl;
        cout<<"6: Round-Robin"<<endl;
        cout<<"7: Your-Own-Algorithm"<<endl;
        cout<<"8: Compare-All"<<endl;
        cout<<endl;
        cout<<"Input your choice: ";
        int choice;
        cin>>choice;
        cout<<endl;

        if(choice==1||choice==2||choice==3)
        {
            int n,p_no,b_time,a_time,r_time;
            vector<Process> processes;

            cout<<"Number of process, n: ";
            cin>>n;
            cout<<endl;
            for(int i=1;i<=n;i++)
            {
                p_no=i;
                cout<<"Enter the burst time of P"<<i<<": ";
                cin>>b_time;
                cout<<"Enter the arrival time of P"<<i<<": ";
                cin>>a_time;
                r_time=b_time;
                processes.push_back({p_no,a_time,b_time,r_time,-1,-1,-1,-1,-1,-1});
                cout<<endl;
            }
            sort(processes.begin(),processes.end(),compareArrivalTime);
            if(choice==1)
            {
                first_come_first_serve(processes);
            }
            else if(choice==2)
            {
                non_preemptive_sjf(processes);
            }
            else if(choice==3)
            {
                preemptive_sjf(processes);
            }
        }
        else if(choice==4||choice==5)
        {
            int n,p_no,b_time,a_time,r_time,priority;
            vector<Process> processes;

            cout<<"Number of process, n: ";
            cin>>n;
            cout<<endl;
            for(int i=1;i<=n;i++)
            {
                p_no=i;
                cout<<"Enter the burst time of P"<<i<<": ";
                cin>>b_time;
                cout<<"Enter the arrival time of P"<<i<<": ";
                cin>>a_time;
                cout<<"Enter the priority of P"<<i<<": ";
                cin>>priority;
                r_time=b_time;
                processes.push_back({p_no,a_time,b_time,r_time,priority,-1,-1,-1,-1,-1});
                cout<<endl;
            }
            sort(processes.begin(),processes.end(),compareArrivalTime);
            if(choice==4)
            {
                non_preemptive_priority(processes);
            }
            else if(choice==5)
            {
                preemptive_priority(processes);
            }
        }
        else if(choice==6)
        {
            int n,p_no,b_time,a_time,r_time,time_quantum;
            vector<Process> processes;

            cout<<"Number of process, n: ";
            cin>>n;
            cout<<endl;
            for(int i=1;i<=n;i++)
            {
                p_no=i;
                cout<<"Enter the burst time of P"<<i<<": ";
                cin>>b_time;
                cout<<"Enter the arrival time of P"<<i<<": ";
                cin>>a_time;
                r_time=b_time;
                processes.push_back({p_no,a_time,b_time,r_time,-1,-1,-1,-1,-1,-1});
                cout<<endl;
            }
            cout<<"Time Quantum: ";
            cin>>time_quantum;
            cout<<endl;
            sort(processes.begin(),processes.end(),compareArrivalTime);
            round_robin(processes, time_quantum);
        }
        else if(choice==7)
        {
            int n,p_no,b_time,a_time,r_time,time_quantum;
            vector<Process> processes;

            cout<<"Number of process, n: ";
            cin>>n;
            cout<<endl;
            for(int i=1;i<=n;i++)
            {
                p_no=i;
                cout<<"Enter the burst time of P"<<i<<": ";
                cin>>b_time;
                cout<<"Enter the arrival time of P"<<i<<": ";
                cin>>a_time;
                r_time=b_time;
                processes.push_back({p_no,a_time,b_time,r_time,-1,-1,-1,-1,-1,-1});
                cout<<endl;
            }
            cout<<"Time Quantum: ";
            cin>>time_quantum;
            cout<<endl;
            sort(processes.begin(),processes.end(),compareArrivalTime);
            own_algorithm(processes, time_quantum);
        }
        else if(choice==8)
        {
            int n,p_no,b_time,a_time,r_time,priority,time_quantum;
            vector<Process> processes;

            cout<<"Number of process, n: ";
            cin>>n;
            cout<<endl;
            for(int i=1;i<=n;i++)
            {
                p_no=i;
                cout<<"Enter the burst time of P"<<i<<": ";
                cin>>b_time;
                cout<<"Enter the arrival time of P"<<i<<": ";
                cin>>a_time;
                cout<<"Enter the priority of P"<<i<<": ";
                cin>>priority;
                r_time=b_time;
                processes.push_back({p_no,a_time,b_time,r_time,priority,-1,-1,-1,-1,-1});
                cout<<endl;
            }
            cout<<"Time Quantum: ";
            cin>>time_quantum;
            cout<<endl;
            sort(processes.begin(),processes.end(),compareArrivalTime);

            vector<Process>n_processes=processes;
            first_come_first_serve(n_processes,1);

            n_processes=processes;
            non_preemptive_sjf(n_processes,1);

            n_processes=processes;
            preemptive_sjf(n_processes,1);

            n_processes=processes;
            non_preemptive_priority(n_processes,1);

            n_processes=processes;
            preemptive_priority(n_processes,1);

            n_processes=processes;
            round_robin(n_processes, time_quantum,1);

            n_processes=processes;
            own_algorithm(n_processes, time_quantum,1);
            cout<<endl;
        }
        else if(choice==9)
        {
            cout<<"Program Terminated"<<endl;
            break;
        }
    }
    return 0;
}

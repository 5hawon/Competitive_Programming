#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, min, k = 1, btime = 0;
    cout << "Number of process,"
         << "n=";
    cin >> n;

    int p[n + 3];
    for (i = 0; i <= n; i++)
        p[i] = i + 1;
    int bt[n + 1], temp, j, at[n + 1], wt[n + 1], tt[n + 1], ta = 0, sum = 0;
    float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

    for (i = 0; i < n; i++)
    {
        cout << "Enter the burst time of " << i + 1 << " process :";
        cin >> bt[i];
        cout << "Enter the arrival time of" << i + 1 << " process :";
        cin >> at[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (at[i] < at[j])
            {

                swap(p[j], p[i]);
                swap(at[i], at[j]);
                swap(bt[j], bt[i]);
            }
        }
    }

    for (j = 0; j < n; j++)
    {
        btime = btime + bt[j];
        min = bt[k];
        for (i = k; i < n; i++)
        {
            if (btime >= at[i] && bt[i] < min)
            {
                swap(p[i], p[k]);
                swap(at[i], at[k]);
                swap(bt[k], bt[i]);
            }
        }
        k++;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        sum = sum + bt[i - 1];
        wt[i] = sum - at[i];
        wsum = wsum + wt[i];
    }

    wavg = (wsum / n);
    for (i = 0; i < n; i++)
    {
        ta = ta + bt[i];
        tt[i] = ta - at[i];
        tsum = tsum + tt[i];
    }

    tavg = (tsum / n);
    cout << "Grant chat" << endl;
    for (i = 0; i < n; i++)
    {
        cout << wt[i] + at[i] << " p" << p[i] << " ";
    }
    cout << endl;
    cout << endl;

    for (i = 0; i < n; i++)
    {

        cout << "Process" << p[i] << " Start Time: " << at[i] + wt[i] << " Waiting Time:" << wt[i] << " Turn Araound Time:" << tt[i] << endl;
        cout << endl;
    }

    cout << "AVERAGE WAITING TIME :" << wavg << endl;
    cout << "AVERAGE TURN AROUND TIME " << tavg << endl;
}

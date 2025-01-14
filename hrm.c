// C program for the Highest Response Ratio Next (HRRN) Scheduling 
#include <stdio.h> 

// This structure defines the details of the process
struct process { 
 char name; 
 int at, bt, ct, wt, tt; 
 int complete; 
 float ntt; 
} p[10]; 

int m; 

//The Sorting of Processes by Arrival Time 
void sortByArrival() 
{ 
 struct process temp; 
 int i, j; 

 // Selection Sort applied 
 for (i = 0; i < m - 1; i++) { 
  for (j = i + 1; j < m; j++) { 

   // This condition is used to Check for the lesser arrival time 
   if (p[i].at > p[j].at) { 

    // Swaping of earlier process to front 
    temp = p[i]; 
    p[i] = p[j]; 
    p[j] = temp; 
   } 
  } 
 } 
} 

void main() 
{ 
 int i, j, t, sum_bt = 0; 
 char c; 
 float avgwt = 0, avgtt = 0; 
 m = 5; 

 // the predefined arrival times 
 int arriv[] = { 2,3 ,0 ,5 ,4,4  }; 

 // the predefined burst times 
 int burst[] = { 3,4 ,7 ,2 ,3,1 }; 

 // Initialize the structure variables 
 for (i = 0, c = 'A'; i < m; i++, c++) { 
  p[i].name = c; 
  p[i].at = arriv[i]; 
  p[i].bt = burst[i]; 

  // Variable for Completion status 
  // for Pending = 0 
  // for Completed = 1 
  p[i].complete = 0; 

  // the Variable for the sum of all Burst Times 
  sum_bt += p[i].bt; 
 } 

 // Let us Sort the structure by the arrival times 
 sortByArrival(); 
 printf("\nName\tArrival Time\tBurst Time\tWaiting Time"); 
 printf("\tTurnAround Time\t Normalized TT"); 
 for (t = p[0].at; t < sum_bt;) { 

  // Now Set the lower limit to response ratio 
  float hrr = -9999; 

  //The Response Ratio Variable 
  float temp; 

  // Variable used to store the next processs selected 
  int loc; 
  for (i = 0; i < m; i++) { 

   // Check if the process has arrived and is Incomplete 
   if (p[i].at <= t && p[i].complete != 1) { 

    // Calculating the Response Ratio 
    temp = (p[i].bt + (t - p[i].at)) / p[i].bt; 

    // Checking for the Highest Response Ratio 
    if (hrr < temp) { 

     // Storing the Response Ratio 
     hrr = temp; 

     // Storing the  Location 
     loc = i; 
    } 
   } 
  } 

  // Updating the time value 
  t += p[loc].bt; 

  // Calculation of the waiting time 
  p[loc].wt = t - p[loc].at - p[loc].bt; 

  // Calculation of the Turn Around Time 
  p[loc].tt = t - p[loc].at; 

  // Sum of Turn Around Time for the average 
  avgtt += p[loc].tt; 

  // Calculation of the Normalized Turn Around Time 
  p[loc].ntt = ((float)p[loc].tt / p[loc].bt); 

  // Updating  the Completion Status 
  p[loc].complete = 1; 

  // Sum of the Waiting Time to calculate the average 
  avgwt += p[loc].wt; 
  printf("\n%c\t\t%d\t\t", p[loc].name, p[loc].at); 
  printf("%d\t\t%d\t\t", p[loc].bt, p[loc].wt); 
  printf("%d\t\t%f", p[loc].tt, p[loc].ntt); 
 } 
 printf("\nThe Average waiting time:%f\n", avgwt / m); 
 printf("The Average Turn Around time:%f\n", avgtt / m); 
}
#include <bits/stdc++.h>

using namespace std;

#define SIZE 100

struct job {
    string jobId;
    int start_time;
    int finish_time;
    int compatibility;
} jobs[SIZE];

bool compareByFinishTime(const job& a, const job& b) {
    return a.finish_time < b.finish_time;
}

int recursive(int i)
{
  int m = i+1;
  while(m)
}

int main() {
    int i,j,n; 
    
    cout << "Enter number of jobs:";
    cin >> n;

    
    if (n <= 0 || n > SIZE) {
        cout << "Invalid number of jobs. Please enter a value between 1 and " << SIZE << "." << endl;
        return 1;
    }

    cout << "Enter information:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].jobId >> jobs[i].start_time >> jobs[i].finish_time;
        jobs[i].compatibility = 1;
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << "Job ID: " << jobs[i].jobId << ", Start Time: " << jobs[i].start_time
            << ", Finish Time: " << jobs[i].finish_time << ", Compatibility: " << jobs[i].compatibility << endl;
    }

   
    sort(jobs, jobs + n, compareByFinishTime);

    cout << "\nSorted Jobs:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job ID: " << jobs[i].jobId << ", Start Time: " << jobs[i].start_time
            << ", Finish Time: " << jobs[i].finish_time << ", Compatibility: " << jobs[i].compatibility << endl;
    }

    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
         {
            if(jobs[i].start_time <= jobs[i].finish_time && jobs[i].compatibility == 1)
              jobs[i].compatibility = 0;
         }

        for(i=0;i<n;i++)
          if(!jobs[i].compatibility)
           cout << jobs[i].jobId << " " << jobs[i].start_time << " " <<jobs[i].finish_time << endl;

    return 0;
}

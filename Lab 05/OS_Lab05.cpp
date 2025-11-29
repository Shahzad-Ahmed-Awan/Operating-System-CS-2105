
#include <iostream>
using namespace std;

int main() {

    const int n = 5; // number of processes

    // Fixed Arrival Time (AT) and Burst Time (BT)
    int AT[n] = {0, 1, 2, 3, 4};
    int BT[n] = {4, 3, 1, 2, 5};

    int CT[n], TAT[n], WT[n];

    // FCFS Calculation
    CT[0] = BT[0];  // first process finishes after its burst time

    for(int i = 1; i < n; i++) {
        CT[i] = CT[i - 1] + BT[i];
    }

    // Turnaround time & Waiting time
    for(int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    // Output
    cout << "P\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << "\n";
    }

    return 0;
}

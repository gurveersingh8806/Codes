#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, profit, time;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int N;
    cout << "Enter number of jobs: ";
    cin >> N;

    vector<Job> jobs(N);

    cout << "Enter deadline, profit, execution time:\n";
    for (int i = 0; i < N; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit >> jobs[i].time;
    }

    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (auto j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline + 1, 0);

    int totalProfit = 0;

    for (auto job : jobs) {
        int timeNeeded = job.time;

        for (int t = job.deadline; t >= 1; t--) {
            if (t - timeNeeded + 1 >= 1) {
                bool canFit = true;

                for (int k = t; k > t - timeNeeded; k--) {
                    if (slot[k]) {
                        canFit = false;
                        break;
                    }
                }

                if (canFit) {
                    for (int k = t; k > t - timeNeeded; k--) {
                        slot[k] = 1;
                    }
                    totalProfit += job.profit;
                    break;
                }
            }
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b)
{
    return a[2] > b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int last_deadline = 0;
    for (auto& job: jobs) last_deadline = max(last_deadline, job[1]);
    vector<int> schedule(last_deadline+1,-1);
    
    int count = 0, profit = 0;
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {return a[2] > b[2];});
    for (auto& job: jobs)
    {
        int t = job[1];
        for (int t = job[1]; t>0;t--)
        {
            if (schedule[t] == -1)
            {
                count++;
                profit += job[2];
                schedule[t] = job[0];
                break;
            }
        }
    }
    return {count, profit};
}

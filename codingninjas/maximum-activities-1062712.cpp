#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activities;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        activities.push_back(make_pair(start[i], finish[i]));
    }
    sort(activities.begin(), activities.end());

    int count = 0, last_end = -1;
    for (auto& activity: activities)
    {
        if (activity.first >= last_end)
        {
            count++;
            last_end = activity.second;
        }
        else if (activity.second < last_end)
        {
            last_end = activity.second;
        }
    }
    return count;
}

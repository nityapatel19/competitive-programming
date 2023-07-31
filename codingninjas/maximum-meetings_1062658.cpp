int maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<pair<int,int>> meetings;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        meetings.push_back(make_pair(start[i], end[i]));
    }
    sort(meetings.begin(), meetings.end());

    int last_end = -1, count = 0;
    for (auto& ele: meetings)
    {
        if (last_end < ele.first)
        {
            count++;
            last_end = ele.second;
        }
        else if (ele.second < last_end)
        {
            last_end = ele.second;
        }
    }
    return count;
}

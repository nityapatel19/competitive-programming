int calculateMinPatforms(int at[], int dt[], int n) {
    // Number of platforms required at time t = Number of arrivals-departures till time t
    sort(at, at+n);
    sort(dt, dt+n);
    int max_req = 1, curr_req = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            curr_req++; i++;
        }
        else
        {
            curr_req--;
            j++;
        }
        max_req = max(max_req, curr_req);
    }
    return max_req;
}

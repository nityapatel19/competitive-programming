#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [](pair<int,int> a, pair<int,int> b) {return a.second/(double)a.first > b.second/(double)b.first;});
    
    double value = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].first < w)
        {
            value += items[i].second;
            w -= items[i].first;
        }
        else
        {
            value += items[i].second * w / (double)items[i].first;
            break;
        }
    }
    return value;
}

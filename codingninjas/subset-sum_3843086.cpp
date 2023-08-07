void helper(vector<int> &num, int i, int sum, vector<int>& ans){
    if (i==num.size())
    {
        ans.push_back(sum);
        return;
    }
    helper(num, i+1, sum, ans);
    helper(num, i+1, sum+num[i], ans);
}
vector<int> subsetSum(vector<int> &num){
    vector<int> ans;
    helper(num, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> MinimumCoins(int n)
{
    int coins[] = {1000,500,100,50,20,10,5,2,1};
    vector<int> ans;
    for (int coin: coins)
    {
        if (coin <= n)
        {
            int num = n/coin;
            while (num--) ans.push_back(coin);
            n %= coin;
        }
    }
    return ans;
}

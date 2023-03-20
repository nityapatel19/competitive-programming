class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
        
        if (size == 1)
        {
            return n==0 || flowerbed[0]==0;
        }
        else if (size > 1 && flowerbed[1] == 0 && flowerbed[0] == 0)
        {
            flowerbed[0] = 1;
            count++;
        }
        for (int i = 1; i < size; i++)
        {
            if (i == size-1)
            {
                if (flowerbed[i-1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            else if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }

        return count >= n;
    }
};

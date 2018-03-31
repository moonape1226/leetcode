class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        /* C++ map */
        map<int, int> myMap;
        
        for(int i = 0; i < nums.size(); i++)
            myMap[nums[i]]++;
        
        for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
        {
            if (it->second == 1)
                return it->first;
        }
        
        /* XOR */
        /*
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res ^= nums[i];
        return res;
        */
        
        /* Average */
        /*
        set<int> set(nums.begin(), nums.end());
        
        int sum = std::accumulate(set.begin(), set.end(), 0);
        int sum2 = std::accumulate(nums.begin(), nums.end(), 0);
        
        return 2 * sum - sum2;
        */
    }
};
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subset(pow(2, n));
        
        for(int i = 0; i < pow(2,n); i++)
        {
            for(int j = 0; j < n; j++)
            {
                //cout << ((i>>j) & 0x01) << endl;
                if(((i>>j) & 0x01) == 1)
                    subset[i].push_back(nums[j]);
            }
            //cout << endl;
        }
        
        return subset;
    }
};
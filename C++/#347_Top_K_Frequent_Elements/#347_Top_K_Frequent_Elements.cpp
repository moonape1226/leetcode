class Solution {
public:
    static bool comp_by_value(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second > p2.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {

        /* unordered map with vector sort method */
        int n = nums.size();
        unordered_map<int, int> nums_count;
        vector<int> ret(k);
        
        for(int i = 0; i < n; i++)
            nums_count[nums[i]]++;
        
        vector<pair<int,int>> vec(nums_count.begin(), nums_count.end());
        sort(vec.begin(), vec.end(), comp_by_value);
        
        for(int i = 0; i < k; i++)
            ret[i] = vec[i].first;
        
        return ret;
        
        /* time: O(kN) method */
        /*
        int n = nums.size();
        map<int, int> nums_count;
        vector<int> ret(k);
        
        for(int i = 0; i < n; i++)
            nums_count[nums[i]]++;
        
        for(int i = 0; i < k; i++)
        {
            int max_num = 0;
            for(map<int,int>::const_iterator it = nums_count.begin(); it != nums_count.end(); ++it)
            {
                if(it->second > nums_count[max_num])
                    max_num = it->first;
            }

            ret[i] = max_num;
            nums_count[max_num] = 0;
        }
        
        return ret;
        */
        
        /* bucket sort, space: O(N^2) */
        /*
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];
        
        vector<vector<int>> buckets(nums.size() + 1); 
        for (auto p : m)
            buckets[p.second].push_back(p.first);
        
        vector<int> ans;
        for (int i = nums.size(); i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
            }
        }
        return ans;
        */
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /* time:O(N), space:O(N) */
        /*
        int n = nums.size();
        
        vector<int> from_begin(n);
        vector<int> from_last(n);
        
        from_begin[0] = 1;
        from_last[n-1] = 1;
        
        for(int i = 1; i < n; i++)
        {
            from_begin[i] = from_begin[i-1]*nums[i-1];
            from_last[n-(i+1)] = from_last[n-i]*nums[n-i];
        }
        
        vector<int> res(n);

        for(int i = 0; i < n; i++)
        {
            res[i] = from_begin[i]*from_last[i];
        }

        return res;
        */
        
        /* time:O(N), space:O(1) */
        int n = nums.size();
        
        int from_begin = 1;
        int from_last = 1;

        vector<int> res(n, 1);
        
        for(int i = 1; i < n; i++)
        {
            from_begin = from_begin*nums[i-1];
            res[i] *= from_begin;
            
            from_last = from_last*nums[n-i];
            res[n-(i+1)] *= from_last;
        }
     
        return res;         
    }
};
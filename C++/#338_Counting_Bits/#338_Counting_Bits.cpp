#include <bitset>

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i=0; i<=num; i++)
        {
            ret.push_back(bitset<32>(i).count());
        }
        return ret;
        
        /* Time O(n), space O(n) solution */
        /*
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
        */
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* method with unordered_map, may encounter collision problem */
        unordered_map<int, int> numMap;
        int n = nums.size();
        int middleNum = round(n/2.0);
        
        for(int i = 0; i < n; i++)
        {
            numMap[nums[i]]++;
            if(numMap[nums[i]] >= middleNum)
                return nums[i];
        }
        
        return 0;
        
        /* Randomize method from jianchao.li.fighter */
        /*
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            
            if (counts > n / 2) return candidate;
        }
        */
        
        /* Moore voting algorithm method from jianchao.li.fighter */
        /*
        int n = nums.size();
        int count = 0, candidate;
        
        for(int i = 0; i < n; i++)
        {
            if(count == 0)
            {
                count++;
                candidate = nums[i];
            }
            else
                count += (candidate == nums[i]) ? 1:-1;
        }
        
        return candidate;
        */
        
         /* Bit manipulation from jianchao.li.fighter */
		 /*
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            cout << mask << endl;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
		*/
    }
};
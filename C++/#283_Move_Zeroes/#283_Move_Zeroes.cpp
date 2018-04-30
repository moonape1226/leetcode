class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		
        /* O(n^2) method */
		/*
        int max = nums.size();
		
		for(int i = 0; i < max; i++)
        {
            if(nums[i] == 0)
            {
                for(int j = i+1; j < max; j++)
                {
                    if(nums[j] != 0)
                    {
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }

        }
        */
		
		/* O(n) method */
        int index = 0, max = nums.size();
        for(int i = 0; i < max; i++)
        {
            if(nums[i] != 0)
                nums[index++] = nums[i];
        }
        
        while(index < max)
        {
            nums[index++] = 0;
        }
    }
};
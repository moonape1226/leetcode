class Solution {
public:
    /*
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[i] == nums[j])
                    return nums[i];
            }
        }
        
        return -1;
    }
    */
    
	/* Floyd-Cycle-Detection-Algorithm from #142 */
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);
        
        int point1 = nums[0];
        int point2 = tortoise;
        
        while(point1 != point2)
        {
            point1 = nums[point1];
            point2 = nums[point2];
        }
        
        return point2;
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        /* Dynamic programming */
        vector<vector<int>> arr(s.size(), vector<int>(s.size()));
        
        for(int dist = 0; dist < s.size(); dist++)
        {
            for(int j = 0; j < s.size()-dist; j++)
            {
                int head = j;
                int tail = j+dist;
                
                if(dist == 0) //for substr len = 1
                {
                    arr[head][tail] = 1;
                }
                else
                {
                    if(s[head] == s[tail])
                        arr[head][tail] = 2 + arr[head+1][tail-1];
                    else
                        arr[head][tail] += max(arr[head][tail-1], arr[head+1][tail]);
                }
            }
        }
        
        return arr[0][s.size()-1];
    }
};
class Solution {
public:
    int expandAroundCenter(string s, int L, int R)
    {
        while(L >= 0 && R < s.size() && s[L] == s[R])
        {
            L--;
            R++;
        }
        
        return R-L-1;
    }
    
    string longestPalindrome(string s) {
        
        /* Dynamic programming */
        /*
        vector<vector<int>> arr(s.size(), vector<int>(s.size()));
        int maxlen = 0, start = 0;
        
        for(int dist = 0; dist < s.size(); dist++)
        {
            for(int j = 0; j < s.size()-dist; j++)
            {
                int head = j;
                int tail = j+dist;
                
                if(dist == 0) //for substr len = 1
                {
                    arr[head][tail] = 1;
                    maxlen = 1;
                    start = j;
                }
                else if(dist == 1) //for substr len = 2
                {
                    if(s[head] == s[tail])
                    {
                        arr[head][tail] = 1;
                        maxlen = 2;
                        start = j;
                    }
                }
                else
                {
                    if(s[head] == s[tail] && arr[head+1][tail-1])
                    {
                        arr[head][tail] = 1;
                        maxlen = dist+1;
                        start = j;
                    }
                }
            }
        }   
        
        return s.substr(start, maxlen);
        */
        
        /* Expand around center */
        int start = 0, end = 0;
        
        for(int i = 0; i<s.size(); i++)
        {
            int len = max(expandAroundCenter(s, i, i), expandAroundCenter(s, i, i+1));
            
            if(len > end-start)
            {
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }

        return s.substr(start, end-start+1);
    }
};
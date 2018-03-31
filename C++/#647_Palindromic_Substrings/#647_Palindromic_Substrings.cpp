class Solution {
public:
    int isPalindromic(string s)
    {
        int index = 0;
        
        if(s.size() == 1)
            return 1;
        
        while(index < s.size()/2)
        {
            if(s[index] != s[(s.size()-1)-index])
                return 0;
            index++;
        }
        
        return 1;
    }
    
    int countSubstrings(string s) {
        
        /* Brute force */
        /*
        int res = 0;
        for(int i = 1; i <= s.size(); i++)
        {
            int index = 0;
            while(index+i <= s.size())
            {
                res += isPalindromic(s.substr(index, i));
                index++;
            }
        }
        
        return res;
        */
        
        /* Dynamic programming */
        vector<vector<int>> arr(s.size(), vector<int>(s.size()));
        int res = 0;

        for(int dist = 0; dist < s.size(); dist++)
        {
            for(int j = 0; j < s.size()-dist; j++)
            {
                int head = j;
                int tail = j+dist;
                
                if(dist == 0) //for substr len = 1
                {
                    arr[head][tail] = 1;
                    res++;
                }
                else if(dist == 1) //for substr len = 2
                {
                    if(s[head] == s[tail])
                    {
                        arr[head][tail] = 1;
                        res++;
                    }
                }
                else
                {
                    if(s[head] == s[tail] && arr[head+1][tail-1])
                    {
                        arr[head][tail] = 1;
                        res++;
                    }
                }
            }
        }   
        
        return res;
    }
};
class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> parentheses;
        bool flag = true;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                parentheses.push(s[i]);
            }
            else
            {
                if(parentheses.size() == 0)
                    return false;
                
                char curr = parentheses.top();
                parentheses.pop();
                
                if(curr == '(' && s[i] == ')')
                    continue;
                else
                    return false;
            }
        }
        
        if(parentheses.size() != 0)
            return false;
        else
            return true;
    }
    
	/* recursive method */
    void addParenthesis(vector<string> &res, string str, int left, int right)
    {
        //cout << res.size() << " " << str << endl;
        
        if(left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }
    
        if(left > 0)
            addParenthesis(res, str+'(', left-1, right);
        if(right > left)
            addParenthesis(res, str+')', left, right-1);
    }
    
    vector<string> generateParenthesis(int n) {
		/* slow method with parethesis valication */
        /*
        int total = pow(2, n*2);
        vector<string> res;
        
        for(int i = 0; i < total; i++)
        {
            int total_bit = 0;
            string pare_str = "";
            
            for(int j = 0; j < n*2; j++)
            {
                 total_bit += ((i >> j) & 1);
            }
            
            if(total_bit == n)
            {
                for(int j = 0; j < n*2; j++)
                {
                     if(((i >> j) & 1) == 0)
                         pare_str += '(';
                     else
                         pare_str += ')';
                }
                
                if(isValid(pare_str) == true)
                    res.push_back(pare_str);
            }
        }
        */

        vector<string> res;
        addParenthesis(res, "", n, n);
        
        return res;
    }
};
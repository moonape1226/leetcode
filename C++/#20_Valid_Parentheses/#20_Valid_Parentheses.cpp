class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        bool flag = true;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                parentheses.push(s[i]);
            }
            else
            {
                if(parentheses.size() == 0)
                {
                    return false;
                }
                
                char curr = parentheses.top();
                parentheses.pop();
                
                if(curr == '{' && s[i] == '}' ||
                   curr == '[' && s[i] == ']' ||
                   curr == '(' && s[i] == ')')
                    continue;
                else
                {
                    return false;
                }
            }
        }
        
        if(parentheses.size() != 0)
            return false;
        else
            return true;
    }
};
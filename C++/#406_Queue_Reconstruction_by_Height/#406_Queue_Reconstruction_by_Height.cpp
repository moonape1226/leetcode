class Solution {
public:

    static bool comparePairs(const pair<int,int>& lhs, const pair<int,int>& rhs)
    {
        if(lhs.first+lhs.second > rhs.first+rhs.second)
            return false;
        else if(lhs.first+lhs.second < rhs.first+rhs.second)
            return true;
        else
        {
            if(lhs.first > rhs.first)
                return false;
            else
                return true;
        }
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        
        vector<pair<int,int>> sol;
        for (auto person : people){
            sol.insert(sol.begin()+person.second, person);
        }
        
        return sol;
    }
};
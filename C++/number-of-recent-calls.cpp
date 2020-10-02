//https://leetcode.com/problems/number-of-recent-calls/
//Difficulty Level: Easy
//Time complexity: O(1)
//Space complexity: O(1)
//solved using set data structure

class RecentCounter 
{
    set<int> times;
public:
    RecentCounter() {
    }
    
    int ping(int t) 
    {    
        if(times.empty())
        {
            times.insert(t);
            return 1;
        }
        
        auto it = times.begin();
        
        while(it != times.end() && t - *it > 3000)
        {
            times.erase(it);  
            it++;
        }
       
        times.insert(t);
        
        return times.size();
    }
};
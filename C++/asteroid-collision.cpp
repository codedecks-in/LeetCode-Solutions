class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
    
    for(int i=0;i<asteroids.size();i++)
    {
        if(s.empty() or asteroids[i]>0)
        {
            s.push(asteroids[i]);
        }
        else
        {
            while(true)
            {
                int top = s.top();
                
                if(top<0)
                {
                    s.push(asteroids[i]);
                    break;
                }
                else if(top==-asteroids[i])
                {
                    s.pop();
                    break;
                }
                else if(top>(-asteroids[i]))
                {
                    break;
                }
                else
                {
                    s.pop();
                    if(s.empty())
                    {
                        s.push(asteroids[i]);
                        break;
                    }
                }
            }
        }
    }
    
    vector<int> output(s.size(),0);
    
    for(int i=s.size()-1;i>=0;i--)
    {
        output[i]=s.top();
        s.pop();
    }
    
    return output;
    
    
}
};
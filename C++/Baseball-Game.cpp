class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        auto it=ops.begin();
        while(it!=ops.end()){
            if(*it=="+"){    //if char is + then new record is sum of last two records
                int val1=s.top();
                s.pop();
                int val2=s.top();
                s.push(val1);
                s.push(val1+val2);
            }
            else if(*it=="D"){  //if char is D then new record is twice the last record
                s.push(2*s.top());
            }
            else if(*it=="C"){  //if char is C then the last record is invalidated , hence popped
                s.pop();
            }
            else{  // if none of these conditions occur then just push the new record to stack
                s.push(stoi(*it));
            }
            it++;
        }
        int count=0;
        while(!s.empty())  //iteratively pop the top value of the stack and add it to the total
        {
            count+=s.top();
            s.pop();
        }
        return count;
    }
};
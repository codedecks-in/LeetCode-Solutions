#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
    stack<char>s;
    int n=str.size();
    for(int i=0;i<n;i++){
        // If our stack is empty than there is only one choice that is all opening parathesis can taken
        if(s.empty()){
            if(str[i]==')' || str[i]=='}' || str[i]==']'){
                return false;
            }
            else{
                s.push(str[i]);
            }
        }
        // If our stack is non-empty so we have already assured that at current state there will be only open parenthesis available in the stack so now we have to just check that if our str[i] is opening one then No problem just push it into the stack but if it is closing one so in that case we have to check whether this closing parenthsis should have it's conjugate opening parenthesis otherwise we'll return false else we'll just delete than opening conjugate from the stack 
        else{
            char ch=s.top();
            if(str[i]==')' || str[i]=='}' || str[i]==']'){
                if((str[i]==')' && ch!='(') || (str[i]=='}' && ch!='{') || (str[i]==']' && ch!='[')){
                    return false;
                }
                else{
                    s.pop();
                }
            }
            else{
                s.push(str[i]);
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}
int main(){
	string str = "()";
	if(isValid(str)){
	    cout<<"True";
	}
	else{
	    cout<<"False";
	}
	return 0;
}

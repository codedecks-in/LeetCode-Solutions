#include<bits/stdc++.h>
class Solution {
public:
     string defangIPaddr(string address) {
        string op;
      for(int i=0;address[i]!='\0';i++)  
      {
          if(address[i]=='.')
          {
              
              op=op+'['+ address[i]+']';
              i++;
        
          }
          op=op+address[i];
              
      }
        return op;
     }
};
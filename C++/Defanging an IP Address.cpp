/*Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".*/

/* Input: address = "1.1.1.1"
   Output: "1[.]1[.]1[.]1"*/
   
#include<bits/stdc++.h>
class Solution {
public:
     string defangIPaddr(string address) {
        string op;
//A for loop which will execute till the address[i] which means the string runs till the last character of the string is Null 
      for(int i=0;address[i]!='\0';i++)  
      {
           //if address[i]== '.' which means that if the in a string contains a period we'll replace it with [.]
          if(address[i]=='.')
          {
              //This line adds the square brackets if there's a period in a string
              op=op+'['+ address[i]+']';
              i++;
        
          }
          op=op+address[i];
              
      }
        return op;
     }
};

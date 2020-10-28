//time complexity O(n+m) where n and m are the number of input characters in each input string respectively
//space compexity is O(1) since there is a limit on number of possible unique characters
//loop through the first string and add a count of characters to hashmap
//loop through second string and for each letter lookup in hashmap. If found, decrement the count in the hasmap. If the count <0 for any letter then we have found our extra character
//else if the letter cannot be found in our hashmap, then this must be the extra character
//Otherwise if no differences can be found between the two input strings we just return null character



class Solution {
public:
    char findTheDifference(string s, string t) {
        
    char returnChar= '\0';
    std::unordered_map <char,int>ourMap;

    //count the letters in the input string and add it to map
    for (const char& letter:s) {

        if(ourMap.find(letter)==ourMap.end()){ ourMap[letter]=1;}
        else{ourMap[letter]++;}
    }

        
    //compare with letters in other string
    for (const char& letter:t){
        
        //if you can find the letter then decrement it 
        if(ourMap.find(letter)!=ourMap.end()) { 
        
            ourMap[letter]--; 
            if(ourMap[letter]<0) { return letter; } 
        
        }
        
        else{return letter;}
    }
        
    return returnChar;
        
    }
};
/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Problem Link:  https://leetcode.com/problems/word-ladder/
It is a popular interview program which is based on BFS
*/
import java.util.*;
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> hs=new HashSet<>(wordList);
        if(!hs.contains(endWord))
        {
            return 0;
        }
        int steps=1;
        Queue<String> q=new LinkedList<>();
        q.add(beginWord);
        while(!q.isEmpty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                String curr=q.poll();
                char a[]=curr.toCharArray();
                for(int j=0;j<a.length;j++)
                {
                    char temp=a[j];
                    for(char c='a';c<='z';c++)
                    {
                        if(a[j]==c) continue;
                        a[j]=c;
                        String test=new String(a);
                        if(test.equals(endWord)) return steps+1;
                        if(hs.contains(test))
                        {
                            q.add(test);
                            hs.remove(test);
                        }
                    }
                    a[j]=temp;
                }
            }
            steps++;
        }
        return 0;
    }
}
/*
Question :
Given an array of length ‘N’, where each element denotes the position of a stall.
Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. 
To prevent the cows from hurting each other, you need to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.

Eg

array: 1,2,4,8,9  &  k=3
O/P: 3
Explaination: 1st cow at stall 1 , 2nd cow at stall 4 and 3rd cow at stall 8


*/

bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cows=1;               // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    int lastCowPosition=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];              // just take low=0 and high = 1000000 any large number if this seems tricky
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(stalls,mid,k))
        {
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return yes;
}
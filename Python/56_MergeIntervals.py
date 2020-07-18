#Difficluty - Medium
#Speed = 33.94%
'''
First we will sort the intervals (with start time of the interval as the key), so that the (overlapping) intervals that could be merged comes adjacent. For Ex:
Original Array -> [[0,2], [5,9], [1,3], [11,12]]
Sorted Array -> [[0,2], [1,3], [5,9], [11,12]]
Note => Time Complexity of Sorting is O(nlogn)
Overlapping Condition: Two intervals (X and Y) are overlapping if end Time of first interval (X) is greater than start time of second interval (Y)
that is,
            X.end > Y.start
In case of [0,2] and [1,3], since 2 > 1, these intervals are overlapping.
In case of [5,9] and [11,12], since 9 < 11, these intervals are *NOT* overlapping.
So we will start with pushing the first interval in merged array.
Then traverse the array, checking the overlapping condition of every interval with the last interval in merged array,
1) If overlapping condition satisfy, We will update the end time of last interval in merged array as maximum of end time of both intervals.
2) If overlapping condition doesnt satisy, We will push the interval in merged array
'''
#Time Complexity: O(nlogn)
#Space Complexity: O(n)
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])                          #sort the intervals with starting time as the key
        merged = []
        for interval in intervals:
            if not merged or merged[-1][1] < interval[0]:           #If merged list is empty (we need to push the first interval) or Overlapping condn doesnt satisfy
                merged.append(interval)                             #push the interval in merged array
            else:                                                   #else
                merged[-1][1] = max(merged[-1][1], interval[1])     #update the end time of last interval in merged array as maximum of end time of both intervals
        return merged

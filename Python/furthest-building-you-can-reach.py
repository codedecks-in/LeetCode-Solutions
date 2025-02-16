'''
the condition was a person can use ladder or brick to climb a building but the sucessive building's height can be greater than or less than current buiiding.
no. of bricks and ladder given,ladder length can be anything i.e if next buliding in 2 units greater than and we have no bricks so we can use ladder.
so i used maxheap to know where should i use ladder so that it will not waste my resource and we can reach the farthest building.
'''
# import heapq
class Solution:
    def furthestBuilding(self, heights: list[int], bricks: int, ladders: int) -> int:
        heap = []
        for i in range(len(heights)-1):
            diff = heights[i+1]-heights[i]
            print(diff)
            if diff<0:
                continue
            print("hello",diff)
            bricks-=diff
            print("b",bricks)
            heapq.heappush(heap,diff)
            print(heap)
            if bricks<0:
                if ladders==0:
                    return i
                ladders-=1
                print("bricks",bricks,"ladder",ladders)
                bricks+=heapq.heappop(heap)

        return len(heights)-1

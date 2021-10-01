# Q. Find total number of ways to reach from (0, 0) to (width - 1, height - 1) in a grid of size width X height, 
#    where the total distance travelled should be equal to (width + height).
#    Eg. For a grid of size 5 X 3
# 
#              .   .   .   .   . (width - 1, height - 1)
#              .   .   .   .   .                                                Ans: 15
#       (0, 0) .   .   .   .   .


rows = 7
cols = 7

def return_neighbours(cell):
    neighbours = []
    if cell[0] + 1 < rows:
        neighbours.append( [cell[0] + 1, cell[1]] )
    if cell[1] + 1 < cols:
        neighbours.append( [cell[0], cell[1] + 1] )

    return neighbours

def solution(cell, _count):
    if cell == [rows - 1, cols - 1]:
        _count += 1
        return _count
    for ele in return_neighbours(cell):
        print(ele, _count)
        _count = solution(ele, _count)

    return _count

count = 0
print(f"Count : {solution([0,0], count)}")

'''
other approach:-

def count_paths(n, m):
    if n == 1 or m == 1:
        return 1
    else:
        return count_paths(n-1, m) + count_paths(n, m-1)

count = count_paths(7, 7)
print(count)
'''
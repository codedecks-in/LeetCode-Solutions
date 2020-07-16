#Difficulty = Medium
#Submission Speed = 85.81%
'''
#The Algorithm is similar to Graph coloring algorithm.
After making the graph from edge lists,
We will traverse every node one by one. For every node, create a fresh new list of choices of flowers
While Traversing a particular node (say NODE A), we will check its neighbours and if any of the neighbour has been assigned
flower (say flower 'X') we will remove that flower ('X') from the list of choices of the corresponding Node (NODE A)
'''
'''
If  E = Number of Edges
    V = Number of Vertices/Nodes
Time Complexity =  O(V+E)
Space Complexity = O(2V+E)
'''
from collections import defaultdict
class Solution:
    def gardenNoAdj(self, N, paths):

        #Create Graph
        graph = defaultdict(list)
        for i in paths:
            graph[i[0]].append(i[1])                #Since Graph is Bidirectional, we need to add edge both sides
            graph[i[1]].append(i[0])
        flowers = []
        for i in range(1, N + 1):                   #We will traverse every node one by one
            choice = [1, 2, 3, 4]                   #create a fresh new list of choices of flowers
            for k in graph[i]:                      #check its neighbours
                try:
                    choice.remove(flowers[k-1])     #if any of the neighbour has been assigned flower (say flower 'X') we will remove that flower ('X')
                except:
                    pass
            flowers.append(choice[0])               #Select the first flower from the remaining choices
        return flowers
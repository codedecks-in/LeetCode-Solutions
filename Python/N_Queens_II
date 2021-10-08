class QueenSolution(object):
    ''' A class to store the intermediate status towards the
        N-Queen solutions
    '''
    __slots__ = ("col","diagF", "diagB")
    def __init__(self, col, diagF, diagB):
        self.col = col              # Used columns
        self.diagF = diagF          # Used forward diagonal
        self.diagB = diagB          # Used backward diagonal
        return
class Solution:
    # @return an integer
    def totalNQueens(self, n):
        # Handle some special cases
        if n == 1:              return 1
        if n == 2 or n == 3:    return 0
        result = [QueenSolution(0, 0, 0)]
        for row in xrange(n):       # Add the queens row by row
            temp = []
            for preState in result:
                for col in xrange(n):   # Try each position
                    # Column conflicts
                    if (1<<col) & preState.col != 0:        continue
                    diagF = 1 << (col - row + (n-1))
                    # Forward diagonal conflicts
                    if diagF & preState.diagF != 0:         continue
                    diagB = 1 << (row + col)
                    # Backward diagonal conflicts
                    if diagB & preState.diagB != 0:         continue
                    # Find a valid intermediate status
                    temp.append(QueenSolution( (1<<col) | preState.col,
                                              diagF | preState.diagF, diagB | preState.diagB))
            result = temp       # Prepare for working with the next row
        return len(result)

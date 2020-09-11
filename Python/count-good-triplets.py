class Solution:
    """
    The Brute Force Solution

    Time Complexity: O(N^3)
    Space Complexity: O(1)
    """

    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:

        triplet_count = 0

        # for each i, for each j, check if the first condition is satisfied
        for i in range(len(arr) - 2):
            for j in range(i + 1, len(arr) - 1):
                if abs(arr[i] - arr[j]) <= a:

                    # for each k, check if the last two conditions are satisfied
                    for k in range(j + 1, len(arr)):
                        if abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c:

                            # the triplet is Good, increment the count!
                            triplet_count += 1
        return triplet_count

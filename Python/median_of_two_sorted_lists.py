# search for best position 
def deep(a, item):
  start = 0
  end = len(a)
  depth = math.log(len(a) + 1, 2)
  i = 0
  while i <= math.ceil(depth):
    mid = (start + end) // 2
    if start >= end:
      break
    if item == a[mid]:
      return [mid]
    elif item > a[mid]:
      start = mid + 1
    else:
      end = mid
    i += 1
  return [mid, i]

# insert every item 
def merge(a: list, b: list):
  for i in range(len(a)):
    b.insert(deep(b, a[i])[0], a[i])
  return b

# median 
def median(a):
  if len(a) % 2:
    return a[len(a) // 2]
  else:
    return (a[len(a) // 2] + a[len(a) // 2 - 1]) / 2
  
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        return median(merge(nums1, nums2))

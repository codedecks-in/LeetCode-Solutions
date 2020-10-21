"""
Design your implementation of the circular queue. The circular queue is a linear data structure
in which the operations are performed based on FIFO (First In First Out) principle
and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
In a normal queue, once the queue becomes full, we cannot insert the next element
even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

link - https://leetcode.com/problems/design-circular-queue/

runtime - 72ms
memory - 14.6 mb

time complexity - O(n)
space complexity - O(n)

"""



class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.queue = [None] *k
        self.head = 0
        self.tail = -1
        self.size = 0
        self.max_size = k


    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        self.tail = (self.tail +1) % self.max_size
        self.queue[self.tail] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.queue[self.head] = None
        self.head = (self.head +1) % self.max_size
        self.size -= 1
        return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        return -1 if self.isEmpty() else self.queue[self.head]

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        return -1 if self.isEmpty() else self.queue[self.tail]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self.size == 0


    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return self.size == self.max_size

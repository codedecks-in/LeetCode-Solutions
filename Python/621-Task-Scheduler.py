"""
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task.
Tasks could be done in any order. Each task is done in one unit of time. For each unit of time,
the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between
two same tasks (the same letter in the array),
is that there must be at least n units of time between any two same tasks.


Memory ->14.4MB
runtime ->412ms




"""


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter=Counter(tasks)
        freq=sorted(list(counter.values()))

        max_idle=freq.pop()
        total=(max_idle-1)*n

        while freq and total>0:
            total=total-min(max_idle-1,freq.pop())

        total=max(0,total)
        return len(tasks) + total

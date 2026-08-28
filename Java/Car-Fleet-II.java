/*Intuition
To solve this problem, we use a stack to keep track of the cars whose collision times we need to calculate. We analyze the cars from the end of the array to the beginning, because a car's collision time will possibly affect only the cars behind it.

We initiate an empty stack and an array ans filled with -1, since initially, we assume that no car will collide with the car in front.
We iterate over the cars in reverse order:
If our stack is non-empty, we compare the current car's speed with the speed of the last car in the stack (which represents the nearest car in front with a collision time already computed, or yet to be computed).
If the speed of the current car is greater than the last car in the stack, a collision could occur. We then calculate the time it would take for the current car to collide with the last car in the stack.
If this collision time is less than or equal to the collision time of the last car in the stack (or the last car in the stack has no forthcoming collisions (ans[j] is -1)), we set this time as the answer for the current car's collision time, because it will collide before the car in the stack does or the car in the stack won't collide at all.
If the current car does not have a greater speed or if the collision time is greater than the collision time of the last car in the stack, we pop the last car from the stack because it will no longer collide with any previous cars.
After evaluating collision times, we add the index of the current car to the stack for the consideration of the following cars.
By the end of the iteration, the ans array will have the collision times for each car or -1 if no collision occurs.*/


class Solution {
    public double[] getCollisionTimes(int[][] cars) {
        int length = cars.length;
        double[] times = new double[length];
        Deque<Integer> stack = new LinkedList<Integer>();
        for (int i = length - 1; i >= 0; i--) {
            while (!stack.isEmpty()) {
                if (cars[stack.peek()][1] >= cars[i][1])
                    stack.pop();
                else {
                    if (times[stack.peek()] < 0)
                        break;
                    double time = times[stack.peek()] * (cars[i][1] - cars[stack.peek()][1]);
                    if (time > cars[stack.peek()][0] - cars[i][0])
                        break;
                    else
                        stack.pop();
                }
            }
            if (stack.isEmpty())
                times[i] = -1;
            else
                times[i] = (double) (cars[stack.peek()][0] - cars[i][0]) / (cars[i][1] - cars[stack.peek()][1]);
            stack.push(i);
        }
        return times;
    }
}

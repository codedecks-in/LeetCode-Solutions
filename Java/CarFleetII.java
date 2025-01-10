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

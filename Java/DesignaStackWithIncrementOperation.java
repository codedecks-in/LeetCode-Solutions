class CustomStack {
    Stack < Integer > s = new Stack();
    int max;
    public CustomStack(int maxSize) {
        max = maxSize;
    }

    public void push(int x) {
        if (s.size() + 1 <= max) {
            s.push(x);
        }
    }

    public int pop() {
        if (!s.isEmpty()) {
            return s.pop();
        } else {
            return -1;
        }
    }

    public void increment(int k, int val) {

        ArrayList < Integer > l = new ArrayList();
        int len = s.size();
        if (k <= s.size()) {


            for (int i = 0; i <= len - k - 1; i++) {
                l.add(s.pop());
            }
            for (int i = len - k; i <= len - 1; i++) {
                l.add(s.pop() + val);
            }
            for (int i = l.size() - 1; i >= 0; i--) {
                s.push(l.get(i));
            }
        } else {

            for (int i = 0; i <= len - 1; i++) {
                l.add(s.pop() + val);
            }

            for (int i = l.size() - 1; i >= 0; i--) {
                s.push(l.get(i));
            }
        }

    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
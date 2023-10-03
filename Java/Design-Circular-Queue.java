class MyCircularQueue {
    private int[] data;     // An array to store the elements of the circular queue.
    private int front;      // Pointer to the front of the queue.
    private int rear;       // Pointer to the rear of the queue.
    private int size;       // Number of elements currently in the queue.
    private int capacity;   // Maximum capacity of the queue.

    public MyCircularQueue(int k) {
        capacity = k;        // Initialize the capacity of the queue.
        data = new int[k];   // Initialize the data array with the specified capacity.
        front = -1;          // Initialize the front pointer to -1.
        rear = -1;           // Initialize the rear pointer to -1.
        size = 0;            // Initialize the size to 0.
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;    // If the queue is full, return false (cannot enqueue).
        }
        if (isEmpty()) {
            front = 0;        // If the queue is empty, set the front pointer to 0.
        }
        rear = (rear + 1) % capacity;  // Calculate the new rear position using modulo.
        data[rear] = value;            // Store the value at the new rear position.
        size++;                        // Increment the size of the queue.
        return true;                   // Return true to indicate a successful enqueue operation.
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;    // If the queue is empty, return false (cannot dequeue).
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;  // Calculate the new front position using modulo.
        }
        size--;                            // Decrement the size of the queue.
        return true;                       // Return true to indicate a successful dequeue operation.
    }

    public int Front() {
        if (isEmpty()) {
            return -1;     // If the queue is empty, return -1 (no front element).
        }
        return data[front];  // Return the element at the front of the queue.
    }

    public int Rear() {
        if (isEmpty()) {
            return -1;     // If the queue is empty, return -1 (no rear element).
        }
        return data[rear];   // Return the element at the rear of the queue.
    }

    public boolean isEmpty() {
        return size == 0;   // Check if the size is 0 to determine if the queue is empty.
    }

    public boolean isFull() {
        return size == capacity;  // Check if the size is equal to the capacity to determine if the queue is full.
    }

    public static void main(String[] args) {
        // Create a circular queue with a capacity of 5
        MyCircularQueue circularQueue = new MyCircularQueue(5);

        // Enqueue elements
        circularQueue.enQueue(1);
        circularQueue.enQueue(2);
        circularQueue.enQueue(3);

        // Check if the queue is full
        System.out.println("Is the queue full? " + circularQueue.isFull()); // Should print "false"

        // Dequeue an element
        circularQueue.deQueue();

        // Get the front and rear elements
        System.out.println("Front element: " + circularQueue.Front()); // Should print "2"
        System.out.println("Rear element: " + circularQueue.Rear());   // Should print "3"

        // Enqueue more elements
        circularQueue.enQueue(4);
        circularQueue.enQueue(5);

        // Check if the queue is full again
        System.out.println("Is the queue full? " + circularQueue.isFull()); // Should print "true"

        // Try to enqueue one more element (should fail)
        System.out.println("Enqueue result: " + circularQueue.enQueue(6));  // Should print "false"

        // Check if the queue is empty
        System.out.println("Is the queue empty? " + circularQueue.isEmpty()); // Should print "false"
    }
}

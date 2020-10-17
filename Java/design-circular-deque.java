/* We will use an array to store our elements.
Find the comments for a step by step description of the code. */


public class MyCircularDeque {


      int size;							//			keeping the count of elements in your array
      int front = -1;						//			keeping the index of front 
      int rear = -1;						//			keeping the index of rear
      int capacity;						//			total capacity of our DS
      int arr[];							//			array to store the elements


      /** Initialize your data structure here. Set the size of the deque to be k. */
      public MyCircularDeque(int k) {				//		initialising capacity as k
        this.size = 0 ;							//		and initialising the array
        this.capacity = k;
        arr = new int[k];
      }

      /** Adds an item at the front of Deque. Return true if the operation is successful. */
      public boolean insertFront(int value) {
        if( (this.size == this.capacity))		//  means queue is full
          return false;

        if(front == -1) {						//			 means queue is empty
          arr[0] = value;
          front = 0;
          rear = 0;
          this.size ++;						//		increase the size and return true
          return  true;
        }

        if(front == 0) {						//   if front is at 0, then add at last and make front as last
          arr[this.capacity - 1] = value;
          front = this.capacity -  1;	
        }else{									//	 else add to the left of front and make front as front - 1;
          arr[front - 1] = value;
          front --;
        }	
        this.size ++;							//	increase the size and return true..
        return true;
      }

      /** Adds an item at the rear of Deque. Return true if the operation is successful. */
      public boolean insertLast(int value) {

        if(this.size == this.capacity) 			//			means queue is full
          return false;

          if(rear == -1) {						//		means queue is empty
            arr[0] = value;						//		add the first element and return true
            front = 0;
            rear = 0;
            this.size ++;
            return true;
          }

          if(rear == this.capacity - 1) {			//		if rear is at last, means we will have to add this element at first
            arr[0] = value;						//		position and make rear as first
            rear = 0;
          }else {
            arr[rear + 1] = value;				//		if rear is not at last, add to rear  + 1 and 
            rear ++;							// 		increment rear
          }
        this.size ++;								//		increase the size and return true
        return true; 
      }

      /** Deletes an item from the front of Deque. Return true if the operation is successful. */
      public boolean deleteFront() {

        if(this.size == 0) 						//			means queue is empty, cannot delete any element.
          return false;

        if(this.size == 1) {					//			if there is only one element, then remove it(mark it as 0) and
          arr[rear] = 0;						
          rear = -1;							//			mark rear and front as -1(like it was initially)...
          front = -1;
          this.size --;						//			also decrease the size by 1(to 0)
          return true;						//			and return true to mark this operation as successful ...
        }

        if(front == this.capacity -1) {			//			if front is at last position, delete that position 
          arr[front] = 0;						//			and increment front by 1, so front will now be at 0
          front = 0;
          this.size --;						//          decrease the size by 1 marking it as empty
          return true;
        }
          arr[front] = 0;						//			if front is not at last, delete from the front and increment front by 1 
          front ++;		
          this.size --;						//			decrease the size by 1 marking it as empty
          return true;
      }

      /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
      public boolean deleteLast() {

        if(this.size == 0)						//		means queue is empty
          return false;	

        if(this.size == 1) {					//		if there is only one element, then remove it(mark it as 0) and
          arr[rear] = 0;						//		mark rear and front as -1(like it was initially)...
          rear = -1;
          front = -1;
          this.size --;						//		also decrease the size to 0
          return true;						//		and return true to mark this operation as successful ...
        }

        if(rear == 0) {							//		if there are more than one element in the array, 
          arr[rear] = 0;						//		and rear is at 0, then delete the element and reduce rear by 1
          rear = this.capacity - 1;			//		so basically rear will fall back to last position...
          this.size --;
        }else {
          arr[rear] = 0;						//		if rear is not at 0, then decrease rear by 1
          rear --;						
          this.size --;				
        }
        return true;							//		return true to mark the operation as successful
      }

      /** Get the front item from the deque. */
      public int getFront() {
        if(this.size == 0) {					//		if array is empty, return -1
          return -1;
        }
        return arr[front];						//		else return the element
      }

      /** Get the last item from the deque. */
      public int getRear() {						
        if(this.size == 0) {					//		if array is empty, return -1
          return -1;
        }
          return arr[rear];						//		else return the rear
      }

      /** Checks whether the circular deque is empty or not. */
      public boolean isEmpty() {					
          return (this.size == 0);				
      }

      /** Checks whether the circular deque is full or not. */
      public boolean isFull() {
          return (this.size == this.capacity);
      }
}

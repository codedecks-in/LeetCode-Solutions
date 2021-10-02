public class First_Last_Position_of_Element_in_Sorted_Array {
    /**
     * 0 ms, faster than 100.00%, Binary Search
     * if we get the target number, store it as it may or may not be the first occurrence
     * and set right = mid - 1 and search again.
     * Similar for last occurrence, left = mid + 1 and search again.
     */
    public int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.length - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return new int[]{first, last};
    }
}

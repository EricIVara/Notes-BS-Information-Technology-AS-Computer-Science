import java.util.LinkedList;

public class BinarySearch {

    // Method to perform binary search on a sorted array
    public static int search(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid; // Target found
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Target not found
    }

    // Method to perform binary search on a Linked List
    public static int search(LinkedList<Integer> linkedList, int target) {
        int low = 0;
        int high = linkedList.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (linkedList.get(mid) == target) {
                return mid; // Target found
            } else if (linkedList.get(mid) < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Target not found
    }
}
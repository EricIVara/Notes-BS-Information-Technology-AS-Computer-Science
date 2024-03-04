/**
 * File Name: SortAndSearch.java
 * Program Name: Sort and Binary Search Application
 * Author: Eric F. Vara
 * Course Name and Number: Data Structures and Algorithms: CPT307
 * Instructor’s Name: Joel Short
 * Date Submitted: 12, February 2024
 */

public class SortAndSearch {
    public static void main(String[] args) {

        int[] arr = {55, 40, 65, 25, 10, 5, 70, 50, 30, 15, 60, 35, 20, 45};
        int[] targets = {17, 45};

        QuickSort.sort(arr);

        for (int target : targets) {
            int index = BinarySearch.search(arr, target);

            if (index != -1) {
                System.out.println("Number " + target + " found at index: " + index);
            } else {
                System.out.println("\nNumber " + target + " not found in the array.");
            }
        }
    }
}
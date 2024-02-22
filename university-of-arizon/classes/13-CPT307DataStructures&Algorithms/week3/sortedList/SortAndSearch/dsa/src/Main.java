import java.util.LinkedList;

/**
 *
 * File Name: Main.java
 * Program Name: Sort and Binary Search Application
 * Author: Eric F. Vara
 * Course Name and Number: Data Structures and Algorithms: CPT307
 * Instructor’s Name: Joel Short
 * Date Submitted: 12, February 2024
 *
 *
 * STEP 1:
 * For this assignment, you were just hired as a junior software developer as part of a team
 * of developers for a software contracting company. Your company has just won a big contract
 * to develop a software application for the United States Department of Defense. The team
 * lead has tasked you with developing a Java program that uses a binary search algorithm
 * looking for the numbers 17 and 45 from an array. Because you do not have your secret
 * clearance yet, a senior developer will later take your code and modify it for the
 * requirements of the contract.
 *
 * In this coding assignment you will utilize the Java syntax and techniques you learned while
 * reviewing the required resources for Week 2. Include comments for each section of the
 * program. You may select appropriate variable names as long as proper Java syntax is used.
 * You will also submit your source code.
 *
 * STEP 2:
 * you will continue in your role as a junior software developer from your Week 2 assignment.
 * Your team is still working on the software contract that your company won for the United
 * States Department of Defense. The team lead has tasked you with developing a Java program
 * that uses a linked list to insert and remove items. Because you do not have your secret
 * clearance yet, a senior developer will later take your code and modify it for the
 * requirements of the contract.
 *
 * In this coding assignment you will utilize the Java syntax and techniques you learned while
 * reviewing the required resources for Week 3. You may select appropriate variable names as
 * long as proper Java syntax is used. You will also submit your source code.
 *
 */

public class Main {
    public static void main(String[] args) {

        // PART ONE:
        int[] arr = {55, 40, 65, 25, 10, 5, 70, 50, 30, 15, 60, 35, 20, 45};
        int[] targets = {17, 45};

        QuickSort.sort(arr);

        for (int target : targets) {
            int index = BinarySearch.search(arr, target);

            if (index != -1) {
                System.out.println("\nNumber " + target + " found at index: " + index + "\n");
            } else {
                System.out.println("\nNumber " + target + " not found in the array.\n");
            }
        }

        // PART TWO:
        LinkedList<Integer> myLink = new LinkedList<>();

        // Insert elements to the Linked list using a for loop
        for (int i = 5; i <= 60; i += 10) {
            myLink.add(i);
            myLink.add(i+5);
        }

        // Print current state of the Linked List
        System.out.println(myLink);

        // Remove elements to the Linked list using a for loop
        myLink.remove(0);
        myLink.remove(2);
        myLink.remove(5);
        myLink.remove(4);
        myLink.remove(2);
        myLink.remove(5);
        myLink.remove(4);


        // Print updated state of the Linked List
        System.out.println(myLink);
    }
}
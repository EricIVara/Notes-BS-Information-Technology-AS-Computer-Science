import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> myQueue = new LinkedList<>(); // Instantiate a LinkedList as a Queue to hold Integers

        // Use a for loop to add integers to the queue from 10 to 60, in increments of 10
        for (int i = 5; i <= 60; i += 10) {
            myQueue.offer(i);
            myQueue.add(i+5);
        }

        System.out.println(myQueue);

        // Peek at the head of the queue without removing it; returns null if the queue is empty
        System.out.println("Head (peek): " + myQueue.peek());

        // Poll an element from the head of the queue, removing it; returns null if the queue is empty
        System.out.println("Remove (poll): " + myQueue.poll());

        // Retrieve the head of the queue without removing it; throws an exception if the queue is empty
        System.out.println("Head (element): " + myQueue.element());

        // Print the final elements of the queue
        System.out.println("Final Queue: " + myQueue);
    }
}

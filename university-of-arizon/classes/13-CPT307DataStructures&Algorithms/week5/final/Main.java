import java.util.*;

/**
 * For this assignment, you will take on the role of a member of an IT department. Your chief technology officer (CTO)
 * has tasked your department with the replacement of IT equipment. Your manager does not want to buy a piece of
 * equipment based on the brand name alone. Rather, your manager wants to know the return on investment for each piece
 * in order to make a sound purchasing decision.
 *
 * - Your task is to write a Java program that will be used to calculate ROI on three different pieces of equipment
 * - sort it from best to least ROI
 * - The program must prompt the user to enter the brand name of the equipment, the gain, and the cost for each piece
 *   of equipment
 *
 * In this coding assignment, you will express searching and sorting algorithms to return the ROI best to least for
 * each piece of equipment. You must apply algorithmic design techniques in developing your program so that you can
 * ensure the user will receive a correctly sorted list. Utilize a LinkedList class to create the list. Include
 * comments for each section of the program. You may select variable names as long as proper Java syntax is used.
 *
 * File Name: Main.java
 * Program Name: CalculateROI
 * Author: Eric F. Vara
 * Course Name and Number: Data Structures and Algorithms: CPT307
 * Instructor’s Name: Joel Short
 * Date Submitted: 4, March 2024
 * **/

public class Main {
    public static void main(String[] args) {
        List<Map<String, String>> equipmentList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        for(int i = 0; i < 3; i++) {
            System.out.println("Enter the brand of equipment: ");
            String brandName = scanner.nextLine();

            System.out.println("Enter the gain of the equipment: ");
            String gain = scanner.nextLine();

            System.out.println("Enter the cost of the equipment: ");
            String cost = scanner.nextLine();

            Map<String, String> equipment = new HashMap<>();
            equipment.put("brandName", brandName);
            equipment.put("gain", gain);
            equipment.put("cost", cost);

            equipmentList.add(equipment);
        }

        EquipmentManager.sortEquipment(equipmentList);
        EquipmentManager.printSortedEquipment(equipmentList);

        System.out.println("Enter the brand name of the equipment to search: ");
        String searchBrandName = scanner.nextLine();

        Map<String,String> foundEquipment = EquipmentManager.searchEquipment(equipmentList, searchBrandName);
        if(foundEquipment != null) {
            System.out.println("Equipment found: " + foundEquipment);
        } else {
            System.out.println("Equipment not found");
        }
    }
}
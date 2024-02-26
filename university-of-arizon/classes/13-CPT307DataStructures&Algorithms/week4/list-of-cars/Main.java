import java.util.List;

/**
 *
 * Tree
 * Author: Eric F. Vara
 * Date submitted: 23, February 2024
 *
 * Utilized the tree function in Java by recreating the application that Brett Alistair Kromkamp (2015) has created.
 * In this Java app, I replaced the names that Kromkamp created with makes of cars. Your source
 * code must include the copyright information and comments that indicated you have modified the code.
 *
 * This Java tree structure application is inspired by the principles and concepts applied in Brett Alistair
 * Kromkamp's typed-tree project (2015). The original work can be found at
 * <a href="https://github.com/brettkromkamp/typed-tree">Kromkamp's typed-tree project (2015)</a>
 * License for the original work: MIT License
 * Acknowledgment is hereby made to Brett Alistair Kromkamp for the original idea and concepts.
 *
 **/

public class Main {
    public static void main(String[] args) {
        TreeNode<String> vehicles = new TreeNode<>("Vehicles");

        // Adding 10 car makes with 5 models each
        vehicles.addNodeWithChildren("Ford", List.of("F-150", "Mustang", "Explorer", "Fusion", "Escape"));
        vehicles.addNodeWithChildren("Toyota", List.of("Corolla", "Camry", "RAV4", "Highlander", "4Runner"));
        vehicles.addNodeWithChildren("Honda", List.of("Civic", "Accord", "CR-V", "Pilot", "Fit"));
        vehicles.addNodeWithChildren("Chevrolet", List.of("Silverado", "Malibu", "Equinox", "Impala", "Camaro"));
        vehicles.addNodeWithChildren("BMW", List.of("3 Series", "5 Series", "X5", "X3", "M3"));
        vehicles.addNodeWithChildren("Mercedes-Benz", List.of("C-Class", "E-Class", "S-Class", "GLC", "GLE"));
        vehicles.addNodeWithChildren("Audi", List.of("A4", "A6", "Q5", "Q7", "A8"));
        vehicles.addNodeWithChildren("Tesla", List.of("Model S", "Model 3", "Model X", "Model Y", "Roadster"));
        vehicles.addNodeWithChildren("Nissan", List.of("Altima", "Sentra", "Maxima", "Rogue", "Murano"));
        vehicles.addNodeWithChildren("Volkswagen", List.of("Golf", "Passat", "Tiguan", "Jetta", "Atlas"));

        // Print the tree
        printTree(vehicles, "");

        // Example of finding a node (demonstrating another method)
        TreeNode<String> foundNode = vehicles.findNode(vehicles, "Tesla");
        if (foundNode != null) {
            System.out.println("Found node: " + foundNode.getData());
            // Optionally, print all models of the found make
            printTree(foundNode, "  ");
        }
    }

    // Recursive method to print the tree
    public static void printTree(TreeNode<String> node, String prefix) {
        System.out.println(prefix + node.getData());
        for (TreeNode<String> child : node.getChildren()) {
            printTree(child, prefix + "  ");
        }
    }
}

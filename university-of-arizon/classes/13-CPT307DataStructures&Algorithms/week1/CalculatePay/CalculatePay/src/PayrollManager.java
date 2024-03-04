import java.util.Scanner;

/**
 * Payroll Calculation Program
 * Author: Eric F. Vara
 * Course: Data Structures and Algorithms
 * Instructor: Joel Short
 * Date submitted: 2, February 2024
 */
public class PayrollManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Assuming SimplePayrollCalculator is an implementation of PayrollCalculator
        // And PayrollCalculator, Employee classes are defined elsewhere as per previous context
        PayrollCalculator payrollCalculator = new HourlyPayrollCalculator();

        while (true) {
            System.out.println("\nOptions:");
            System.out.println("1. Enter employee's name");
            System.out.println("2. Exit the program");
            System.out.print("Please select an option: ");
            int option = scanner.nextInt();

            // Clear the buffer after reading an integer
            scanner.nextLine();

            if (option == 1) {
                System.out.print("Enter employee's name: ");
                String name = scanner.nextLine();

                System.out.print("Enter rate of pay: ");
                double rateOfPay = scanner.nextDouble();

                System.out.print("Enter hours worked: ");
                double hoursWorked = scanner.nextDouble();

                // Handle next line character after reading a double
                scanner.nextLine();

                Employee employee = new Employee(name, rateOfPay, hoursWorked);

                // Calculate payroll details using the payroll calculator
                payrollCalculator.calculateGrossPay(employee);
                payrollCalculator.calculateDeductions(employee);
                payrollCalculator.calculateNetPay(employee);

                // Displaying the output
                System.out.println("\nEmployee Details:");
                System.out.println("Name: " + employee.getName());
                System.out.println("Rate of Pay: $" + String.format("%.2f", employee.getRateOfPay()));
                System.out.println("Hours Worked: " + employee.getHoursWorked());
                System.out.println("Gross Pay: $" + String.format("%.2f", employee.getGrossPay()));
                System.out.println("Total Deductions: $" + String.format("%.2f", employee.getNetPay() - employee.getGrossPay()));
                System.out.println("Net Pay: $" + String.format("%.2f", employee.getNetPay()));
            } else if (option == 2) {
                System.out.println("Exiting Payroll Manager...");
                break;
            } else {
                System.out.println("Invalid option. Please try again.");
            }
        }

        scanner.close();
    }
}

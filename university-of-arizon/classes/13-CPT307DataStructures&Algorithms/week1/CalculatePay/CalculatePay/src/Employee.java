public class Employee {
    private String name;
    private double rateOfPay;
    private double hoursWorked;
    private double grossPay;
    private double[] deductions = new double[5]; // For federal tax, state tax, medicare, social security, unemployment insurance
    private double netPay;

    // Constructor
    public Employee(String name, double rateOfPay, double hoursWorked) {
        this.name = name;
        this.rateOfPay = rateOfPay;
        this.hoursWorked = hoursWorked;
    }

    // Getters
    public String getName() {
        return name;
    }

    public double getRateOfPay() {
        return rateOfPay;
    }

    public double getHoursWorked() {
        return hoursWorked;
    }

    public double getGrossPay() {
        return grossPay;
    }

    public double[] getDeductions() {
        return deductions;
    }

    public double getNetPay() {
        return netPay;
    }

    // Setters
    public void setGrossPay(double grossPay) {
        this.grossPay = grossPay;
    }

    public void setDeductions(double[] deductions) {
        this.deductions = deductions;
    }

    public void setNetPay(double netPay) {
        this.netPay = netPay;
    }
}

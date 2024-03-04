public class HourlyPayrollCalculator implements PayrollCalculator {

    @Override
    public void calculateGrossPay(Employee employee) {
        double hoursWorked = employee.getHoursWorked();
        double rateOfPay = employee.getRateOfPay();
        double grossPay;
        if (hoursWorked > 40) {
            double overtimeHours = hoursWorked - 40;
            grossPay = (overtimeHours * (rateOfPay * 1.5)) + (40 * rateOfPay);
        } else {
            grossPay = hoursWorked * rateOfPay;
        }
        employee.setGrossPay(grossPay);
    }

    @Override
    public void calculateDeductions(Employee employee) {
        double grossPay = employee.getGrossPay();
        double[] deductions = new double[5];
        deductions[0] = grossPay * 0.15; // Federal tax
        deductions[1] = grossPay * 0.0307; // State tax
        deductions[2] = grossPay * 0.0145; // Medicare
        deductions[3] = grossPay * 0.062; // Social Security
        deductions[4] = grossPay * 0.0007; // Unemployment Insurance
        employee.setDeductions(deductions);
    }

    @Override
    public void calculateNetPay(Employee employee) {
        double[] deductions = employee.getDeductions();
        double totalDeductions = 0;
        for (double deduction : deductions) {
            totalDeductions += deduction;
        }
        employee.setNetPay(employee.getGrossPay() - totalDeductions);
    }
}

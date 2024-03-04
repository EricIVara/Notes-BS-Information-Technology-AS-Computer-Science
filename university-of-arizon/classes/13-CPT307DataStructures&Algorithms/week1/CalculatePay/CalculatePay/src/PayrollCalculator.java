public interface PayrollCalculator {
    void calculateGrossPay(Employee employee);
    void calculateDeductions(Employee employee);
    void calculateNetPay(Employee employee);
}

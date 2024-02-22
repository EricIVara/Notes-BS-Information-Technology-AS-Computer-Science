
public class B extends A {		// continues from class A, must implement abstract methods

	private double interestRate;
	private double loanAmount;
	private double total;

	public B() {
		
	}
	
	public B(double loanAmount, double intrestRate) {
		this.loanAmount = loanAmount;
		this.interestRate = intrestRate;
	}

	public double getIntrestRate() {
		return interestRate;
	}

	public void setIntrestRate(double intrestRate) {
		this.interestRate = intrestRate;
	}
	
	public double getLoanAmount() {
		return loanAmount;
	}

	public void setLoanAmount(double loanAmount) {
		this.loanAmount = loanAmount;
	}
	
	public double getTotal() {
		return total;
	}

	public void setTotal(double total) {
		this.total = total;
	}
	
	@Override
	public double mortgagePerMonth() {
		return (loanAmount / 30) /12;
	}

	@Override
	public double interestPerMonth() {	// calculates interest per month
		return (interestRate * loanAmount) / 12;
	}
	
	@Override
	public double total() {
		return mortgagePerMonth() + interestPerMonth();
	}
	
	@Override
	public String printLoan() {
		return  "\nCreated on: " + getDateCreated() +
				"\nLoan Amount = $" + loanAmount +
				"\n30-year mortgage per month = $" + Math.round(mortgagePerMonth()) +
				"\nInterest Rate = " + interestRate +
  				"\nInterest per month = $" + Math.round(interestPerMonth()) +
  				"\nTotal monthly payment = $" + Math.round(total());
	}
	
}

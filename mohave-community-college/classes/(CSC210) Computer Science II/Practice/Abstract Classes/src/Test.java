import java.util.*;

public class Test {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		double convertInt;
		
		System.out.print("Please enter your loan amount: ");
		double loanAmount = scan.nextDouble();
		
		System.out.print("Please eneter the interest rate: ");
		int interestRate = scan.nextInt();
		convertInt = interestRate * .01;
		
		A aObject1 = new B(loanAmount, convertInt);
		System.out.println(aObject1.printLoan());
	}

}

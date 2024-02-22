// Can no longer create objects: A Object = new A(); because the class is abstract
import java.util.*;

public abstract class A {

	private Date dateCreated;			// imported from java.util.date
	// or java.util.Date dateCreated;	// if not imported
	
	public A() {						// created new default class constructor
		dateCreated = new Date();		// initialize current date
		// or dateCreated = new java.util.Date();		// if not imported
	}
	
	public Date getDateCreated() {				// returns dateCreated value
		return dateCreated;
	}
	
	public abstract double mortgagePerMonth();
	public abstract double interestPerMonth();		// creates a public abstract double method1 that is called and worked on in a separate class
	public abstract double total();
	public abstract String printLoan();			// creates a public abstract String method2 that is called and worked on in a separate class
}

class MyInteger {									// Main class MyInteger
	private int value;								// Created a private variable named value of the integer data type

	public MyInteger(int value) {					// Declared constructor to change private value 
	    this.value = value;							// Private value now equals the variable passed in
	}

	public int getValue() {							// Method that returns the value variable
		return value;
	}
	
	public static boolean isPrime(int number) {		// Pass in parameters and test to see if it a prime number
		for(int i = 2; i <= number / 2; i++) {		// Checks to see if numbers passed in have a remainder
			if(number % i == 0) {					// Returns false if the value has a remainder
				return false;
			}
		}
		if((number == 1) || (number == 2)) {		// filters through and returns true if prime numbers exist
			return true;
		}
		return true;
	}
	
	public boolean isPrime() {						// Returns true if the value is a prime number
		return isPrime(value);
	}
	
	public static boolean isPrime(MyInteger o) {	// Test the passed in value for prime numbers
	    return isPrime(o.getValue());
	}
	public boolean isEven() {						// Returns true if the value is an even number
	    return isEven(value);
	  }
	  
	public boolean isOdd() {						// Returns true if the value is a prime number
		return isOdd(value); 
	}
	  
	public static boolean isEven(int n) {			// Returns even numbers
	    return n % 2 == 0;
	}
	  
	public static boolean isOdd(int n) {			// Returns odd numbers
		return n % 2 != 0;
	}

	public static boolean isEven(MyInteger n) {		// Test the passed in value for even numbers
	    return isEven(n.getValue());
	}

	public boolean equals(int anotherNum) {			// Returns value if it doesn't equal anything
     	    return value == anotherNum;
	}

	public boolean equals(MyInteger o) {			// Returns value
	    return value == o.getValue();
	}

	public static int parseInt(char[] numbers) {			// Converts numeric characters to int values

	    int result = 0;
	    for (int i = 0; i < numbers.length; i++) {			// loops through numeric characters
	      result = result * 10 + (numbers[i] - '0');
	    }
	    return result;
	}
	
	public static int parseInt(String s) {					// Converts a string into an int value

		int result = 0;
	    for (int i = 0; i < s.length(); i++) {				// Loops through the string
	    	result = result * 10 + (s.charAt(i) - '0');
	    }
	    return result;
	}
}

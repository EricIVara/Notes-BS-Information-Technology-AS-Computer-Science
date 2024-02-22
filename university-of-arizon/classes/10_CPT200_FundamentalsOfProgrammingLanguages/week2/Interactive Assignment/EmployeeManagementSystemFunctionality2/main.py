# Initialize an empty list to store employee data
employees = []

# Collect data for employee 1
print("Enter data for employee 1:")
employeeName1 = input("Enter your name: ")
employeeSSN1 = input("Enter your SSN: ")
employeePhone1 = input("Enter your phone number: ")
salary1 = input("Enter your salary: ")
email1 = input("Enter your email: ")

# Add employee 1 data to the employees list
employees.append(
    [employeeName1, employeeSSN1, employeePhone1, salary1, email1])

# Collect data for employee 2
print("Enter data for employee 2:")
employeeName2 = input("Enter your name: ")
employeeSSN2 = input("Enter your SSN: ")
employeePhone2 = input("Enter your phone number: ")
salary2 = input("Enter your salary: ")
email2 = input("Enter your email: ")

# Add employee 2 data to the employees list
employees.append(
    [employeeName2, employeeSSN2, employeePhone2, salary2, email2])

# Collect data for employee 3
print("Enter data for employee 3:")
employeeName3 = input("Enter your name: ")
employeeSSN3 = input("Enter your SSN: ")
employeePhone3 = input("Enter your phone number: ")
salary3 = input("Enter your salary: ")
email3 = input("Enter your email: ")

# Add employee 3 data to the employees list
employees.append(
    [employeeName3, employeeSSN3, employeePhone3, salary3, email3])

# Collect data for employee 4
print("Enter data for employee 4:")
employeeName4 = input("Enter your name: ")
employeeSSN4 = input("Enter your SSN: ")
employeePhone4 = input("Enter your phone number: ")
salary4 = input("Enter your salary: ")
email4 = input("Enter your email: ")

# Add employee 4 data to the employees list
employees.append(
    [employeeName4, employeeSSN4, employeePhone4, salary4, email4])

# Collect data for employee 5
print("Enter data for employee 5:")
employeeName5 = input("Enter your name: ")
employeeSSN5 = input("Enter your SSN: ")
employeePhone5 = input("Enter your phone number: ")
salary5 = input("Enter your salary: ")
email5 = input("Enter your email: ")

# Add employee 5 data to the employees list
employees.append(
    [employeeName5, employeeSSN5, employeePhone5, salary5, email5])

# Prompt the user to select an index to view a specific employee's data
index = int(
    input(
        "Enter a value between 1 and 5 to print specific employee information: "
    )) - 1

# Validate the input and print the selected employee's data
if 0 <= index < 5:
  emp = employees[index]
  print(f"{emp[0]}, {emp[1]},{emp[2]},{emp[4]},${emp[3]}")
else:
  print("Invalid index! Please enter a value between 1 and 5.")

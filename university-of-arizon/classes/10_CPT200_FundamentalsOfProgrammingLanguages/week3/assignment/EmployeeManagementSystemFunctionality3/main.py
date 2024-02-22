# Initialize an empty list to store employee data and a counter for number of employees
employees = []
employee_count = 0  # This is our global counter


def collect_employee_data():
  """
    Function to collect data for a new employee.
    """
  global employee_count  # Access the global variable

  employeeName = input("Enter your name: ")
  employeeSSN = input("Enter your SSN: ")
  employeePhone = input("Enter your phone number: ")
  salary = input("Enter your salary: ")
  email = input("Enter your email: ")
  employees.append([employeeName, employeeSSN, employeePhone, salary, email])

  employee_count += 1  # Increment the counter when a new employee is added


def view_all_employees():
  """
    Function to view all employees in the system.
    """
  print("\nEmployee data:")
  for emp in employees:
    print(emp)


def main():
  global employee_count  # Access the global variable

  while True:
    print(f"\nThere are ({employee_count}) employees in the system.")

    print("Menu:")
    print("1. Add Employee")
    print("2. View all Employees")
    print("3. Exit")

    choice = input("Enter your choice (1/2/3): ")

    if choice == "1":
      collect_employee_data()
    elif choice == "2":
      view_all_employees()
    elif choice == "3":
      break
    else:
      print("Invalid choice. Please enter 1, 2, or 3.")


if __name__ == "__main__":
  main()

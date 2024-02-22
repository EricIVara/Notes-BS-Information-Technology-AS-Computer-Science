# Initialize an empty list to store employee data and a counter for the number of employees
employees = []
employee_count = 0  # This is our global counter



############### Function to collect data for a new employee ###############
def collect_employee_data():
    global employee_count  # Access the global variable

    # Gather employee information
    employeeName = input("Enter your name: ")
    employeeSSN = input("Enter your SSN: ")
    employeePhone = input("Enter your phone number: ")
    salary = input("Enter your salary: ")
    email = input("Enter your email: ")

    # Append employee data to the list
    employees.append([employeeName, employeeSSN, employeePhone, salary, email])

    # Increment the counter when a new employee is added
    employee_count += 1



############### Function to display all employees in the system ###############
def view_all_employees():
    print("\nEmployee data:")
    for emp in employees:
        print("-" * 70)  # Separator line
        print(f"{' ' * 28} {emp[0]} ")  # Print employee name
        print(f"SSN: {emp[1]}")
        print(f"Phone: {emp[2]}")
        print(f"Email: {emp[4]}")
        print(f"Salary: ${emp[3]}")
        print("-" * 70)  # Separator line



############### Function to update employee information ###############
def update_employee_data():
    ssn_to_update = input("Enter the SSN of the employee you want to update: ")
    for emp in employees:
        if emp[1] == ssn_to_update:
            print("Employee found. Please select the field to update:")
            print("1. Name")
            print("2. Phone")
            print("3. Email")
            print("4. Salary")
            choice = input("Enter your choice (1/2/3/4): ")
            if choice == "1":
                emp[0] = input("Enter the new name: ")
            elif choice == "2":
                emp[2] = input("Enter the new phone number: ")
            elif choice == "3":
                emp[4] = input("Enter the new email: ")
            elif choice == "4":
                emp[3] = input("Enter the new salary: ")
            else:
                print("Invalid choice. Please enter 1, 2, 3, or 4.")
            print("Employee information updated.")
            break
    else:
        print(f"No employee found with SSN {ssn_to_update}.")


############### Function to delete an employee ###############
def delete_employee():
    global employee_count  # Access the global variable
    ssn_to_delete = input("Enter the SSN of the employee you want to delete: ")
    for emp in employees:
        if emp[1] == ssn_to_delete:
            employees.remove(emp)
            employee_count -= 1  # Decrement the counter when an employee is deleted
            print(f"Employee with SSN {ssn_to_delete} has been deleted.")
            break
    else:
        print(f"No employee found with SSN {ssn_to_delete}.")


############### Function to search for an employee by SSN and display their information ###############
def search_employee_by_ssn():
    ssn_to_search = input("Enter the SSN of the employee you want to search: ")
    for emp in employees:
        if emp[1] == ssn_to_search:
            print("-" * 70)  # Separator line
            print(f"{' ' * 28} {emp[0]} ")  # Print employee name
            print(f"SSN: {emp[1]}")
            print(f"Phone: {emp[2]}")
            print(f"Email: {emp[4]}")
            print(f"Salary: ${emp[3]}")
            print("-" * 70)  # Separator line
            break
    else:
        print(f"No employee found with SSN {ssn_to_search}.")



############### Function to edit employee information ###############
def edit_employee_information():
    ssn_to_edit = input("Enter the SSN of the employee you want to edit: ")
    for emp in employees:
        if emp[1] == ssn_to_edit:
            print("Employee found. Please select the field to edit:")
            print("1. Name")
            print("2. Phone")
            print("3. Email")
            print("4. Salary")
            choice = input("Enter your choice (1/2/3/4): ")
            if choice == "1":
                emp[0] = input("Enter the new name: ")
            elif choice == "2":
                emp[2] = input("Enter the new phone number: ")
            elif choice == "3":
                emp[4] = input("Enter the new email: ")
            elif choice == "4":
                emp[3] = input("Enter the new salary: ")
            else:
                print("Invalid choice. Please enter 1, 2, 3, or 4.")
            print("Employee information updated.")
            break
    else:
        print(f"No employee found with SSN {ssn_to_edit}.")



############### Main function to run the Employee Management System ###############
def main():
    global employee_count

    while True:
        print(f"\nThere are ({employee_count}) employees in the system.")

        print("Menu:")
        print("1. Add Employee")
        print("2. View all Employees")
        print("3. Search Employee by SSN")
        print("4. Edit Employee Information")
        print("5. Delete Employee")
        print("6. Exit")

        choice = input("Enter your choice (1/2/3/4/5/6): ")

        if choice == "1":
            collect_employee_data()
        elif choice == "2":
            view_all_employees()
        elif choice == "3":
            search_employee_by_ssn()
        elif choice == "4":
            edit_employee_information()
        elif choice == "5":
            delete_employee()
        elif choice == "6":
            break
        else:
            print("Invalid choice. Please enter 1, 2, 3, 4, 5, or 6.")

if __name__ == "__main__":
    main()
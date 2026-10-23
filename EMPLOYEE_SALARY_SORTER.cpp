
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store employee details
struct Employee {
    int id;
    string name;
    float salary;
};

// Function to add a new employee
void addEmployee(vector<Employee>& emp) {
    Employee e;

    cout << "\nEnter Employee ID: ";
    cin >> e.id;

    cout << "Enter Employee Name: ";
    cin >> ws;
    getline(cin, e.name);

    cout << "Enter Employee Salary: ";
    cin >> e.salary;

    emp.push_back(e);
    cout << "\nEmployee added successfully!\n";
}

// Function to display all employees
void display(vector<Employee> emp) {
    if (emp.empty()) {
        cout << "\nNo employee records found!\n";
        return;
    }

    cout << "\n";
    cout << left << setw(10) << "ID"
         << setw(22) << "Name" << "Salary\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < emp.size(); i++) {
        cout << left << setw(10) << emp[i].id
             << setw(22) << emp[i].name
             << fixed << setprecision(2)
             << emp[i].salary << endl;
    }
}

// Function to sort employees using Bubble Sort
void sortSalary(vector<Employee> emp, bool ascending) {
    if (emp.empty()) {
        cout << "\nPlease add employees first!\n";
        return;
    }

    int n = emp.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool condition = ascending
                ? emp[j].salary > emp[j + 1].salary
                : emp[j].salary < emp[j + 1].salary;

            if (condition) {
                Employee temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    cout << "\n--- Sorted Employee Salary List ---\n";
    cout << left << setw(10) << "ID"
         << setw(22) << "Name"
         << setw(15) << "Salary" << "Rank\n";

    for (int i = 0; i < n; i++) {
        int rank = ascending ? n - i : i + 1;

        cout << left << setw(10) << emp[i].id
             << setw(22) << emp[i].name
             << setw(15) << fixed << setprecision(2)
             << emp[i].salary << rank << endl;
    }
}

// Function to search for an employee by ID
void searchEmployee(vector<Employee> emp) {
    int id;
    cout << "\nEnter Employee ID to search: ";
    cin >> id;

    for (int i = 0; i < emp.size(); i++) {
        if (emp[i].id == id) {
            cout << "\nEmployee Found!\n";
            cout << "Name: " << emp[i].name << endl;
            cout << "Salary: Rs. " << emp[i].salary << endl;
            return;
        }
    }

    cout << "\nEmployee not found!\n";
}

// Main function
int main() {
    vector<Employee> employees;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "       EMPLOYEE SALARY SORTER\n";
        cout << "====================================\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Sort Salary (Ascending)\n";
        cout << "4. Sort Salary (Descending)\n";
        cout << "5. Show Salary Rankings\n";
        cout << "6. Search Employee\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(employees);
                break;

            case 2:
                display(employees);
                break;

            case 3:
                sortSalary(employees, true);
                break;

            case 4:
                sortSalary(employees, false);
                break;

            case 5:
                sortSalary(employees, false);
                break;

            case 6:
                searchEmployee(employees);
                break;

            case 7:
                cout << "\nThank you for using the program!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
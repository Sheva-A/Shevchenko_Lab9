#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct Employee {
    string name;
    tm hireDate;
    double salary;
    string department;
};

int calculateExperience(const tm& hireDate) {
    time_t now = time(0);
    tm currentDate{};
    localtime_s(&currentDate, &now);

    int years = currentDate.tm_year - hireDate.tm_year;
    int months = currentDate.tm_mon - hireDate.tm_mon;
    int days = currentDate.tm_mday - hireDate.tm_mday;

    return years;
}

void filterEmployeesByDepartmentAndExperience(const vector<Employee>& employees, const string& department) {
    cout << "Employee from " << department << " with more than five years of experience:" << endl;
    bool found = false;
    for (const auto& employee : employees) {
        if (employee.department == department && calculateExperience(employee.hireDate) > 5) {
            cout << "Name: " << employee.name
                << ", Salary: " << employee.salary
                << ", Hire Date: " << (employee.hireDate.tm_mday) << "."
                << (employee.hireDate.tm_mon + 1) << "."
                << (employee.hireDate.tm_year + 1900)
                << endl;
        }
    }
}

int main() {
    int numEmployees = 5;
    vector<Employee> employees(numEmployees);

    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for Employee " << i + 1 << endl;
        cout << "Name: ";
        cin >> employees[i].name;

        cout << "Hire Year: ";
        cin >> employees[i].hireDate.tm_year;
        employees[i].hireDate.tm_year -= 1900;

        cout << "Hire Month: ";
        cin >> employees[i].hireDate.tm_mon;
        employees[i].hireDate.tm_mon -= 1;

        cout << "Hire Day: ";
        cin >> employees[i].hireDate.tm_mday;

        cout << "Salary: ";
        cin >> employees[i].salary;

        cout << "Depatrment: ";
        cin >> employees[i].department;
    }

    for (int i = 0; i < numEmployees; ++i) {
        int experience = calculateExperience(employees[i].hireDate);
        cout << "Employee " << employees[i].name << " has " << experience << " years of experience." << endl;
    }

    string department;
    cout << "Enter name of the department: ";
    cin >> department;
    filterEmployeesByDepartmentAndExperience(employees, department);

    return 0;
}

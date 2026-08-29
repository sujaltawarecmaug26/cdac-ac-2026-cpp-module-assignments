#include <iostream>
#include <iomanip>

using namespace std;

class Employee {

private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:


    Employee() {
        employeeCount++;
        empId = 1000 + employeeCount;
        isActive = true;
    }


    bool setName(const string& n) {

        if (n.empty()) {
            cout << "ERROR: Name must be required." << endl;
            return false;
        }

        name = n;
        return true;
    }


    bool setDepartment(const string& dept) {

        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations") {

            department = dept;
            return true;
        }

        cout << "ERROR: '" << dept
             << "' is not a registered department." << endl;

        return false;
    }


    bool setGrade(char g) {

        if (g == 'A' ||
            g == 'B' ||
            g == 'C' ||
            g == 'D') {

            grade = g;
            return true;
        }

        cout << "ERROR: Invalid grade '" << g
             << "'. Accepted values: A, B, C, D." << endl;

        return false;
    }


    bool setBasicSalary(double salary) {

        if (salary > 10000 && salary < 500000) {

            basicSalary = salary;
            return true;
        }

        cout << "ERROR: Salary must be between "
             << "Rs.10,000 and Rs.5,00,000. "
             << "Value rejected." << endl;

        return false;
    }


    void deactivate() {
        isActive = false;
    }


    int getEmpId() const {
        return empId;
    }


    string getName() const {
        return name;
    }


    string getDepartment() const {
        return department;
    }


    char getGrade() const {
        return grade;
    }


    double getBasicSalary() const {
        return basicSalary;
    }


    bool getIsActive() const {
        return isActive;
    }

    double computeAllowances() const {

        if (grade == 'A') {
            return basicSalary * 0.40;
        }
        else if (grade == 'B') {
            return basicSalary * 0.30;
        }
        else if (grade == 'C') {
            return basicSalary * 0.20;
        }
        else if (grade == 'D') {
            return basicSalary * 0.10;
        }

        return 0;
    }


    double computeGrossSalary() const {

        return basicSalary + computeAllowances();
    }


    double computeTax() const {

        double grossSalary = computeGrossSalary();

        if (grossSalary <= 50000) {

            return 0;
        }

        else if (grossSalary <= 100000) {

            return (grossSalary - 50000) * 0.10;
        }

        else {

            return 5000 +
                   (grossSalary - 100000) * 0.20;
        }
    }


    double computeNetSalary() const {

        return computeGrossSalary() - computeTax();
    }


    void acceptDetails() {

        string tempName;
        string tempDepartment;
        char tempGrade;
        double tempSalary;

        cout << "\nEnter Employee Details" << endl;


        bool isNameValid = false;

        while (!isNameValid) {

            cout << "Enter name: ";

            cin >> ws;
            getline(cin, tempName);

            isNameValid = setName(tempName);
        }



        bool isDepartmentValid = false;

        while (!isDepartmentValid) {

            cout << "Enter department: ";

            getline(cin, tempDepartment);

            isDepartmentValid =
                setDepartment(tempDepartment);
        }


        bool isGradeValid = false;

        while (!isGradeValid) {

            cout << "Enter grade: ";

            cin >> tempGrade;

            isGradeValid = setGrade(tempGrade);
        }


        bool isSalaryValid = false;

        while (!isSalaryValid) {

            cout << "Enter basic salary: ";

            cin >> tempSalary;

            isSalaryValid =
                setBasicSalary(tempSalary);
        }
    }




    void printPayslip() const {

        cout << fixed << setprecision(2);

        cout << "\n============================================" << endl;
        cout << "EMPLOYEE PAYSLIP — AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID      : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Grade       : " << grade << endl;

        cout << "Status      : "
             << (isActive ? "Active" : "Inactive")
             << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Basic Salary     : Rs. "
             << basicSalary << endl;

        cout << "Allowances       : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary     : Rs. "
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction    : Rs. "
             << computeTax() << endl;

        cout << "Net Salary       : Rs. "
             << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }


    static int getEmployeeCount() {

        return employeeCount;
    }
};


int Employee::employeeCount = 0;



int main() {

    Employee e1;

    Employee* e2 = new Employee();

    Employee* e3 = new Employee();


    e1.acceptDetails();

    e2->acceptDetails();

    e3->acceptDetails();


    // These cause compiler errors because
    // empId and basicSalary are private.

    // e1.empId = 999;
    // e1.basicSalary = -1000;


    e1.printPayslip();

    e2->printPayslip();

    e3->printPayslip();



    e3->deactivate();

    if (!e3->getIsActive()) {

        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }


    cout << "\nTotal Employees : "
         << Employee::getEmployeeCount()
         << endl;



    delete e2;

    delete e3;


    return 0;
}


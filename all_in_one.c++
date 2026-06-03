#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>
using namespace std;
// Subject names
const string SUBJECTS[5] = {"Physics", "Chemistry", "Mathematics", "English", "Computer Science"};
const int MAX_STUDENTS = 100;
// ANSI Escape Codes for Premium Console Styling
const string RESET   = "\033[0m";
const string BOLD    = "\033[1m";
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN    = "\033[36m";
const string WHITE   = "\033[37m";
const string BG_BLUE = "\033[44m";
// ==========================================
// 1. CLASS DEFINITION & CONSTRUCTORS
// ==========================================
class Student {
private:
    int studentID;
    string name;
    int age;
    string gender;
    string branch;
    int semester;
    string mobileNumber;
    int marks[5];
public:
    // Default Constructor
    Student() {
        studentID = 0;
        name = "";
        age = 0;
        gender = "";
        branch = "";
        semester = 1;
        mobileNumber = "";
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
    }
    // Parameterized Constructor
    Student(int id, string n, int a, string g, string b, int sem, string mob, int m[]) {
        studentID = id;
        name = n;
        age = a;
        gender = g;
        branch = b;
        semester = sem;
        mobileNumber = mob;
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
    }
    // Getters
    int getStudentID() const { return studentID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getBranch() const { return branch; }
    int getSemester() const { return semester; }
    string getMobileNumber() const { return mobileNumber; }
    int getMark(int index) const { return marks[index]; }
    // Setters
    void setStudentID(int id) { studentID = id; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(string g) { gender = g; }
    void setBranch(string b) { branch = b; }
    void setSemester(int sem) { semester = sem; }
    void setMobileNumber(string mob) { mobileNumber = mob; }
    void setMarks(int m[]) {
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }
    }
    // Result Calculation Functions
    int calculateTotal() const {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        return total;
    }
    double calculateAverage() const {
        return calculateTotal() / 5.0;
    }
    double calculatePercentage() const {
        return (calculateTotal() / 500.0) * 100.0;
    }
    string calculateGrade() const {
        double pct = calculatePercentage();
        if (pct >= 90.0) return "A+";
        if (pct >= 80.0) return "A";
        if (pct >= 70.0) return "B";
        if (pct >= 60.0) return "C";
        if (pct >= 50.0) return "D";
        return "F";
    }
};
// ==========================================
// 2. INPUT VALIDATION UTILITY FUNCTIONS
// ==========================================
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int getValidatedInteger(string prompt, int minVal = numeric_limits<int>::min(), int maxVal = numeric_limits<int>::max()) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= minVal && value <= maxVal) {
                clearInputBuffer();
                return value;
            } else {
                cout << RED << " [!] Error: Value must be between " << minVal << " and " << maxVal << "." << RESET << endl;
            }
        } else {
            cout << RED << " [!] Error: Invalid numerical input. Please enter an integer." << RESET << endl;
            clearInputBuffer();
        }
    }
}
string getValidatedString(string prompt, bool allowEmpty = false) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        // Trim leading/trailing spaces if needed, but a simple check is fine here
        if (!allowEmpty && value.empty()) {
            cout << RED << " [!] Error: Field cannot be empty." << RESET << endl;
        } else {
            return value;
        }
    }
}
string getValidatedMobile(string prompt) {
    string mob;
    while (true) {
        mob = getValidatedString(prompt);
        bool allDigits = true;
        for (char c : mob) {
            if (!isdigit(c)) {
                allDigits = false;
                break;
            }
        }
        if (mob.length() == 10 && allDigits) {
            return mob;
        } else {
            cout << RED << " [!] Error: Mobile number must be exactly 10 digits." << RESET << endl;
        }
    }
}
// ==========================================
// 3. RECURSIVE UTILITY DECLARATIONS
// ==========================================
long long recursiveFactorial(int n) {
    if (n <= 1) return 1;
    return n * recursiveFactorial(n - 1);
}
int recursiveFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}
long long recursiveSumOfN(int n) {
    if (n <= 0) return 0;
    return n + recursiveSumOfN(n - 1);
}
// Call by Value and Call by Reference Demonstrations
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// ==========================================
// 4. MAIN COLLEGE SYSTEM STATE & IMPLEMENTATION
// ==========================================
Student students[MAX_STUDENTS];
int studentCount = 0;
// Linear Search Helper
int findStudentIndexByID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getStudentID() == id) {
            return i; // Index found
        }
    }
    return -1; // Not found
}
// Print single student details using normal print
void printStudentDetailsTableHead() {
    cout << WHITE << string(125, '-') << RESET << endl;
    cout << left << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(6) << "Age"
         << setw(8) << "Gender"
         << setw(10) << "Branch"
         << setw(6) << "Sem"
         << setw(14) << "Mobile"
         << setw(8) << "Phys"
         << setw(8) << "Chem"
         << setw(8) << "Math"
         << setw(8) << "Engl"
         << setw(8) << "CS"
         << setw(8) << "Total"
         << setw(7) << "Grade" << endl;
    cout << WHITE << string(125, '-') << RESET << endl;
}
void printStudentRow(const Student& s) {
    cout << left << setw(8) << s.getStudentID()
         << setw(20) << s.getName()
         << setw(6) << s.getAge()
         << setw(8) << s.getGender()
         << setw(10) << s.getBranch()
         << setw(6) << s.getSemester()
         << setw(14) << s.getMobileNumber()
         << setw(8) << s.getMark(0)
         << setw(8) << s.getMark(1)
         << setw(8) << s.getMark(2)
         << setw(8) << s.getMark(3)
         << setw(8) << s.getMark(4)
         << setw(8) << s.calculateTotal()
         << setw(7) << s.calculateGrade() << endl;
}
// Option 1: Add Student
void addStudent() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "             ADD NEW STUDENT                 " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount >= MAX_STUDENTS) {
        cout << RED << " [!] Error: Student database is full (Max 100 students reached)." << RESET << endl;
        return;
    }
    int id;
    while (true) {
        id = getValidatedInteger(" Enter Student ID: ", 1, 999999);
        if (findStudentIndexByID(id) != -1) {
            cout << RED << " [!] Error: A student with ID " << id << " already exists. Try a unique ID." << RESET << endl;
        } else {
            break;
        }
    }
    string name = getValidatedString(" Enter Student Name: ");
    int age = getValidatedInteger(" Enter Age (Min 16): ", 16, 120);
    string gender = getValidatedString(" Enter Gender (Male/Female/Other): ");
    string branch = getValidatedString(" Enter Branch (e.g. CSE, ECE, ME): ");
    int sem = getValidatedInteger(" Enter Semester (1-8): ", 1, 8);
    string mobile = getValidatedMobile(" Enter 10-digit Mobile Number: ");
    int marks[5];
    cout << "\n Enter marks for 5 subjects (0 to 100):" << endl;
    for (int i = 0; i < 5; i++) {
        marks[i] = getValidatedInteger("   " + SUBJECTS[i] + ": ", 0, 100);
    }
    // Insert student using parameterized constructor
    students[studentCount] = Student(id, name, age, gender, branch, sem, mobile, marks);
    studentCount++;
    cout << GREEN << "\n [✓] Student Record Added Successfully! (Total Students: " << studentCount << ")" << RESET << endl;
}
// Option 2: Display All Students
void displayAllStudents() {
    cout << BOLD << CYAN << "\n=========================================================================================================================" << RESET << endl;
    cout << BOLD << CYAN << "                                                  REGISTERED STUDENTS LIST                                               " << RESET << endl;
    cout << BOLD << CYAN << "=========================================================================================================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] No students in the system yet. Please add a student." << RESET << endl;
        return;
    }
    printStudentDetailsTableHead();
    for (int i = 0; i < studentCount; i++) {
        printStudentRow(students[i]);
    }
    cout << WHITE << string(125, '-') << RESET << endl;
}
// Option 3: Search Student by ID (Linear Search)
void searchStudentByID() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "             SEARCH STUDENT BY ID            " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID to search: ", 1, 999999);
    
    // Perform Linear Search
    int index = findStudentIndexByID(id);
    if (index != -1) {
        cout << GREEN << "\n [✓] Student Record Found!" << RESET << endl;
        printStudentDetailsTableHead();
        printStudentRow(students[index]);
        cout << WHITE << string(125, '-') << RESET << endl;
    } else {
        cout << RED << " [!] Student with ID " << id << " not found." << RESET << endl;
    }
}
// Option 4: Update Student Details
void updateStudentDetails() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "            UPDATE STUDENT DETAILS           " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID to update: ", 1, 999999);
    int index = findStudentIndexByID(id);
    if (index == -1) {
        cout << RED << " [!] Student with ID " << id << " not found." << RESET << endl;
        return;
    }
    cout << YELLOW << "\n Current details for ID " << id << ":" << RESET << endl;
    printStudentDetailsTableHead();
    printStudentRow(students[index]);
    cout << WHITE << string(125, '-') << RESET << endl;
    cout << "\n Enter new details (Press Enter to keep current value):" << endl;
    
    // To allow keeping current values, we can read strings and check if empty.
    string inputStr;
    
    // Update Name
    cout << " Enter New Name [" << students[index].getName() << "]: ";
    getline(cin, inputStr);
    if (!inputStr.empty()) {
        students[index].setName(inputStr);
    }
    // Update Age
    while (true) {
        cout << " Enter New Age [" << students[index].getAge() << "]: ";
        getline(cin, inputStr);
        if (inputStr.empty()) break;
        try {
            int newAge = stoi(inputStr);
            if (newAge >= 16 && newAge <= 120) {
                students[index].setAge(newAge);
                break;
            } else {
                cout << RED << "   [!] Age must be >= 16." << RESET << endl;
            }
        } catch (...) {
            cout << RED << "   [!] Please enter a valid number." << RESET << endl;
        }
    }
    // Update Gender
    cout << " Enter New Gender [" << students[index].getGender() << "]: ";
    getline(cin, inputStr);
    if (!inputStr.empty()) {
        students[index].setGender(inputStr);
    }
    // Update Branch
    cout << " Enter New Branch [" << students[index].getBranch() << "]: ";
    getline(cin, inputStr);
    if (!inputStr.empty()) {
        students[index].setBranch(inputStr);
    }
    // Update Semester
    while (true) {
        cout << " Enter New Semester [" << students[index].getSemester() << "]: ";
        getline(cin, inputStr);
        if (inputStr.empty()) break;
        try {
            int newSem = stoi(inputStr);
            if (newSem >= 1 && newSem <= 8) {
                students[index].setSemester(newSem);
                break;
            } else {
                cout << RED << "   [!] Semester must be between 1 and 8." << RESET << endl;
            }
        } catch (...) {
            cout << RED << "   [!] Please enter a valid number." << RESET << endl;
        }
    }
    // Update Mobile
    while (true) {
        cout << " Enter New Mobile [" << students[index].getMobileNumber() << "]: ";
        getline(cin, inputStr);
        if (inputStr.empty()) break;
        bool allDigits = true;
        for (char c : inputStr) {
            if (!isdigit(c)) allDigits = false;
        }
        if (inputStr.length() == 10 && allDigits) {
            students[index].setMobileNumber(inputStr);
            break;
        } else {
            cout << RED << "   [!] Mobile must be exactly 10 digits." << RESET << endl;
        }
    }
    // Update Marks
    cout << "\n Update Marks (Press Enter to keep current mark):" << endl;
    int currentMarks[5];
    for (int i = 0; i < 5; i++) {
        currentMarks[i] = students[index].getMark(i);
        while (true) {
            cout << "   " << SUBJECTS[i] << " [" << currentMarks[i] << "]: ";
            getline(cin, inputStr);
            if (inputStr.empty()) break;
            try {
                int markVal = stoi(inputStr);
                if (markVal >= 0 && markVal <= 100) {
                    currentMarks[i] = markVal;
                    break;
                } else {
                    cout << RED << "     [!] Marks must be 0-100." << RESET << endl;
                }
            } catch (...) {
                cout << RED << "     [!] Please enter a valid integer." << RESET << endl;
            }
        }
    }
    students[index].setMarks(currentMarks);
    cout << GREEN << "\n [✓] Student Details Updated Successfully!" << RESET << endl;
}
// Option 5: Delete Student
void deleteStudent() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "             DELETE STUDENT RECORD           " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID to delete: ", 1, 999999);
    int index = findStudentIndexByID(id);
    if (index == -1) {
        cout << RED << " [!] Student with ID " << id << " not found." << RESET << endl;
        return;
    }
    // Confirm deletion
    cout << RED << " Are you sure you want to delete student: " << students[index].getName() << " (ID: " << id << ")? [y/n]: " << RESET;
    string confirm;
    cin >> confirm;
    clearInputBuffer();
    if (confirm == "y" || confirm == "Y") {
        // Shift remaining students to the left
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << GREEN << " [✓] Student Record Deleted Successfully!" << RESET << endl;
    } else {
        cout << YELLOW << " [!] Deletion cancelled." << RESET << endl;
    }
}
// Option 6: Calculate Result
void calculateResult() {
    cout << BOLD << CYAN << "\n=======================================================================================" << RESET << endl;
    cout << BOLD << CYAN << "                                    STUDENT REPORT CARDS                               " << RESET << endl;
    cout << BOLD << CYAN << "=======================================================================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] No students in the system." << RESET << endl;
        return;
    }
    cout << WHITE << string(90, '-') << RESET << endl;
    cout << left << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Total Marks"
         << setw(10) << "Average"
         << setw(14) << "Percentage"
         << setw(10) << "Grade"
         << setw(16) << "Result Status" << endl;
    cout << WHITE << string(90, '-') << RESET << endl;
    for (int i = 0; i < studentCount; i++) {
        double pct = students[i].calculatePercentage();
        string grade = students[i].calculateGrade();
        string status = (grade != "F") ? (GREEN + "PASS" + RESET) : (RED + "FAIL" + RESET);
        cout << left << setw(8) << students[i].getStudentID()
             << setw(20) << students[i].getName()
             << setw(12) << students[i].calculateTotal()
             << setw(10) << fixed << setprecision(2) << students[i].calculateAverage()
             << setw(14) << to_string(pct).substr(0, 5) + "%"
             << setw(10) << grade
             << status << endl;
    }
    cout << WHITE << string(90, '-') << RESET << endl;
}
// Option 7: Find Class Topper
void findClassTopper() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "             FIND CLASS TOPPER               " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] No students in the database." << RESET << endl;
        return;
    }
    int highestTotal = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].calculateTotal() > highestTotal) {
            highestTotal = students[i].calculateTotal();
        }
    }
    cout << GREEN << "\n [✓] Class Topper(s) with Highest Total of " << highestTotal << "/500:" << RESET << endl;
    printStudentDetailsTableHead();
    for (int i = 0; i < studentCount; i++) {
        if (students[i].calculateTotal() == highestTotal) {
            printStudentRow(students[i]);
        }
    }
    cout << WHITE << string(125, '-') << RESET << endl;
}
// Option 8: Find Subject Topper
void findSubjectTopper() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "            FIND SUBJECT TOPPER              " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] No students in the database." << RESET << endl;
        return;
    }
    cout << " Choose Subject:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  " << (i + 1) << ". " << SUBJECTS[i] << endl;
    }
    int choice = getValidatedInteger(" Enter choice (1-5): ", 1, 5) - 1;
    int highestMark = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getMark(choice) > highestMark) {
            highestMark = students[i].getMark(choice);
        }
    }
    cout << GREEN << "\n [✓] Topper(s) in " << SUBJECTS[choice] << " with score " << highestMark << "/100:" << RESET << endl;
    printStudentDetailsTableHead();
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getMark(choice) == highestMark) {
            printStudentRow(students[i]);
        }
    }
    cout << WHITE << string(125, '-') << RESET << endl;
}
// ==========================================
// STRING MANIPULATION FUNCTIONS (Option 9-11)
// ==========================================
string reverseString(const string &str) {
    string rev = str;
    int len = rev.length();
    for (int i = 0; i < len / 2; i++) {
        // Swap front and back characters using pointers/references or temporary variables
        char temp = rev[i];
        rev[i] = rev[len - i - 1];
        rev[len - i - 1] = temp;
    }
    return rev;
}
bool isPalindromeString(const string &str) {
    string normalized = "";
    for (char c : str) {
        if (!isspace(c)) {
            normalized += tolower(c);
        }
    }
    string rev = reverseString(normalized);
    return (normalized == rev);
}
int countVowels(const string &str) {
    int vowels = 0;
    for (char c : str) {
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            vowels++;
        }
    }
    return vowels;
}
void reverseStudentName() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "             REVERSE STUDENT NAME            " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID: ", 1, 999999);
    int idx = findStudentIndexByID(id);
    if (idx == -1) {
        cout << RED << " [!] Student not found." << RESET << endl;
        return;
    }
    string originalName = students[idx].getName();
    string reversed = reverseString(originalName);
    cout << "\n Student Name  : " << BOLD << originalName << RESET << endl;
    cout << GREEN << " Reversed Name : " << BOLD << reversed << RESET << endl;
}
void checkPalindromeName() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "            CHECK PALINDROME NAME            " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID: ", 1, 999999);
    int idx = findStudentIndexByID(id);
    if (idx == -1) {
        cout << RED << " [!] Student not found." << RESET << endl;
        return;
    }
    string name = students[idx].getName();
    bool status = isPalindromeString(name);
    cout << "\n Student Name: " << BOLD << name << RESET << endl;
    if (status) {
        cout << GREEN << " [✓] Yes! The name is a Palindrome." << RESET << endl;
    } else {
        cout << RED << " [X] No! The name is NOT a Palindrome." << RESET << endl;
    }
}
void countVowelsInName() {
    cout << BOLD << CYAN << "\n=============================================" << RESET << endl;
    cout << BOLD << CYAN << "             COUNT VOWELS IN NAME            " << RESET << endl;
    cout << BOLD << CYAN << "=============================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID: ", 1, 999999);
    int idx = findStudentIndexByID(id);
    if (idx == -1) {
        cout << RED << " [!] Student not found." << RESET << endl;
        return;
    }
    string name = students[idx].getName();
    int count = countVowels(name);
    cout << "\n Student Name : " << BOLD << name << RESET << endl;
    cout << GREEN << " Vowel Count  : " << BOLD << count << " vowels" << RESET << endl;
}
// ==========================================
// POINTER DEMONSTRATION FUNCTIONS (Option 12)
// ==========================================
void printStudentUsingPointer(const Student* sPtr) {
    if (sPtr == nullptr) return;
    
    // Access details using pointer arrow operator `->` or dereference `(*sPtr)`
    cout << CYAN << "  ID            : " << RESET << sPtr->getStudentID() << endl;
    cout << CYAN << "  Name          : " << RESET << sPtr->getName() << endl;
    cout << CYAN << "  Age           : " << RESET << sPtr->getAge() << endl;
    cout << CYAN << "  Gender        : " << RESET << sPtr->getGender() << endl;
    cout << CYAN << "  Branch        : " << RESET << sPtr->getBranch() << endl;
    cout << CYAN << "  Semester      : " << RESET << sPtr->getSemester() << endl;
    cout << CYAN << "  Mobile Number : " << RESET << sPtr->getMobileNumber() << endl;
    cout << CYAN << "  Marks         : " << RESET;
    for (int i = 0; i < 5; i++) {
        cout << SUBJECTS[i] << ":" << sPtr->getMark(i) << " ";
    }
    cout << endl;
    cout << CYAN << "  Total Marks   : " << RESET << sPtr->calculateTotal() << " / 500" << endl;
    cout << CYAN << "  Percentage    : " << RESET << fixed << setprecision(2) << sPtr->calculatePercentage() << "%" << endl;
    cout << CYAN << "  Grade         : " << RESET << sPtr->calculateGrade() << endl;
}
void displayDataUsingPointers() {
    cout << BOLD << CYAN << "\n==================================================" << RESET << endl;
    cout << BOLD << CYAN << "        DISPLAY DETAILS USING POINTERS            " << RESET << endl;
    cout << BOLD << CYAN << "==================================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] The database is empty." << RESET << endl;
        return;
    }
    int id = getValidatedInteger(" Enter Student ID: ", 1, 999999);
    int idx = findStudentIndexByID(id);
    if (idx == -1) {
        cout << RED << " [!] Student not found." << RESET << endl;
        return;
    }
    // Declare a pointer to the student object
    const Student* studentPtr = &students[idx];
    cout << GREEN << "\n [✓] Displaying Student details via Pointer variable (addr: " << studentPtr << "):" << RESET << endl;
    cout << WHITE << string(55, '-') << RESET << endl;
    printStudentUsingPointer(studentPtr);
    cout << WHITE << string(55, '-') << RESET << endl;
}
// ==========================================
// 2D MATRIX OPERATIONS ON MARKS (Option 13)
// ==========================================
void performMatrixOperations() {
    cout << BOLD << CYAN << "\n==================================================================================" << RESET << endl;
    cout << BOLD << CYAN << "                           2D MATRIX OPERATIONS ON MARKS                          " << RESET << endl;
    cout << BOLD << CYAN << "==================================================================================" << RESET << endl;
    if (studentCount == 0) {
        cout << YELLOW << " [!] Add students first to populate the matrix." << RESET << endl;
        return;
    }
    // Declare 2D Marks Matrix
    int marksMatrix[MAX_STUDENTS][5];
    // Populate matrix with marks of all active students
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < 5; j++) {
            marksMatrix[i][j] = students[i].getMark(j);
        }
    }
    cout << "\n Populated Marks Matrix [Students (" << studentCount << ") x Subjects (5)]:" << endl;
    cout << WHITE << string(80, '-') << RESET << endl;
    cout << left << setw(18) << "Student Name";
    for (int j = 0; j < 5; j++) {
        cout << right << setw(10) << SUBJECTS[j].substr(0, 8);
    }
    cout << right << setw(12) << "Row Sum" << endl;
    cout << WHITE << string(80, '-') << RESET << endl;
    // Display matrix with Row Sum (Total marks per student)
    // demonstrates nested loops
    int absoluteHighest = -1;
    int absoluteLowest = 101;
    string highestStudent = "", lowestStudent = "";
    string highestSubject = "", lowestSubject = "";
    
    int rowSums[MAX_STUDENTS] = {0};
    int colSums[5] = {0};
    double grandTotal = 0.0;
    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(18) << (students[i].getName().length() > 15 ? students[i].getName().substr(0, 15) + "..." : students[i].getName());
        for (int j = 0; j < 5; j++) {
            int score = marksMatrix[i][j];
            cout << right << setw(10) << score;
            
            // Computations
            rowSums[i] += score;
            colSums[j] += score;
            grandTotal += score;
            if (score > absoluteHighest) {
                absoluteHighest = score;
                highestStudent = students[i].getName();
                highestSubject = SUBJECTS[j];
            }
            if (score < absoluteLowest) {
                absoluteLowest = score;
                lowestStudent = students[i].getName();
                lowestSubject = SUBJECTS[j];
            }
        }
        cout << right << setw(12) << GREEN << rowSums[i] << RESET << endl;
    }
    cout << WHITE << string(80, '-') << RESET << endl;
    // Column Sums display
    cout << left << setw(18) << "Col Sum";
    for (int j = 0; j < 5; j++) {
        cout << right << setw(10) << colSums[j];
    }
    cout << endl;
    // Column Averages display
    cout << left << setw(18) << "Subject Avg";
    for (int j = 0; j < 5; j++) {
        double avg = (double)colSums[j] / studentCount;
        cout << right << setw(10) << fixed << setprecision(1) << avg;
    }
    cout << endl;
    cout << WHITE << string(80, '-') << RESET << endl;
    // Highest, Lowest, and Average of entire matrix
    double overallAverage = grandTotal / (studentCount * 5.0);
    cout << "\n Matrix Analysis Results:" << endl;
    cout << GREEN << "  [✓] Highest Mark Stored: " << BOLD << absoluteHighest << RESET << " (By " << highestStudent << " in " << highestSubject << ")" << endl;
    cout << RED << "  [✓] Lowest Mark Stored : " << BOLD << absoluteLowest << RESET << " (By " << lowestStudent << " in " << lowestSubject << ")" << endl;
    cout << BLUE << "  [✓] Overall Class Avg  : " << BOLD << fixed << setprecision(2) << overallAverage << "/100" << RESET << " across all subjects." << endl;
}
// ==========================================
// 5. UTILITY SUB-MENU (Option 14)
// ==========================================
void showUtilityMenu() {
    int choice;
    do {
        cout << BOLD << MAGENTA << "\n=============================================" << RESET << endl;
        cout << BOLD << MAGENTA << "            RECURSION & UTILITY MENU         " << RESET << endl;
        cout << BOLD << MAGENTA << "=============================================" << RESET << endl;
        cout << "  1. Factorial of a Number (Recursive)" << endl;
        cout << "  2. Fibonacci Series (Recursive)" << endl;
        cout << "  3. Sum of N Natural Numbers (Recursive)" << endl;
        cout << "  4. Swap Operation (Call by Value vs Ref vs Pointer)" << endl;
        cout << "  5. Back to Main Menu" << endl;
        cout << MAGENTA << "---------------------------------------------" << RESET << endl;
        choice = getValidatedInteger(" Enter choice (1-5): ", 1, 5);
        switch (choice) {
            case 1: {
                cout << BOLD << "\n--- Recursive Factorial ---" << RESET << endl;
                int n = getValidatedInteger(" Enter a number (0-20): ", 0, 20);
                long long fact = recursiveFactorial(n);
                cout << GREEN << " [✓] Factorial of " << n << " is: " << BOLD << fact << RESET << endl;
                break;
            }
            case 2: {
                cout << BOLD << "\n--- Recursive Fibonacci Series ---" << RESET << endl;
                int n = getValidatedInteger(" Enter count of elements to print (1-35): ", 1, 35);
                cout << GREEN << " [✓] Fibonacci series of " << n << " elements: " << BOLD << endl;
                for (int i = 0; i < n; i++) {
                    cout << recursiveFibonacci(i) << " ";
                }
                cout << RESET << endl;
                break;
            }
            case 3: {
                cout << BOLD << "\n--- Recursive Sum of N Numbers ---" << RESET << endl;
                int n = getValidatedInteger(" Enter a positive integer N (1-5000): ", 1, 5000);
                long long sum = recursiveSumOfN(n);
                cout << GREEN << " [✓] Sum of first " << n << " natural numbers is: " << BOLD << sum << RESET << endl;
                break;
            }
            case 4: {
                cout << BOLD << "\n--- Swap Demonstration (Call by Value vs Reference vs Pointer) ---" << RESET << endl;
                int x = getValidatedInteger(" Enter Value for X: ");
                int y = getValidatedInteger(" Enter Value for Y: ");
                cout << "\n Initial Values in Main: X = " << x << ", Y = " << y << endl;
                // 1. Call by Value
                int xVal = x, yVal = y;
                swapByValue(xVal, yVal);
                cout << YELLOW << " After Swap by Value (Inside Main)     : X = " << xVal << ", Y = " << yVal 
                     << "  --> (NO CHANGE)" << RESET << endl;
                // 2. Call by Reference
                int xRef = x, yRef = y;
                swapByReference(xRef, yRef);
                cout << GREEN << " After Swap by Reference (Inside Main) : X = " << xRef << ", Y = " << yRef 
                     << "  --> (SWAPPED)" << RESET << endl;
                // 3. Swap by Pointer
                int xPtr = x, yPtr = y;
                swapByPointer(&xPtr, &yPtr);
                cout << BLUE << " After Swap by Pointer (Inside Main)   : X = " << xPtr << ", Y = " << yPtr 
                     << "  --> (SWAPPED)" << RESET << endl;
                break;
            }
            case 5:
                cout << YELLOW << " Returning to Main Menu..." << RESET << endl;
                break;
        }
    } while (choice != 5);
}
// ==========================================
// 6. MAIN PROGRAM ENTRY & LOOP
// ==========================================
int main() {
    // Adding some mock data so the system is not completely blank when run
    int m1[5] = {85, 90, 92, 78, 95}; // Total: 440, Avg: 88, Grade: A
    students[0] = Student(101, "Aman Sharma", 19, "Male", "CSE", 2, "9876543210", m1);
    
    int m2[5] = {72, 80, 85, 88, 79}; // Total: 404, Avg: 80.8, Grade: A
    students[1] = Student(102, "Nitin Kumar", 20, "Male", "ECE", 4, "9988776655", m2);
    
    int m3[5] = {95, 96, 98, 92, 99}; // Total: 480, Avg: 96, Grade: A+
    students[2] = Student(103, "Sofia Sen", 18, "Female", "CSE", 1, "9123456789", m3);
    studentCount = 3;
    int choice;
    do {
        cout << BOLD << BLUE << "\n=========================================================================" << RESET << endl;
        cout << BOLD << BLUE << "                 SMART COLLEGE MANAGEMENT SYSTEM                         " << RESET << endl;
        cout << BOLD << BLUE << "=========================================================================" << RESET << endl;
        cout << "  1. Add Student Record" << endl;
        cout << "  2. Display All Students" << endl;
        cout << "  3. Search Student by ID (Linear Search)" << endl;
        cout << "  4. Update Student Details" << endl;
        cout << "  5. Delete Student Record" << endl;
        cout << "  6. Calculate and Display Results (Total, Avg, %, Grade)" << endl;
        cout << "  7. Find Class Topper" << endl;
        cout << "  8. Find Subject Topper" << endl;
        cout << "  9. Reverse Student Name" << endl;
        cout << "  10. Check Palindrome Name" << endl;
        cout << "  11. Count Vowels in Name" << endl;
        cout << "  12. Display Student Details via Pointer" << endl;
        cout << "  13. 2D Marks Matrix Operations" << endl;
        cout << "  14. Open Recursion & Swap Utility Menu" << endl;
        cout << "  15. Exit System" << endl;
        cout << BLUE << "=========================================================================" << RESET << endl;
        
        choice = getValidatedInteger(" Enter your choice (1-15): ", 1, 15);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudentByID();
                break;
            case 4:
                updateStudentDetails();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                calculateResult();
                break;
            case 7:
                findClassTopper();
                break;
            case 8:
                findSubjectTopper();
                break;
            case 9:
                reverseStudentName();
                break;
            case 10:
                checkPalindromeName();
                break;
            case 11:
                countVowelsInName();
                break;
            case 12:
                displayDataUsingPointers();
                break;
            case 13:
                performMatrixOperations();
                break;
            case 14:
                showUtilityMenu();
                break;
            case 15:
                cout << GREEN << BOLD << "\n Thank you for using the Smart College Management System. Goodbye!\n" << RESET << endl;
                break;
            default:
                cout << RED << " [!] Unexpected Error: Invalid choice." << RESET << endl;
                break;
        }
    } while (choice != 15);
    return 0;
}

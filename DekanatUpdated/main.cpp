#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Subject;
class Student;
class Group;
class Teacher;
class Admin;

enum class Role {
    None,
    Student,
    Teacher,
    Admin
};

// Function to convert role name to Role enum value
Role getRoleFromString(const string& roleName) {
    if (roleName == "student") {
        return Role::Student;
    }
    else if (roleName == "teacher") {
        return Role::Teacher;
    }
    else if (roleName == "admin") {
        return Role::Admin;
    }
    else {
        return Role::None;
    }
}
class Subject {
private:
    string name;
public:
    Subject(string subjectName) : name(subjectName) {}

    string getName() {
        return name;
    }
    bool operator<(const Subject& other) const {
        return name < other.name;
    }

};


class Student {
private:
    Role role = Role::Student;
    string name;
    string password;
    string group;
    map<Subject, vector<int>> marks;
public:
    Student(string studentName, string studentPassword, string studentGroup, map<Subject, vector<int>> m )
            : name(studentName), password(studentPassword), group(studentGroup), marks(m) {}

    string getName() {
        return name;
    }

    bool operator==(const Student& other) const {
        return name == other.name;
    }
    bool operator<(const Student& other) const {
        return name < other.name;
    }
    bool authorize(const string& studentName, const string& studentPassword, const string& studentGroup) {
        if (role != Role::Student) {
            cout << "Authorization failed. Invalid role." << endl;
            return false;
        }

        if (name != studentName || password != studentPassword || group != studentGroup) {
            cout << "Authorization failed. Invalid credentials." << endl;
            return false;
        }

        cout << "Authorization successful. Welcome, " << name << "!" << endl;
        return true;
    }
    string getPassword() {
        return password;
    }

    string getGroup() {
        return group;
    }

    map<Subject, vector<int>>& getMarks() {
        return marks;
    }

    void viewMarks() {
        cout << "Marks for " << name << ":" << endl;
        for (auto& marksEntry : marks) {
            Subject subject = marksEntry.first;
            vector<int> marksForSubject = marksEntry.second;

            cout << "Subject: " << subject.getName() << ", Marks: ";
            for (int mark : marksForSubject) {
                cout << mark << " ";
            }
            cout << endl;
        }
    }

    void viewMarksBySubject(Subject& subject) {
        vector<int> marksForSubject = marks[subject];

        cout << "Marks for " << name << " in " << subject.getName() << ": ";
        for (int mark : marksForSubject) {
            cout << mark << " ";
        }
        cout << endl;
    }

    void updateMarks(Subject& subject, int Mark) {
        marks[subject].push_back(Mark);

    }



};

class Group {
private:
    string name;
    vector<Student> students;
    vector<Subject> subjects;
public:
    Group(string groupName, vector<Subject> subj) : name(groupName), subjects(subj) {}

    string getName() {
        return name;
    }
    vector<Subject>& getSubjects() {
        return subjects;
    }

    vector<Student>& getStudents() {
        return students;
    }

    void addStudent(Student& student) {
        students.push_back(student);
    }
    void printStudents() {
        cout << "Students in " << name << ":" << endl;
        for (Student& student : students) {
            cout << student.getName() << endl;
        }
    }

};

class Teacher {
private:
    Role role = Role::Teacher;
    string name;
    string password;
    Subject subject;
public:
    Teacher(string teacherName, string teacherPassword, Subject teacherSubject)
            : name(teacherName), password(teacherPassword), subject(teacherSubject) {}

    string getName() {
        return name;
    }

    string getPassword() {
        return password;
    }

    Subject& getSubject() {
        return subject;
    }

    bool authorize(const string& teacherName, const string& teacherPassword) {
        if (role != Role::Teacher) {
            cout << "Authorization failed. Invalid role." << endl;
            return false;
        }

        if (name != teacherName || password != teacherPassword) {
            cout << "Authorization failed. Invalid credentials." << endl;
            return false;
        }

        cout << "Authorization successful. Welcome, " << name << "!" << endl;
        return true;
    }


    void addMarks(Student& student, int Mark) {
        student.updateMarks(subject, Mark);
    }
    void printStudentsWithMarks(Group& group) {
        for (Student& student : group.getStudents()) {
            student.viewMarksBySubject(subject);
        }
    }


};

class Admin {
private:
    string name;
    string password;
    Role role = Role::Admin;
public:
    Admin(string adminName, string adminPassword) : name(adminName), password(adminPassword) {}

    string getName() {
        return name;
    }

    string getPassword() {
        return password;
    }

    void addStudent(Group& group, Student& student) {
        group.addStudent(student);
    }

    void deleteStudent(Group& group, Student& student) {
        vector<Student>& students = group.getStudents();
        students.erase(remove(students.begin(), students.end(), student), students.end());

        // You can also clear the marks of the student if needed
        map<Subject, vector<int>>& marks = student.getMarks();
        for (auto& marksEntry : marks) {
            marksEntry.second.clear();
        }
    }
    bool authorize(const string& adminName, const string& adminPassword) {
        if (role != Role::Admin) {
            cout << "Authorization failed. Invalid role." << endl;
            return false;
        }

        if (name != adminName || password != adminPassword) {
            cout << "Authorization failed. Invalid credentials." << endl;
            return false;
        }

        cout << "Authorization successful. Welcome, " << name << "!" << endl;
        return true;
    }


};

Group findGroup(vector<Group> groups, string groupname) {
    for (auto& elem : groups) {
        if (elem.getName() == groupname) {
            return elem;
        }
    }
    cout << "There is no such group." << endl;
    return Group("", {});
}

Student findStudent(vector<Student> students, string Stname) {
    for (auto& elem : students) {
        if (elem.getName() == Stname) {
            return elem;
        }
    }
    cout << "There is no such student." << endl;
    return Student("", "", "", {});
}

Teacher findTeacher(vector<Teacher> teachers, string Tchname) {
    for (auto& elem : teachers) {
        if (elem.getName() == Tchname) {
            return elem;
        }
    }
    cout << "There is no such teacher." << endl;
    return Teacher("", "", Subject(""));
}

Admin findAdmin(vector<Admin> admins, string Admname) {
    for (auto& elem : admins) {
        if (elem.getName() == Admname) {
            return elem;
        }
    }
    cout << "There is no such admin." << endl;
}



int main() {
    // Creating subjects
    Subject math("Mathematics");
    Subject physics("Physics");
    Subject chemistry("Chemistry");

    vector<Subject> group1;
    group1.push_back(math);
    group1.push_back(physics);
    group1.push_back(chemistry);

    // Creating group
    Group group("Group1", group1);
    vector<Group> groups;


    map<Subject, vector<int>> marks1;
    vector<int> temp = { 10, 2, 7 };
    vector<int> temp2 = { 1, 2, 3 };
    vector<int> temp3 = { 4, 5, 6 };
    marks1.emplace(math, temp);
    marks1.emplace(physics, temp2);
    marks1.emplace(chemistry, temp3);

    map<Subject, vector<int>> marks2;
    marks2.emplace(math, temp2);
    marks2.emplace(physics, temp2);
    marks2.emplace(chemistry, temp3);

    map<Subject, vector<int>> marks3;
    marks3.emplace(math, temp2);
    marks3.emplace(physics, temp2);
    marks3.emplace(chemistry, temp3);
    // Creating students
    Student student1("John", "pass1", "Group1", marks1);
    Student student2("Jane", "pass2", "Group1", marks2);
    Student student3("Mike", "pass3", "Group1", marks3);

    // Adding students to the group
    group.addStudent(student1);
    group.addStudent(student2);
    group.addStudent(student3);
    groups.push_back(group);
    // Creating a teacher
    Teacher teacher1("Smith", "teacherpass", math);
    vector<Teacher> teachers = { teacher1 };
    // Creating an admin
    Admin admin1("Admin", "adminpass");
    vector<Admin> admins = { admin1 };
    // Admin adding a student
    Student student4("Sarah", "pass4", "Group1", marks1);

    // Teacher adding marks for a subject

    vector<Student> students = { student1, student2, student3, student4 };


    // Authorization process
    string roleInput;
    bool exitProgram = false;
    while (!exitProgram) {
        cout << "Enter your role (student, teacher, or admin) or enter 'close' to exit: ";
        cin >> roleInput;

        if (roleInput == "close") {
            cout << "Closing the program. Goodbye!" << endl;
            exitProgram = true;
            break;
        }
        Role role = getRoleFromString(roleInput);
        if (role == Role::Student) {
            string studentName;
            string studentPassword;
            string studentGroup;
            cout << "Enter your name: ";
            cin >> studentName;
            cout << "Enter your password: ";
            cin >> studentPassword;
            cout << "Enter your group: ";
            cin >> studentGroup;


            Student student = findStudent(students, studentName);
            if (student.authorize(studentName, studentPassword, studentGroup)) {
                Group g = findGroup(groups, studentGroup);
                while (true) {
                    cout << "Choose action (1 - view marks, 2 - view marks by subject)" << endl;
                    string act;
                    cin >> act;
                    if (act == "1") {
                        student.viewMarks();
                        cout << "1 - Continue or 2 - to go to menu:" << endl;
                        string a;
                        cin >> a;
                        if (a == "2") {
                            break;
                        }
                    }
                    else if (act == "2") {
                        cout << "Enter name of subject:" << endl;
                        string sub;
                        cin >> sub;
                        bool flag = true;
                        for (auto& elem : g.getSubjects()) {
                            if (sub == elem.getName()) {
                                student.viewMarksBySubject(elem);
                                flag = false;
                                break;
                            }

                        }
                        if (flag) {
                            cout << "There is no such subject." << endl;
                        }
                        cout << "1 - Continue or 2 - to go to menu:" << endl;
                        string a;
                        cin >> a;
                        if (a == "2") {
                            break;
                        }

                    }
                    else {
                        cout << "There is no such action." << endl;
                    }
                }
            }
            else {
                cout << "There is no such student." << endl;
            }
        }
        else if (role == Role::Teacher) {
            string teacherName;
            string teacherPassword;
            cout << "Enter your name: ";
            cin >> teacherName;
            cout << "Enter your password: ";
            cin >> teacherPassword;

            Teacher teacher = findTeacher(teachers, teacherName);
            if (teacher.authorize(teacherName, teacherPassword)) {
                bool exit = false;
                while (true) {
                    cout << "What do you want (1 - add marks to a student, 2 - view marks of the group):" << endl;
                    string act;
                    cin >> act;
                    if (act == "1") {
                        cout << "Which group you want to add marks" << endl;
                        string g;
                        cin >> g;
                        Group gr = findGroup(groups, g);
                        if (gr.getName() == "") {
                            continue;
                        }
                        cout << "Which student you want to add marks" << endl;
                        string st;
                        cin >> st;
                        Student stud = findStudent(gr.getStudents(), st);
                        if (stud.getName() == "") {
                            continue;
                        }
                        cout << "Mark:" << endl;
                        int mark;
                        cin >> mark;
                        teacher.addMarks(stud, mark);
                        stud.viewMarksBySubject(teacher.getSubject());
                        cout << "1 - Continue or 2 - to go to menu:" << endl;
                        string a;
                        cin >> a;
                        if (a == "2") {
                            break;
                        }
                    }
                    else if (act == "2") {
                        cout << "Which group you want to see marks:" << endl;
                        string gr;
                        cin >> gr;
                        Group g = findGroup(groups, gr);
                        if (g.getName() == "") {
                            continue;
                        }
                        teacher.printStudentsWithMarks(g);
                        cout << "1 - Continue or 2 - to go to menu:" << endl;
                        string a;
                        cin >> a;
                        if (a == "2") {
                            break;

                        }
                    }
                    else {
                        cout << "There is no such action." << endl;
                    }
                }
            }
            else {
                cout << "There is no such teacher." << endl;
            }
        }
        else if (role == Role::Admin) {
            string adminName;
            string adminPassword;

            cout << "Enter your name: ";
            cin >> adminName;
            cout << "Enter your password: ";
            cin >> adminPassword;

            Admin admin = findAdmin(admins, adminName);
            if (admin.authorize(adminName, adminPassword)) {
                while (true) {
                    cout << "Choose action (1 - add student, 2 - delete student)" << endl;
                    string act;
                    cin >> act;
                    if (act == "1") {
                        string name;
                        string psw;
                        string gr;
                        vector<int> temp = {};
                        map<Subject, vector<int>> temMarks;

                        cout << "Enter name:" << endl;
                        cin >> name;
                        cout << "Enter password:" << endl;
                        cin >> psw;
                        cout << "Enter group:" << endl;
                        cin >> gr;
                        Group g = findGroup(groups, gr);
                        if (g.getName() == "") {
                            continue;
                        }
                        for (auto& elem : g.getSubjects()) {
                            temMarks.emplace(elem, temp);
                        }
                        Student st(name, psw, gr, temMarks);
                        admin.addStudent(g, st);
                        g.printStudents();
                        cout << "1 - Continue or 2 - to go to menu:" << endl;
                        string a;
                        cin >> a;
                        if (a == "2") {
                            break;
                        }
                    }
                    else if (act == "2") {
                        cout << "Enter group of student you want to delete" << endl;
                        string gr;
                        cin >> gr;
                        Group g = findGroup(groups, gr);
                        if (g.getName() == "") {
                            continue;
                        }
                        cout << "Enter student you want to delete" << endl;
                        string nameSt;
                        cin >> nameSt;
                        Student st = findStudent(students, nameSt);
                        if (st.getName() == "") {
                            continue;
                        }
                        admin.deleteStudent(g, st);
                        g.printStudents();
                        cout << "1 - Continue or 2 - to go to menu:" << endl;
                        string a;
                        cin >> a;
                        if (a == "2") {
                            break;
                        }
                    }
                    else {
                        cout << "There is no such action." << endl;
                    }
                }
            }
            else {
                cout << "There is no such admin." << endl;
            }
        }
        else {
            cout << "Invalid role entered." << endl;
        }
    }

    return 0;
}
// Developed by Hesham Elshafey
// Version 1.0



/////////// Notice, A large amount of functions in this class loops around students or items and calls function from these classes that actually dispalys the information
/////////// or creates the object. This approach was followed to decouple the classes as much as possible.
#include "Course.h"
#include "Color.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "bits/stdc++.h"

using namespace std;
//This function checks if the student user want to delete exists.
int Course::CheckStudentForDeletion(string a)
{
    for (size_t i = 0; i < student.size(); i++)
    {
        string checker = student[i].studentIDcopier();
        if (checker == a)
        {
            return 1;
        }
    }
    return 0;
}
//returns course name, Used to access the specific needed coruse from the parsing class.
string Course::coursenamecopier()
{
    return name;
}

void Course::createcourse(string a)
{
    name = a;
}
//Exactly the same like above, initial object and current objects are separated to prevent any unexpected overlapping.
void Course::initalcreatecourse(string a)
{
    name = a;
}
//initialy, no students exist and the first part only works, after that the second part checks if the student already exist, otherwise creates it.
void Course::addstudenttocourse(string first, string second, string id)
{

    if (student.size() == 0)
    {
        Student obj{};
        obj.addstudentStudent(first, second, id, name, items);
        student.push_back(obj);
        cout << ">> student has been created." << endl;
    }
    else
    {
        for (size_t i = 0; i < student.size(); i++)
        {
            string checker = student[i].studentIDcopier();
            if (checker == id)
            {
                cout << ">> Student already exist" << endl;
                return;
            }
        }
        Student obj{};
        obj.addstudentStudent(first, second, id, name, items);
        student.push_back(obj);
        cout << ">> student has been created." << endl;
    }
}

void Course::liststudentcourse()
{
    vector<string> data;
    cout << "\n"
         << name << " Students:" << endl;
    for (size_t x = 0; x < student.size(); x++)
    {
        data = student[x].studentdatastringcreation(); // this function return vector of strings that contains all student data.
        string combine = data[2] + ",  " + data[1]; // This line combines the last name and first name with the comma between them in single string to make formatting the output easier.
        cout << left << setw(20) << combine;
        cout << data[3] << endl;// prints the ID.
    }
}
//Writes student data to file
void Course::writestudentdate()
{
    vector<string> data;
    ofstream file;
    file.open("students2.csv", ofstream::out | ofstream::app);
    for (size_t x= 0; x < student.size(); x++)
    {
        data = student[x].studentdatastringcreation();
        for (int y = 0; y < 4; y++)
        {
            if (y < 3)
            {
                file << "\"" << data[y] << "\",";
            }
            else if (y == 3)
            {
                file << "\"" << data[y] << "\"" << endl; //this line prevent the function from outputing comma at the very end of each line.
                break;
            }
        }
    }
    file.close();
    return;
}
//Calls function that access student grades from the Student class to write the grades file.
void Course::writestudentgradestofileC()
{
    for (size_t i = 0; i < student.size(); i++)
    {
        student[i].writestudentgradestofileS();
    }
}
//Add item to course. The item existance is checked in the item class
void Course::additemtocourse(string a, int b)
{

    Gradeditem obji{};
    obji.additemtoitems(a, b, name);
    cout << ">> item is created." << endl;
    for (size_t i = 0; i < student.size(); i++)
    {
        student[i].createitemobject(obji);
    }
    items.push_back(obji);
}
// write item data to file.
// Note the file is opened in appended mode because the headline of the files are written in another function before calling this one.
void Course::writeitemdata()
{
    vector<string> data;
    ofstream file;
    file.open("items.csv", ofstream::out | ofstream::app);
    for (size_t i = 0; i < items.size(); i++)
    {
        data = items[i].itemdatacopier();
        for (int y = 0; y < 3; y++)
        {
            if (y < 2)
            {
                file << "\"" << data[y] << "\",";
            }
            else if (y == 2)
            {
                file << "\"" << data[y] << "\"" << endl;
                break;
            }
        }
    }
    file.close();
    return;
}
//This function at the beginning of the program reads from the file line by line and pass the line to formatting function.
void Course::intialstudentobject()
{
    ifstream filefff("students2.csv");
    string readingthefile;
    string reader2;
    vector<string> data;
    filefff.is_open();
    filefff.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (getline(filefff, readingthefile))
    {
        reader2 = commaspacereplace(readingthefile, string(","), string(" ")); // this function replaces each comma with space, making sstream extraction easier.
        intialstudentobjectspliter(reader2);
    }
    filefff.close();
}
//This function removes the double quotes around data and extract each word in a string. It checks if the extracted course name is the same name of the course and starts
//creating student objects.
void Course::intialstudentobjectspliter(string a)
{
    string first{};
    string second{};
    string id{};
    string name15{};
    stringstream spliter12(a);
    spliter12 >> name15 >> first >> second >> id;
    first.erase(remove(first.begin(), first.end(), '"'), first.end());
    second.erase(remove(second.begin(), second.end(), '"'), second.end());
    id.erase(remove(id.begin(), id.end(), '"'), id.end());
    name15.erase(remove(name15.begin(), name15.end(), '"'), name15.end());
    if (name15 == name)
    {
        Student obj;
        obj.addstudentStudent(first, second, id, name15, items);
        student.push_back(obj);
    }
}
// This system of functions is exactly the same like student objects but for item objects.
void Course::intialitemobject()
{
    ifstream file404("items.csv");
    string readingthefile;
    string reader2;
    vector<string> data;
    file404.is_open();
    file404.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (getline(file404, readingthefile))
    {
        reader2 = commaspacereplace(readingthefile, string(","), string(" "));
        intialitemobjectspliter(reader2);
    }
    file404.close();
}

void Course::intialitemobjectspliter(string a)
{
    string nameofitem{};
    string maxpoints{};
    string belongingcourse{};
    stringstream spliter(a);
    spliter >> belongingcourse >> nameofitem >> maxpoints;
    nameofitem.erase(remove(nameofitem.begin(), nameofitem.end(), '"'), nameofitem.end());
    maxpoints.erase(remove(maxpoints.begin(), maxpoints.end(), '"'), maxpoints.end());
    belongingcourse.erase(remove(belongingcourse.begin(), belongingcourse.end(), '"'), belongingcourse.end());
    int points{0};
    if (maxpoints.empty() != 1)
    {
        points = stoi(maxpoints);
    }
    if (belongingcourse == name)
    {

        Gradeditem obj200{};
        obj200.additemtoitems(nameofitem, points, belongingcourse);
        for (size_t i = 0; i < student.size(); i++)
        {
            student[i].createitemobject(obj200);
        }
        items.push_back(obj200);
    }
}
// Same idea for student grades file.
void Course::initialstudentgradesC()
{
    ifstream file("grades.csv");
    string readingthefile;
    string reader2;
    file.is_open();
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (getline(file, readingthefile))
    {
        reader2 = commaspacereplace(readingthefile, string(","), string(" "));
        initialstudentgradesCsplitter(reader2);
    }
    file.close();
}

void Course::initialstudentgradesCsplitter(string a)
{
    string nameofcourse{};
    string studentID{};
    string nameofitem{};
    string studentscore{};
    stringstream spliter(a);
    spliter >> nameofcourse >> studentID >> nameofitem >> studentscore;
    nameofcourse.erase(remove(nameofcourse.begin(), nameofcourse.end(), '"'), nameofcourse.end());
    studentID.erase(remove(studentID.begin(), studentID.end(), '"'), studentID.end());
    nameofitem.erase(remove(nameofitem.begin(), nameofitem.end(), '"'), nameofitem.end());
    studentscore.erase(remove(studentscore.begin(), studentscore.end(), '"'), studentscore.end());
    int studentint{0};
    if (studentscore.empty() != 1)
    {
        studentint = stoi(studentscore);
    }
    if (nameofcourse == name)
    {
        for (size_t i = 0; i < student.size(); i++)
        {

            if (studentID == student[i].studentIDcopier())
            {
                student[i].initialstudentgrades(nameofitem, studentint);
            }
        }
    }
}
//This is the formatting function that replaces each comma with space and return the string back.
string Course::commaspacereplace(string a, const string &from, const string &to)
{
    size_t start_pos = 0;
    while ((start_pos = a.find(from, start_pos)) != std::string::npos)
    {
        a.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return a;
}
//Lists all items.
void Course::listitems()
{
    vector<string> data;
    cout << "\n"
         << name << "   Graded Items" << endl;
    for (size_t i = 0; i < items.size(); i++)
    {
        data = items[i].itemdatacopier();
        for (size_t j = 1; j < 3; j++)
        {
            cout << left << setw(10) << data[j] << "  " << right;
        }
        cout << "\n";
    }
    cout << left << Color::setColor(Color::black, Color::green) << setw(12) << "TOTAL " << right;
    cout << generatetotalpoints() << Color::reset() << endl
         << endl;
}
//checks if student exist and deletes it.
void Course::deletestudent(string a)
{
    for (size_t r = 0; r < student.size(); r++)
    {
        if (a == student[r].studentIDcopier())
        {
            student.erase(student.begin() + r);
            cout << ">> Student has been deleted" << endl;
            break;
        }
    }
}
//Checks if item exist and deletes it.
void Course::deleteitem(string a)
{
    for (size_t r = 0; r < items.size(); r++)
    {
        if (a == items[r].itemnamecopier())
        {
            items.erase(items.begin() + r);
            cout << ">> Item has been deleted" << endl;
            break;
        }
    }
}
//Loops around students, calls a function in student class that let's user input grades
void Course::addgradescourse(string a)
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if (a == items[i].itemnamecopier())
        {
            for (size_t j= 0; j < student.size(); j++)
            {
                student[j].addgrades(a);
            }
        }
    }
}
//Add or updates a grade for specific student
void Course::addgradesinglestudent(string a, string b)
{
    for (size_t i = 0; i < student.size(); i++)
    {
        string studentid = student[i].studentIDcopier();
        if (studentid == b)
        {
            if (checkitemexitance(a) == 1)
            {
                student[i].addgrades(a);
            }
            else if (checkitemexitance(a) == 0)
            {
                cout << ">> Invalid Item" << endl;
                return;
            }
        }
    }
}
//Generates total points of the coruse, This function is used in listing items, computing finals grades, and listing grades.
//NOTE that the totalpoints is zeroed each time becasue this is a class member.
int Course::generatetotalpoints()
{
    totalpoints = 0;
    for (size_t i = 0; i < items.size(); i++)
    {
        int j = items[i].coursepointscopier();
        totalpoints += j;
    }
    return totalpoints;
}
//list grade for specific item.
void Course::listgradeC(string a)
{
    totalnumberofstudents = student.size();
    if (checkitemexitance(a) == 1)
    {
        cout << "\nGrades for item " << a << " in the course " << name << ": " << endl;
        for (size_t i = 0; i < student.size(); i++)
        {
            student[i].listgradeS(a, totalnumberofstudents);
        }
        cout << endl;
    }
    else
    {
        cout << ">> item doesn't exist." << endl;
    }
}
//This function checks if item already exists or not and is called in many situations like create item, add grade, or add grades.
int Course::checkitemexitance(string a)
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if (a == items[i].itemnamecopier())
        {
            return 1;
        }
    }
    return 0;
}
// Lists all grades and calls the function that prints the histogram.
void Course::listallgrades()
{
    double TotalC = generatetotalpoints();
    double TotalS{0};
    double average;
    vector<string> data;
    stringstream ex;
    cout << name << " Grades: " << endl;
    cout << left << setw(30) << "Student" << right;
    for (size_t j= 0; j < items.size(); j++)
    {
        cout << left << setw(8) << items[j].itemnamecopier() << right;
    }
    cout << left << setw(8) << "Average" << right << endl;
    for (size_t i = 0; i < student.size(); i++)
    {
        data = student[i].studentdatastringcreation();
        TotalS = student[i].generatefinalgrade();
        average = (TotalS / TotalC) * 100;

        string s = data[2] + ",  " + data[1] + "   " + data[3];
        cout << left << setw(30) << s << right;
        student[i].listgradesS();
        int CC = TotalC;
        int SS = TotalS;
        string C = to_string(CC);
        string S = to_string(SS);
        string sum = S + "/" + C;
        cout << left << setw(8) << sum << right;
        int coloring = average / 2;
        cout << Color::setColor(Color::black, Color::blue)
             << fixed << setprecision(1) << average << "%   "
             << finallettergrade(average, 0) << left << setfill(' ')
             << setw(coloring) << right << Color::reset() << endl;
    }
    finallettergrade(0, 1);
}
//This function have two modes, the first mode is just incrementing integers that corresponds to number of students got A,B,C,D, or E. The other called mode is resting the 
//static variables and calls the histogram function.
char Course::finallettergrade(double a, int b)
{
    static int AF = 0;
    static int BF = 0;
    static int CF = 0;
    static int DF = 0;
    static int EF = 0;
    if (b == 0)
    {
        if (a >= 91 && a <= 100)
        {
            AF++;
            return 'A';
        }
        else if (a >= 81 && a <= 90)
        {
            BF++;
            return 'B';
        }
        else if (a >= 71 && a <= 80)
        {
            CF++;
            return 'C';
        }
        else if (a >= 61 && a <= 70)
        {
            DF++;
            return 'D';
        }
        else if (a < 60)
        {
            EF++;
            return 'E';
        }
    }
    if (b == 1)
    {
        ListFinalGradeHistogram(AF, BF, CF, DF, EF);
        AF = 0;
        BF = 0;
        CF = 0;
        DF = 0;
        EF = 0;
    }
    return 0;
}
//This function takes its information from the previous function. It comuptes how many students got what grade and displays the percentage with perscion of 1 
//and a colored characters. 50 colored character is equivelant to 100% and the rest are just percent diveded by 2 to compute the number of colored characters.
void Course::ListFinalGradeHistogram(int A, int B, int C, int D, int E)
{
    double O = student.size();
    int J = student.size();
    double Apercent = (A / O) * 100;
    double Bpercent = (B / O) * 100;
    double Cpercent = (C / O) * 100;
    double Dpercent = (D / O) * 100;
    double Epercent = (E / O) * 100;
    int Acoloring = Apercent / 2;
    int Bcoloring = Bpercent / 2;
    int Ccoloring = Cpercent / 2;
    int Dcoloring = Dpercent / 2;
    int Ecoloring = Epercent / 2;
    cout << name << " "
         << "Final Grades" << endl;
    cout << "91-99 (A):  " << A << "/" << J << "     " << Color::setColor(Color::black, Color::green) << fixed << setprecision(1)
         << Apercent << "%" << setfill(' ') << setw(Acoloring) << Color::reset() << endl;
    cout << "81-90 (B):  " << B << "/" << J << "     " << Color::setColor(Color::black, Color::blue) << fixed << setprecision(1) 
         << Bpercent << "%" << setfill(' ') << setw(Bcoloring) << Color::reset() << endl;
    cout << "71-80 (C):  " << C << "/" << J << "     " << Color::setColor(Color::black, Color::purple) << fixed << setprecision(1) 
         << Cpercent << "%" << setfill(' ') << setw(Ccoloring) << Color::reset() << endl;
    cout << "61-70 (D):  " << D << "/" << J << "     " << Color::setColor(Color::black, Color::cyan) << fixed << setprecision(1) 
         << Dpercent << "%" << setfill(' ') << setw(Dcoloring) << Color::reset() << endl;
    cout << "  <60 (E):  " << E << "/" << J << "     " << Color::setColor(Color::black, Color::red) << fixed << setprecision(1) 
         << Epercent << "%" << setfill(' ') << setw(Ecoloring) << Color::reset() << endl;
}
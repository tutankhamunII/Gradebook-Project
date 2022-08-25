// Developed by Hesham Elshafey
// Version 1.0

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Gradeditem.h"
#include "Student.h"
#include "Color.h"
using namespace std;
//Add student to coruse, Note that this is a function not a constructer. The developer didn't use any user-typed constructors(for no specific reason)
void Student::addstudentStudent(string first, string last, string id, string course, vector<Gradeditem> items)
{
    firstname = first;
    lastname = last;
    ID = id;
    coursename = course;
    studentitems = items;
}
//This function creates vector of strigns holding student data. The developer preferred the student data to be in individual strings becasue sometimes only one part of 
//this data is needed
vector<string> Student::studentdatastringcreation()
{
    studentdata.push_back(coursename);
    studentdata.push_back(firstname);
    studentdata.push_back(lastname);
    studentdata.push_back(ID);
    return studentdata;
}
//This function returns student ID. An example on why the data was saved individually. This function is used to verfiy existance of a student and to access this student grades
//wheather to input or print.
string Student::studentIDcopier()
{
    return ID;
}
//Create itemobject. This function is used in the course class when the item is created. It is called so that the same exact item that was added to the course is added
//to each student in the course.
void Student::createitemobject(Gradeditem a)
{
    studentitems.push_back(a);
}
//Displays the name for each student one by one and let's user enter grade for specific item. Another example that the first and last name only was needed rather than all
//student data
void Student::addgrades(string a)
{
    int grade = 0;
    for (size_t i = 0; i < studentitems.size(); i++)
    {
        if (a == studentitems[i].itemnamecopier())
        {
            cout << ">> type grade for " << firstname << " " << lastname << ": ";
            cin >> grade;
            studentitems[i].studentgradesetter(grade);
        }
    }
}
//generates final grade of the student by accessing the item object and copied the student points.
int Student::generatefinalgrade()
{
    finalgrade = 0;
    for (size_t i = 0; i < studentitems.size(); i++)
    {
        int j = studentitems[i].studentgradecopier();
        finalgrade += j;
    }
    return finalgrade;
}
//Actual function the writes grades to file.
void Student::writestudentgradestofileS()
{
    ofstream file;
    file.open("grades.csv", ofstream::out | ofstream::app);
    for (size_t i = 0; i < studentitems.size(); i++)
    {
        file << "\"" << coursename << "\","
             << "\"" << ID << "\","
             << "\"" << studentitems[i].itemnamecopier() << "\","
             << "\"" << studentitems[i].studentgradecopier() << "\"" << endl;
    }
    file.close();
}
//Populate the student grades each time the program starts
void Student::initialstudentgrades(string a, int b)
{
    for (size_t i = 0; i < studentitems.size(); i++)
    {
        if (a == studentitems[i].itemnamecopier())
        {
            studentitems[i].studentgradesetter(b);
        }
    }
}
//List grades and setup the information needed to print the histogram
int Student::listgradeS(string a, int b)
{
    static int t = 0;
    t++;
    static double A = 0;
    static double B = 0;
    static double C = 0;
    static double D = 0;
    static double E = 0;
    double f{0};
    double g{0};
    int percent{0};
    for (size_t i = 0; i < studentitems.size(); i++)
    {
        if (a == studentitems[i].itemnamecopier())
        {
            string lister = firstname + ", " + lastname;
            cout << left << setw(20) << lister << studentitems[i].studentgradecopier() << right << endl;
            f = studentitems[i].studentgradecopier();
            g = studentitems[i].coursepointscopier();
            percent = (f / g) * 100;

            if (percent >= 91 && percent <= 100)
            {
                A += 1;
            }
            else if (percent >= 81 && percent <= 90)
            {
                B += 1;
            }
            else if (percent >= 71 && percent <= 80)
            {
                C += 1;
            }
            else if (percent >= 61 && percent <= 70)
            {
                D += 1;
            }
            else if (percent < 60)
            {
                E += 1;
            }
        }
    }
    if (t == b)
    {
        onegradehistogram(b, A, B, C, D, E, a);
        A = 0;
        B = 0;
        C = 0;
        D = 0;
        E = 0;
        t = 0;
    }

    return 0;
}

void Student::listgradesS()
{
    for (size_t i = 0; i < studentitems.size(); i++)
    {

        cout << left << setw(8) << studentitems[i].studentgradecopier() << right;
    }
}
//prints the histogram using the same logic like all grades histogram
void Student::onegradehistogram(int g, int A, int B, int C, int D, int E, string a)
{
    double O = g;
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
    cout << coursename << " " << a << endl;
    cout << "91-99 (A):  " << A << "/" << g << "     " << Color::setColor(Color::black, Color::green) << fixed << setprecision(1) << Apercent << "%" << setfill(' ') << setw(Acoloring) << Color::reset() << endl;
    cout << "81-90 (B):  " << B << "/" << g << "     " << Color::setColor(Color::black, Color::blue) << fixed << setprecision(1) << Bpercent << "%" << setfill(' ') << setw(Bcoloring) << Color::reset() << endl;
    cout << "71-80 (C):  " << C << "/" << g << "     " << Color::setColor(Color::black, Color::purple) << fixed << setprecision(1) << Cpercent << "%" << setfill(' ') << setw(Ccoloring) << Color::reset() << endl;
    cout << "61-70 (D):  " << D << "/" << g << "     " << Color::setColor(Color::black, Color::cyan) << fixed << setprecision(1) << Dpercent << "%" << setfill(' ') << setw(Dcoloring) << Color::reset() << endl;
    cout << "  <60 (E):  " << E << "/" << g << "     " << Color::setColor(Color::black, Color::red) << fixed << setprecision(1) << Epercent << "%" << setfill(' ') << setw(Ecoloring) << Color::reset() << endl;
}

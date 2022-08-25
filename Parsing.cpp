// Developed by Hesham Elshafey
// Version 1.0

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Parsing.h"
#include "Course.h"
#include "Color.h"
using namespace std;
//This function rests the input strings, takes input, and split it to individual strings to be used.
void parsing::Extractor()
{
    if (terminator == 0)
    {
        cout << Color::setColor(Color::white, Color::cyan) << test << Color::reset() << ">> ";
        verb1.erase();
        verb2.erase();
        verb3.erase();
        verb4.erase();
        verb5.erase();
        verb6.erase();
        getline(cin, main);
        while (main.empty() == 1) // This loop let's user input again if he/she just hit enter.
        {
            cout << Color::setColor(Color::white, Color::cyan) << test << Color::reset() << ">> ";
            getline(cin, main);
        }
        stringstream ex(main);
        ex >> verb1 >> verb2 >> verb3 >> verb4 >> verb5;
        checkbufferoverrun();// This function checks if the user overrunned strings. overrun is set to > 50 characters, but this is not neccessary as strings can virtually handle the situation.
        Distributor(verb1, verb2, verb3, verb4, verb5);
    }
    else if (terminator == 1) // this if statement is only activated when the input it to Quit, this method is used for the program to quit immediatly from the main function.
    {
        return;
    }
}
//This function checks if user overruned any buffers or if the user entered more than five arguments (the max number of arguments needed it 5, any larger is considered an error)
void parsing::checkbufferoverrun()
{
    if(verb1.size() > 50 || verb2.size() > 50 || verb3.size() > 50 || verb4.size() > 50 || verb5.size() > 50 || verb6.size() > 50 )
    {
        cout << ">> You have overrunned the buffer and your input is disgarded, please input again" << endl;
        Extractor();
        return;
    }
    else if(verb6.empty() == 0)
    {
        cout << ">> you have entered more than five arguments, please input again" << endl;
        Extractor();
        return;
    }
}
//This function just checks the first two words that corresponds to the command user wish to excute and accordingally calls the needed function for this task. If the input
//didn't match any command, error message is displayed and user is prompted again.
void parsing::Distributor(string word1, string word2, string word3, string word4, string word5)
{
    if (word1 == "set" && word2 == "course")
    {
        setcoursechecker(word3);
    }
    else if (word1 == "create" && word2 == "course")
    {
        CreateCourseP();
    }
    else if (word1 == "list" && word2 == "courses")
    {
        ListCoursesP();
    }
    else if (word1 == "delete" && word2 == "course")
    {
        DeleteCourseP();
    }
    else if (word1 == "create" && word2 == "student")
    {
        CreateStudent();
    }
    else if (word1 == "list" && word2 == "students")
    {
        ListStudentsP();
    }
    else if (word1 == "delete" && word2 == "student")
    {
        DeleteStudentP();
    }
    else if (word1 == "create" && word2 == "item")
    {
        CreateItemP();
    }
    else if (word1 == "list" && word2 == "items")
    {
        ListItemsP();
    }
    else if (word1 == "delete" && word2 == "item")
    {
        DeleteItemP();
    }
    else if (word1 == "add" && word2 == "grade")
    {
        AddGradeP();
    }
    else if (word1 == "list" && word2 == "grade")
    {
        ListGradeP();
    }
    else if (word1 == "list" && word2 == "grades")
    {
        ListGradesP();
    }
    else if (word1 == "add" && word2 == "grades")
    {
        AddGradesP();
    }
    else if (word1 == "delete" && word2 == "grades")
    {
        // put command here
    }
    else if (word1 == "help")
    {
        Help();
    }
    else if (word1 == "quit" || word1 == "stop" || word1 == "q" || word1 == "exit")
    {
        Quit();
    }
    else
    {
        cout << ">> Wrong command, Please enter again" << endl;
        Extractor();
    }
}
//This function loops around courses, checks if coruse exists, and set the course. not that the looping variable X is a member variable. After setting the course. 
//X will still carrying the last looping quantity and then this specific course can be accessed anywhere in parsing class using course[x].fucntion()
void parsing::setcoursechecker(string coursename)
{
    x = 0;
    test = coursename;
    if (coursename.empty() == 1)
    {
        cout << ">> No coursename specifided, Input again" << endl;
        Extractor();
        return;
    }
    else
    {
        for (x = 0; x < course.size(); x++)
        {
            if (coursename == course[x].coursenamecopier())
            {
                cout << ">> Course has been set" << endl;
                Extractor();
                return;
            }
            else
            {
                continue;
            }
        }
        cout << ">> course doesn't exist." << endl;
        test.clear();
        Extractor();
        return; 
    }
}
//Validate input, checks if course already exists, and add the course.
void parsing::CreateCourseP()
{
    if (verb3.empty())
    {
        cout << "No course name is specific, please enter again" << endl;
        Extractor();
        return;
    }
    for (size_t b = 0; b < course.size(); b++)
    {
        if (verb3 == course[b].coursenamecopier())
        {
            cout << ">> Course already exist." << endl;
            Extractor();
            return;
        }
    }
    Course obj2{};
    obj2.createcourse(verb3);
    course.push_back(obj2);
    cout << ">> course is created" << endl;
    Extractor();
}
//Validate input, checks if course exist, asks for confirmation, and then deletes the course.
void parsing::DeleteCourseP()
{
    int breaker{0};
    string Deletion;
    test.erase();
    if (verb3.empty())
    {
        cout << "No course name is specific, please enter again" << endl;
        Extractor();
        return;
    }
    for (size_t r = 0; r < course.size(); r++)
    {
        if (verb3 == course[r].coursenamecopier())
        {
            cout << ">> Are you sure? Type YES to confirm : ";
            cin >> Deletion;
            if (Deletion == "YES")
            {
                course.erase(course.begin() + r);
                cout << ">> Course is deleted" << endl;
                breaker++;
                break;
            }
            else
            {
                cout << ">> Aborted" << endl;
                main.erase();
                Extractor();
                return;
            }
        }
    }
    if (breaker == 0)
    {
        cout << ">> Course doesn't exits" << endl;
        Extractor();
        return;
    }
}
//List all courses, it the no courses exists yet outputs error.
void parsing::ListCoursesP()
{
    if (course.size() == 0)
    {
        cout << ">> No data" << endl;
        Extractor();
        return;
    }
    cout << endl;
    for (size_t x = 0; x < course.size(); x++)
    {
        string corusename = course[x].coursenamecopier();
        cout << corusename << endl;
    }
    cout << endl;
    Extractor();
}
//Validate input and call the appropriate function to add student
void parsing::CreateStudent()
{
    if (testsetcourse() == 0)
    {
        Extractor();
        return;
    }
    else if (verb3.empty() == 1 || verb4.empty() == 1 || verb5.empty() == 1)
    {
        cout << ">> Missing data, Please type this format [create student firstname lastname ID]" << endl;
        Extractor();
    }
    else
    {
        course[x].addstudenttocourse(verb3, verb4, verb5);
    }
    Extractor();
}
//lists all students.
void parsing::ListStudentsP()
{
    if (testsetcourse() == 0)
    {
        Extractor();
    }
    course[x].liststudentcourse();
    Extractor();
}
//validate input, asks for confirmation, checks student existance, and behave accordingly.
void parsing::DeleteStudentP()
{
    string Deletion;
    if (testsetcourse() == 0)
    {
        Extractor();
        return;
    }
    if (verb3.empty() == 1)
    {
        cout << "Student ID is not specified, Please enter again" << endl;
        Extractor();
        return;
    }
    if (course[x].CheckStudentForDeletion(verb3) == 0)
    {
        cout << "Invalid ID" << endl;
        Extractor();
        return;
    }
    cout << "Are you sure? type YES to confirm: ";
    cin >> Deletion;
    if (Deletion == "YES")
    {
        course[x].deletestudent(verb3);
        Extractor();
        return;
    }
    if (Deletion != "YES")
    {
        cout << "Aborted" << endl;
        Extractor();
        return;
    }
}
//Creates item. Catches any errors from stoi like blank points, non-numeric points, or very larg points. Note that buffer overrun already checks for large input
//but this catch was included as extra safty because stoi terminates if the error is not catched.
int parsing::CreateItemP()
{
    int pointtest{0};
    if (testsetcourse() == 0)
    {
        Extractor();
        return 0;
    }
    if (verb3.empty() == 1 || verb4.empty() == 1)
    {
        cout << "Incomplete data, Please enter again" << endl;
        Extractor();
        return 0;
    }
    try
    {
        pointtest = stoi(verb4);
    }
    catch(std::invalid_argument&e)
    {
        cout << ">> your grade input is not a number, input again" << endl;
        Extractor();
        return 0;
    }
    catch(std::out_of_range&e)
    {
        cout <<">> your number is so large, input again" << endl;
        Extractor();
        return 0;
    }
    if (pointtest < 0 || pointtest > 100)
    {
        cout << "Ivalid data, Maxpoints should be from 0 to 100, Please enter again" << endl;
        pointtest = 0;
        Extractor();
        return 0;
    }
    if (course[x].checkitemexitance(verb3) == 1)
    {
        cout << ">> item already exists" << endl;
        Extractor();
        return 0;
    }
    else
    {
        course[x].additemtocourse(verb3, pointtest);
        Extractor();
        return 0;
    }
}
//lists all items and total points
void parsing::ListItemsP()
{
    if (testsetcourse() == 0)
    {
        Extractor();
    }
    course[x].listitems();
    Extractor();
}
// deletes item in the same methodolgy like deleting student
int parsing::DeleteItemP()
{
    string Deletion;
    if (testsetcourse() == 0)
    {
        Extractor();
        return 0;
    }
    else if (verb3.empty() == 1)
    {
        cout << "Item name is not specified, Please enter again" << endl;
        Extractor();
        return 0;
    }
    cout << "Are you sure? type YES to confirm: ";
    cin >> Deletion;
    if (Deletion == "YES")
    {
        course[x].deleteitem(verb3);
        Extractor();
        return 0;
    }
    else if (Deletion != " YES")
    {
        cout << "Deletion process has been Terminated, you will be redirected to input again" << endl;
        Extractor();
        return 0;
    }
    return 1;
}
//Add a grade for specific student.
int parsing::AddGradeP()
{
    if (testsetcourse() == 0)
    {
        Extractor();
        return 0;
    }
    else if (verb3.empty() == 1 || verb4.empty() == 1)
    {
        cout << "Invalid input, please enter again" << endl;
        Extractor();
        return 0;
    }
    else
    {
        course[x].addgradesinglestudent(verb4, verb3);
        Extractor();
    }
    return 1;
}
// Add grades for specific item to all students, one by one.
int parsing::AddGradesP()
{
    if (testsetcourse() == 0)
    {
        Extractor();
        return 0;
    }
    else if (verb3.empty() == 1)
    {
        cout << "Item is not specified, please enter again" << endl;
        Extractor();
        return 0;
    }
    else
    {
        course[x].addgradescourse(verb3);
        Extractor();
    }

    return 1;
}
// list grade for one item for each students
int parsing::ListGradeP()
{
    if (testsetcourse() == 0)
    {
        Extractor();
        return 0;
    }
    else if (verb3.empty() == 1)
    {
        cout << "Item is not specified, please enter again" << endl;
        Extractor();
        return 0;
    }
    else
    {
        course[x].listgradeC(verb3);
        Extractor();
    }
    return 1;
}
//list all grades including final numeric, percentage, and letter.
void parsing::ListGradesP()
{
    if (testsetcourse() == 0)
    {
        Extractor();
    }
    else
    {
        course[x].listallgrades();
        Extractor();
    }
}

void parsing::Save()
{
    // The developer already saves all data right after the user inputs it, This function definition is left blank for future developers if they
    // want to create a function just for saving the data in the file instead of step-by-step saving design used in here.
}
//This function writes all the headline for the four files, calls appropriate functions to write the data of students, coruses, grades, and items, then exits the program.
void parsing::Quit()
{
    cout << "saving data....." << endl;
    ofstream fileS;
    ofstream fileC;
    ofstream fileI;
    ofstream fileG;
    fileS.open("students2.csv");
    fileS << "\"coursename\","
          << "\"firstname\","
          << "\"lastname\","
          << "\"ID\"" << endl;
    fileS.close();
    fileC.open("courses.csv");
    fileC << "\"coursename\"" << endl;
    fileC.close();
    fileI.open("items.csv");
    fileI << "\"coursename\","
          << "\"name\","
          << "\"max\"" << endl;
    fileI.close();
    fileG.open("grades.csv");
    fileG << "\"coursename\","
          << "\"studentID\","
          << "\"itemname\","
          << "\"grade\"" << endl;
    fileG.close();
    for (size_t j = 0; j < course.size(); j++)
    {
        string d = course[j].coursenamecopier();
        fileC.open("courses.csv", ofstream::out | ofstream::app);
        fileC << "\"" << d << "\"" << endl;
        fileC.close();
    }
    for (size_t y = 0; y < course.size(); y++)
    {
        course[y].writestudentdate();
    }
    for (size_t i = 0; i < course.size(); i++)
    {
        course[i].writeitemdata();
    }

    for (size_t i = 0; i < course.size(); i++)
    {
        course[i].writestudentgradestofileC();
    }
    terminator = 1;
    Extractor();
    cout << "Goodbye!" << endl;
}
//creates intial coruse objects from the file.
int parsing::intitalcourseobjects()
{

    ifstream file("courses.csv");
    file.is_open();
    string parser;
    while (getline(file, parser))
    {
        if (parser.empty() == 1)
        {
            return 0;
        }
        else if (parser == "\"coursename\"")
        {
            continue;
        }
        else
        {
            parser.erase(remove(parser.begin(), parser.end(), '"'), parser.end());
            Course obj2{};
            obj2.initalcreatecourse(parser);
            obj2.intialstudentobject();
            obj2.intialitemobject();
            course.push_back(obj2);
        }
    }
    for (size_t i = 0; i < course.size(); i++)
    {
        course[i].initialstudentgradesC();
    }
    return 0;
}
//This function is used in most upper functions, it checks if the course is set or not.
int parsing::testsetcourse()
{
    if (test.empty() == 1)
    {
        cout << ">> No course is set, set the course first before adding any traits." << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

void parsing::Help()
{
    cout << "This program recognize a set of specific commands associated with specific data that a user input, and these commands are as follows: \n"
         << "Create Course <Coursname>: to create a course, if course is already exists your input will not be excuted.\n"
         << "Set course <Coursename>: signals the program that all upcoming data entries will be associated with this course.\n"
         << "If course is not set, most of the upcoming commands won't excute untill you set a course first\n"
         << "List Courses: Command to list all the courses you have created recently or been created and saved in the program file before.\n"
         << "Delete Course <coursename>: Deletes the course and all data associated with it\n"
         << "Create Student <first> <last> <ID>: Adds a student the course you set before.\n"
         << "list students: list all students in the course you set before.\n"
         << "Delete student <ID>: deletes specific student and all their data from the course you set before.\n"
         << "Create item <name> <maxpoints>: create a graded item and adds it to your course data.\n"
         << "List items: lists all items been created and associated with this course.\n"
         << "Delete item <name>: deletes the graded item.\n"
         << "Add grades <item>: outputing each student name and prompt you to enter their grades for that specific item.\n"
         << "Add grade <item>: <student>: adds grade for only one student.\n"
         << "List grade <item>: list each student and the grade they got for this item.\n"
         << "List grades: lists all grades and total grade for each student in your coruse.\n"
         << "Save: saves all the data you entered.\n"
         << "quit, stop, exit, or q: saves your data and exits the program.\n"
         << endl;
    Extractor();
    return;
}
void parsing::MiniHelp()
{
    cout << "This is the Gradebook app, The list of following commands are the only ones the program can recognize."
         << "\nThe information should be entered exactly like the format specifed below: (don't write the <> symbols)" << endl
         << "- create course <coursename>" << endl
         << "- set course <coursename>" << endl
         << "- list courses" << endl
         << "- create student <first> <last> <id>" << endl
         << "- list students" << endl
         << "- delete student <id>" << endl
         << "- list items" << endl
         << "- delete item <name>" << endl
         << "- add grades <item>" << endl
         << "- add grade <studentid> <item>" << endl
         << "- list grade <item>" << endl
         << "- list grades" << endl
         << "- help" << endl
         << "- quit OR stop OR exit OR q" << endl
         << "If entered any incomplete or invalid data, the program will output an error text and prompts you to input again." << endl
         << "If you have any further questions, PLEASE, google them. The developer of this program is exhausted enough. Thank you!" << endl;
    Extractor();
    return;
}
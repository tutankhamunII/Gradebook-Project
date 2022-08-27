# Gradebook OOP project that allows user to add, edit, present, or delete a full course and grades registeration system.

This is a terminal based OOP C++ project that accepts user input of information, create objects, allows user to edit the attributes, show attributes results, and saves
all the inputted info in CSV files before existing.
  The following is the user input commands and their description:
  Create Course <Coursname>: to create a course, if course is already exists your input will not be excuted.
  
  Set course <Coursename>: signals the program that all upcoming data entries will be associated with this course.
  
  If course is not set, most of the upcoming commands won't excute untill you set a course first.
  
  List Courses: Command to list all the courses you have created recently or been created and saved in the program file before.
  
  Delete Course <coursename>: Deletes the course and all data associated with it.
  
  Create Student <first> <last> <ID>: Adds a student the course you set before.
  
  list students: list all students in the course you set before.
  
  Delete student <ID>: deletes specific student and all their data from the course you set before.
  
  Create item <name> <maxpoints>: create a graded item and adds it to your course data.
  
  List items: lists all items been created and associated with this course.
  
  Delete item <name>: deletes the graded item.
  
  Add grades <item>: outputing each student name and prompt you to enter their grades for that specific item.
  
  Add grade <item>: <student>: adds grade for only one student.
  
  List grade <item>: list each student and the grade they got for this item.
  
  List grades: lists all grades and total grade for each student in your coruse.
  
  Save: saves all the data you entered.
  
  quit, stop, exit, or q: saves your data and exits the program.
  
  You can start the program in the CMD just using the Gradebokk.exe file. you can supply Course name argument to start the program directly in a specific course.
  
  you can supply other CMD arguments like -h or -help to show a help message before startiing the program.
  
  This program uses OOP to build and connects different classes. The main class is Parser class that has all the parsing and contains a vector of Course objects.
  
  The course class contain vector of students objects and graded item objects. The Student class finally contain vector of item Objects.
  
  The program is built to have a consistant data base, so before quiting it will save all the entered data into CSV files automatically.
  
  The second time you start the program it will first - under the hood - create objects from the data inside the CSV files so you access or change them or add new data.
  
  Bugs:
  	The program can't accept student names that consists of two spearted words by space due to the basic sstream spliting of the student data per line.
	
 
  

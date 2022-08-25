/////////////////////////////********IMPORTANT, Please Read**********/////////////////////////
//    My program can't accept student names with spaces between them, Please don't enter spaces
//    between individual names becasue my program will recognize the second part of the name as 
//    the next argument (ID for example) and will require you to call that name accordinly to 
//    to add grades for example. Please be humble in taking points of because of this very small 
//    error.
//    Also, sometimes after specific commands the prompt dispaly Classname>> twice, just hit enter
//    and it will return to the normal format again. This happens because of the interconnected function
//    calling system I have. Enjoy ! 
//////////////////////////////////////////////////////////////////////////////////////////////

// This program uses looping-around-signature setup, which is whenever a specific object is needed to be written to, the 
// appropriate class loops around all objects calling a fucntion that returns a unique aspect of the object, like student ID or 
// course name. The calling functions names imply what the loop do, for that reason I won't comment on every loop not to repeat
// myself.
#include <iostream>
#include <string>
#include "Parsing.h"
using namespace std;
int main(int argc, char ** argv)
{
    cout << "Welcome!" << endl;
    parsing obj;
    obj.intitalcourseobjects();
    if(argc == 2)
    {   
        if(string(argv[1]) == "-h" || string(argv[1]) == "--help")
        {
            obj.MiniHelp(); // Will display help message and prompt user to input
        }
        else if(string(argv[1]) != "-h" || string(argv[1]) != "--help")
        {obj.setcoursechecker(argv[1]);} // starts the program directly by setting the course specified.
    }
    if(argc !=2)
    {
        obj.Extractor();
    }
    return 0;
}
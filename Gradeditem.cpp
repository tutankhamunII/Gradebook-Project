// Developed by Hesham Elshafey
// Version 1.0

#include <iostream>
#include <string>
#include <vector>
#include "Gradeditem.h"
using namespace std;
//This is the simplest grade

//returns items name. Used in input valudation, checks for item existance, and accessing the item when needed.
string Gradeditem::itemnamecopier()
{
    return itemname;
}

//add item object.
void Gradeditem::additemtoitems(string a, int b, string c)
{
    itemname = a;
    maxpoints = b;
    itemcoursename = c;
}

//returns all data about item, without including student grade. This function is needed in computing total points of the course.
vector<string> Gradeditem::itemdatacopier()
{
    string points = to_string(maxpoints);
    vector<string> itemdata;
    itemdata.push_back(itemcoursename);
    itemdata.push_back(itemname);
    itemdata.push_back(points);
    return itemdata;
}
//Returns student grade rather than maxpoints, used in pretty much any grade listing.
int Gradeditem::studentgradecopier()
{
    return studentscore;
}
//sets the student grade, accessed only when user add grades to the student
void Gradeditem::studentgradesetter(int a)
{
    studentscore = a;
}
//copies maxpoitns, needed in computing totalpoints.
int Gradeditem::coursepointscopier()
{
    return maxpoints;
}
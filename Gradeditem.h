// Developed by Hesham Elshafey
// Version 1.0

#ifndef GRADEDITEM_h
#define GRADEDITEM_h
#include <string>
#include <vector>
class Gradeditem
{
private:
    std::string itemname;
    std::string itemcoursename;
    int maxpoints;
    int studentscore{0};

public:
    std::string itemnamecopier();
    void additemtoitems(std::string, int, std::string);
    std::vector<std::string> itemdatacopier();
    void additemtostudent();
    int studentgradecopier();
    void studentgradesetter(int);
    int coursepointscopier();
};
#endif
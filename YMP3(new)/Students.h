#pragma once

#include <string>
#include <vector>
using namespace std;

struct Fullname {
    string surname;
    string name;
    string patronymic;
};

struct Exam {
    string subject;
    int grade;
};

struct Student {
    Fullname fullname;
    int course;
    int group;
    bool isBudget;
    vector <Exam>grades;
};
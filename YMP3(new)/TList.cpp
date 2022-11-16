#include "TList.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void init(TList& list) {
    list = nullptr;
}

bool isEmpty(TList list) {
    return list == nullptr;
}

// Заполнение списка информацией из файла
void input(TList& list, string filename) {
    ifstream in(filename);

    TList current = list;
    TList p = new Node;

    if (in.is_open())
    {
        stringstream lineStream;
        string line;
        bool isFirst = isEmpty(list);
        while (getline(in, line))
        {
            Student _student;

            lineStream << line;
            lineStream >> _student.fullname.surname;
            lineStream >> _student.fullname.name;
            lineStream >> _student.fullname.patronymic;
            lineStream >> _student.course;
            lineStream >> _student.group;
            string temp;
            lineStream >> temp;

            if (temp == "Бюджет")
                _student.isBudget = true;
            else
                _student.isBudget = false;

            lineStream >> temp;
            lineStream.clear();

            if (getline(in, line)) {
                lineStream << line;
                for (int i = 0; i < 5; i++) {
                    Exam _exam;
                    lineStream >> _exam.subject;
                    lineStream >> _exam.grade;
                    _student.grades.push_back(_exam);
                }
                lineStream.clear();
            }
            addToHead(list, _student);
        }
    }
    in.close();
}

void output(TList list, string filename) {
    ofstream out;
    out.open(filename);
    TList head = list;
    if (out.is_open()) {
        while (!isEmpty(list)) {
            out << list->data.fullname.surname << " " << list->data.fullname.name << " " << list->data.fullname.patronymic << endl;
            for (int i = 0; i < 5; i++) {
                out << list->data.grades[i].subject << " " << list->data.grades[i].grade << " ";
            }
            out << endl;
            list = list->next;
        }
        out.close();
        list = head;
    }
}

void scholarshipList(TList list, string filename) {
    ofstream out;
    out.open(filename);
    TList head = list;
    if (out.is_open())
    {
        out << "Список студентов получающих стипендию: " << endl;

        while (!isEmpty(list)) {
            if (list->data.isBudget) {
                bool gradeFive = false;
                bool gradeFour = false;
                bool gradeThree = false;
                bool gradeBad = false;
                int a = list->data.grades[0].grade;
                for (int i = 0; i < 5; i++) {
                    switch (list->data.grades[i].grade) {
                    case 5:
                        gradeFive = true;
                        break;
                    case 4:
                        gradeFour = true;
                        break;
                    case 3:
                        gradeThree = true;
                        break;
                    default:
                        gradeBad = true;
                        break;
                    }

                }
                if (gradeBad);
                else if (gradeThree) {
                    out << list->data.fullname.surname << " " << list->data.fullname.name << " " << list->data.fullname.patronymic << " " << 3 << endl;
                }
                else if (gradeFour) {
                    out << list->data.fullname.surname << " " << list->data.fullname.name << " " << list->data.fullname.patronymic << " " << 4 << endl;
                }
                else {
                    out << list->data.fullname.surname << " " << list->data.fullname.name << " " << list->data.fullname.patronymic << " " << 5 << endl;
                }
            }
            list = list->next;
        }
        list = head;
        out.close();
    }
}

void addToHead(TList& head, Student data) {
    TList p = new Node;
    p->data = data;
    p->next = head;
    head = p;
}

void addAfterNode(TList list, Student data) {
    TList p = new Node;
    p->data = data;
    p->next = list->next;
    list->next = p;
}

void deleteFromHead(TList& list) {
    TList current = list;
    list = list->next;
    current->next = nullptr;
    delete current;
}

void deleteAfterNode(TList list) {
    TList temp = list->next;
    list->next = temp->next;
    delete temp;
}
#pragma once
#include "Students.h"

using namespace std;

struct Node {
    Student data;
    Node* next;
};

typedef Node* TList;

void init(TList& list);
bool isEmpty(TList list);
void input(TList& list, string filename);
void output(TList list, string filename);
void scholarshipList(TList list, string filename);
void addToHead(TList& list, Student value);
void addAfterNode(TList list, Student value);
void deleteFromHead(TList& list);
void deleteAfterNode(TList list);
void scholarshipList(TList list, string filename);
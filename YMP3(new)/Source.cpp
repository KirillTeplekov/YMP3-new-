#include "TList.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
    
	TList head;
	string inFile = "";
	string outFile = "";
	init(head);
	input(head, inFile);
	cout << isEmpty(head);
	scholarshipList(head, outFile);
	return 0;
}
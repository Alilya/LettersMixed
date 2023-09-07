#include <iostream>
#include <clocale>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

#include "Common.h"
#include "Input.h"

using namespace std;

void randomInput::createText(string& str) {
	int count;
	cout << "������� ����� ������� ������ ����" << endl;
	count = getInt();
	while (count <= 0) {
		cout << "����� ������ ���� ������ 0 " << endl;
		cout << "������� ����� ������� ������ ����" << endl;
		count = getInt();
	}
	for (int i = 0; i < count; i++) {
		str += char('a' + rand() % ('z' - 'a'));
	}
	
	cout << endl;
	cout << "��������������� �����: " << str << endl;
	cout << endl;
}

void keyboardInput::createText(string& str) {
	cout << "������� �����: " << endl;
	cin >> str;
}

bool checkEnter(string enterfile) {///
	/*try {
		static_cast<void>(std::filesystem::is_regular_file(enterfile));
	}
	catch (...) {
		cout << "������ ����������, ������������ ����������������� ���������" << endl;
		return true;
	}
	return false;*/
	return true;
}

void fileInput::createText(string& str) {
	//stringC input;
	string enterfile;
	cout << "������� ������ ���� ����� " << endl;
	cin >> enterfile;

	while (checkEnter(enterfile)) {
		cout << "������� ������ ���� ����� " << endl;
		cin >> enterfile;
	}

	ifstream filereading;
	filereading.open(enterfile);
	string save1, save2;
	while (!filereading.is_open() || checkEnter(enterfile)) {
		cout << "������, ������� ����������/������������ ����� �����" << endl;
		cout << "������� ������ ���� ����� " << endl;
		cin >> enterfile;
		filereading.close();
		filereading.open(enterfile);
	}

	if (filereading.eof()) {
		cout << "������ ������������ " << endl;
	}
	else {
		string buff;
		getline(filereading, buff, '\n');
		str = buff;
		/*getline(filereading, buff, '\n');
		str1 += buff;*/
		buff = "";
	}
	filereading.close();
}


unique_ptr<input> makeChoiceInput(int enter) {
	if (enter == random) {
		return make_unique<randomInput>();
	}
	if (enter == keyboard) {
		return make_unique<keyboardInput>();
	}
	if (enter == file) {
		return make_unique<fileInput>();
	}
	return make_unique<keyboardInput>();
}

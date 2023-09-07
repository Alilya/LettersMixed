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
	cout << "¬ведите длину первого набора букв" << endl;
	count = getInt();
	while (count <= 0) {
		cout << "ƒлина должна быть больше 0 " << endl;
		cout << "¬ведите длину первого набора букв" << endl;
		count = getInt();
	}
	for (int i = 0; i < count; i++) {
		str += char('a' + rand() % ('z' - 'a'));
	}
	
	cout << endl;
	cout << "—генерированный текст: " << str << endl;
	cout << endl;
}

void keyboardInput::createText(string& str) {
	cout << "¬ведите текст: " << endl;
	cin >> str;
}

bool checkEnter(string enterfile) {///
	/*try {
		static_cast<void>(std::filesystem::is_regular_file(enterfile));
	}
	catch (...) {
		cout << "запись невозможна, использовано зарезервированное выражение" << endl;
		return true;
	}
	return false;*/
	return true;
}

void fileInput::createText(string& str) {
	//stringC input;
	string enterfile;
	cout << "введите полный путь файла " << endl;
	cin >> enterfile;

	while (checkEnter(enterfile)) {
		cout << "введите полный путь файла " << endl;
		cin >> enterfile;
	}

	ifstream filereading;
	filereading.open(enterfile);
	string save1, save2;
	while (!filereading.is_open() || checkEnter(enterfile)) {
		cout << "ошибка, введите корректный/существующий адрес файла" << endl;
		cout << "введите полный путь файла " << endl;
		cin >> enterfile;
		filereading.close();
		filereading.open(enterfile);
	}

	if (filereading.eof()) {
		cout << "данных недостаточно " << endl;
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

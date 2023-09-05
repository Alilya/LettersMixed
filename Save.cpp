#include "save.h"

using namespace std;

//namespace fs = std::filesystem;

bool askRew() {
	cout << "������������ ������������ ����?" << endl <<
		"1 - ��" << endl << "2 - ���" << endl;
	int saveAnswer;
	saveAnswer = getInt();
	while (saveAnswer != yes && saveAnswer != no) {
		cout << "������������ ������������ ����?" << endl <<
			"1 - ��" << endl << "2 - ���" << endl;
		saveAnswer = getInt();
	}
	if (saveAnswer == yes)
		return true;
	else
		return false;
}

bool check(string dir) {
	ifstream checkTest(dir);
	error_code ec;
	/*try {
		filesystem::is_regular_file(dir, ec);
	}
	catch (...) {
		cout << "������ ����������! ������������ ����������������� ���������" << endl;
		return false;
	}
	if (!filesystem::is_regular_file(dir, ec)) {
		cout << "������ ����������! ������������ ����������������� ���������" << endl;
		return false;
	}*/

	if (!checkTest.is_open()) {
		checkTest.close();
		std::cout << "��������� ����� ����\n";
		return true;
	}
	else {
		cout << "���� ��� ����������!\n";
		checkTest.close();
		return askRew();
	}
}

void saveData(string str) {
	string fileSaveInput = "";
	cout << "������� ���� ���������� �������� ������: ";
	cin >> fileSaveInput;
	int chars = getchar();
	while (chars != '\n') {
		fileSaveInput += char(chars);
		chars = getchar();
	}
	while (!check(fileSaveInput)) {
		cout << "������� ���� ���������� ������: ";
		fileSaveInput = "";
		chars = getchar();
		while (chars != '\n') {
			fileSaveInput += char(chars);
			chars = getchar();
		}
	}
	ofstream file(fileSaveInput);
	file << str;
	file << endl;
	file.close();
	cout << "�������� � ���� " << fileSaveInput << endl;
}

//void saveResult(stringC& save) {
//	string fileSaveInput;
//	cout << "������� ���� ���������� ����������: ";
//	cin >> fileSaveInput;
//	int chars = getchar();
//	while (chars != '\n') {
//		fileSaveInput += char(chars);
//		cin >> fileSaveInput;
//		chars = getchar();
//	}
//
//	while (!check(fileSaveInput)) {
//		cout << "������� ���� ���������� ����������: ";
//		fileSaveInput = "";
//		cin >> fileSaveInput;
//		chars = getchar();
//		while (chars != '\n') {
//			fileSaveInput += char(chars);
//			cin >> fileSaveInput;
//			chars = getchar();
//		}
//	}
//	ofstream file(fileSaveInput);
//
//	file << save.str;
//	file << endl;
//	file << save.pos1 + 1;
//	file << endl;
//	file << save.pos2 + 1;
//
//	file.close();
//	cout << "�������� � ���� " << fileSaveInput << endl;
//}


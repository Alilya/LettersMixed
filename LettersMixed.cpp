#include <Windows.h>
#include <iostream>
#include <clocale>
#include <fstream>
#include <stdlib.h>
#include <filesystem>

#include "Common.h"
#include "Input.h"
#include "Save.h"


using namespace std;

void Calc(string words) {
	int countWord = words.size();
	char firstLetter = words[0];
	char lastLetter = words[words.size() - 1];

	int* randArrayIndex = new int[countWord];

	randArrayIndex[0] = 0;
	randArrayIndex[countWord-1] = countWord-1;
	
	int random;
	for (int i = 1; i < countWord-1; i++)
	{
		for (;;)
		{
			bool good = true;
			random = rand() % countWord;
			for (int j = 0; j < countWord; j++)
			{
				if (random == randArrayIndex[j]) { good = false; break; }
			}
			if (good) break;
		}
		randArrayIndex[i] = random; 
		
	}

	randArrayIndex[0] = 0;
	randArrayIndex[countWord - 1] = countWord - 1;

	string* resultArray = new string[countWord];
	cout << "----------" << endl;

	for (int i = 0;i < countWord;i++) {
		resultArray[i] = words[randArrayIndex[i]];
		cout << resultArray[i];
	}
	cout << " " << endl;
	cout << " " << endl;
};


//int main(){
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	int enter = 0;
//	cout << "Hello World!\n";
//	do {
//		cout << "Введите 1, чтобы сгенерировать данные случайным образом" << endl;
//		cout << "Введите 2, чтобы ввести с клавиатуры" << endl;
//		cout << "Введите 3, чтобы использовать файл" << endl;
//		cout << "Введите 0, чтобы закончить" << endl;
//		cin >> enter;
//
//		switch (enter){
//			case 1:
//				cout << "1---" << endl;
//				break;
//			case 2:
//				cout << "2--" << endl;
//				break;
//			case 3:
//				cout << "3-" << endl;
//				break;
//			default:
//				break;
//		}
//
//		string words{};
//		cout << "Enter your word" << endl;
//		cin >> words;
//		int countWord = words.size();
//		Calc(words, static_cast<int>(countWord));
//	} while (enter);
//	return 0;
//}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Добро пожаловать!" << endl;
	cout << "|||Колесникова Алина ||| 8 вариант " << endl << "||| 404 группа       ||| 1 лабораторная " << endl << endl;
	cout << "Тескт задачи_____________" << endl <<
		" " << endl << endl;
	int enter = 0;
	//if (test()) {
		do {
			cout << "Введите 1, чтобы сгенерировать данные случайным образом" << endl;
			cout << "Введите 2, чтобы ввести с клавиатуры" << endl;
			cout << "Введите 3, чтобы использовать файл" << endl;
			cout << "Введите 0, чтобы закончить" << endl;
			enter = getInt();

			if (enter == random || enter == keyboard || enter == file) {
				string str;
				
				auto metod = makeChoiceInput(enter);
				metod->createText(str);
				Calc(str);
			


				if (enter == random || enter == keyboard) {
					cout << endl;
					cout << "Введите 1, чтобы сохранить исходные данные" << endl;
					cout << "Введите 2, чтобы не сохранить" << endl;
					enter = getInt();
					while (enter != save && enter != notSave) {
						cout << endl;
						cout << "Введите 1, чтобы сохранить исходные данные" << endl;
						cout << "Введите 2, чтобы не сохранить" << endl;
						enter = getInt();
					}
					if (enter == save) {
						saveData(str);
					}

				}
				cout << endl;
				cout << "Введите 1, чтобы сохранить результат" << endl;
				cout << "Введите 2, чтобы не сохранить" << endl;
				enter = getInt();
				while (enter != save && enter != notSave) {
					cout << endl;
					cout << "Введите 1, чтобы сохранить  сохранить результат" << endl;
					cout << "Введите 2, чтобы не сохранить" << endl;
					enter = getInt();
				}
			/*	if (enter == save) {
					saveResult(text);
				}*/
			}

		} while (enter);
	//}
return 0;
}
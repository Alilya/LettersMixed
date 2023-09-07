#include <Windows.h>
#include <iostream>
#include <clocale>
#include <fstream>
#include <stdlib.h>
#include <filesystem>
#include <string>

#include "Common.h"
#include "Input.h"
#include "Save.h"
#include "Calc.h"
#include "Test.h"

using namespace std;

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
	cout << "Задан текст. В каждом слове текста оставить на своих местах первую и"<<endl 
		<< "последнюю буквы, а в середине слова буквы перемешать" << endl << endl;
	int enter = 0;
	if (test()) {
		do {
			cout << "Введите 1, чтобы сгенерировать данные случайным образом" << endl;
			cout << "Введите 2, чтобы ввести с клавиатуры" << endl;
			cout << "Введите 3, чтобы использовать файл" << endl;
			cout << "Введите 0, чтобы закончить" << endl;
			enter = getInt();

			if (enter == random || enter == keyboard || enter == file) {
				string str;
				stringC result;
				
				auto metod = makeChoiceInput(enter);
				metod->createText(str);
				Calc(str, result);
				
				cout << "Полученный текст:" << endl;
				cout << result.result << endl;
		
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

			/*	cout << "Введите 1, чтобы сохранить результат" << endl;
				cout << "Введите 2, чтобы не сохранить" << endl;
				enter = getInt();
				while (enter != save && enter != notSave) {
					cout << endl;
					cout << "Введите 1, чтобы сохранить  сохранить результат" << endl;
					cout << "Введите 2, чтобы не сохранить" << endl;
					enter = getInt();
				}
				if (enter == save) {
					saveResult(text);
				}*/
			}

		} while (enter);
	}
 return 0;
}
#include <iostream>

using namespace std;

void Calc(string words, int countWord) {

	char firstLetter = words[0];
	char lastLetter = words[words.size() - 1];

	int* randArrayIndex = new int[countWord];

	randArrayIndex[0] = 0;
	randArrayIndex[countWord-1] = countWord-1;
	
	int random;
	cout << "randArrayIndex[i]  ";
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
	cout << "resultArray "<< endl;
	
	for (int i = 0;i < countWord;i++) {
		resultArray[i] = words[randArrayIndex[i]];
		cout << resultArray[i];
	}
};


int main(){

	int enter = 0;
	cout << "Hello World!\n";
	//do {
		string words{};
		cout << "Enter your word" << endl;
		cin >> words;
		int countWord = words.size();
		Calc(words, countWord);
	//} while (enter);
}






// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

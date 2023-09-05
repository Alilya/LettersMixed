#pragma once
#include <string>
#include <iostream>

using namespace std;

int getInt();

enum inputChoice {
	random = 1,
	keyboard,
	file
};
enum saveChoice {
	save = 1,
	notSave
};
enum answer {
	yes = 1,
	no
};

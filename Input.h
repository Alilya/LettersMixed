#pragma once

#include <string>
#include <filesystem>
#include <memory>
#include <string>

using namespace std;

class input {
public:
	virtual void createText(string&) = 0;
	virtual ~input() = default;
};

class randomInput :public input {
public:
	void createText(string&) override;
};

class keyboardInput : public input {
public:
	void createText(string&) override;
};

class fileInput : public input {
public:
	void createText(string&) override;
};

std::unique_ptr<input> makeChoiceInput(int);
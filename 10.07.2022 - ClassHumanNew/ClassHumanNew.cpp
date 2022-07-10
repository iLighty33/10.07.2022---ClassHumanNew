#include <iostream>
#include <string>
#include <ctime>//chrono
#include <exception>

using namespace std;

class Human : public exception {

public:

	Human();
	Human(string name, string sName, string pName, int setAge, int setHeight, int workingOrNot)

		:FirstName_("Jane"),
		SurName_(""),
		PantonymicName_(""),
		age_(15),
		height_(150),
		birthDate_(std::tm())
	{
		this->FirstName_ = name;
		this->SurName_ = sName;
		this->PantonymicName_ = pName;
		this->age_ = setAge;
		this->height_ = setHeight;
		this->isWorking_ = workingOrNot;
	}


	// setter and getters
	void setName(string name, string sName, string pName) {
		this->FirstName_ = name;
		this->SurName_ = sName;
		this->PantonymicName_ = pName;
	}
	string getName() const noexcept {
		return (FirstName_ + " " + SurName_ + " " + PantonymicName_);
	}

	void setAge(int setAge) {
		if (setAge <= 0) {
			throw std::invalid_argument("Invalid Age");
		}
		this->age_ = setAge;
	}
	int getAge() const noexcept {
		return age_;
	}

	void setHeight(int setHeight) {
		height_ = setHeight;
	}
	int getHeight() const {
		return height_;
	}

	void setIsWorking(bool workingOrNot) {
		this->isWorking_ = workingOrNot;
	}
	bool getIsWorking() const noexcept {
		return isWorking_;
	}

	// predicate
	bool isAdult();
	// operators and traits
	friend bool operator == (Human a, Human b);

	bool olderThen(int age);

private:
	string FirstName_ = "";
	string SurName_ = "";
	string PantonymicName_ = "";
	tm birthDate_;
	int age_ = 0;
	int height_ = 150;
	bool isWorking_ = true;
};

void foo(int value) {
	if (value < 0)
	{
		throw exception("Возраст меньше 0 !!! ");
	}

	if (value >= 1) {
		throw Human();
	}

	cout << "Переменная = " << value << endl;
}



int main() {
	setlocale(LC_ALL, "Russian");
	Human h;

	// Полное имя человека
	h.setName("Roman", "Perekrasov", "Olegovich");
	string Name = h.getName();

	// Возраст человека

	try {
		foo(1);


	}
	catch (std::exception& ex) {
		std::cerr << "Мы поймали " << ex.what() << endl;
	}
	catch (...) {
		std::cerr << "Мы поймали " << "undefined exception";
	}
	int Age = h.getAge();

	// Рост человека
	h.setHeight(177);
	int Height = h.getHeight();

	// Наличие работы
	h.setIsWorking(true);
	bool WorkingOrNot = h.getIsWorking();

	cout << "Human: " << Name << "\n";
	cout << "Age: " << Age << "\n";
	cout << "Height: " << Height << "\n";
	cout << "Is working?: ";
	if (WorkingOrNot)
		cout << "True" << endl;
	else
		cout << "False" << endl;



	return 0;
}

Human::Human()
	:FirstName_(""),
	SurName_(""),
	PantonymicName_(""),
	birthDate_({}),
	age_(15),
	height_(150)
{
	// to-do data insertion
}


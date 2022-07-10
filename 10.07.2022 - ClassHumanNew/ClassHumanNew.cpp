#include <iostream>
#include <string>
#include <ctime>//chrono
#include <exception>

using namespace std;

class Human {

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

// Задание 1а

class Student {
public:
	Student();
	Student(Human person, int grades[5], string group, string direction) {
		this->person_ = person;
		for (int i = 0; i < 5; i++)
			this->grades_[i] = grades[i];
		this->group_ = group;
		this->direction_ = direction;
	}

	// setters and getters
	void setHuman(Human person) {
		this->person_ = person;
	}
	Human getHuman() const {
		return person_;
	}

	void setGrades(float grades[5]) {
		for (int i = 0; i < 5; i++)
			this->grades_[i] = grades[i];
	}
	int getAverageGrade() const {
		float sum = 0;
		for (int i = 0; i < 5; i++)
			sum += grades_[i];
		return sum / 5;
	}

	void setGroup(string group) {
		this->group_ = group;
	}
	string getGroup() const {
		return group_;
	}

	void setDirection(string direction) {
		this->direction_ = direction;
	}

	string getDirection() const {
		return direction_;
	}

private:
	Human person_;

	// Хранение успеваемости студента
	float grades_[5];
	string group_;
	string direction_;
};

// Задание 1б

class Appartment {
public:
	Human person;
	Appartment();
	Appartment(Human person, string adress, double square, string listOfTenants[10], double livingWageCoefficcient) {
		this->adress_ = adress;
		this->square_ = square;
		for (int i = 0; i < 10; i++)
			this->listOfTenants_[i] = listOfTenants[i];
		this->livingWageCoefficient_ = livingWageCoefficcient;
	}
	// setters and getters
	void setAdress(string adress) {
		this->adress_ = adress;
	}

	string getAdress() const {
		return adress_;
	}

	void setSquare(double square) {
		this->square_ = square;
	}

	double getSquare() const {
		return square_;
	}

	void setListOfTenants(string listOfTenants[10]) {
		for (int i = 0; i < 10; i++)
			this->listOfTenants_[i] = listOfTenants[i];
	}

	string getListOfTenants() const {
		string listOfTenants;
		listOfTenants += "\n";
		for (int i = 0; i < 10; i++)
			if (i < 9)
				listOfTenants += listOfTenants_[i] + " \n";
			else
				listOfTenants += listOfTenants_[i];

		return listOfTenants;
	}

	void setLivingWage(double livingWageCoefficcient) {
		this->livingWageCoefficient_ = livingWageCoefficcient;
	}

	double getLivingWage() const {
		return livingWageCoefficient_;
	}

private:
	string adress_;
	double square_;
	string listOfTenants_[10];
	double livingWageCoefficient_;
};

// Задание 3

class Fraction {
public:
	Fraction();
	Fraction(int numerator, int denominator) {
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	// setters and getters
	void composition(int numerator, int denominator) {
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	int getCompositionResult() const {
		return numerator_ + denominator_;
	}

	void subtraction(int numerator, int denominator) {
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	int getSubtractionResult() const {
		return numerator_ - denominator_;
	}

	void multiplication(int numerator, int denominator) {
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	int getMultiplicationResult() const {
		return numerator_ * denominator_;
	}

	void division(int numerator, int denominator) {
		this->numerator_ = numerator;
		this->denominator_ = denominator;
	}

	int getDivisionResult() const {
		return numerator_ / denominator_;
	}

private:
	int numerator_;
	int denominator_;
};

int main() {
	setlocale(LC_ALL, "Russian");
	Human h;

	// Полное имя человека
	h.setName("Roman", "Perekrasov", "Olegovich");
	string Name = h.getName();

	// Возраст человека

	try {
		h.setAge(0);

	}
	catch (std::exception& ex) {
		std::cerr << ex.what();
	}
	catch (...) {
		std::cerr << "undefined exception";
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

	// Задание 1a

	cout << "\nTast 1a\n";

	Student Vasya;


	Vasya.setHuman(h);
	Vasya.getHuman();

	float VasyaGrades[5] = { 5.0, 4.0, 5.0, 4.0, 5.0 };
	Vasya.setGrades(VasyaGrades);
	int VasyaAvgGrades = Vasya.getAverageGrade();

	Vasya.setGroup("BV111");
	string VasyaGroup = Vasya.getGroup();

	Vasya.setDirection("IT");
	string VasyaDirection = Vasya.getDirection();

	cout << "\nStudent: Vasya" << "\n";
	cout << "Average grade: " << VasyaAvgGrades << "\n";
	cout << "Group: " << VasyaGroup << "\n";
	cout << "Specialization: " << VasyaDirection << "\n";

	// Задание 1б

	cout << "\nTast 1b\n";

	Appartment VasyasHouse;
	VasyasHouse.setAdress("Industrii street 21-11");
	string VasyasAdress = VasyasHouse.getAdress();

	VasyasHouse.setSquare(60.0);
	double VasyasHouseSquare = VasyasHouse.getSquare();

	string listOfTenants[10] = { "Katya", "Petya", "Nastya", "Volodya", "Dima", "Olga", "Helga", "Vita", "Gerda", "Kai" };
	VasyasHouse.setListOfTenants(listOfTenants);
	string listOfTenantsFull = VasyasHouse.getListOfTenants();

	VasyasHouse.setLivingWage(59.0);
	double livingWageCoefficient = VasyasHouse.getLivingWage();


	cout << "\nVasya's Adress: " << VasyasAdress << "\n";
	cout << "Vasya's square amount: " << VasyasHouseSquare << "\n";
	cout << "Vasya's list of Tenants: " << listOfTenantsFull << "\n";
	cout << "Living Wage Coefficient: ";
	while (livingWageCoefficient) {
		if (livingWageCoefficient >= 33.0 && livingWageCoefficient <= 42.0) {
			cout << "Family of 2 people\n";
			break;
		}
		else
			if (livingWageCoefficient >= 42.0 && livingWageCoefficient <= 60.0) {
				cout << "Family of 3 people\n";
				break;
			}
			else
				if (livingWageCoefficient >= 60.0) {
					cout << "Family of 4 and more people\n";
					break;
				}
	}

	// Задание 3

	cout << "\nTask 3\n";

	Fraction numbers;
	int x, y;
	cout << "\nEnter two numbers for composion: ";
	cin >> x >> y;
	numbers.composition(x, y);
	int composition = numbers.getCompositionResult();

	cout << "Enter two numbers for subtraction: ";
	cin >> x >> y;
	if (x < y)
		swap(x, y);
	numbers.subtraction(x, y);
	int subtraction = numbers.getSubtractionResult();

	cout << "Enter two numbers for multiplication: ";
	cin >> x >> y;
	if (x, y)
		numbers.multiplication(x, y);
	int multiplication = numbers.getMultiplicationResult();

	cout << "Enter two number for division: ";
	cin >> x >> y;
	if (x < y)
		swap(x, y);
	numbers.division(x, y);
	int division = numbers.getDivisionResult();

	cout << "\nComposition: " << composition << "\n";
	cout << "Subtraction: " << subtraction << "\n";
	cout << "Multiplication: " << multiplication << "\n";
	cout << "Division: " << division << "\n";

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

// Задание 3

Fraction::Fraction()
	:numerator_(1),
	denominator_(1)
{
}


// Задание 1б

Appartment::Appartment()
	:adress_("Lenina Street"),
	square_(0),
	listOfTenants_(),
	livingWageCoefficient_(30)
{
}

// Задание 1a

Student::Student()
	:grades_(),
	group_(""),
	direction_("")
{
}


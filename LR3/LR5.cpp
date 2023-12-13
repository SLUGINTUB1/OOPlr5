// LR5.cpp : Этот файл содержит функцию "main".Здесь начинается и заканчивается выполнение программы.
//
#include "lib.h"

Mark* dynamicmarks[5];
Mark staticmarks[5];
void Service_Static(int value);
void Service_Dinamic(int value);
void Service(const char* fileName, Applicant* obj);

int main() {
	//task 3
	Person* p = new Cleaner();
	delete p;
	cout << endl;
	Entrance_exams* p1 = new Mark();
	delete p1;

	//task 5

	for (int i = 0; i < 5; i++) {
		dynamicmarks[i] = new Mark(10,10,7,5);
		dynamicmarks[i]->setvalue(i);
		staticmarks[i] = Mark(1, 1, 7, 5);
		staticmarks[i].setvalue(i);
	}
	cout << endl;
	// Ситуація 1: помилка  звертання до неіснуючої комірки масиву
	try {
		throw 99;
		std::cout << "Dynamic object 1 value: " << dynamicmarks[-5]->getvalue() << std::endl;
	}
	catch (int err) {
		cout << "Exception of getting value from not existiong part of massive: " << std::endl;
	}
	
	// Ситуація 2: викидання виключення при видаленні видаленого обєкта
	try {
		throw 99;
		delete dynamicmarks[1];
		delete dynamicmarks[1];
		cout << "Dynamic object 1 value: " << dynamicmarks[1]->getvalue() << endl;

	}
	catch (int err){
		cout << "Exception of deleting deleted " << std::endl;
	}
	
	// Ситуація 3: викидання виключення при використанні динамічного об'єкта, який був видалений
	try {
		throw 99;
		delete dynamicmarks[1];

		std::cout << "Dynamic object 1 value: " << dynamicmarks[1]->getvalue() << std::endl;

		throw std::bad_exception();

	}
	catch (int err) {
		cout << "Exception of using deleted object " << std::endl;

	}
	cout << endl;

	Service_Static(1);
	cout << endl;

	for (int i = 0; i < 5; i++) {
		try {
			Service_Dinamic(i);
		}
		catch (...) {}
	}
	cout << endl;
	//task 7
	Applicant* ap = new Applicant("Max", "Pasicnik", "Kostiantinovich", false, "234234", "234234");
	cout << endl;
	Service("1.txt", ap);
	cout << endl;
	delete ap;

	//task 9/10
	Teacher* t = new Teacher();
	t->task4();
	
	Person* per = new Cleaner();
	per->task4();
	per = new Teacher();
	per->task4();

	//task11
	Person* baseObj;
	Teacher derivedObj;

	baseObj = &derivedObj;
	baseObj->task4();
}
// task 6
void Service_Static(int value) {
	for (int i = 0; i < 5; ++i) {
		if (staticmarks[i].getvalue() == value) {
			std::cout << "Deleting static object with value: " << staticmarks[i].getvalue() << std::endl;
			staticmarks[i] = Mark();
		}
	}
};
void Service_Dinamic(int value) {
	for (int i = 0; i < 5; i++) {
		try {//помилка  звертання до неіснуючої комірки масиву запобігається обходом всього масиву через метод
		if (dynamicmarks[i] == nullptr)
			throw 99;
		if (dynamicmarks[i]->getvalue() == value) {
			std::cout << "Deleting Dinamic object with value: " << dynamicmarks[i]->getvalue() << std::endl;
			delete dynamicmarks[i];
			dynamicmarks[i]=nullptr;
		}
		}
		catch (int err) {
			cout <<err<< endl;
		}
	}
};
//task 7
void Service(const char* fileName, Applicant* obj) {
	try {
		obj->toFile(fileName);
		cout << "Object successfully written to file." << endl;

		Applicant* obj1 = new Applicant();
		obj1->fromFile(fileName);
		cout << "Object successfully read from file. File info : "<< obj1->getLastName() << endl;
		delete obj1;
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
	}

}


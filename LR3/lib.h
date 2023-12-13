#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <vector>

using namespace std;

class Entrance_exams {
protected:
    void basetoFile(size_t t,const char* file_path);
    void basefromFile(size_t t,const char* file_path);
public:
    Entrance_exams();
    ~Entrance_exams();
    
    virtual void toFile()=0;
    virtual void toFile(const char* file_path)=0;
    virtual void fromFile()=0;
    virtual void fromFile(const char* file_path)=0;
};

class Mark : public Entrance_exams {
private: 
    int value;
    int subjectID;
    int day;
    int month;
    int year;
public:
    bool evaluated;
    bool passed;
    char teacher[30];

    Mark();
    Mark(int _subjectID, int _day, int _month, int _year);
    Mark(const Mark& _mark);
    ~Mark();
    
    // сетери
    void setvalue(int _value);

    void setsubjectID(int _subjectID);

    void setday(int _day);

    void setmonth(int _month);

    void setyear(int _year);

    // гетери
    int getvalue();

    int getsubjectID();

    int getday();

    int getmonth();

    int getyear();

    void Copy(Mark a);

    friend class Budy;

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

class Exam : public Entrance_exams {
private:
    Mark mathematics;
    Mark physics;
    Mark chemistry;
    Mark history;
    Mark literature;
public:
    Mark geography;
    Mark computerScience;
    int total_value;

    Exam();
    Exam(int _day, int _month, int _year);
    Exam(const Exam& _exam);
    ~Exam();
  
    // Сетери
    void setMathematics(Mark grade);

    void setPhysics(Mark grade);

    void setChemistry(Mark grade);

    void setHistory(Mark grade);

    void setLiterature(Mark grade);

    // Гетери
    Mark getMathematics();

    Mark getPhysics();

    Mark getChemistry();

    Mark getHistory();

    Mark getLiterature();

    void calculate_total_value();

    void Copy(Exam a);

    friend void displayData(const Exam& obj);
    friend void displayData(const Exam* obj);

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

//task 1
class Person :public Entrance_exams {
protected:
    char first_name[30];
    char last_name[30];
    char father_name[30];
    bool gender;
    
    void changeGender();
    void clearEmail();
    void clearPhone_number();
public:
    char email[50];
    char phone_number[13];

    Person();
    Person(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Person(Person& _person);
    //task 3
    virtual ~Person();//task3
    
    // сетери
    void setFirstName(const char* _first_name);

    void setLastName(const char* _last_name);

    void setFatherName(const char* _father_name);

    void setGender(bool _gender);

    // гетери 
    char* getFirstName();

    char* getLastName();

    char* getFatherName();

    bool getGender();

    //task 4
    virtual void task4() const = 0;

    virtual void Copy(Person& a) = 0;
};

class Applicant :public Person {
public:
    Exam exam_score;

    Applicant();
    Applicant(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Applicant(Applicant& _applicant);
    ~Applicant() override;//task 3

    void Copy(Person& a) override;
    //task4
    void task4() const override { cout << "Applicant task 4" << endl; };

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

class Teacher : public Person {
public:
    int subjectID;

    Teacher();
    Teacher(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number, int _subjectID);
    Teacher(Teacher& _teacher);
    ~Teacher() override;//task 3

    void evaluation(Mark _mark, int valule);

    void evaluation(Exam _exam, int valule);

    void evaluation(Applicant _applicant, int valule);

    void Copy(Person& a) override;


    //task4
    void task4() const override { cout << "Teacher task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

//task 1
class Rector : public Person{
public:
    Rector();
    Rector(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Rector(Rector& _rector);
    ~Rector() override;//task3

    void Copy(Person& a) override;
    void exercisesPolicyMaking();


    //task4
    void task4() const override { cout << "Rector task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};
//task 1
class Guardian :public Person {
public:
    Guardian();
    Guardian(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Guardian(Guardian& _rector);
    ~Guardian() override;//task3

    void Copy(Person& a) override;
    void guard();


    //task4
    void task4() const override { cout << "Guardian task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};
//task 1
class Cleaner :public Person {
public:
    Cleaner();
    Cleaner(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Cleaner(Cleaner& _rector);
    ~Cleaner() override;//task3

    void Copy(Person& a) override;//task 4
    void clean();
    //task4
    void task4() const override { cout << "Cleaner task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

class Lector : private Teacher {
public:
    Lector();
    Lector(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number, int _subjectID);
    Lector(Teacher& _teacher);
    ~Lector();

    //seter
    void setFirstName(const char* _first_name);

    void setLastName(const char* _last_name);

    void setFatherName(const char* _father_name);

    void setGender(bool _gender);

    // гетери 
    char* getFirstName();

    char* getLastName();

    char* getFatherName();

    bool getGender();

    int getSubjectID();

    void setSubjectID(int value);

    void Copy(Teacher a);
};

//task 2
class A : virtual public Applicant {
public:
     A();
    ~A();
};
//task 2
class B : virtual public Teacher {
public:
     B();
    ~B();
};
//task 2
class C : virtual public Lector {
public:
    C();
    ~C();
};
class ABC : public A, public B, public C {
public:
    ABC();
    ~ABC();
};

class Faculty : public Entrance_exams {
private:
    char name[50];
    char code[5];
    int foundation_year;
    vector<Applicant*> applicants;
    vector<Teacher*> teachers;
public:
    char dean_first_name[30];
    char dean_last_name[30];
    char dean_father_name[30];

    Faculty();
    Faculty(const char* _name, const char* _code, const char* _dean_first_name, const char* _dean_last_name, const char* _dean_father_name, int _foundation_year);
    Faculty(const Faculty& _faculty);
    ~Faculty();
    
    // сетери
    void setName(const char* _name);

    void setCode(const char* _code);

    void setFoundationYear(int _foundation_year);

    void setApplicants(const vector<Applicant*> newVector);

    void setTeachers(const vector<Teacher*> newVector);

    // гетери 
    char* getName();

    char* getCode();

    int getFoundationYear();

    vector<Applicant*> getApplicants();

    vector<Teacher*> getTeachers();

    void registration(Applicant *_faculty);

    void Copy(Faculty a);
    
    Faculty getdefaultFaculty();

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

void displayData(const Exam& obj);
void displayData(const Exam* obj);

class Budy {
public:
    static int howmany;
    static void displayData(const Mark& obj);
};

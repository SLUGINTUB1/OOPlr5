#include "lib.h"
#include <typeinfo>
#include <iostream>
#include <fstream>

//task 7
void Entrance_exams::basetoFile(size_t t, const char* file_path) {
    // Open a binary file for writing
    FILE* f = fopen(file_path, "w");

    ofstream wf(file_path);
    if (!wf) {
        //Помилка 1: неможливо відкрити файл
        throw runtime_error("Cannot open file!");
    }
    wf.write((char*)this, t);
    wf.close();
    if (!wf.good()) {
        //Помилка 2: помилка запису в файл
        throw runtime_error("Error occurred at writing time!");
    }
}
void Entrance_exams::basefromFile(size_t t, const char* file_path) {
    ifstream rf(file_path);
    if (!rf) {
        //Помилка 3: неможливо відкрити файл
        throw runtime_error("Cannot open file!");
    }

    rf.read((char*)this, t);
    rf.close();
    if (!rf.good()) {
        //Помилка 4: неможливо прочитати файл
        throw runtime_error("Error occurred at reading time!");
    }
}

void Mark::toFile() {
    basetoFile(sizeof(Mark),"indo.txt");
}

void Mark::toFile(const char* file_path) {
    basetoFile(sizeof(Mark), file_path);
}

void Mark::fromFile() {
    basefromFile(sizeof(Mark), "indo.txt");
}

void Mark::fromFile(const char* file_path) {
    basefromFile(sizeof(Mark), file_path);
}

void Exam::toFile() {
    basetoFile(sizeof(Exam), "indo.txt");
}

void Exam::toFile(const char* file_path) {
    basetoFile(sizeof(Exam), file_path);
}

void Exam::fromFile() {
    basefromFile(sizeof(Exam), "indo.txt");
}

void Exam::fromFile(const char* file_path) {
    basefromFile(sizeof(Exam), file_path);
}

void Applicant::toFile() {
    basetoFile(sizeof(Applicant), "indo.txt");
}

void Applicant::toFile(const char* file_path) {
    basetoFile(sizeof(Applicant), file_path);
}

void Applicant::fromFile() {
    basefromFile(sizeof(Applicant), "indo.txt");
}

void Applicant::fromFile(const char* file_path) {
    basefromFile(sizeof(Applicant), file_path);
}

void Teacher::toFile() {
    basetoFile(sizeof(Teacher), "indo.txt");
}

void Teacher::toFile(const char* file_path) {
    basetoFile(sizeof(Teacher), file_path);
}

void Teacher::fromFile() {
    basefromFile(sizeof(Teacher), "indo.txt");
}

void Teacher::fromFile(const char* file_path) {
    basefromFile(sizeof(Teacher), file_path);
}

void Rector::toFile() {
    basetoFile(sizeof(Rector), "indo.txt");
}

void Rector::toFile(const char* file_path) {
    basetoFile(sizeof(Rector), file_path);
}

void Rector::fromFile() {
    basefromFile(sizeof(Rector), "indo.txt");
}

void Rector::fromFile(const char* file_path) {
    basefromFile(sizeof(Rector), file_path);
}

void Guardian::toFile() {
    basetoFile(sizeof(Guardian), "indo.txt");
}

void Guardian::toFile(const char* file_path) {
    basetoFile(sizeof(Guardian), file_path);
}

void Guardian::fromFile() {
    basefromFile(sizeof(Guardian), "indo.txt");
}

void Guardian::fromFile(const char* file_path) {
    basefromFile(sizeof(Guardian), file_path);
}

void Cleaner::toFile() {
    basetoFile(sizeof(Cleaner), "indo.txt");
}

void Cleaner::toFile(const char* file_path) {
    basetoFile(sizeof(Cleaner), file_path);
}

void Cleaner::fromFile() {
    basefromFile(sizeof(Cleaner), "indo.txt");
}

void Cleaner::fromFile(const char* file_path) {
    basefromFile(sizeof(Cleaner), file_path);
}

void Faculty::toFile() {
    basetoFile(sizeof(Faculty), "indo.txt");
}

void Faculty::toFile(const char* file_path) {
    basetoFile(sizeof(Faculty), file_path);
}

void Faculty::fromFile() {
    basefromFile(sizeof(Faculty), "indo.txt");
}

void Faculty::fromFile(const char* file_path) {
    basefromFile(sizeof(Faculty), file_path);
}

Entrance_exams::Entrance_exams() {
    cout << "Entrance_exams constractor" << endl;
}
Entrance_exams::~Entrance_exams() {
    cout << "Entrance_exams destractor" << endl;
}



Mark::Mark() :value(0), subjectID(0), day(1), month(1), year(2000), evaluated(false), passed(false), teacher("") { cout << "Mark constractor" << endl; }

Mark::Mark(int _subjectID, int _day, int _month, int _year) :value(0), evaluated(false), passed(false), teacher("") {
    subjectID = _subjectID;
    day = _day;
    month = _month;
    year = _year;
    cout << "Mark constractor" << endl;
}

Mark::Mark(const Mark& _mark) {
    Copy(_mark);
    cout << "Mark constractor" << endl;
}

Mark::~Mark() {
    cout << "Mark destractor" << endl;
}

// сетери
void Mark::setvalue(int _value) {
    value = _value;
}

void Mark::setsubjectID(int _subjectID) {
    subjectID = _subjectID;
}

void Mark::setday(int _day) {
    day = _day;
}

void Mark::setmonth(int _month) {
    month = _month;
}

void Mark::setyear(int _year) {
    year = _year;
}

// гетери
int Mark::getvalue() {
   return value;
}

int Mark::getsubjectID() {
    return subjectID;
}

int Mark::getday() {
    return day;
}

int Mark::getmonth() {
    return month;
}

int Mark::getyear() {
    return year;
}

void Mark::Copy(Mark a) {
    value = a.value;
    subjectID = a.subjectID;
    day = a.day;
    month = a.month;
    year = a.year;
    evaluated = a.evaluated;
    passed = a.passed;
    strncpy(teacher, a.teacher, sizeof(teacher) - 1);
}



Exam::Exam() :mathematics(Mark()), physics(Mark()), chemistry(Mark()), history(Mark()), literature(Mark()), geography(Mark()), computerScience(Mark()), total_value(0) { cout << "Exam constractor" << endl; }

Exam::Exam(int _day, int _month, int _year) {
    mathematics = Mark(1, _day, _month, _year);
    physics = Mark(2, _day, _month, _year);
    chemistry = Mark(3, _day, _month, _year);
    history = Mark(4, _day, _month, _year);
    literature = Mark(5, _day, _month, _year);
    geography = Mark(6, _day, _month, _year);
    computerScience = Mark(7, _day, _month, _year);
    total_value = 0;
    cout << "Exam constractor" << endl;
}

Exam::Exam(const Exam& _exam) {
    Copy(_exam);
    cout << "Exam constractor" << endl;
}
Exam::~Exam() {
    cout << "Exam destractor" << endl;
}

// Сетери
void Exam::setMathematics(Mark grade) {
    mathematics.Copy(grade);
}

void Exam::setPhysics(Mark grade) {
    physics.Copy(grade);
}

void Exam::setChemistry(Mark grade) {
    chemistry.Copy(grade);
}

void Exam::setHistory(Mark grade) {
    history.Copy(grade);
}

void Exam::setLiterature(Mark grade) {
    literature.Copy(grade);
}

// Гетери
Mark Exam::getMathematics() {
    return mathematics;
}

Mark Exam::getPhysics() {
    return physics;
}

Mark Exam::getChemistry() {
    return chemistry;
}

Mark Exam::getHistory() {
    return history;
}

Mark Exam::getLiterature() {
    return literature;
}

void Exam::calculate_total_value() {
    total_value = (mathematics.getvalue() + physics.getvalue() + chemistry.getvalue() + history.getvalue() + literature.getvalue() + geography.getvalue() + computerScience.getvalue()) / 7;
}

void Exam::Copy(Exam a) {
    mathematics.Copy(a.getMathematics());
    physics.Copy(a.getPhysics());
    chemistry.Copy(a.getChemistry());
    history.Copy(a.getHistory());
    literature.Copy(a.getLiterature());
    geography = a.geography;
    computerScience = a.computerScience;
    calculate_total_value();
}

void Applicant::Copy(Person& a)
{
    if (typeid(a) == typeid(Applicant)) {
        strncpy(first_name, a.getFirstName(), sizeof(first_name) - 1);
        strncpy(last_name, a.getLastName(), sizeof(last_name) - 1);
        strncpy(father_name, a.getFatherName(), sizeof(father_name) - 1);
        gender = a.getGender();
        strncpy(email, a.email, sizeof(email) - 1);
        strncpy(phone_number, a.phone_number, sizeof(phone_number) - 1);

        Applicant* applicant = dynamic_cast<Applicant*>(&a);
        exam_score.Copy(applicant->exam_score);
        delete applicant;
    }
    else {
        cout << "wrong input class" << endl;
    }
}

Person::Person() : first_name(""), last_name(""), father_name(""), gender(true), email(""), phone_number("") { cout << "Person constractor" << endl; }

Person::Person(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number) {
    strncpy(first_name, _first_name, sizeof(first_name) - 1);
    strncpy(last_name, _last_name, sizeof(last_name) - 1);
    strncpy(father_name, _father_name, sizeof(father_name) - 1);
    gender = _gender;
    strncpy(email, _email, sizeof(email) - 1);
    strncpy(phone_number, _phone_number, sizeof(phone_number) - 1);
    cout << "Person constractor" << endl;
}

Person::Person(Person& _person) {
    strncpy(first_name, _person.getFirstName(), sizeof(first_name) - 1);
    strncpy(last_name, _person.getLastName(), sizeof(last_name) - 1);
    strncpy(father_name, _person.getFatherName(), sizeof(father_name) - 1);
    gender = _person.getGender();
    strncpy(email, _person.email, sizeof(email) - 1);
    strncpy(phone_number, _person.phone_number, sizeof(phone_number) - 1);
    cout << "Person constractor" << endl;
}
Person::~Person() {
    cout << "Person destractor" << endl;
}

// сетери
void Person::setFirstName(const char* _first_name) {
    strncpy(first_name, _first_name, sizeof(first_name) - 1);
}

void Person::setLastName(const char* _last_name) {
    strncpy(last_name, _last_name, sizeof(last_name) - 1);
}

void Person::setFatherName(const char* _father_name) {
    strncpy(father_name, _father_name, sizeof(father_name) - 1);
}

void Person::setGender(bool _gender) {
    gender = _gender;
}

// гетери 
char* Person::getFirstName() {
    return first_name;
}

char* Person::getLastName() {
    return last_name;
}

char* Person::getFatherName() {
    return father_name;
}

bool Person::getGender() {
    return gender;
}

void Person::changeGender() {
    gender = !gender;
}

void Person::clearEmail() {
    strncpy(email, "", sizeof(email) - 1);
}

void Person::clearPhone_number() {
    strncpy(phone_number, "", sizeof(phone_number) - 1);
}




Applicant::Applicant() :Person() {
    cout << "Applicant constractor" << endl;
}

Applicant::Applicant(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number) : Person(_first_name, _last_name, _father_name, _gender, _email, _phone_number) {
    cout << "Applicant constractor" << endl;
}

Applicant::Applicant(Applicant& _applicant) {
    Copy(_applicant);
    cout << "Applicant constractor" << endl;
}
Applicant::~Applicant() {
    cout << "Applicant destractor" << endl;
}




Teacher::Teacher() :Person() {
    subjectID = 0;
    cout << "Teacher constractor" << endl;
}

Teacher::Teacher(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number, int _subjectID) :Person(_first_name, _last_name, _father_name, _gender, _email, _phone_number) {
    subjectID = _subjectID;
    cout << "Teacher constractor" << endl;
}

Teacher::Teacher(Teacher& _teacher) {
    Copy(_teacher);
    cout << "Teacher constractor" << endl;
}
Teacher::~Teacher() {
    cout << "Teacher destractor" << endl;
}
void Teacher::evaluation(Mark _mark, int valule) {
    if (subjectID = _mark.getsubjectID())
        _mark.setvalue(valule);
}

void Teacher::evaluation(Exam _exam, int valule) {
    evaluation(_exam.getMathematics(), valule);
    evaluation(_exam.getPhysics(), valule);
    evaluation(_exam.getChemistry(), valule);
    evaluation(_exam.getHistory(), valule);
    evaluation(_exam.getLiterature(), valule);
    evaluation(_exam.geography, valule);
    evaluation(_exam.computerScience, valule);
    _exam.calculate_total_value();
}

void Teacher::evaluation(Applicant _applicant, int valule) {
    evaluation(_applicant.exam_score, valule);
}

void Teacher::Copy(Person& a) {
    if (typeid(a) == typeid(Teacher)) {
        strncpy(first_name, a.getFirstName(), sizeof(first_name) - 1);
        strncpy(last_name, a.getLastName(), sizeof(last_name) - 1);
        strncpy(father_name, a.getFatherName(), sizeof(father_name) - 1);
        gender = a.getGender();
        strncpy(email, a.email, sizeof(email) - 1);
        strncpy(phone_number, a.phone_number, sizeof(phone_number) - 1);

        Teacher* teacher = dynamic_cast<Teacher*>(&a);
        subjectID = teacher->subjectID;
        delete teacher;
    }
    else {
        cout << "wrong input class" << endl;
    }
}
//task 1
Rector::Rector():Person() { cout << "Rector constractor" << endl; };
Rector::Rector(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number) :Person(_first_name, _last_name, _father_name, _gender, _email, _phone_number) { cout << "Rector constractor" << endl; };
Rector::Rector(Rector& _rector) :Person(_rector) { cout << "Rector constractor" << endl; };
Rector::~Rector() { cout << "Rector destractor" << endl; };
void Rector::Copy(Person& a) {
    if (typeid(a) == typeid(Rector)) {
        strncpy(first_name, a.getFirstName(), sizeof(first_name) - 1);
        strncpy(last_name, a.getLastName(), sizeof(last_name) - 1);
        strncpy(father_name, a.getFatherName(), sizeof(father_name) - 1);
        gender = a.getGender();
        strncpy(email, a.email, sizeof(email) - 1);
        strncpy(phone_number, a.phone_number, sizeof(phone_number) - 1);
    }
    else {
        cout << "wrong input class" << endl;
    }
};
void Rector::exercisesPolicyMaking() { cout << "do Rector stuff" << endl; }
//task 1
Guardian::Guardian() :Person() { cout << "Guardian constractor" << endl; };
Guardian::Guardian(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number) :Person(_first_name, _last_name, _father_name, _gender, _email, _phone_number) { cout << "Guardian constractor" << endl; };
Guardian::Guardian(Guardian& _guardian) :Person(_guardian) { cout << "Guardian constractor" << endl; };
Guardian::~Guardian() { cout << "Guardian destractor" << endl; };
void Guardian::Copy(Person& a) {
    if (typeid(a) == typeid(Guardian)) {
        strncpy(first_name, a.getFirstName(), sizeof(first_name) - 1);
        strncpy(last_name, a.getLastName(), sizeof(last_name) - 1);
        strncpy(father_name, a.getFatherName(), sizeof(father_name) - 1);
        gender = a.getGender();
        strncpy(email, a.email, sizeof(email) - 1);
        strncpy(phone_number, a.phone_number, sizeof(phone_number) - 1);
    }
    else {
        cout << "wrong input class" << endl;
    }
};
void Guardian::guard() { cout << "guard" << endl; }
//task 1
Cleaner::Cleaner() :Person() { cout << "Cleaner constractor" << endl; };
Cleaner::Cleaner(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number) :Person(_first_name, _last_name, _father_name, _gender, _email, _phone_number) { cout << "Cleaner constractor" << endl; };
Cleaner::Cleaner(Cleaner& _cleaner) :Person(_cleaner) { cout << "Cleaner constractor" << endl; };
Cleaner::~Cleaner() { cout << "Cleaner destractor" << endl; };
void Cleaner::Copy(Person& a) {
    if (typeid(a) == typeid(Cleaner)) {
        strncpy(first_name, a.getFirstName(), sizeof(first_name) - 1);
        strncpy(last_name, a.getLastName(), sizeof(last_name) - 1);
        strncpy(father_name, a.getFatherName(), sizeof(father_name) - 1);
        gender = a.getGender();
        strncpy(email, a.email, sizeof(email) - 1);
        strncpy(phone_number, a.phone_number, sizeof(phone_number) - 1);
    }
    else {
        cout << "wrong input class" << endl;
    }
};
void Cleaner::clean() { cout << "clean" << endl; }

Lector::Lector() :Teacher() { cout << "Lector constractor" << endl; }

Lector::Lector(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number, int _subjectID) :Teacher(_first_name, _last_name, _father_name, _gender, _email, _phone_number, _subjectID) { cout << "Lector constractor" << endl; }

Lector::Lector(Teacher& _teacher) :Teacher(_teacher) { cout << "Lector constractor" << endl; }

Lector::~Lector() {
    cout << "Lector destractor" << endl;
}

int Lector::getSubjectID() {
    return subjectID;
}

void Lector::setSubjectID(int value) {
    subjectID = value;
}

void Lector::Copy(Teacher a) {
    Teacher::Copy(a);
}

char* Lector::getFirstName() {
    return first_name;
}

char* Lector::getLastName() {
    return last_name;
}

char* Lector::getFatherName() {
    return father_name;
}

bool Lector::getGender() {
    return gender;
}



Faculty::Faculty() : name(""), code(""), dean_first_name(""), dean_last_name(""), dean_father_name(""), foundation_year(0) {
    cout << "Faculty constractor" << endl;
}

Faculty::Faculty(const char* _name, const char* _code, const char* _dean_first_name, const char* _dean_last_name, const char* _dean_father_name, int _foundation_year) {
    strncpy(name, _name, sizeof(name) - 1);
    strncpy(code, _code, sizeof(code) - 1);
    strncpy(dean_first_name, _dean_first_name, sizeof(dean_first_name) - 1);
    strncpy(dean_last_name, _dean_last_name, sizeof(dean_last_name) - 1);
    strncpy(dean_father_name, _dean_father_name, sizeof(dean_father_name) - 1);
    foundation_year = _foundation_year;
    cout << "Faculty constractor" << endl;
}

Faculty::Faculty(const Faculty& _faculty) {
    Copy(_faculty);
    cout << "Faculty constractor" << endl;
}
Faculty::~Faculty() {
    cout << "Faculty destractor" << endl;
}

// сетери
void Faculty::setName(const char* _name) {
    strncpy(name, _name, sizeof(name) - 1);
}

void Faculty::setCode(const char* _code) {
    strncpy(code, _code, sizeof(code) - 1);
}

void Faculty::setFoundationYear(int _foundation_year) {
    foundation_year = _foundation_year;
}

void Faculty::setApplicants(const vector<Applicant*> newVector) {
    applicants = newVector;
}

void Faculty::setTeachers(const vector<Teacher*> newVector) {
    teachers = newVector;
}

// гетери 
char* Faculty::getName() {
    return name;
}

char* Faculty::getCode() {
    return code;
}

int Faculty::getFoundationYear() {
    return foundation_year;
}

vector<Applicant*> Faculty::getApplicants() {
    return applicants;
}

vector<Teacher*> Faculty::getTeachers() {
    return teachers;
}

void Faculty::registration(Applicant* _applicant) {
    applicants.push_back(_applicant);
}

void Faculty::Copy(Faculty a) {
    strncpy(name, a.getName(), sizeof(name) - 1);
    strncpy(code, a.getCode(), sizeof(code) - 1);
    strncpy(dean_first_name, a.dean_first_name, sizeof(dean_first_name) - 1);
    strncpy(dean_last_name, a.dean_last_name, sizeof(dean_last_name) - 1);
    strncpy(dean_father_name, a.dean_father_name, sizeof(dean_father_name) - 1);
    foundation_year = a.getFoundationYear();
    applicants = a.applicants;
    teachers = a.teachers;
}

Faculty getdefaultFaculty() {
    return Faculty("KI", "001", "Petro", "Snijenko", "Sergijovich", 1700);;
}

A::A() :Applicant("", "", "", false, "", "") { cout << "A constractor" << endl; }
A::~A() { cout << "A destractor" << endl; }
B::B() :Teacher("", "", "", false, "", "", 1) { cout << "B constractor" << endl; }
B::~B() { cout << "B destractor" << endl; }
C::C() :Lector("", "", "", false, "", "",2) { cout << "C constractor" << endl; }
C::~C() { cout << "C destractor" << endl; }
ABC::ABC() :A(),B(),C() { cout << "ABC constractor" << endl; }
ABC::~ABC() { cout << "ABC destractor" << endl; }

void displayData(const Exam& obj) {
    cout << obj.total_value << endl;
}
void displayData(const Exam* obj) {
    cout << obj->total_value << endl;
}

int Budy::howmany = 0;
void Budy::displayData(const Mark& obj) {
    cout << obj.value << endl;
    howmany++;
}
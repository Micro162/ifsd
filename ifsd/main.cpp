#include <iostream>
using namespace std;

class Person {
protected:
    const char* name;
    int age;

public:
    Person(const char* n, int a) : name(n), age(a) {}

    virtual void info() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
    const char* university;

public:
    Student(const char* n, int a, const char* u)
        : Person(n, a), university(u) {
    }

    void info() const override {
        cout << "Student | Name: " << name
            << ", Age: " << age
            << ", University: " << university << endl;
    }
};

class Driver : public Person {
    const char* carNumber;
    const char* license;

public:
    Driver(const char* n, int a,
        const char* car, const char* lic)
        : Person(n, a), carNumber(car), license(lic) {
    }

    void info() const override {
        cout << "Driver | Name: " << name
            << ", Car: " << carNumber
            << ", License: " << license << endl;
    }
};

class Employee : public Person {
protected:
    double salary;

public:
    Employee(const char* n, int a, double s)
        : Person(n, a), salary(s) {
    }

    void info() const override {
        cout << "Employee | Name: " << name
            << ", Salary: " << salary << endl;
    }
};

class Doctor : public Employee {
    const char* specialty;

public:
    Doctor(const char* n, int a, double s, const char* sp)
        : Employee(n, a, s), specialty(sp) {
    }

    void info() const override {
        cout << "Doctor | Name: " << name
            << ", Specialty: " << specialty
            << ", Salary: " << salary << endl;
    }
};

int main() {
    Person p("Alex", 30);
    Student s("Ivan", 19, "KPI");
    Driver d("Oleg", 45, "AA1234BB", "B");
    Employee e("Maria", 35, 2500);
    Doctor doc("Anna", 40, 4000, "Surgeon");

    Person* people[] = { &p, &s, &d, &e, &doc };

    for (int i = 0; i < 5; i++)
        people[i]->info(); 

    return 0;
}

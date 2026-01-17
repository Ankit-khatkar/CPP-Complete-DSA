#include <bits/stdc++.h>
using namespace std;
#include <string>
// Basic structure of class and its properties and methods.
class Student
{
public:
  string name;
  int age;
  int rollno;

  void student(string name, int age, int rollno)
  {
    this->name = name;
    this->age = age;
    this->rollno = rollno;
  }
  void getinfo()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll NO: " << rollno << endl;
  }
};

// Understands access modifires.

class BankAccount
{
private:
  double balance = 0.0;

public:
  string acHolder;
  long long acNumber;

  void createUsr(string name, long long acNumber, double amount)
  {
    this->acHolder = name;
    this->acNumber = acNumber;
    if (amount > 0)
    {
      this->balance = amount;
    }
  }
  void updateBalance(double amount)
  {
    if (amount > 0)
    {
      balance = balance + amount;
    }
    else
    {
      cout << "Please, Enter valid amount";
    }
  }

  void getInfo()
  {
    cout << "Account Holder: " << acHolder << endl;
    cout << "Account Number: " << acNumber << endl;
    cout << "Balance " << balance;
  }
};

// memory allocation in heap;
class Teacher
{
private:
  string *name;
  int *age;
  double *salary;

public:
  Teacher(string name, int age, double salary)
  {
    cout << "heap variables declaration" << endl;
    this->name = new string(name);
    this->age = new int(age);
    this->salary = new double(salary);
  }
  ~Teacher()
  {
    cout << "delete memeory allocation form heap" << endl;
    delete name;
    delete age;
    delete salary;
  }
  void getinfo()
  {
    cout << *name << endl;
    cout << *age << endl;
    cout << *salary << endl;
  }
};

// Inheritance of classes
class Animal
{
public:
  void eat()
  {
    cout << "I can eat";
  }
  void sleep()
  {
    cout << "I can sleep";
  }
};
class Dog : public Animal
{
public:
  void bark()
  {
    cout << "I can bark";
  }
};

// friend function

class Box
{
private:
  int length;

public:
  Box()
  {
    length = 10;
  }
  friend void boxlength(Box mybox);
};

void boxlength(Box mybox)
{
  cout << "Box length is: " << mybox.length;
}

int main()
{
  Box b;
  boxlength(b);
}
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
using namespace std;


class Student {
public:
  int _id;
  char name[30];
  Student(int id, string name) {
    strcpy(this->name, name.c_str());
    this->_id = id;
  }
  Student() {}
  void Output() { cout << name << endl; }
};
void CreateStudent(Student* a) {
  ofstream f("Student.dat", ios::app | ios::binary);
  f.write((char*)a, sizeof(*a));
  f.close();
}
void Read() {
  ifstream f("Student.dat", ios::binary);
  Student A;
  int i = 0;
  while (f.read((char*)&A, sizeof(A))) {
    cout << ++i << ". ";
    A.Output();
  }
  f.close();
}
void Update(int id, string name) {
  fstream f("Student.dat", ios::in | ios::out | ios::binary);
  Student A;
  while (f.read((char*)&A, sizeof(A))) {
    if (A._id != id) continue;
    strcpy(A.name, name.c_str());
    f.seekp(f.tellg() - (long long int)sizeof(Student), ios::beg);
    f.write((char*)&A, sizeof(A));
  }
}

#if __INCLUDE_LEVEL__ == 0
int main() {
  Update(50, "FUCK");
  Update(52, "FUCK++++++++++");
  Read();
}
#else
#pragma once
#endif
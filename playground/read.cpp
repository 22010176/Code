// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds
#include <fstream>
#include <climits>
#include <cmath>
#include <bitset>
#include <vector>
// a non-optimized way of checking for prime numbers:

using namespace std;
void ReadBin(string path) {
  vector<char> A;
  for (int i = 0; i < (int)pow(2, 3);i++) A.push_back((char)i);
  string result = "";
  ifstream f(path, ios::binary);
  char a; while (f.read(&a, sizeof(a))) {
    for (int i = 0; i < A.size();i++) {
      if (A.at(i) != a) continue;
      cout << a;
    }
  }
  // cout << result;
  f.close();
}
void Write(string path, char* a) {
  ofstream f(path, ios::binary);
  f.write(a, 1);
  f.close();
}
int main() {
  string path = "Student.dat";
  int i;
  fstream f(path, ios::binary | ios::in);
  for (i = 0; i < 200;i++) {
    f.write((char*)&i, sizeof(i));
  }
  // ReadBin(path);
}
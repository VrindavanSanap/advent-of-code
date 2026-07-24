#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() { 
	fstream file("2020_day8.txt");
  string line;
  while(getline(file, line)){
    cout << line << endl;
  }
}

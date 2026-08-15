#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main() {
  ifstream file("2015_smol_day7.txt");
  string line;
  while(getline(file, line)){
    cout << line << endl;
    /*
      five possible operations
      3 chunks
        Assignment
          123 -> x

      5 chunks
        AND
          x AND y -> d
        OR
          x OR y -> e
        LSHIFT
          x LSHIFT 2 -> f
        RSHIFT
          y RSHIFT 2 -> g

      4 chunks
        NOT
          NOT x -> h





    */
  }
  return 0;
}
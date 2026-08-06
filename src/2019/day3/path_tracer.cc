#include <iostream>
#include <vector>
#include <sstream>
#include <print>

using namespace std;
int main(){
  string wire_path = "R8,U5,L5,D3";
  stringstream ss;
  ss = stringstream(wire_path);
  string token;
  vector<string> path;
  while (getline(ss , token, ',')){
    path.emplace_back(token);
  }
  println("{}", path);
  vector<vector<char>> grid;
  
  for (const auto& move: path){
    cout << move<<endl;

  }
  return 0;
}

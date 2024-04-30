#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cstdint>

using namespace std;


int main() {
  ifstream file("day7.txt"); 
  if (!file.is_open()) {
    cerr << "Failed to open the file." << std::endl;
    return 1;
  }
  string line;
  int i = 0;

  map<std::string, uint16_t> variables;

  while (getline(file, line)) { 
    cout << i++<<"  " << line << endl; 
    stringstream ss(line);
    vector<string> words;
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    int words_len = words.size();

    string destination = words[words_len-1];
    if (words_len == 3){
      // store instruction 
      cout << "Instruction type: STORE"<<endl;
      uint16_t value;
      try{
        value = stoi(words[0]);
      }catch(...){
        value = variables[words[0]];
      }
      variables[destination] = value;
    }
    if (words_len == 4){
      // store instruction 
      cout << "Instruction type: UNARY OP"<<endl;
      string opcode = words[0];
      string source = words[1];

      cout << "Opcode: " << opcode<<endl;
      if (opcode == "NOT"){
         variables[destination] =  ~variables[source];
      }
      // int value = stoi(words[0]);
    }
 

    if (words_len == 5){
      // store instruction 
      cout << "Instruction type: BINARY OP"<<endl;
      string source1 = words[0];
      uint16_t value1;
      uint16_t value2;
      
      try{
        value1 = stoi(words[0]);
      }catch(...){
        value1 = variables[words[0]];
      }
      try{
        value2 = stoi(words[2]);
      }catch(...){
        value2 = variables[words[2]];
      }

      string opcode = words[1];
      if (opcode == "AND"){
        variables[destination]  = value1 & value2;
      }else if (opcode == "OR"){
        variables[destination]  = value1 | value2;
      }else if (opcode =="LSHIFT"){
        variables[destination] = value1 << value2 ;
      }else if (opcode =="RSHIFT"){
        variables[destination] = value1 >> value2;
      }
    }
    cout << "--"<<endl;
 
  }

  for (const auto& pair : variables) {
    cout << pair.first << " : " << pair.second << endl;
  }


  file.close(); 
  return 0;
}


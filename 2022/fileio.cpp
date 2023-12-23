#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ifstream inputFile("day1.txt");

    if (inputFile.is_open()){
        string calorie_string;
        int total_elf_calories = 0;
        int calorie_int = 0;
        while (getline(inputFile, calorie_string)){
            if (calorie_string.empty()){
                calorie_int = 0;
                cout <<"Total = "<<total_elf_calories << endl;
                cout << "-\n";
                total_elf_calories = 0;
            }else{
                calorie_int = stoi(calorie_string);
                cout << calorie_int << endl;
                total_elf_calories += calorie_int;
            }
        }
        inputFile.close(); 
    }
    else{
        cerr << "Error opening the file." << endl;
    }

    return 0;
}

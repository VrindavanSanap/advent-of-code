#include <iostream>
#include <string>

int main() {
  std::string mainString = "onefivehdt88five";
  std::string subString = "88";

  size_t found = mainString.find_last_of(subString);

  if (found != std::string::npos) {
    std::cout << "Last occurrence found at index: " << found << std::endl;
  } else {
    std::cout << "Substring not found." << std::endl;
  }

  return 0;
}

#include <iostream>
#include <string>

int main()
{
    std::string mainString = "two1nine";
    std::string substring = "two";

    size_t foundIndex = mainString.find(substring);

    if (foundIndex != std::string::npos)
    {
        std::cout << "Substring '" << substring << "' found at index " << foundIndex << std::endl;
    }
    else
    {
        std::cout << "Substring '" << substring << "' not found in the main string." << std::endl;
    }

    return 0;
}

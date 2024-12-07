#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    std::regex pattern("mul\\((\\d+),(\\d+)\\)");
    int result = 0;

    while (std::getline(file, line))
    {
        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it)
        {
            std::smatch match = *it;

            int first_number = std::stoi(match[1].str());
            int second_number =std::stoi(match[2].str());
            result += first_number * second_number;
        }
    }

    std::cout << "Result: " << result << std::endl;
    file.close();
    return 0;
}
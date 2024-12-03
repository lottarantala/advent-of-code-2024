#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> split_line_to_numbers(const std::string& line) {
    std::vector<int> numbers;
    std::istringstream stream(line);
    int number;
    while (stream >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

bool check_increase(const std::vector<int>& line)
{
    for(int i = 1u; i < line.size(); i++)
    {
        if(!(line[i-1] < line[i] && line[i] - line[i-1] <= 3 && line[i] - line[i-1] >= 1))
        {
            return false;
        }
    }
    return true;
}

bool check_decrease(const std::vector<int>& line)
{
    for(int i = 1u; i < line.size(); i++)
    {
        if(!(line[i-1] > line[i] && line[i-1] - line[i] <= 3 && line[i-1] - line[i] >= 1))
        {
            return false;
        }
    }
    return true;
}

bool check_if_safe(const std::vector<int>& line)
{

    return check_increase(line) || check_decrease(line);
}

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int number_of_safe_lines = 0;
    while (std::getline(file, line)) {
        std::vector<int> numbers = split_line_to_numbers(line);
        if(check_if_safe(numbers))
        {
            number_of_safe_lines += 1;
        }
    }
    std::cout << "Number of safe lines: " << number_of_safe_lines << std::endl;
    return 0;
}
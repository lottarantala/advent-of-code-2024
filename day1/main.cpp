#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int calculate_distance(int val1, int val2)
{
    return std::abs(val1 - val2);
}

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int val1, val2;
    int total_distance = 0;
    std::vector<int> list1{};
    std::vector<int> list2{};

    // reading file into lists
    while (std::getline(file, line)) {
        std::istringstream stream(line);

        stream >> val1;
        stream.ignore(3, ' ');
        stream >> val2;

        list1.push_back(val1);
        list2.push_back(val2);
    }

    // sorting
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    // calculating distances
    for(auto i = 0u; i < list1.size(); i++)
    {
        int distance = calculate_distance(list1[i], list2[i]);
        total_distance += distance;
    }

    std::cout << "Total distance: " << total_distance << std::endl;

    file.close();
    return 0;
}
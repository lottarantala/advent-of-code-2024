#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int calculate_distance(std::vector<int> list1, std::vector<int> list2)
{
    int total_distance = 0;
    for(auto i = 0u; i < list1.size(); i++)
    {
        int distance = std::abs(list1[i] - list2[i]);;
        total_distance += distance;
    }
    return total_distance;
}

int calculate_similarity_score(std::vector<int> list1, std::vector<int> list2)
{
    int similarity_score = 0;
    for(auto i = 0u; i < list1.size(); i++)
    {
        auto count_of_item = std::count(list2.begin(), list2.end(), list1[i]);
        similarity_score += list1[i] * count_of_item;
    }
    return similarity_score;
}

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int val1, val2;
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

    int total_distance = calculate_distance(list1, list2);
    int similarity_score = calculate_similarity_score(list1, list2);

    std::cout << "Total distance: " << total_distance << std::endl;
    std::cout << "Similarity score: " << similarity_score << std::endl;

    file.close();
    return 0;
}
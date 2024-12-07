#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int check_horizontal(const std::vector<std::string>& lines)
{
    std::string xmas = "XMAS";
    std::string samx = "SAMX";
    int num_of_xmas = 0;

    for(const auto& line : lines)
    {
        std::string::size_type pos = 0;
        while ((pos = line.find(xmas, pos)) != std::string::npos)
        {
            num_of_xmas++;
            pos++;
        }
        pos = 0;
        while ((pos = line.find(samx, pos)) != std::string::npos)
        {
            num_of_xmas++;
            pos++;
        }
    }

    return num_of_xmas;
}

int check_vertical(const std::vector<std::string>& lines)
{
    int num_of_xmas = 0;

    std::vector<std::string> new_vector{};

    for(auto col_idx = 0u; col_idx < lines[0].size(); col_idx++)
    {
        std::string new_row("");
        for(auto row_idx = 0u; row_idx < lines.size(); row_idx++)
        {
            new_row.push_back(lines[row_idx][col_idx]);
        }
        new_vector.push_back(new_row);
    }

    num_of_xmas = check_horizontal(new_vector);
    return num_of_xmas;
}

int check_diagonal(const std::vector<std::string>& lines)
{
    int num_of_xmas = 0;
    size_t rows = lines.size();
    size_t cols = lines[0].size();

    for (size_t row = 0; row <= rows - 4; ++row)
    {
        for (size_t col = 0; col < cols; ++col)
        {
            // Down-right diagonal
            if (col + 3 < cols)
            {
                std::string diag = {lines[row][col], lines[row + 1][col + 1], lines[row + 2][col + 2], lines[row + 3][col + 3]};
                if (diag == "XMAS" || diag == "SAMX")
                {
                    num_of_xmas++;
                }
            }

            // Down-left diagonal
            if (col >= 3)
            {
                std::string diag = {lines[row][col], lines[row + 1][col - 1], lines[row + 2][col - 2], lines[row + 3][col - 3]};
                if (diag == "XMAS" || diag == "SAMX")
                {
                    num_of_xmas++;
                }
            }
        }
    }
    return num_of_xmas;
}

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int result = 0;
    std::vector<std::string> lines{};

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    result += check_horizontal(lines);
    result += check_vertical(lines);
    result += check_diagonal(lines);

    std::cout << result << std::endl;
    file.close();
    return 0;
}
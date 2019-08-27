
#include <string>
#include <sstream>
#include <vector>

// int charNumberToInt(char c)
// {
//     if (c - '0' >= 0)
//         return c - '0';
//     else
//         return -1;
// }

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> result;
    std::string item;
    std::stringstream ss(s);
    while (std::getline(ss, item, delimiter))
        result.push_back(item);
    return result;
}
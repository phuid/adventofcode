#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

#include <map>

std::map<std::string, char> dict = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}};

void start(std::string inputfile, std::vector<std::string> &inputvector)
{
  std::ifstream input(inputfile);
  if (input.is_open())
  {
    std::string line;
    while (getline(input, line))
    {
      inputvector.push_back(line);
    }
  }
  else
  {
    std::cout << "input not open" << std::endl;
    exit(0);
  }
}

int main()
{
  std::cout << "Hello World!\n";

  std::vector<std::string> inputvector;

  start("input.txt", inputvector);

  std::vector<std::string> numbersstring;
  for (auto i : inputvector)
  {
    std::string current = "";
    for (char c : i)
    {
      if (c <= '9' && c >= '0')
        current += c;
    }
    numbersstring.push_back(current);
  }
  int final = 0;
  for (auto i : numbersstring)
  {
    // std::cout << i << "," << (i[0]*10) + i[i.length() - 1] << std::endl;
    final += ((i[0] - '0') * 10) + (i[i.length() - 1] - '0');
  }
  std::cout << final << std::endl;

  final = 0;

  std::vector<std::vector<int>> numbers;

  std::regex rgx("([0-9]|one|two|three|four|five|six|seven|eight|nine)");

  std::cout << "part two:" << std::endl;

  for (size_t i = 0; i < inputvector.size(); i++)
  {
    std::smatch match;
    std::vector<int> current;

    while (std::regex_search(inputvector[i], match, rgx))
    {
      if (match.str()[0] >= '0' && match.str()[0] <= '9')
      {
        current.push_back(match.str()[0] - '0');
      }
      else
      {
        current.push_back(dict[match[0]]);
      }
      inputvector[i] = inputvector[i].substr(match.position() + 1);
    }
    // std::cout << "current:";
    // for (auto &&i : current)
    // {
    //   std::cout << i << ", ";
    // }
    // std::cout << std::endl;

    numbers.push_back(current);
  }
  for (auto i : numbers)
  {
    // std::cout << i[0] << "," << i[i.size() - 1] << std::endl;
    final += (i[0] * 10) + i[i.size() - 1];
  }
  std::cout << final << std::endl;
}
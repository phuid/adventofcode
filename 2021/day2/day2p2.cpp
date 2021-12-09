#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
  std::vector<std::string> inputvector;

  start("day2input.txt", inputvector);

  int horizontal = 0;
  int vertical = 0;
  int aim = 0;

  for (auto &&i : inputvector)
  {
    std::cout << "string: " << i << ", substr: " << i.substr(0, i.find(' ')) << ", ";
    if (i.substr(0, i.find(' ')) == "forward")
    {
      horizontal += stoi(i.substr(i.find(' ') + 1));
      vertical += aim * stoi(i.substr(i.find(' ') + 1));
    }
    if (i.substr(0, i.find(' ')) == "up")
    {
      aim -= stoi(i.substr(i.find(' ') + 1));
    }
    if (i.substr(0, i.find(' ')) == "down")
    {
      aim += stoi(i.substr(i.find(' ') + 1));
    }
    std::cout << std::endl;
  }

  std::cout << "horizontal: " << horizontal << ", vertical (depth): " << vertical << std::endl << "result = " << horizontal << " * " << vertical << ": " << horizontal * vertical << std::endl;
}
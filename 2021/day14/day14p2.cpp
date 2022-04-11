#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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

size_t countpairs(std::string line, std::string pair)
{
  size_t count = 0;

  for (size_t i = 0; i < line.length() - 1; i++)
    if (line[i] == pair[0] && line[i + 1] == pair[1])
      count++;

  return count;
}

int main()
{
  std::vector<std::string> inputvector;

  start("day14input.txt", inputvector);

  std::map<std::string, size_t> counts;
  std::map<std::string, char> rules;

  for (auto &&i : inputvector)
  {
    if (i.find(" -> ") == std::string::npos)
      continue;
    rules[i.substr(0, i.find(" -> "))] = i.substr(i.find(" -> ") + 4)[0];
  }

  for (auto &&i : rules)
  {
    counts[i.first] = countpairs(inputvector[0], i.first);
  }

  for (size_t i = 0; i < 10; i++)
  {
    for (auto &&count : counts)
    {
      counts[std::string() + count.first[0] + rules[count.first]] += count.second;
      counts[std::string() + rules[count.first] + count.first[1]] += count.second;
      count.second = 0;
    }
  }

  for (char i = 'A'; i <= 'Z'; i++)
  {
    std::cout << i << " : " <<
        [](char n, std::map<std::string, size_t> counts) -> size_t
    {
      size_t counter = 0;
      for (auto &&count : counts)
      {
        if (count.first[0] == n)
          counter += count.second;
      }
      return counter;
    }(i, counts) << std::endl;
  }
}
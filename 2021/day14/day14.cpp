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

  for (size_t i = 0; i < 40; i++)
  {
    std::map<std::string, size_t> prevcounts = counts;
    for (auto &&count : prevcounts)
    {
      counts[std::string() + count.first[0] + rules[count.first]] += count.second;
      counts[std::string() + rules[count.first] + count.first[1]] += count.second;
      counts[count.first] -= count.second;
    }
  }

  std::map<char, size_t> lettercounts;
  for (char el = 'A'; el <= 'Z'; el++)
  {
    size_t currentcount =
        [](char el, std::map<std::string, size_t> counts, std::vector<std::string> inputvector) -> size_t
    {
      size_t counter = 0;
      for (auto &&count : counts)
      {
        if (count.first[0] == el)
          counter += count.second;
      }
      return counter + (el == inputvector[0][inputvector[0].length() - 1] ? 1 : 0);
    }(el, counts, inputvector);
    if (currentcount > 0)
      lettercounts[el] = currentcount;
  }

  for (auto &&i : lettercounts)
  {
    std::cout << i.first << " : " << i.second << std::endl;
  }

  size_t smallest = [](std::map<char, size_t> lettercounts) -> size_t
  {
    size_t smallest = SIZE_MAX;
    for (auto &&count : lettercounts)
    {
      if (count.second == 0)
      {
        continue;
      }
      if (smallest > count.second)
      {
        smallest = count.second;
      }
    }
    return smallest;
  }(lettercounts);

  size_t biggest = [](std::map<char, size_t> lettercounts) -> size_t
  {
    size_t biggest = 0;
    for (auto &&count : lettercounts)
    {
      if (biggest < count.second)
      {
        biggest = count.second;
      }
    }
    return biggest;
  }(lettercounts);

  std::cout << "smalLest: " << smallest << ", biggest: " << biggest << std::endl << biggest << " - " << smallest << " = " << biggest - smallest << std::endl;
}
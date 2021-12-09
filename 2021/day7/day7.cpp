#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>

void start(std::string inputfile, std::vector<int> &positions)
{
  std::ifstream input(inputfile);
  if (input.is_open())
  {
    std::string line;
    while (getline(input, line))
    {
      while (line.length() > 0)
      {
        if (line.find(',') != std::string::npos)
        {

          positions.push_back(stoi(line.substr(0, line.find(',' - 1))));
          line = line.substr(line.find(',') + 1);
        }
        else
        {
          positions.push_back(stoi(line));
          line = "";
        }
      }
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
  std::vector<int> positions;

  start("day7input.txt", positions);

  int big = 0;

  for (auto &&i : positions)
  {
    if (i > big)
      big = i;
  }

  std::vector<int> costs;
  std::vector<int> newcosts;

  for (int i = 0; i < big; i++)
  {
    int cost = 0;
    int newcost = 0;
    for (auto &&u : positions)
    {
      cost += std::abs(u - i);
      int currentcost = 0;
      for (size_t z = 1; z <= std::abs(u - i); z++)
      {
        currentcost += z;
      }
      newcost += currentcost;
    }
    costs.push_back(cost);
    newcosts.push_back(newcost);
  }

  int smallest = 0;
  int newsmallest = 0;

  for (size_t i = 0; i < big; i++)
  {
    if (costs[i] < costs[smallest])
      smallest = i;
  }
  for (size_t i = 0; i < big; i++)
  {
    if (newcosts[i] < newcosts[newsmallest])
      newsmallest = i;
  }

  std::cout << "smallest cost in position " << smallest << " (" << costs[smallest] << ")." << std::endl;
  std::cout << "new smalles cost position " << newsmallest << " (" << newcosts[newsmallest] << ")." << std::endl;
}
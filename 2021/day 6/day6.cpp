#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

void start(std::string inputfile, std::vector<int> &inputvector)
{
  std::ifstream input(inputfile);
  if (input.is_open())
  {
    std::string line;
    while (getline(input, line))
    {
      for (size_t i = 0; i < line.length(); i += 2)
      {
        inputvector.push_back(stoi(line.substr(i, 1)));
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
  std::vector<int> population;

  start("day6input.txt", population);

  std::cout << "Initial state: ";
  for (auto &&i : population)
  {
    std::cout << i << ",";
  }

  for (size_t t = 1; t <= 256; t++)
  {
    size_t population_size = population.size();
    for (size_t i = 0; i < population_size; i++)
    {
      if (population[i] == 0)
      {
        population[i] = 6;
        population.push_back(8);
      }
      else
      {
        population[i]--;
      }
    }
    std::cout << std::endl
              << population.size() << " fish " << "After " << std::setw(2) << t << " days: ";
    // for (auto &&i : population)
    // {
    //   std::cout << i << ",";
    // }
  }
}

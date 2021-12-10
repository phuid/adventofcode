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
  const int frequency = 6;
  const int pretime = 2;
  const int total_time = 256;
  std::vector<int> inputvector;

  start("day6input.txt", inputvector);

  size_t population[frequency + pretime + 1];

  for (auto &&i : population)
  {
    i = 0;
  }

  std::cout << "Initial state: ";
  for (auto &&i : inputvector)
  {
    std::cout << i << ",";

    population[i]++;
  }

  std::cout << std::endl
            << "Initial state: ";

  for (size_t i = 0; i <= frequency + pretime; i++)
  {
    std::cout << "[" << i << "]=" << population[i] << ",";
  }
  std::cout << std::endl;

  for (size_t t = 1; t <= total_time; t++)
  {
    size_t total = 0;
    size_t zeros = population[0];
    for (size_t i = 0; i < frequency + pretime; i++)
    {
      population[i] = population[i + 1];
      total += population[i];
    }
    population[frequency] += zeros;
    population[frequency + pretime] = zeros;
    total += 2 * zeros;

    std::cout << total << " fish "
              << "After " << std::setw(2) << t << " days: ";
    for (size_t i = 0; i <= frequency + pretime; i++)
    {
      std::cout << "[" << i << "]=" << population[i] << ",";
    }
    std::cout << std::endl;
  }
}

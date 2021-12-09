#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

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

int binarytodecimal(std::string binary)
{
  int decimal = 0;
  for (size_t i = 0; i < binary.size(); i++)
  {
    decimal += (binary[i] - '0') * pow(2, binary.size() - i - 1);
  }
  return decimal;
}

int main()
{
  std::vector<std::string> inputvector;

  start("day3input.txt", inputvector);

  std::vector<std::vector<bool>> data;

  for (auto &&i : inputvector)
  {
    data.push_back({});
    for (auto &&u : i)
    {
      if (u == '0')
      {
        data.back().push_back(0);
      }
      else if (u == '1')
      {
        data.back().push_back(1);
      }
    }
  }

  std::string gamma_rate = "";
  std::string epsilon_rate = "";

  for (size_t i = 0; i < data[0].size(); i++)
  {
    int trues = 0;
    for (size_t u = 0; u < data.size(); u++)
    {
      trues += data[u][i];
    }
    if (trues >= data.size() - trues)
    {
      gamma_rate += "1";
      epsilon_rate += "0";
    }
    else if (trues < data.size() - trues)
    {
      gamma_rate += "0";
      epsilon_rate += "1";
    }
  }
  std::cout << "gamma: " << gamma_rate << ", epsilon: " << epsilon_rate << std::endl;
  std::cout << "gamma: " << binarytodecimal(gamma_rate) << ", epsilon: " << binarytodecimal(epsilon_rate) << std::endl;
  std::cout << "power consumption: " << binarytodecimal(gamma_rate) * binarytodecimal(epsilon_rate) << std::endl;

  std::vector<std::vector<bool>> data2 = data;

  for (size_t i = 0; data.size() > 1; i++)
  {
    int trues = 0;
    for (size_t u = 0; u < data.size(); u++)
    {
      trues += data[u][i];
    }

    char common;

    if (trues >= data.size() - trues)
    {
      common = '1';
    }
    else if (trues < data.size() - trues)
    {
      common = '0';
    }

    for (int z = 0; z < data.size(); z++)
    {
      if (data[z][i] != common - '0')
      {
        data.erase(data.begin() + z);
        z--;
      }
    }
  }

  for (size_t i = 0; data2.size() > 1; i++)
  {
    int trues = 0;
    for (size_t u = 0; u < data2.size(); u++)
    {
      trues += data2[u][i];
    }

    char common;

    if (trues >= data2.size() - trues)
    {
      common = '0';
    }
    else if (trues < data2.size() - trues)
    {
      common = '1';
    }

    for (int z = 0; z < data2.size(); z++)
    {
      if (data2[z][i] != common - '0')
      {
        data2.erase(data2.begin() + z);
        z--;
      }
    }
  }

  std::string oxgenr = "";
  std::string coscrur = "";

  for (auto &&i : data[0])
  {
    oxgenr += '0' + i;
  }
  for (auto &&i : data2[0])
  {
    coscrur += '0' + i;
  }
  

  std::cout << "oxygen generator rating: " << oxgenr << ", CO2 scrubber rating: " << coscrur << std::endl;
  std::cout << "oxygen generator rating: " << binarytodecimal(oxgenr) << ", CO2 scrubber rating: " << binarytodecimal(coscrur) << std::endl;
  std::cout << "life support rating: " << binarytodecimal(oxgenr) * binarytodecimal(coscrur) << std::endl;
}
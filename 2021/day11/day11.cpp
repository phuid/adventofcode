#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> // WinApi header

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
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  std::vector<std::string> inputvector;

  start("day11input.txt", inputvector);

  struct octopus
  {
    int energy;
    bool flashed = 0;
  };

  const size_t totalsteps = 1000;
  size_t flashes = 0;

  std::vector<std::vector<octopus>> field;

  for (auto &&i : inputvector)
  {
    field.push_back({});
    for (auto &&u : i)
    {
      field.back().push_back(octopus{u - '0', 0});
    }
  }

  //draw
  std::cout << "before any steps" << std::endl;
  for (auto &&i : field)
  {
    for (auto &&u : i)
    {
      std::cout << u.energy;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for (size_t steps = 1; steps <= totalsteps; steps++)
  {
    for (auto &&i : field)
    {
      for (auto &&u : i)
      {
        u.energy++;
      }
    }

    bool done = 0;
    while (!done)
    {
      done = 1;
      for (size_t i = 0; i < field.size(); i++)
      {
        for (size_t u = 0; u < field[i].size(); u++)
        {
          if (field[i][u].energy > 9 && field[i][u].flashed == 0)
          {
            field[i][u].flashed = 1;
            done = 0;
            for (int x = -1; x <= 1; x++)
            {
              for (int y = -1; y <= 1; y++)
              {
                if ((x != 0 || y != 0) && i + y >= 0 && u + x >= 0 && i + y < field.size() && u + x < field[i + y].size())
                {
                  field[i + y][u + x].energy++;
                }
              }
            }
          }
        }
      }
    }

    for (auto &&i : field)
    {
      for (auto &&u : i)
      {
        if (u.flashed == 1)
        {
          u.energy = 0;
          u.flashed = 0;
          flashes++;
        }
      }
    }
    //draw
    std::cout << "step " << steps << std::endl;
    size_t currentflashes = 0;
    for (auto &&i : field)
    {
      for (auto &&u : i)
      {
        if (u.energy == 0)
        {
          SetConsoleTextAttribute(hConsole, 14);
          currentflashes++;
        }

        std::cout << u.energy;
        SetConsoleTextAttribute(hConsole, 7);
      }
      std::cout << std::endl;
    }
    std::cout << "currentflashes: " << currentflashes << std::endl << "flashes so far: " << flashes << std::endl;

    if (currentflashes >= field.size() * field[0].size())
    {
      exit(0);
    }
    
  }
}
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

class fold
{
public:
  char axis;
  int distance;

  fold(char i_axis, int i_distance)
  {
    axis = i_axis;
    distance = i_distance;
  };
};

void placedot(unsigned int x, unsigned int y, std::vector<std::vector<bool>> &field)
{

  while (field.size() < y + 1)
  {
    field.push_back(std::vector<bool>{});
  }

  for (auto &&row : field)
  {
    while (row.size() < x + 1)
    {
      row.push_back(0);
    }
  }
  field[y][x] = 1;
}

void drawfield(std::vector<std::vector<bool>> field)
{
  size_t counter = 0;
  std::string drawstring = ".#";
  for (auto &&i : field)
  {
    for (auto &&u : i)
    {
      std::cout << drawstring[u];
      counter += u;
    }
    std::cout << std::endl;
  }
  std::cout << "-------^" << counter << "^--------" << std::endl;
}

int main()
{
  std::vector<std::string> inputvector;

  start("day13input.txt", inputvector);

  std::vector<std::vector<bool>> field;
  std::vector<fold> folds;

  field.push_back(std::vector<bool>(0));

  for (auto &&i : inputvector)
  {
    if (i.find(',') != std::string::npos)
      placedot(stoi(i.substr(0, i.find(','))), stoi(i.substr(i.find(',') + 1)), field);
    else if (i.find("fold along") != std::string::npos)
      folds.push_back(fold(i.substr(i.find('=') - 1, i.find('=') - 1)[0], stoi(i.substr(i.find('=') + 1))));
  }

  // drawfield(field);

  while (folds.size() > 0)
  {
    // pocitam s tim, ze fold nikdy nebude bliz k zacatku pole, nez ke konci
    if (folds[0].axis == 'x')
    {
      for (size_t i = (field[0].size() - 1) - folds[0].distance; i > 0; i--)
      {
        for (auto &&row : field)
        {
          row[folds[0].distance - i] = row[folds[0].distance + i] | row[folds[0].distance - i];
          row.erase(row.begin() + folds[0].distance + i);
        }
      }
      for (auto &&row : field)
      {
        row.erase(row.begin() + folds[0].distance);
      }
    }
    else if (folds[0].axis = 'y')
    {
      for (size_t i = (field.size() - 1) - folds[0].distance; i > 0; i--)
      {
        for (size_t u = 0; u < field[folds[0].distance - i].size(); u++)
        {
          field[folds[0].distance - i][u] = field[folds[0].distance + i][u] | field[folds[0].distance - i][u];
        }
        field.erase(field.begin() + folds[0].distance + i); // need one more, nechava mi to tam v prvnim exxamplu 3 prazdny radky misto 2
      }
      field.erase(field.begin() + folds[0].distance);
    }
    // drawfield(field);

    folds.erase(folds.begin());
  }

  std::cout << "final: ˇ " << std::endl;
  drawfield(field);
}
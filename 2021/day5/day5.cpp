#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct point
{
  int x;
  int y;
};

struct line
{
  point start;
  point end;
};

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

  start("day5input.txt", inputvector);

  std::vector<line> lines;

  for (auto &&i : inputvector)
  {
    lines.push_back(line{});
    lines.back().start.x = stoi(i.substr(0, i.find(',')));
    lines.back().start.y = stoi(i.substr(i.find(',') + 1, i.find(' ')));
    i = i.substr(i.find('>') + 2);
    lines.back().end.x = stoi(i.substr(0, i.find(',')));
    lines.back().end.y = stoi(i.substr(i.find(',') + 1));
  }

  int width = 0;
  int height = 0;

  for (auto &&i : lines)
  {
    if (i.start.x > width)
      width = i.start.x;
    if (i.end.x > width)
      width = i.end.x;

    if (i.start.y > height)
      height = i.start.y;
    if (i.end.y > height)
      height = i.end.y;
  }

  std::vector<std::vector<int>> field;
  for (size_t i = 0; i <= height; i++)
  {
    field.push_back({});
    for (size_t u = 0; u <= width; u++)
    {
      field.back().push_back(0);
    }
  }

  for (auto &&i : lines)
  {
    if (i.start.x == i.end.x)
    {
      if (i.start.y < i.end.y)
      {
        for (size_t u = i.start.y; u <= i.end.y; u++)
        {
          field[u][i.start.x]++;
        }
      }
      else
      {
        for (size_t u = i.start.y; u >= i.end.y; u--)
        {
          field[u][i.start.x]++;
        }
      }
    }
    else if (i.start.y == i.end.y)
    {
      if (i.start.x < i.end.x)
      {
        for (size_t u = i.start.x; u <= i.end.x; u++)
        {
          field[i.start.y][u]++;
        }
      }
      else
      {
        for (size_t u = i.start.x; u >= i.end.x; u--)
        {
          field[i.start.y][u]++;
        }
      }
    }
  }

  int count = 0;

  for (auto &&i : field)
  {
    for (auto &&u : i)
    {
      std::cout << u;
      if (u >= 2)
      {
        count++;
      }
    }
    std::cout << std::endl;
  }
  std::cout << "the number of points where at least 2 lines overlap: " << count << std::endl;
}
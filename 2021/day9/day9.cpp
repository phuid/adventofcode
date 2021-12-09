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

struct point
{
  int x;
  int y;
  bool checked = 0;
};

void createpoint(int y, int x, std::vector<point> &currentbasin, std::vector<std::vector<int>> field)
{
  if (y >= field.size() || x >= field[y].size() || y < 0 || x < 0)
    return;
  if (field[y][x] >= 9)
    return;
  for (auto &&i : currentbasin)
  {
    if (i.x == x && i.y == y)
    {
      return;
    }
  }
  currentbasin.push_back({x, y, 0});
}

void lowpoint(std::vector<std::vector<point>> &basins, int *total_lowpoints, int i, int u, std::vector<std::vector<int>> field)
{
  // std::cout << field[i][u] << ", ";
  *total_lowpoints += field[i][u] + 1;

  std::vector<point> currentbasin;
  currentbasin.push_back({u, i, 0});

  bool done = 0;
  while (!done)
  {
    done = 1;
    for (size_t point = 0; point < currentbasin.size(); point++)
    {
      if (!currentbasin[point].checked)
      {
        done = 0;
        currentbasin[point].checked = 1;
        // if (currentbasin[point].y == 0)
        // {
        //   if (currentbasin[point].x == 0)
        //   {
        //     createpoint(currentbasin[point].y + 1, currentbasin[point].x, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x + 1, currentbasin, field);
        //   }
        //   else if (currentbasin[point].x == field[currentbasin[point].y].size() - 1)
        //   {
        //     createpoint(currentbasin[point].y + 1, currentbasin[point].x, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x - 1, currentbasin, field);
        //   }
        //   else
        //   {
        //     createpoint(currentbasin[point].y + 1, currentbasin[point].x, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x + 1, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x - 1, currentbasin, field);
        //   }
        // }
        // else if (currentbasin[point].y == field.size() - 1)
        // {
        //   if (currentbasin[point].x == 0)
        //   {
        //     createpoint(currentbasin[point].y - 1, currentbasin[point].x, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x + 1, currentbasin, field);
        //   }
        //   else if (currentbasin[point].x == field[currentbasin[point].y].size() - 1)
        //   {
        //     createpoint(currentbasin[point].y - 1, currentbasin[point].x, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x - 1, currentbasin, field);
        //   }
        //   else
        //   {
        //     createpoint(currentbasin[point].y - 1, currentbasin[point].x, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x + 1, currentbasin, field);
        //     createpoint(currentbasin[point].y, currentbasin[point].x - 1, currentbasin, field);
        //   }
        // }

        // else if (currentbasin[point].x == 0)
        // {
        //   createpoint(currentbasin[point].y + 1, currentbasin[point].x, currentbasin, field);
        //   createpoint(currentbasin[point].y - 1, currentbasin[point].x, currentbasin, field);
        //   createpoint(currentbasin[point].y, currentbasin[point].x + 1, currentbasin, field);
        // }
        // else if (currentbasin[point].x == field[currentbasin[point].y].size() - 1)
        // {
        //   createpoint(currentbasin[point].y + 1, currentbasin[point].x, currentbasin, field);
        //   createpoint(currentbasin[point].y - 1, currentbasin[point].x, currentbasin, field);
        //   createpoint(currentbasin[point].y, currentbasin[point].x - 1, currentbasin, field);
        // }

        // else
        // {
        createpoint(currentbasin[point].y + 1, currentbasin[point].x, currentbasin, field);
        createpoint(currentbasin[point].y - 1, currentbasin[point].x, currentbasin, field);
        createpoint(currentbasin[point].y, currentbasin[point].x + 1, currentbasin, field);
        createpoint(currentbasin[point].y, currentbasin[point].x - 1, currentbasin, field);
        // }
      }
    }
  }
  basins.push_back(currentbasin);
}

int main()
{
  std::vector<std::string> inputvector;

  start("day9input.txt", inputvector);

  std::vector<std::vector<int>> field;

  for (auto &&i : inputvector)
  {
    std::vector<int> currentline;
    for (auto &&u : i)
    {
      currentline.push_back(u - '0');
    }
    field.push_back(currentline);
  }

  int total_lowpoints = 0;
  std::vector<std::vector<point>> basins;

  for (size_t i = 0; i < field.size(); i++)
  {
    for (size_t u = 0; u < field[i].size(); u++)
    {
      if (i == 0)
      {
        if (u == 0)
        {
          if (field[i][u] < field[i][u + 1] && field[i][u] < field[i + 1][u])
          {
            lowpoint(basins, &total_lowpoints, i, u, field);
          }
        }
        else if (u == field[i].size() - 1)
        {
          if (field[i][u] < field[i][u - 1] && field[i][u] < field[i + 1][u])
          {
            lowpoint(basins, &total_lowpoints, i, u, field);
          }
        }
        else
        {
          if (field[i][u] < field[i][u - 1] && field[i][u] < field[i][u + 1] && field[i][u] < field[i + 1][u])
          {
            lowpoint(basins, &total_lowpoints, i, u, field);
          }
        }
      }
      else if (i == field.size() - 1)
      {
        if (u == 0)
        {
          if (field[i][u] < field[i][u + 1] && field[i][u] < field[i - 1][u])
          {
            lowpoint(basins, &total_lowpoints, i, u, field);
          }
        }
        else if (u == field[i].size() - 1)
        {
          if (field[i][u] < field[i][u - 1] && field[i][u] < field[i - 1][u])
          {
            lowpoint(basins, &total_lowpoints, i, u, field);
          }
        }
        else
        {
          if (field[i][u] < field[i][u - 1] && field[i][u] < field[i][u + 1] && field[i][u] < field[i - 1][u])
          {
            lowpoint(basins, &total_lowpoints, i, u, field);
          }
        }
      }

      else if (u == 0)
      {
        if (field[i][u] < field[i][u + 1] && field[i][u] < field[i + 1][u] && field[i][u] < field[i - 1][u])
        {
          lowpoint(basins, &total_lowpoints, i, u, field);
        }
      }
      else if (u == field[i].size() - 1)
      {
        if (field[i][u] < field[i][u - 1] && field[i][u] < field[i + 1][u] && field[i][u] < field[i - 1][u])
        {
          lowpoint(basins, &total_lowpoints, i, u, field);
        }
      }

      else if (field[i][u] < field[i][u + 1] && field[i][u] < field[i][u - 1] && field[i][u] < field[i - 1][u] && field[i][u] < field[i + 1][u])
      {
        lowpoint(basins, &total_lowpoints, i, u, field);
        ;
      }
    }
  }

  int basinareascore = 1;

  for (auto &&i : basins)
  {
    int biggerbasincount = 0;
    for (auto &&u : basins)
    {
      if (i.size() < u.size())
      {
        biggerbasincount++;
      }
    }
    if (biggerbasincount < 3)
    {
      basinareascore *= i.size();
      std::cout << i.size() << std::endl;
    }
    
  }

  std::cout << std::endl
            << "total lowpoints: " << total_lowpoints << std::endl;
std::cout << "basin areascore: " << basinareascore << std::endl;

  // for (auto &&i : field);
  // {
  //   for (auto &&u : i)
  //   {
  //     std::cout << u;
  //   }
  //   std::cout << std::endl;
  // }
}
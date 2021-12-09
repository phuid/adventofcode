#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int alivecountfunc(std::vector<std::vector<bool>> dim)
{
  int counter = 0;

  for (auto &&u : dim)
  {
    for (auto &&z : u)
    {
      counter += z;
    }
  }

  return counter;
}

void draw(std::vector<std::vector<std::vector<std::vector<bool>>>> dim)
{
  int totalalivecount = 0;
  for (size_t o = 0; o < dim.size(); o++)
  {
    for (size_t i = 0; i < dim[o].size(); i++)
    {
      int alivecount = alivecountfunc(dim[o][i]);
      if (alivecount)
      {
        totalalivecount += alivecount;
        std::cout << std::endl
                  << "z = " << i << ", w = " << o << ", alive : " << alivecount << std::endl;
        for (auto &&u : dim[o][i])
        {
          for (auto &&z : u)
          {
            std::cout << z;
          }
          std::cout << std::endl;
        }
      }
    }
  }
  std::cout << std::endl
            << "totalalivecount: " << totalalivecount << std::endl;
}

void start(std::vector<std::string> &inputvector, std::vector<std::vector<std::vector<std::vector<bool>>>> &dim, int cycles)
{
  std::ifstream input("day17input.txt");
  std::string line;
  while (getline(input, line))
  {
    inputvector.push_back(line);
  }

  dim.resize((cycles * 2) + 1);
  for (auto &&o : dim)
  {
    o.resize((cycles * 2) + 1);
    for (auto &&i : o)
    {
      i.resize(inputvector.size() + (cycles * 2));
      for (auto &&u : i)
      {
        u.resize(inputvector[0].length() + (cycles * 2), 0);
      }
    }
  }

  for (size_t i = 0; i < inputvector.size(); i++)
  {
    for (size_t u = 0; u < inputvector[0].length(); u++)
    {
      if (inputvector[i][u] == '#')
      {
        dim[cycles][cycles][cycles + i][cycles + u] = 1;
      }
    }
  }
}

//as long, as the cell is inside the dimension, return its value
bool iscellalive(std::vector<std::vector<std::vector<std::vector<bool>>>> &dim, int w, int z, int y, int x)
{
  if (w >= 0 && w < dim.size() && z >= 0 && z < dim[w].size() && y >= 0 && y < dim[w][z].size() && x >= 0 && x < dim[w][z][y].size())
  {
    return (dim[w][z][y][x]);
  }
  return 0;
}
//what cells should tay alive
void logic(std::vector<std::vector<std::vector<std::vector<bool>>>> &firstdim, std::vector<std::vector<std::vector<std::vector<bool>>>> &seconddim)
{
  for (size_t p = 0; p < seconddim.size(); p++)
  {
    for (size_t i = 0; i < seconddim[p].size(); i++)
    {
      for (size_t u = 0; u < seconddim[p][i].size(); u++)
      {
        for (size_t o = 0; o < seconddim[p][i][u].size(); o++)
        {

          int aliveneighbors = 0 - firstdim[p][i][u][o];

          for (int w = -1; w < 2; w++)
          {
            for (int z = -1; z < 2; z++)
            {
              for (int y = -1; y < 2; y++)
              {
                for (int x = -1; x < 2; x++)
                {
                  aliveneighbors += iscellalive(firstdim, p + w, i + z, u + y, o + x);
                }
              }
            }
          }

          if (firstdim[p][i][u][o])
          {
            if (aliveneighbors == 2 | aliveneighbors == 3)
            {
              seconddim[p][i][u][o] = 1;
            }
            else
            {
              seconddim[p][i][u][o] = 0;
            }
          }
          else
          {
            if (aliveneighbors == 3)
            {
              seconddim[p][i][u][o] = 1;
            }
            else
            {
              seconddim[p][i][u][o] = 0;
            }
          }
        }
      }
    }
  }
}

int main()
{
  std::vector<std::string> inputvector;
  std::vector<std::vector<std::vector<std::vector<bool>>>> dim[2];
  int cycles = 6;

  start(inputvector, dim[0], cycles);
  dim[1] = dim[0];

  // draw(dim[0]);

  for (size_t i = 1; i <= cycles; i++)
  {
    std::cout << std::endl
              << std::endl
              << "cycle: " << i << ", firstdim: " << (i % 2 == 1) << ", seconddim: " << ((i % 2) != 1) << std::endl;
    logic(dim[i % 2 == 1], dim[(i % 2) != 1]);
    draw(dim[i % 2 != 1]);
  }

  // //alternative drawing
  // int totalalivecount = 0;
  // for (size_t i = 0; i < dim[cycles % 2 == 0].size(); i++)
  // {
  //   totalalivecount += alivecountfunc(dim[cycles % 2 == 0][i]);
  // }
  // std::cout << std::endl
  //           << "totalalivecount: " << totalalivecount << std::endl;
}
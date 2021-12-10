#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

struct tile
{
  int number;
  bool marked = 0;
};

using line = std::vector<tile>;

struct boardstruct
{
  std::vector<line> lines;
  bool won = 0;
};

using board = boardstruct;

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

void draw(std::vector<board> boards, HANDLE hConsole)
{
  for (size_t i = 0; i < boards.size(); i++)
  {
    std::cout << "board <" << i << ">: " << std::endl;
    for (auto &&u : boards[i].lines)
    {
      for (auto &&z : u)
      {
        SetConsoleTextAttribute(hConsole, z.marked * 4 + 7);
        std::cout.width(2);
        std::cout << z.number;
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << " ";
      }
      std::cout << std::endl;
    }
  }
}

int calcscore(std::vector<board> boards, int boardnum, int num)
{
  int sum = 0;
  for (auto &&i : boards[boardnum].lines)
  {
    for (auto &&u : i)
    {
      if (!u.marked)
        sum += u.number;
    }
  }
  // std::cout << "sum: " << sum << std::endl;
  return sum * num;
}

int killwinners(std::vector<boardstruct> &boards)
{
  for (size_t i = 0; i < boards.size(); i++)
  {
    if (boards[i].won)
    {
      boards.erase(boards.begin() + i);
    }
  }

  return boards.size();
}

int main()
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  std::vector<std::string> inputvector;

  start("day4input.txt", inputvector);

  std::vector<int> nums;
  std::vector<boardstruct> boards;

  // tile test[5][5];
  // test[0][0].number = 23;

  // boards.push_back(test);

  // // boards.push_back({{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},});
  // boards[0][0][1].number = 2;

  while (inputvector[0].length() > 0)
  {
    if (inputvector[0].find(',') != std::string::npos)
    {
      nums.push_back(stoi(inputvector[0].substr(0, inputvector[0].find(','))));
      inputvector[0] = inputvector[0].substr(inputvector[0].find(',') + 1);
    }
    else
    {
      nums.push_back(stoi(inputvector[0]));
      inputvector[0] = "";
    }
  }

  // std::cout << "nums: ";
  // for (auto &&i : nums)
  // {
  //   std::cout << i << ",";
  // }
  // std::cout << std::endl;

  int linenum = 0;

  boards.push_back(board{});
  boards.back().lines.push_back(line{});

  for (size_t i = 2; i < inputvector.size(); i++)
  {
    if (inputvector[i].length() > 0)
    {
      int u = 0;
      while (inputvector[i].length() > 0)
      {
        if (inputvector[i][0] == ' ')
        {
          inputvector[i] = inputvector[i].substr(1);
        }
        if (inputvector[i].find(' ') != std::string::npos)
        {
          boards.back().lines.back().push_back({stoi(inputvector[i].substr(0, inputvector[i].find(' '))), 0});
          inputvector[i] = inputvector[i].substr(inputvector[i].find(' ') + 1);
        }
        else
        {
          boards.back().lines.back().push_back({stoi(inputvector[i].substr(0, inputvector[i].find(' '))), 0});
          inputvector[i] = "";
          boards.back().lines.push_back(line{});
        }
        u++;
      }
      linenum++;
    }
    else
    {
      // boards.push_back({{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},});
      // for (auto &&i : currentboard)
      // {
      //   for (auto &&u : i)
      //   {
      //     std::cout << u.number << " ";
      //   }
      //   std::cout << std::endl;
      // }
      // std::cout << std::endl;

      // std::cout << "boardsasdf: " << boards[0][0][0].number << std::endl;
      // for (auto &&i : boards.back())
      // {
      //   for (auto &&u : i)
      //   {
      //     std::cout << u.number << " ";
      //   }
      //   std::cout << std::endl;
      // }

      boards.push_back(board{});
      boards.back().lines.push_back(line{});

      // currentboard = {{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},{{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},},};
      linenum = 0;
    }
  }

  for (auto &&i : boards)
  {
    i.lines.pop_back();
  }

  // draw(boards, hConsole);

  while (/*!gameover*/ killwinners(boards) > 1)
  {
    int num = nums[0];
    SetConsoleTextAttribute(hConsole, 10);
    // std::cout << "num: " << num << std::endl;
    SetConsoleTextAttribute(hConsole, 7);
    nums.erase(nums.begin());
    for (auto &&i : boards)
    {
      for (auto &&u : i.lines)
      {
        for (auto &&z : u)
        {
          if (z.number == num)
          {
            z.marked = 1;
          }
        }
      }
    }
    // draw(boards, hConsole);
    //rows
    for (size_t z = 0; z < boards.size(); z++)
    {
      for (size_t y = 0; y < boards[z].lines.size(); y++)
      {
        bool allmarked = 1;
        for (size_t x = 0; x < boards[z].lines[y].size(); x++)
        {
          allmarked *= boards[z].lines[y][x].marked;
        }

        if (allmarked == 1)
        {
          // std::cout << "score: " << calcscore(boards, z, num) << std::endl;
          // gameover = 1;
          boards[z].won = 1;
        }
      }
    }

    //cols
    for (size_t z = 0; z < boards.size(); z++)
    {
      for (size_t x = 0; x < boards[z].lines.size(); x++)
      {
        int allmarked = 1;
        for (size_t y = 0; y < boards[z].lines[x].size(); y++)
        {
          allmarked *= boards[z].lines[y][x].marked;
        }
        if (allmarked == 1)
        {
          // std::cout << "score: " << calcscore(boards, z, num) << std::endl;
          // gameover = 1;
          boards[z].won = 1;
        }
      }
    }
  }

  bool gameover = 0;

  while (!gameover)
  {
    int num = nums[0];
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "num: " << num << std::endl;
    SetConsoleTextAttribute(hConsole, 7);
    nums.erase(nums.begin());
    for (auto &&i : boards)
    {
      for (auto &&u : i.lines)
      {
        for (auto &&z : u)
        {
          if (z.number == num)
          {
            z.marked = 1;
          }
        }
      }
    }
    draw(boards, hConsole);
    //rows
    for (size_t z = 0; z < boards.size(); z++)
    {
      for (size_t y = 0; y < boards[z].lines.size(); y++)
      {
        bool allmarked = 1;
        for (size_t x = 0; x < boards[z].lines[y].size(); x++)
        {
          allmarked *= boards[z].lines[y][x].marked;
        }

        if (allmarked == 1)
        {
          std::cout << "score: " << calcscore(boards, z, num) << std::endl;
          gameover = 1;
        }
      }
    }

    //cols
    for (size_t z = 0; z < boards.size(); z++)
    {
      for (size_t x = 0; x < boards[z].lines.size(); x++)
      {
        int allmarked = 1;
        for (size_t y = 0; y < boards[z].lines[x].size(); y++)
        {
          allmarked *= boards[z].lines[y][x].marked;
        }
        if (allmarked == 1)
        {
          gameover = 1;
          std::cout << "score: " << calcscore(boards, z, num) << std::endl;
        }
      }
    }
  }
}
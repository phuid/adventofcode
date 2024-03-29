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

struct point
{
  uint16_t A_cost;
  uint16_t B_cost;
  uint16_t N_cost;
  bool searched = 0;
  bool visited = 0;

  point(uint16_t i_A_cost, uint16_t i_B_cost, uint16_t i_N_cost)
  {
    A_cost = i_A_cost;
    B_cost = i_B_cost;
    N_cost = i_N_cost;
  }
};

using vector_of_points = std::vector<std::vector<point>>;

int main()
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  std::vector<std::string> inputvector;

  start("day15input.txt", inputvector);

  vector_of_points field;

  // part2˘
  for (size_t y = 0; y < 5; y++)
  {
    for (size_t i = 0; i < inputvector.size(); i++)
    {
      std::vector<point> currentline;
      for (size_t x = 0; x < 5; x++)
      {
        for (size_t u = 0; u < inputvector[i].length(); u++)
        {
          currentline.push_back(point(0, (inputvector.size() - 1 - i) + (inputvector[i].length() - 1 - u), (inputvector[i][u] - '0' + x + y - 1) % 9 + 1));
        }
      }
      field.push_back(currentline);
    }
  }
  // part2^

  // //print
  // for (auto &&i : field)
  // {
  //   for (auto &&u : i)
  //   {
  //     std::cout << "<" << u.A_cost << "," << u.B_cost << "," << u.N_cost << "> ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;

  field[0][0].visited = 1;

  int last = 0;

  // explore the field and fill all important A_costs
  while (!field[field.size() - 1][field[field.size() - 1].size() - 1].visited)
  {
    uint8_t XCoord = 0;
    uint8_t YCoord = 0;

    uint16_t smallest = UINT16_MAX;
    // find smallest total cost coords
    for (size_t i = 0; i < field.size(); i++)
    {
      for (size_t u = 0; u < field[i].size(); u++)
      {
        if (smallest > field[i][u].A_cost + field[i][u].B_cost + (field.size() + field[0].size() - XCoord - YCoord) && field[i][u].visited && !field[i][u].searched)
        {
          smallest = field[i][u].A_cost + field[i][u].B_cost + (field.size() + field[0].size() - XCoord - YCoord);
          XCoord = u;
          YCoord = i;
        }
      }
    }

    // calculate nearby A_costs
    if (YCoord > 0 && (!field[YCoord - 1][XCoord].visited || field[YCoord - 1][XCoord].N_cost + field[YCoord][XCoord].A_cost < field[YCoord - 1][XCoord].A_cost))
    {
      field[YCoord - 1][XCoord].A_cost = field[YCoord - 1][XCoord].N_cost + field[YCoord][XCoord].A_cost;
      field[YCoord - 1][XCoord].searched = 0;
      field[YCoord - 1][XCoord].visited = 1;
    }
    if (XCoord > 0 && (!field[YCoord][XCoord - 1].visited || field[YCoord][XCoord - 1].N_cost + field[YCoord][XCoord].A_cost < field[YCoord][XCoord - 1].A_cost))
    {
      field[YCoord][XCoord - 1].A_cost = field[YCoord][XCoord - 1].N_cost + field[YCoord][XCoord].A_cost;
      field[YCoord][XCoord - 1].searched = 0;
      field[YCoord][XCoord - 1].visited = 1;
    }
    if (YCoord < field.size() - 1 && (!field[YCoord + 1][XCoord].visited || field[YCoord + 1][XCoord].N_cost + field[YCoord][XCoord].A_cost < field[YCoord + 1][XCoord].A_cost))
    {
      field[YCoord + 1][XCoord].A_cost = field[YCoord + 1][XCoord].N_cost + field[YCoord][XCoord].A_cost;
      field[YCoord + 1][XCoord].searched = 0;
      field[YCoord + 1][XCoord].visited = 1;
    }
    if (XCoord < field[0].size() - 1 && (!field[YCoord][XCoord + 1].visited || field[YCoord][XCoord + 1].N_cost + field[YCoord][XCoord].A_cost < field[YCoord][XCoord + 1].A_cost))
    {
      field[YCoord][XCoord + 1].A_cost = field[YCoord][XCoord + 1].N_cost + field[YCoord][XCoord].A_cost;
      field[YCoord][XCoord + 1].searched = 0;
      field[YCoord][XCoord + 1].visited = 1;
    }

    field[YCoord][XCoord].searched = 1;

    std::cout << field.size() + field[0].size() - XCoord - YCoord << std::endl;

    if (field.size() + field[0].size() - XCoord - YCoord == 960 && last == 960)
    {
      std::cout << field.size() + field[0].size() - XCoord - YCoord << std::endl;
      std::cout << "print?: " << std::endl;
      bool print = 0;
      std::cin >> print;

      if (print)
      {
        std::ofstream output;
        output.open("out.csv");
        if (output.is_open())
        {
          output.clear();
          for (auto &&i : field)
          {
            for (auto &&u : i)
            {
              output << (u.searched ? '>' : '<') << u.A_cost << (u.visited ? '_' : ',') << u.B_cost << (u.visited ? '_' : ',') << u.N_cost << (u.searched ? "< " : ">") << ";";
            }
            output << std::endl;
          }
          output.close();
        }
        else
        {
          std::cerr << "ERR: out.txt isnt open" << std::endl;
        }

        std::cout << "printed" << std::endl;

        //   // print
        //   for (auto &&i : field)
        //   {
        //     for (auto &&u : i)
        //     {
        //       SetConsoleTextAttribute(hConsole, u.searched + u.visited * 2);
        //       std::cout << (u.searched ? '>' : '<') << u.A_cost << (u.visited ? '_' : ',') << u.B_cost << (u.visited ? '_' : ',') << u.N_cost << (u.searched ? "< " : "> ");
        //       SetConsoleTextAttribute(hConsole, 7);
        //     }
        //     std::cout << std::endl;
        //   }
        //   std::cout << std::endl;
        // }
      }

      // if (last == 931)
      //   std::cout << field.size() + field[0].size() - XCoord - YCoord << std::endl;

      // std::cout << "dist to end(0-1000): " << field.size() + field[0].size() - XCoord - YCoord << std::endl;
    }
    last = field.size() + field[0].size() - XCoord - YCoord;
  }
  
  // print
  for (auto &&i : field)
  {
    for (auto &&u : i)
    {
      SetConsoleTextAttribute(hConsole, u.searched + u.visited * 2);
      // std::cout << (u.searched ? '>' : '<') << u.A_cost << (u.visited ? '_' : ',') << u.B_cost << (u.visited ? '_' : ',') << u.N_cost << (u.searched ? "< " : "> ");
      std::cout << u.N_cost;
      SetConsoleTextAttribute(hConsole, 7);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::cout << "total: " << field[field.size() - 1][field[field.size() - 1].size() - 1].A_cost << std::endl;
}

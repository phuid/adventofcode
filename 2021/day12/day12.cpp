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

struct Cave
{
  std::string name;
  bool big;
  std::vector<Cave *> connections;
};

int main()
{
  std::vector<std::string> inputvector;

  start("day12input.txt", inputvector);

  std::vector<Cave> caves;

  for (auto &&i : inputvector)
  {
    for (size_t n = 0; n < 2; n++)
    {
      std::string currentcavename;
      if (n == 0)
      {
        currentcavename = i.substr(0, i.find('-'));
      }
      else
      {
        currentcavename = i.substr(i.find('-') + 1);
      }
      bool caveexists = 0;
      for (auto &&u : caves)
      {
        if (u.name == currentcavename)
        {
          caveexists = 1;
          break;
        }
      }
      if (!caveexists)
      {
        bool bigcave = 0;
        if (currentcavename[0] >= 'A' && currentcavename[0] <= 'Z')
        {
          bigcave = 1;
        }
        caves.push_back({currentcavename, bigcave});
      }
    }
  }

  for (auto &&i : inputvector)
  {
    for (size_t n = 0; n < 2; n++)
    {
      std::string currentcavename;
      std::string othercavename;
      if (n == 0)
      {
        currentcavename = i.substr(0, i.find('-'));
        othercavename = i.substr(i.find('-') + 1);
      }
      else
      {
        currentcavename = i.substr(i.find('-') + 1);
        othercavename = i.substr(0, i.find('-'));
      }

      Cave *othercavepointer;

      for (size_t i = 0; i < caves.size(); i++)
      {
        if (caves[i].name == othercavename)
        {
          othercavepointer = &caves[i];
        }
      }

      for (auto &&i : caves)
      {
        if (i.name == currentcavename)
        {
          i.connections.push_back(othercavepointer);
        }
      }
    }
  }

  

  // for (auto &&i : caves)
  // {
  //   std::cout << i.name << i.big;
  //   for (auto &&u : i.connections)
  //   {
  //     std::cout << u->name << ',';
  //   }
  //   std::cout << std::endl;
  // }
}
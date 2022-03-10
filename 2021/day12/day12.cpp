#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Cave
{
  std::string name;
  bool big;
  std::vector<Cave *> connections;
};

using path = std::vector<Cave *>;

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
    exit(1);
  }
}

void pathfinder(path inputpath, std::vector<path> &paths)
{
  if (inputpath.back()->name != "end")
  {
    for (Cave *connection : inputpath.back()->connections)
    {
      path newpath = inputpath;
      if (std::find(newpath.begin(), newpath.end(), connection) != newpath.end() && !connection->big)
        continue;
      newpath.push_back(connection);
      pathfinder(newpath, paths);
    }
  }
  else
  {
    paths.push_back(inputpath);
  }
}

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

  std::vector<path> paths;

  for (auto &&i : caves)
  {
    if (i.name == "start")
    {
      path newpath;
      newpath.push_back(&i);
      pathfinder(newpath, paths);
      break;
    }
  }

  size_t counter = 0;
  for (auto &&i : paths)
  {
    // for (auto &&u : i)
    // {
    //   std::cout << u->name << " ";
    // }
    // std::cout << std::endl;
    counter++;
  }
  std::cout << "counter: " << counter << std::endl;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Cave
{
  std::string name;
  int big;
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
      // std::cout << std::count(newpath.begin(), newpath.end(), connection) << std::endl;
      if (((std::count(newpath.begin(), newpath.end(), connection) >= 2 && connection->big == 1) && connection->big != 2) || (std::find(newpath.begin(), newpath.end(), connection) != newpath.end() && !connection->big) || connection->name == "start")
        continue;
      newpath.push_back(connection);
      pathfinder(newpath, paths);
    }
  }
  else if (std::find(paths.begin(), paths.end(), inputpath) == paths.end())
  {
    paths.push_back(inputpath);
    if (paths.size() % 2500 == 0)
      std::cout << paths.size() << std::endl;
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
        int bigcave = 0;
        if (currentcavename[0] >= 'A' && currentcavename[0] <= 'Z')
        {
          bigcave = 2;
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
      for (auto &&cave : caves)
      {
        if (cave.big == 0)
        {
          cave.big = 1;
        }

        path newpath;
        newpath.push_back(&i);
        pathfinder(newpath, paths);

        if (cave.big == 1)
        {
          cave.big = 0;
        }
      }
      break;
    }
  }

  // std::vector<path> pathscopy = paths;

  // for (size_t i = 0; i < pathscopy.size(); i++)
  // {
  //   if (std::count(paths.begin(), paths.end(), pathscopy[i]) > 1)
  //   {
  //     paths.erase(std::find(paths.begin(), paths.end(), pathscopy[i]));
  //     std::cout << "erase " << i << "/" << pathscopy.size() << " = " << i/pathscopy.size() << std::endl;
  //   }
  // }

  std::cout << "pathscount: " << paths.size() << std::endl;
  exit(0);
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

constexpr int max[3] = {12, 13, 14};

std::map<std::string, char> dict = {
    {"red", 0},
    {"green", 1},
    {"blue", 2}};

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
  std::cout << "Hello World!" << std::endl;

  std::vector<std::string> inputvector;
  std::vector<std::vector<std::vector<int>>> games;

  start("input.txt", inputvector);

  for (auto &&i : inputvector)
  {
    std::vector<std::vector<int>> current_game;
    size_t colon_pos = i.find(':');
    int game_id = stoi(i.substr(5, colon_pos - 5));
    i = i.substr(colon_pos + 2);
    // std::cout << game_id << "-";
    while (i.length() > 0)
    {
      size_t delimeter_pos = i.find(';');
      std::string set_string;
      if (delimeter_pos == std::string::npos)
      {
        set_string = i;
        i = "";
      }
      else
      {
        set_string = i.substr(0, delimeter_pos);
        i = i.substr(delimeter_pos + 2);
      }
      // std::cout << set_string << "|";
      std::vector<int> current_set = {0, 0, 0};
      uint8_t counter = 0;
      while (set_string.size() > 0)
      {
        if (counter > 2)
        {
          std::cerr << "err: counter more than 3" << std::endl;
          break;
        }
        size_t comma_pos = set_string.find(',');
        std::string color_string;
        if (comma_pos == std::string::npos)
        {
          color_string = set_string.substr(set_string.find(' ') + 1);
        }
        else
        {
          color_string = set_string.substr(set_string.find(' ') + 1, comma_pos - (set_string.find(' ') + 1));
        }

        current_set[dict[color_string]] = stoi(set_string.substr(0, set_string.find(' ')));

        if (comma_pos == std::string::npos)
        {
          set_string = "";
        }
        else
        {
          set_string = set_string.substr(set_string.find(',') + 2);
        }
        // std::cout << current_set[counter] << ",";
        counter++;
      }
      current_game.push_back(current_set);
      // std::cout << ";";
    }
    games.push_back(current_game);
    // std::cout << std::endl;
  }

  std::cout << "succesfully parsed" << std::endl;

  std::vector<int> possible_games;

  for (size_t i = 0; i < games.size(); i++)
  {
    for (size_t u = 0; u < games[i].size(); u++)
    {
      for (size_t z = 0; z < games[i][u].size(); z++)
      {
        if (games[i][u][z] > max[z])
        {
          goto break_games;
        }
      }
      if (u == games[i].size() - 1)
      {
        possible_games.push_back(i + 1); // games[0] id: 1
      }
    }
  break_games:
    continue; // lol
  }
  int sum = 0;
  std::cout << "possible games: ";
  for (auto &&i : possible_games)
  {
    std::cout << i << ", ";
    sum += i;
  }
  std::cout << std::endl;
  std::cout << "sum:" << sum << std::endl;

  std::cout << "part two:" << std::endl;

  std::vector<std::vector<int>> min_cubes_per_games;
  for (auto &&game : games)
  {
    std::vector<int> current_min;
    for (size_t color_i = 0; color_i < 3; color_i++)
    {
      int min = game[0][color_i];
      for (size_t set_i = 1; set_i < game.size(); set_i++)
      {
        if (game[set_i][color_i] > min)
          min = game[set_i][color_i];
      }
      current_min.push_back(min);
    }
    min_cubes_per_games.push_back(current_min);
  }

  int total = 0;
  for (size_t i = 0; i < min_cubes_per_games.size(); i++)
  {
    std::cout << "game " << i + 1 << ": ";
    int power = 1;
    for (auto &&color : min_cubes_per_games[i])
    {
      std::cout << color << ", ";
      power *= color;
    }
    std::cout << std::endl
              << "power:" << power << std::endl;
    total += power;
  }
  std::cout << "total: " << total << std::endl;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

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

bool hasoneinside(std::string u, std::map<char, std::string> map)
{
  std::string numberone = "";
  for (auto &&i : map['c'])
  {
    if (numberone.find(i) == std::string::npos && i != '.')
    {
      numberone += i;
    }
  }
  for (auto &&i : map['f'])
  {
    if (numberone.find(i) == std::string::npos && i != '.')
    {
      numberone += i;
    }
  }
  // std::cout << numberone << std::endl;
  for (auto &&i : numberone)
  {
    if (u.find(i) == std::string::npos)
    {
      return 0;
    }
  }
  return 1;
}

int similaritieswithfour(std::string u, std::map<char, std::string> map)
{
  std::string numberfour = "";
  for (auto &&i : map['b'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  for (auto &&i : map['c'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  for (auto &&i : map['d'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  for (auto &&i : map['f'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  // std::cout << numberfour << std::endl;
  int counter = 0;
  for (auto &&i : numberfour)
  {
    if (u.find(i) != std::string::npos)
    {
      counter++;
    }
  }
  return counter;
}

bool apartoftwo(char z, std::map<char, std::string> map)
{
  std::string numbertwo = "";
  for (auto &&i : map['a'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['c'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['d'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['e'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['g'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }

  if (numbertwo.find(z) != std::string::npos)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool apartofthree(char z, std::map<char, std::string> map)
{
  std::string numbertwo = "";
  for (auto &&i : map['a'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['c'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['d'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['f'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }
  for (auto &&i : map['g'])
  {
    if (numbertwo.find(i) == std::string::npos && i != '.')
    {
      numbertwo += i;
    }
  }

  if (numbertwo.find(z) != std::string::npos)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool apartoffour(char z, std::map<char, std::string> map)
{
  std::string numberfour = "";
  for (auto &&i : map['b'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  for (auto &&i : map['c'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  for (auto &&i : map['d'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }
  for (auto &&i : map['f'])
  {
    if (numberfour.find(i) == std::string::npos && i != '.')
    {
      numberfour += i;
    }
  }

  if (numberfour.find(z) != std::string::npos)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool apartofseven(char z, std::map<char, std::string> map)
{
  std::string numberseven = "";
  for (auto &&i : map['a'])
  {
    if (numberseven.find(i) == std::string::npos && i != '.')
    {
      numberseven += i;
    }
  }
  for (auto &&i : map['c'])
  {
    if (numberseven.find(i) == std::string::npos && i != '.')
    {
      numberseven += i;
    }
  }
  for (auto &&i : map['f'])
  {
    if (numberseven.find(i) == std::string::npos && i != '.')
    {
      numberseven += i;
    }
  }

  if (numberseven.find(z) != std::string::npos)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool done(std::map<char, std::string> map)
{
  for (auto &&i : map)
  {
    int possibilities = 0;
    for (auto &&u : std::get<std::string>(i))
    {
      if (u != '.')
      {
        possibilities++;
      }
    }
    if (possibilities > 1)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  std::vector<std::string> inputvector;

  start("day8input.txt", inputvector);

  struct display
  {
    std::vector<std::string> combinations;
    std::vector<std::string> digits;
    std::map<char, std::string> map{
        {'a', "abcdefg"},
        {'b', "abcdefg"},
        {'c', "abcdefg"},
        {'d', "abcdefg"},
        {'e', "abcdefg"},
        {'f', "abcdefg"},
        {'g', "abcdefg"},
    };
    int value = 0;
  };

  std::vector<display> displays;

  for (auto &&i : inputvector)
  {
    display currentdisplay;
    while (i.find('|') != 0)
    {
      currentdisplay.combinations.push_back(i.substr(0, i.find(' ')));
      i = i.substr(i.find(' ') + 1);
    }
    i = i.substr(2);
    while (i.length() > 0)
    {
      if (i.find(' ') != std::string::npos)
      {
        currentdisplay.digits.push_back(i.substr(0, i.find(' ')));
        i = i.substr(i.find(' ') + 1);
      }
      else
      {
        currentdisplay.digits.push_back(i);
        i = "";
      }
    }
    displays.push_back(currentdisplay);
  }

  size_t total = 0;
  for (auto &&i : displays)
  {
    int frames = 0;
    while (!done(i.map))
    {
      for (auto &&u : i.combinations)
      {
        //if number inside u is 1
        if (u.length() == 2)
        {
          for (auto &&z : i.map['c'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
          for (auto &&z : i.map['f'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
        }
        //gotta be 7
        else if (u.length() == 3)
        {
          for (auto &&z : i.map['a'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
          for (auto &&z : i.map['c'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
          for (auto &&z : i.map['f'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
        }
        //gotta be 4
        else if (u.length() == 4)
        {
          for (auto &&z : i.map['b'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
          for (auto &&z : i.map['c'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
          for (auto &&z : i.map['d'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
          for (auto &&z : i.map['f'])
          {
            if (u.find(z) == std::string::npos)
            {
              z = '.';
            }
          }
        }
        //gotta be 3/2/5
        else if (u.length() == 5)
        {
          //gotta be 3
          if (hasoneinside(u, i.map))
          {
            for (auto &&z : i.map['a'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['c'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['d'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['f'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['g'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
          }

          // std::cout << "smi:" << similaritieswithfour(u, i.map) << std::endl;
          //gotta be 2
          else if (similaritieswithfour(u, i.map) == 2)
          {
            for (auto &&z : i.map['a'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['c'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['d'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['e'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['g'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
          }
          //gotta be 5
          else if (similaritieswithfour(u, i.map) == 3 && frames > 12)
          {
            for (auto &&z : i.map['a'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['b'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['d'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['f'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
            for (auto &&z : i.map['g'])
            {
              if (u.find(z) == std::string::npos)
              {
                z = '.';
              }
            }
          }
        }
        //gotta be 0/6/9
        else if (u.length() == 6 && frames > 20)
        {
          //gotta be 9
          // std::cout << "ja nevim uz" << similaritieswithfour(u, i.map) << std::endl;
          if (similaritieswithfour(u, i.map) == 4)
          {
            for (auto &&z : i.map['e'])
            {
              if (u.find(z) == std::string::npos && z != '.' && z != 0)
              {
                i.map['e'] = z;
              }
            }
          }
          //gotta be 0
          else if (hasoneinside(u, i.map))
          {
            for (auto &&z : i.map['d'])
            {
              if (u.find(z) == std::string::npos && z != '.' && z != 0)
              {
                i.map['d'] = z;
              }
            }
          }
          //is 6
          else
          {
            // std::cout << "else" << std::endl;
            for (auto &&z : i.map['c'])
            {
              if (u.find(z) == std::string::npos && z != '.' && z != 0)
              {
                i.map['c'] = z;
              }
            }
          }
        }
        if (frames > 30)
        {
          //is top left
          for (auto &&z : u)
          {
            if (!apartoftwo(z, i.map) && !apartofthree(z, i.map) && z != '.' && z != 0)
            {
              i.map['b'] = z;
            }
            else if (apartoftwo(z, i.map) && apartofthree(z, i.map) && !apartoffour(z, i.map) && !apartofseven(z, i.map) && z != '.' && z != 0)
            {
              i.map['g'] = z;
            }
          }
        }
      }
      frames++;
    }
    // for (int u = 0; u < 7; u++)
    // {
    //   std::cout << "   "
    //             << "abcdefg"[u] << "   |";
    // }
    // std::cout << std::endl;
    // for (auto &&u : i.map)
    // {
    //   std::cout << std::setw(7) << std::get<std::string>(u) << "|";
    // }
    // std::cout << std::endl;

    for (auto &&u : i.map)
    {
      for (auto &&z : u.second)
      {
        if (z >= 'a' && z <= 'g')
        {
          u.second = z;
          break;
        }
      }
    }

    std::string currenttotal = "";
    for (auto &&u : i.digits)
    {
      //is 0
      if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) != std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) == std::string::npos && u.find(i.map['e'][0]) != std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "0";
        currenttotal += "0";
      }
      //is 1
      else if (u.find(i.map['a'][0]) == std::string::npos && u.find(i.map['b'][0]) == std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) == std::string::npos && u.find(i.map['e'][0]) == std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) == std::string::npos)
      {
        std::cout << "1";
        currenttotal += "1";
      }
      //is 2
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) == std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) != std::string::npos && u.find(i.map['f'][0]) == std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "2";
        currenttotal += "2";
      }
      //is 3
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) == std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) == std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "3";
        currenttotal += "3";
      }
      //is 4
      else if (u.find(i.map['a'][0]) == std::string::npos && u.find(i.map['b'][0]) != std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) == std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) == std::string::npos)
      {
        std::cout << "4";
        currenttotal += "4";
      }
      //is 5
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) != std::string::npos && u.find(i.map['c'][0]) == std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) == std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "5";
        currenttotal += "5";
      }
      //is 6
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) != std::string::npos && u.find(i.map['c'][0]) == std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) != std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "6";
        currenttotal += "6";
      }
      //is 7
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) == std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) == std::string::npos && u.find(i.map['e'][0]) == std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) == std::string::npos)
      {
        std::cout << "7";
        currenttotal += "7";
      }
      //is 8
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) != std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) != std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "8";
        currenttotal += "8";
      }
      //is 9
      else if (u.find(i.map['a'][0]) != std::string::npos && u.find(i.map['b'][0]) != std::string::npos && u.find(i.map['c'][0]) != std::string::npos && u.find(i.map['d'][0]) != std::string::npos && u.find(i.map['e'][0]) == std::string::npos && u.find(i.map['f'][0]) != std::string::npos && u.find(i.map['g'][0]) != std::string::npos)
      {
        std::cout << "9";
        currenttotal += "9";
      }
    }
    total += stoi(currenttotal);
  }
  std::cout << std::endl << "total: " << total << std::endl;
}
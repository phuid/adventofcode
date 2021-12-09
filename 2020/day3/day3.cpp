#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

int strom[323][32];

int main()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  ifstream sjezdovka;
  sjezdovka.open("day3input.txt");

  string line;
  vector<int> hitvector;
  long long unsigned int hits = 1;

  for (int y = 0; getline(sjezdovka, line); y++)
  {
    for (int x = 0; x < 31; x++)
    {

      if (line[x] == '.')
        strom[y][x] = 0;
      else
        strom[y][x] = 1;
    }
  }

  sjezdovka.close();

  for (int route = 1; route <= 9; route += 2)
  {
    int currentcount = 0;
    int xx = 0;
    int color;

    if (route == 1)
      color = 3;
    else if (route == 3)
      color = 4;
    else if (route == 5)
      color = 5;
    else if (route == 7)
      color = 6;
    else if (route == 9)
      color = 10;

    for (int y = 0; y < 323; y++)
    {
      if (route == 9 & y > 0)
        y++;

      if (xx < 31)
      {
        if (strom[y][xx] == 1 | strom[y][xx] > 63)
        {
          strom[y][xx] = color + 63;
          currentcount++;
        }
        else
          strom[y][xx] = color;
      }
      else
      {
        xx = xx % 31;
        if (strom[y][xx] == 1 | strom[y][xx] > 63)
        {
          strom[y][xx] = color + 63;
          currentcount++;
        }
        else
          strom[y][xx] = color;
      }
      if (route != 9)
        xx += route;
      else
        xx++;
    }
    hitvector.push_back(currentcount);
  }

  for (int y = 0; y < 323; y++)
  {
    for (int x = 0; x < 31; x++)
    {

      if (strom[y][x] == 0)
        cout << '.';
      else if (strom[y][x] == 1)
        cout << '#';
      else if (strom[y][x] > 1 & strom[y][x] < 63)
      {
        SetConsoleTextAttribute(hConsole, strom[y][x]);
        cout << 'o';
        SetConsoleTextAttribute(hConsole, 7);
      }
      else if (strom[y][x] > 63)
      {
        SetConsoleTextAttribute(hConsole, strom[y][x] - 63);
        cout << 'X';
        SetConsoleTextAttribute(hConsole, 7);
      }
      if (x >= 30)
        cout << endl;
    }
  }

  cout << "hits = ";

  for (int i = 0; i < hitvector.size(); i++)
  {
    if (i != hitvector.size() - 1)
    {
      hits *= hitvector[i];
      cout << hitvector[i] << " * ";
    }
    else
    {
      hits *= hitvector[i];
      cout << hitvector[i];
    }
  }

  cout << " = " << hits << endl;
}
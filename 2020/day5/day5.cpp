#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool plane[128][8];
int high = 0;

vector<string> inputvector;

int main()
{

  ifstream input;
  input.open("day5input.txt");
  string line;
  int x;
  if (input.is_open())
  {
    while (getline(input, line))
    {
      inputvector.push_back(line);
      x++;
    }
    input.close();

    for (size_t i = 0; i < inputvector.size(); i++)
    {
      int xtop = 127;
      int xbot = 0;
      int ytop = 7;
      int ybot = 0;

      // cout << i << endl;
      //get seat coordinates
      for (size_t u = 0; u < 10; u++)
      {
        if (inputvector[i].substr(u, 1) == "B")
          xbot += pow(2, 6 - u);
        else if (inputvector[i].substr(u, 1) == "F")
          xtop -= pow(2, 6 - u);
        else if (inputvector[i].substr(u, 1) == "R")
          ybot += pow(2, 9 - u);
        else if (inputvector[i].substr(u, 1) == "L")
          ytop -= pow(2, 9 - u);

        // cout << "  " << u << inputvector[i].substr(u, 1) << endl;
        // cout << "  x( " << xbot << "-" << xtop << " )" << endl;
        // cout << "  y( " << ybot << "-" << ytop << " )" << endl
        //      << endl;
        // cout << inputvector[i].substr(u, 1) << ".." << endl;
      }
      // cout << "  row: " << xtop << ", seat: " << ytop << endl;
      // cout << "  id: " << (xtop * 8) + ytop << endl;
      // plane[xtop][ytop] = 1;

      //get highest seat id
      if ((xtop * 8) + ytop > high)
        high = (xtop * 8) + ytop;

      //print the plane (# - working on, 0 - unknown seat, 1 - occupied seat)
      int occupied = 0;
      int free = 0;
      for (size_t i = 0; i < 8; i++)
      {
        for (size_t u = 0; u < 128; u++)
        {
          if (u == xtop && i == ytop)
          {
            // cout << "#";
            plane[u][i] = true;
            // occupied++;
          }
          else
            // cout << plane[u][i];

          if (plane[u][i])
            occupied++;
          if (!plane[u][i])
            free++;
        }
        // cout << endl;
      }
      // cout << "occupied: " << occupied << ", free: " << free << endl;
      // cout << endl;
    }


    for (size_t i = 0; i < 8; i++)
      {
        for (size_t u = 0; u < 128; u++)
        {
            cout << plane[u][i];
        }
        cout << endl;
      }
      
    

    cout << "high: " << high << endl;

    for (size_t i = 0; i < 8; i++)
    {
      for (size_t u = 0; u < 128; u++)
      {
        if (!plane[u][i] && (plane[u][i+1] && plane[u][i-1]) /*|(i == 0 && plane[u-1][7])|(i == 7 && plane[u+1][0])*/)
        {
          cout << "plane[" << u << "][" << i << "], id: " << (u * 8) + i << endl;
        }
        
      }
      
    }
    
  }
  else
  {
    cout << "no!§!§!§!!!!" << endl;
  }
}
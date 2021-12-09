#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string numstr;
string nummstr;
string character;
string pass;
int num;
int numm;
int totalcount = 0;

int main()
{
  string line;
  ifstream input("day2input.txt");

  while (!input.is_open())
  {
    ifstream input("day2input.txt");
    cout << "trying to open day2input.txt" << endl;
  }

  while (getline(input, line))
  {
    // for (int i = 0; i <= line.strlen(); i++) {
    //     if (line[i] == '-') {
    //     }
    // }

    numstr = line.substr(0, line.find('-'));
    nummstr = line.substr(line.find('-') + 1, line.find(' ') - 1);
    num = stoi(numstr);
    numm = stoi(nummstr);
    character = line.substr(line.find(':') - 1, 1);
    pass = line.substr(line.find(':') + 2, line.length() - 1);

    int count = 0;
    for (int i = 0; i < pass.length(); i++)
    {
      std::string s(1, pass[i]);
      if (s == character)
      {
        count++;
      }
    }

    bool valid = 0;

    if (num <= count & count <= numm)
    {
      valid = 1;
      totalcount++;
    }

    cout << line << endl;
    cout << num << "-" << numm << " " << character << ": " << pass << " -- " << valid << endl;
    cout << "totalcount: " << totalcount << endl;
  }
}

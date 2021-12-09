#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string numstr;
string nummstr;
string character;
string pass;
string check;
string checkk;
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

    check = line.substr(line.find(':') + 1 + num, 1);
    checkk = line.substr(line.find(':') + 1 + numm, 1);

    int count = 0;
    if (check == character)
    {
      count++;
    }
    if (checkk == character)
    {
      count++;
    }

    bool valid = 0;

    if (count == 1)
    {
      valid = 1;
      totalcount++;
    }

    cout << line << endl;
    cout << num << "-" << numm << " " << character << ": "
         << " -- " << valid << endl;
    cout << "totalcount: " << totalcount << endl;
  }
}

/*
zadani:
    cisla jsou pozice
    dane pismeno musi byt presne na jedne z techto pozic
*/
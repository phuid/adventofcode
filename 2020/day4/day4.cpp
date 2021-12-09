#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <regex>

using namespace std;

vector<string> inputvector;
vector<string> outputvector;

int main()
{
    cout<<"gg"<<endl;
    ifstream input;
    input.open("day4input.txt");
    string line;
    int x;
    if(input.is_open()) {
    while (getline(input, line))
    {
        inputvector.push_back(line);
        x++;
    }
    input.close();

    // int u = 0;
    // while (u < inputvector.size())
    // {
    //     // stringstream ss;
    //     // for (int i = 0; i < 8 & u + i < inputvector.size(); i++)
    //     // {
    //     //     ss << inputvector[u + i];
    //     // }
    //     // string s = ss.str();
    //     // string subs = s.substr(s.find("\r\n\r\n"));
    //     // cout << subs;

    //     for (int i = 0; i < inputvector.size(); i=i)
    //     {
    //         /* code */
    //     }

    // }

    stringstream ss;
    int haha;
    for (int i = 0; i <= inputvector.size(); i++)
    {
        // cout << inputvector[i].length() << endl;
        if (inputvector[i].length() != 0)
            ss << inputvector[i] << " ";
        else
        {
            outputvector.push_back(ss.str());
            ss.str("");
            ss.clear();
        }
    }
    inputvector.clear();

    //novy kod


    int validcount = 0;
    for (int i = 0; i < outputvector.size(); i++)
    {
        bool valid = 0;
        //definovat regexy
        regex rege("(byr:(19[2-9][0-9])|(200[0-2])) (((hcl)|(iyr)|(eyr)|(hgt)|(ecl)|(pid)|(cid)|($)))"); //1xxxxxx    
        regex regee("(iyr:(201[0-9])|(2020)) (((byr)|(hcl)|(eyr)|(hgt)|(ecl)|(pid)|(cid)|($)))"); //x1xxxxx
        regex regeee("(eyr:(202[0-9])|(2030)) (((byr)|(iyr)|(hcl)|(hgt)|(ecl)|(pid)|(cid)|($)))");//xx1xxxx
        regex regeeee("(hgt:(1[5-8][0-9]cm)|(19[0-3]cm)|(59in)|(6[0-9]in)|(7[0-6]in)) (((byr)|(iyr)|(eyr)|(hcl)|(ecl)|(pid)|(cid)|($)))"); //xxx1xxx
        regex regeeeee("(hcl:#((([a-f])|([0-9])){6}) (((byr)|(iyr)|(eyr)|(hgt)|(ecl)|(pid)|(cid)|($))))"); //xxxx1xx
        regex regeeeeee("(ecl:(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)) (((byr)|(iyr)|(eyr)|(hgt)|(hcl)|(pid)|(cid)|($)))"); //xxxxx1x
        regex regeeeeeee("(pid:[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]) (((byr)|(iyr)|(eyr)|(hgt)|(ecl)|(hcl)|(cid)|($)))"); //xxxxxx1
        //overit pravost
        if (regex_search(outputvector[i], rege) && regex_search(outputvector[i], regee) && regex_search(outputvector[i], regeee) && regex_search(outputvector[i], regeeee) && regex_search(outputvector[i], regeeeee) && regex_search(outputvector[i], regeeeeee) && regex_search(outputvector[i], regeeeeeee))
        {
            valid = 1;
            validcount++;
        }
        //vypsat ve formatu '<pasport string> "---"<overeni jednotlivych regexu 1-7>"------"<pravost>"----------"'
        cout << outputvector[i] << "---" << regex_search(outputvector[i], rege) << regex_search(outputvector[i], regee) << regex_search(outputvector[i], regeee) << regex_search(outputvector[i], regeeee) << regex_search(outputvector[i], regeeeee) << regex_search(outputvector[i], regeeeeee) << regex_search(outputvector[i], regeeeeeee) << "------" << valid << "----------" << endl;
    }
    cout << "validcount: " << validcount - 1 /*pššššššššššššššššššššt*/ << endl;
    }
    else {
        cout << "input not open" << endl;
    }
}
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{
    regex regexes[] = {
        regex("iyr:.+?(?=\\W)"),
        regex("byr:.+?(?=\\W)"),
        regex("eyr:.+?(?=\\W)"),
        regex("hgt:.+?(?=\\W)"),
        regex("hcl:.+?(?=\\W)"),
        regex("ecl:.+?(?=\\W)"),
        regex("pid:.+?(?=\\W)"),
        // regex("cid:.+?(?=[\\W])"),
    };

    ifstream myfile("day4input.txt");

    if (myfile.is_open())
    {
        string line;
        vector<string> data;
        data.push_back(""); // vytvoří první prvek vektoru
        while (getline(myfile, line))
        {
            if (line.size() > 0)           // pokud řádek není prázdný == neodděluje záznamy:
                data.back() += line + " "; // přidej řádek k aktuálnímu záznamu
            else                           // pokud prázdný řádek == oddělování záznamů:
                data.push_back("");        // vytvoř nový záznam
        }
        myfile.close();

        for (auto &i : data)
            cout << i << endl; // debug výpis

        cout << "------------------------------------------------------------------" << endl;

        int counter = 0;
        for (auto &i : data)
        {
            int isOk = 1;
            for (auto &j : regexes)
            {
                // cout << regex_search(i, j) << " "; // debug výpis
                isOk *= regex_search(i, j);
            }
            counter += isOk;
            // cout << endl;
        }
        cout << "Výsledek: " << counter << endl;
    }
    else
        cout << "Unable to open file!";
    return 0;
}

// byr (Birth Year)
// iyr (Issue Year)
// eyr (Expiration Year)
// hgt (Height)
// hcl (Hair Color)
// ecl (Eye Color)
// pid (Passport ID)

// cid (Country ID)
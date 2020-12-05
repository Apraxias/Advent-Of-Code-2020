#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int passPorts(string ip)
{
    int ipln = ip.length();
    string id_note;
    int count = 0;
    for (int i = 0; i < ipln; i++)
    {
        if (ip[i] == ':')
        {
            id_note = ip.substr(i - 3, 3);
            if (id_note == "byr" || id_note == "iyr" || id_note == "eyr" || id_note == "hgt" ||
                id_note == "hcl" || id_note == "ecl" || id_note == "pid")
            {
                count++;
                id_note = "";
            }
        }
    }
    return count >= 7;
}

int main(void)
{
    ifstream ifp;
    string task = "";
    string buffer;
    int count = 0;
    ifp.open("input.txt");

    while (!ifp.eof())
    {
        getline(ifp, buffer);
        task += buffer;
        if (!buffer.size())
        {
            if (passPorts(task))
            {
                count++;
            }
            task = "";
        }
    }
    cout << "There are " << count << " valid passports!";
}
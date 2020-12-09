#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{
    fstream ifp;
    string buffer;
    vector<string> file;
    ifp.open("input.txt");
    while (!ifp.eof())
    {
        getline(ifp, buffer);
    }
}
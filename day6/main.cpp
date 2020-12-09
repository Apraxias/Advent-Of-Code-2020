#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int getAnswer(string ip)
{
    
    int n = 0;
    int iplen = ip.length();
    for (int i = 0; i < iplen-n; i++)
    {
        for (int j = i+1; j < iplen-n; j++)
        {
            if (ip[i] == ip[j])
            {
                ip.erase(j,1);
                n++;
            }
        }
    }
    return ip.length();
}

int main(void)
{
    string buffer;
    string task = "";
    fstream ifp;
    int sum = 0;
    ifp.open("input.txt");
    while (!ifp.eof())
    {
        getline(ifp, buffer);
        task += buffer;
        if (!buffer.size())
        {
            sum += getAnswer(task);
            task = "";
        }
    }
    cout << "The sum of their answers are " << sum << "!";
}
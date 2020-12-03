#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    string buffer;
    ifstream ifp;
    ifp.open("input.txt");

    int counte = 0;
    int multi = 1;
    int i = 0;

   // for (int n = 1; n < 7; n += 2)
   // {
        while (!ifp.eof())
        {
            getline(ifp, buffer);
            getline(ifp, buffer);

            if (buffer.substr(i, 1) == "#")
            {
                counte++;
            }
            i = (i + 1) % 31;
        }
    //    multi = multi * counte;
        cout << "You've seen " << counte << " trees on your path, multiplied to " << multi << endl;
    //    counte = 0;
    //    i = 0;
   // }
   //29 is the answer for 1 across 1 down!!!
}
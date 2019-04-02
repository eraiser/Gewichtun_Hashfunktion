

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("most_common_words.txt");
    string line;

    int len = 1511;

    int hitsGewichtet[len];

    int hitsUngewichtet[len];

    for (int i = 0; i < len; i++)
    {
        hitsGewichtet[i] = 0;
        hitsUngewichtet[i] = 0;
    }

    while (getline(myfile, line, '\n'))
    {
        // KeyGewichtet
        int keyG = 1;
        // KeyUngewichtet
        int keyU = 1;

        for (int y = 0; y < line.length(); y++)
        {
            keyG *= (line[y] * (y + 1));
        }

        for (int y = 0; y < line.length(); y++)
        {
            keyU *= line[y];
        }

        while (keyG < 0)
        {
            keyG += len;
        }
        while (keyU < 0)
        {
            keyU += len;
        }

        int base = 0;

        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
            {
                int index = keyG + pow(base, 2);
                while (index < 0)
                {
                    index += len;
                }
                index %= len;

                if (hitsGewichtet[index] == 0)
                {
                    hitsGewichtet[index]++;
                    break;
                }
                else
                {
                    hitsGewichtet[index]++;
                }
            }
            else
            {
                int index = keyG - pow(base, 2);
                while (index < 0)
                {
                    index += len;
                }
                index %= len;

                if (hitsGewichtet[index] == 0)
                {
                    hitsGewichtet[index]++;
                    break;
                }
                else
                {
                    hitsGewichtet[index]++;
                }
                base++;
            }
        }

        base = 0;

        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
            {
                int index = keyU + pow(base, 2);
                while (index < 0)
                {
                    index += len;
                }
                index %= len;

                if (hitsUngewichtet[index] == 0)
                {
                    hitsUngewichtet[index]++;
                    break;
                }
                else
                {
                    hitsUngewichtet[index]++;
                }
            }
            else
            {
                int index = keyU - pow(base, 2);
                while (index < 0)
                {
                    index += len;
                }
                index %= len;

                if (hitsUngewichtet[index] == 0)
                {
                    hitsUngewichtet[index]++;
                    break;
                }
                else
                {
                    hitsUngewichtet[index]++;
                }
                base++;
            }
        }
    }

    // Null Counter ungewichtet/gewichtet
    int ncu = 0;
    int ncg = 0;

    // Summe der Hits ungewichtet/gewichtet
    int scu = 0;
    int scg = 0;

    for (int i = 0; i < len; i++)
    {
        cout << "ges:" << hitsGewichtet[i] << " uges:" << hitsUngewichtet[i] << endl;

        scg += hitsGewichtet[i];
        scu += hitsUngewichtet[i];

        if (hitsGewichtet[i] == 0)
        {
            ncg++;
        }
        if (hitsUngewichtet[i] == 0)
        {
            ncu++;
        }
    }

    cout << "Nuller gewichtet: " << ncg << ", Nuller ungewichtet: " << ncu << ", Summe Hits gewichtet: " << scg << ", Summe Hits ungewichtet: " << scu << endl;

    string a;
    cin >> a;

    return 0;
}
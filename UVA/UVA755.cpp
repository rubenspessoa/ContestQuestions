#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

map<char, char> dictionary;

void fillDict ()
{
    dictionary['A'] = '2';
    dictionary['B'] = '2';
    dictionary['C'] = '2';
    dictionary['D'] = '3';
    dictionary['E'] = '3';
    dictionary['F'] = '3';
    dictionary['G'] = '4';
    dictionary['H'] = '4';
    dictionary['I'] = '4';
    dictionary['J'] = '5';
    dictionary['K'] = '5';
    dictionary['L'] = '5';
    dictionary['M'] = '6';
    dictionary['N'] = '6';
    dictionary['O'] = '6';
    dictionary['P'] = '7';
    dictionary['R'] = '7';
    dictionary['S'] = '7';
    dictionary['T'] = '8';
    dictionary['U'] = '8';
    dictionary['V'] = '8';
    dictionary['W'] = '9';
    dictionary['X'] = '9';
    dictionary['Y'] = '9';
}

int main()
{
    fillDict();
    int n;
    cin >> n;
    for ( int i = 0 ; i < n ; ++i )
    {
        int m;
        cin >> m;
        getchar();
        string phones[m];
        map<string,int> frequency;
        for ( int j = 0 ; j < m ; ++j )
        {
            getline(cin,phones[j]);
            int pos2 = phones[j].find(' ');
            if(pos2 != -1)
                phones[j].erase(pos2,1);
            int pos = phones[j].find('-');
            while(pos != -1)
            {
                phones[j].erase(pos,1);
                pos = phones[j].find('-');
            }
            for( int k = 0 ; k < phones[j].length() ; ++k)
            {
                if(phones[j][k] > '9')
                {
                    phones[j][k] = dictionary[phones[j][k]];
                }
            }
            phones[j].insert(3,"-");

            frequency[phones[j]]++;
        }
        string data[frequency.size()];
        int tamanho=0;
        for(map<string,int>::iterator it = frequency.begin();it != frequency.end();it++)
        {
            if(it->second >=2)
            {
                data[tamanho] = it->first;
                tamanho ++;
            }
        }
        sort(data, data+tamanho);

        if(data[0].empty())
        {
            cout << "No duplicates." << endl;
        }
        else
        {
            for(int k = 0 ; k < tamanho ; ++k)
            {
                cout << data[k] << " " << frequency[data[k]] << endl;
            }
        }
        if(i != n-1)
            cout << endl;
    }
}



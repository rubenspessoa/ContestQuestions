#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int somaCaracter (string phrase)
{
    int result = 0;
    for(int i=0 ; i < phrase.length() ; ++i)
    {
        char aux[2];
        aux[0] = phrase[i];
        aux[1] = '\0';
        result+= atoi(aux);
    }
    if(result >= 10)
    {
        char result2[3];
        sprintf(result2,"%d",result);
        string resultado(result2);
        return somaCaracter(resultado);
    }
    return result;
}

int main() {
    string phrase;
    getline(cin, phrase);
    while(phrase[0]!='0')
    {
        cout << somaCaracter(phrase) << endl;
        getline(cin, phrase);
    }
}

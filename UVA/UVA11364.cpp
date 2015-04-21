#include <iostream>
#include <climits>
using namespace std;

int main () {
    int t, n;
    cin >> t;
    for(int i=0; i <t ; ++i)
    {
        cin >> n;
        int maior = 0, menor = INT_MAX, x;
        for(int j=0; j < n; ++j)
        {
            cin >> x;
            if(x>maior)maior=x;
            if(x<menor)menor=x;
        }
        cout << (maior-menor)*2 << endl;
    }
}

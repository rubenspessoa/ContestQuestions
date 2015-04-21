#include <iostream>
using namespace std;

int main () {
    int k;
    cin >> k;
    while(k!=0)
    {
        int m, n, x, y;
        cin >> n >> m;
        for(int i=0; i<k; ++i)
        {
            cin >> x >> y;
            if(x==n || y==m) cout << "divisa" << endl;
            else if(x>n && y>m) cout << "NE" << endl;
            else if(x>n && y<m) cout << "SE" << endl;
            else if(x<n && y>m) cout << "NO" << endl;
            else cout << "SO" << endl;
        }
        cin >> k;
    }
}

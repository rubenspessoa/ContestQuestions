#include <iostream>
using namespace std;

int main()
{
    int H,U,D,F;
    cin >> H >> U >> D >> F ;
    while(H!=0)
    {
        int day = 0;
        double dist = 0, fatigue = (double)U, newU = U;
        fatigue *= (double)F/(double)100;
        day++;
        dist += newU;
        if(dist <= (double)H)dist -= D;
        while (dist < (double) H && (dist >= 0.0))
        {
            day++;
            newU = newU - fatigue;
            if(newU > 0)
            {
                dist += newU;
            }
            if(dist <=  H)dist -= D;
        }
        if(dist >= H)
        {
            cout << "success on day " << day << endl;
        }
        else
        {
            cout << "failure on day " << day << endl;
        }
        cin >> H >> U >> D >> F ;
    }
}

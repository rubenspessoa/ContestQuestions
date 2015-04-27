#include <iostream>

using namespace std;

int main()
{
    int n;
    int set = 1;
    cin >> n;
    while(n != 0)
    {
        int stacks[n];
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            cin >> stacks[i];
            sum += stacks[i];
        }
        int mean = sum / n;
        int result = 0;
        for(int i = 0;i < n;i++)
        {
            if(stacks[i] > mean)
            {
                result += stacks[i] - mean;
            }
        }
        cout << "Set #" << set << endl << "The minimum number of moves is " << result << '.' << endl << endl;
        set++;
        cin >> n;
    }
}

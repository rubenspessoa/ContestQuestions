#include <iostream>
#include <queue>
#include <stack>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

using namespace std;

priority_queue<string> answers;

void backtrack(string original, string transformed, stack<char> currentStack, string current = "", string currentStatus = "", int currentCharIndex = 0)
{
	D("Testing '" << current << "'" << " index = " << currentCharIndex);
	if(transformed.find(current) != 0)
	{
		D("Could not find " << current << " in the start of " << original);
		return;
	}
	else if(transformed.compare(current) == 0)
	{
		D("Pushing " << currentStatus);
		answers.push(currentStatus);
		return;
	}
	else if(currentCharIndex < transformed.length())
	{
		//INSERINDO
		currentStack.push(original[currentCharIndex]);
		backtrack(original, transformed, currentStack, current, currentStatus + "i", currentCharIndex + 1);
		currentStack.pop();
	}
	D("Chegou");
	//REMOVENDO
	if(!currentStack.empty())
	{

		char currentTop = currentStack.top();
		currentStack.pop();
		D("popping current = " << current);
		backtrack(original,transformed,currentStack, current + currentTop, currentStatus + "o",currentCharIndex);
	}
}

int main()
{
    string original;
    while(cin >> original)
    {
        string transformed;
        cin >> transformed;
        stack<char> currentStack;
        backtrack(original,transformed,	currentStack);
        stack<string> invertingAnswer;
		while(!answers.empty())
		{
			invertingAnswer.push(answers.top());
			answers.pop();
		}
        cout << "[" << endl;
		while(!invertingAnswer.empty())
		{
			string current = invertingAnswer.top();
			invertingAnswer.pop();
			REP(i,0,current.length())
			{
				if(i == current.length() - 1)
				{
					cout << current[i] << endl;
				}
				else
				{
					cout << current[i] << " ";
				}
			}
		}
        cout << "]" << endl;
    }
}

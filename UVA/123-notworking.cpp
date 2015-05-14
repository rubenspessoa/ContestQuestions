#include <iostream>
#include <map>
#include <list>
#include <queue>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;

#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!

using namespace std;

int order = 1;

class KWIC
{
public:
    string keyWord;
    string phrase;
    int order;
    int iKeyWord;

    int size()
    {
        return keyWord.size();
    }
    char operator[](int i)
    {
        return keyWord[i];
    }
};

class Compare
{
public:
    bool operator()(KWIC n1, KWIC n2)
    {
    	D("Cheking " << n1.keyWord << " with " << n2.keyWord)
    	if (n1.keyWord.compare(n2.keyWord) == 0)
		{
			if(n1.order != n2.order)
			{
				return (n1.order > n2.order);
			}
			else
			{
				return (n1.keyWord > n2.keyWord);
			}
		}
        bool smallestOne = false;
        int smallest = n1.size();
        if(n2.size() < smallest)
        {
            smallestOne = true;
            smallest = n1.size();
        }
        REP(i,0,smallest)
        {
            if (n1[i] != n2[i])
            {
                if(n1.keyWord[i] < n2.keyWord[i])
                {
//                	D(n1.keyWord << " < " << n2.keyWord);
                    return false;
                }
                else
                {
//                	D(n2.keyWord << " < " << n1.keyWord);
                    return true;
                }
            }
        }
        return smallestOne;
    }
};

typedef priority_queue<KWIC,vector<KWIC>,Compare> KWICpq;

KWICpq splitted;

string allLower(string n)
{
    REP(i,0,n.length())
    {
        n[i] = tolower(n[i]);
    }
    return n;
}

void split(string main,map<string,bool> ignored_words)
{
    int iLastCut = 0;
    KWIC current;
    current.keyWord = "";
    REP(i, 0, main.length() + 1)
    {
        if(main[i] != ' ' && main[i] != '\0')
        {
            current.keyWord += main[i];
        }
        else
        {
            if(!ignored_words[current.keyWord])
            {
                if (current.keyWord.length() > 0)
                {
                    string mainWithUpper = main;
                    REP(j,iLastCut,i)
                    {
                        mainWithUpper[j] = toupper(mainWithUpper[j]);
                    }
                    current.phrase = mainWithUpper;
                    current.order = order;
                    current.iKeyWord = iLastCut;
                    splitted.push(current);
                    iLastCut = i + 1;
                }

            }
            else
            {
                iLastCut = i + 1;
            }
            current.keyWord.clear();
        }
    }
    order++;
}

int main()
{
    map<string,bool> ignored_words;
    string current;
    getline(cin, current);
    while(current != "::")
    {
        current = allLower(current);
        D(current);
        ignored_words[current] = true;
        getline(cin, current);
    }
    while(getline(cin, current))
    {
        if(current == "acabou")
        {
            break;
        }
        split(allLower(current),ignored_words);
    }
    while(!splitted.empty())
    {
        cout << splitted.top().phrase << endl;
        splitted.pop();
    }
}

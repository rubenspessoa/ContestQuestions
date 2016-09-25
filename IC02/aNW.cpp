#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#define DEBUG 1
#define D(value) if (DEBUG) cout << value << endl;
#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

using namespace std;

vector<int> extract(string str) {
  vector<int> vec;
  string blank = " ";
  string aux = "";

  REP(i, 0, str.length()) {
    cout << "str.at(i) is of type: " << typeid(str.at(i)).name() << endl; 
  }
  
  return vec;
}

int main () {
  int SET;
  cin >> SET;
  getchar(); // enter

  while(SET--) {
    getchar(); // blank line

    string first;
    getline(cin, first);
    string second;
    getline(cin, second);
    cout << "str.at(i) is of type: " << typeid(first.at(0)).name() << endl; 

    //vector<int> firstVec = extract(first);
    getchar();
  }	
}


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

#define DEBUG 0
#define D(value) if (DEBUG) cout << value << endl;
#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

vi extract_int(string str) {
  vi vec;
  str += ' ';
  char blank = ' ';
  string aux = "";

  REP(i, 0, str.length()) {
    
    if (str[i] != blank) {
      aux += str[i];
    } else {
      if (aux == "") continue;
      vec.insert(vec.end(), stoi(aux));
      aux = "";
    }
  }

  return vec;
}

vs extract_float(string str) {
  vs vec;
  str += ' ';
  char blank = ' ';
  string aux = "";

  REP(i, 0, str.length()) {
    
    if (str[i] != blank) {
      aux += str[i];
    } else {
      if (aux == "") continue;
      vec.insert(vec.end(), aux);
      aux = "";
    }
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

    /*
    D("Entrada de first: ");
    D(first);
    D("Entrada de second: ");
    D(second);
    */

    vi firstVec = extract_int(first);
    vs secondVec = extract_float(second);

    D(firstVec.size());
    D(secondVec.size());

    // the following code is not efficient

    REP(i, 0, firstVec.size()) {
      REP (j, 0, firstVec.size()) {
        if (i + 1 == firstVec.at(j)) {
          cout << secondVec.at(j) << endl;
        }
      }
    }

    if(SET) {
      cout << endl;
    }
  }	
  return 0;
}
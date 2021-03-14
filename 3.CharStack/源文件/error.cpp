#include <iostream>
#include <string>
#include <cstdlib> //EXIT_FAILURE
using namespace std;
void error(string msg) {
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

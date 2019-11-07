#include <iostream>
#include <string.h>
#include "proj1.h"
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
  vector<int>v;
  int e;
  for (int i = 1; i < argc; i++) { //for loop looping through all cmd args
    if (strcmp(argv[i],"-e") == 0) { //checks for cmd arg "-e" then stores value in string e
      e = atoi(argv[i+1]);      
    } else if (strcmp(argv[i],"-v") == 0) { //checks for cmd arg "-v" then stores next 5 values in Array of chars
      for (int j = 0; j < 5; j++) { //for loop to store next 5 ints
	int input = atoi(argv[i+j+1]);
	v.push_back(input);
      }
    } //check for -e and -v first to use their stored values in arithmetic and binary methods later
  }
  for (int i = 1; i < argc; i++) { //for loop looping through all cmd args
    string str = argv[i];
    if (strcmp(argv[i],"-a") == 0) {  //checks for cmd arg "-a" for arithmetic method
      arithmetic(e,v);
    } else if (strcmp(argv[i],"-b") == 0) { //checks for cmd arg "-b" for binary method
      binary(e,v);
    }
  }
}

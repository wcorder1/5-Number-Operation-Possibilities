#include <iostream>
#include "proj1.h"
#include <vector>

using namespace std;

//all needed arithmetic operators
int add(int a, int b) { return a + b; }
int subtr(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divid(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

//all needed bitwise operators
int ls(int a, int b) { return a << b; }
int rs(int a, int b) { return a >> b; }
int aand(int a, int b) { return a & b; }
int oor(int a, int b) { return a | b; }
int exor(int a, int b) { return a ^ b; }

/*Implements integer x as a counter to start with to be used later. Loops through an 
array of functions (on for loops 2,4,6,8) using pointers and a vector of operands 
(on for loops 1,3,5,7,9) taken from the command line. Then uses an if statement to 
check operands for repititon and eliminate those without. Then checks actual
equation of operands and operators for equality to integer 'e' taken from the command
line and outputs the equations that read true. Finally uses the x counter to tally the
number of true statements and print that at the end.*/

void binary(int e, vector<int> v) {  
  int x = 0;
  typedef int (*pnt)(int,int);
  pnt op[] = {aand,oor,exor,ls,rs};
  vector<string> opu  = {"&","|","^","<<",">>"};
  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      for (int k=0; k<5; k++) {
	for (int l=0; l<5; l++) {
	  for (int m=0; m<5; m++) {
	    for (int n=0; n<5; n++) {
	      for (int o=0; o<5; o++) {
		for (int p=0; p<5; p++) {
		  for (int q=0; q<5; q++) {
		    if((i!=k) && (i!=m) && (i!=o) && (i!=q) && (k!=m) && (k!=o) && (k!=q) && (m!=o) && (m!=q) && (o!=q)) {
                      if ((op[p](op[n](op[l](op[j](v[i],v[k]),v[m]),v[o]),v[q])) == e) {
                        x++; 
                        cout << "(((" << v[i] << opu[j] << v[k] << ")" << opu[l]  << v[m]
                             << ")" << opu[n] << v[o] << ")" << opu[p] << v[q] << endl;
                      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  cout << x << " bitwise expressions found that evaluate to " << e << endl; 
}

//arithmetic function is exact same as bitwise function except it uses arithmetic operators
void arithmetic(int e, vector<int> v) {
  int x = 0;
  typedef int (*pnt)(int,int);
  pnt op[] = {add,subtr,mult,divid,mod};
  vector<string> opu  = {"+","-","*","/","%"};
  for (int i=0; i<5; i++) { 
    for (int j=0; j<5; j++) { 
      for (int k=0; k<5; k++) {
	for (int l=0; l<5; l++) {
	  for (int m=0; m<5; m++) {
	    for (int n=0; n<5; n++) {
	      for (int o=0; o<5; o++) {
		for (int p=0; p<5; p++) {
		  for (int q=0; q<5; q++) {
		    if((i!=k) && (i!=m) && (i!=o) && (i!=q) && (k!=m) && (k!=o) && (k!=q) && (m!=o) && (m!=q) && (o!=q)) {
		      if ((op[p](op[n](op[l](op[j](v[i],v[k]),v[m]),v[o]),v[q])) == e) {
                        x++;
                        cout << "(((" << v[i] << opu[j] << v[k] << ")" << opu[l]  << v[m]
                             << ")" << opu[n] << v[o] << ")" << opu[p] << v[q] << endl;
                      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  cout << x << " arithmetic expressions found that evaluate to " << e << endl;
}

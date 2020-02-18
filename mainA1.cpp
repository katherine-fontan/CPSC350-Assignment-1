#include <iostream>
#include <fstream>
#include "FileAnalysis.h"


using namespace std;

//functions

int main (int argc, char **argv){

  /*
  The program will accept as a command line argument
  the name of a text file that will contain an arbitrary list of DNA strings.
  (ie. ~/assign1/filename.txt) DNA strings consist of a sequence of nucleotides
  (A,C,T, or G). There will be 1 string per line of the file.
  No guarantees on capitalization.*/

  //getting input from command line argument
    //check command line argument
    if(argc < 2){
      cout<< "invalid command line parameters" <<endl;
      return 1;
    }


    //getting file name from command line argument
    string fName = argv[1];//file name from command line

    FileAnalysis  *analysis = new FileAnalysis(fName);

    cout<< "printing analysis: "<< endl;
    cout<< analysis -> extractInfo(fName);




    delete analysis;
    return 0;
}

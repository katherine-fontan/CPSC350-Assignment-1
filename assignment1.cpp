#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char **argv){

//getting input from command line argument
  //check command line argument
  if(argc < 2){
    cout<< "invalid command line parameters" <<endl;
    return 1;
  }
  ifstream inFS;  // Input file stream
  string fileInfo; //file information

  //getting file name from command line argument
  string fName = argv[1];//file name from command line

  // Try to open file
   cout << "Opening file "<< fName << endl;

  inFS.open(fName);

  //check if file exist
  if (!inFS.is_open()) {
    cout << "Could not open file " << fName << endl;
    return 1; //error
  }

  //reading from a file
  while(!inFS.eof()){
    inFS >> fileInfo;
    if(!inFS.fail()){
      cout << "string ->    "<< fileInfo <<endl;
    }
  }
	inFS.close();




  //first work on reading from a file
  //then work on counting DNA string
  //then probability



  //math library in c++
  //D represents the length of the string and generate that 1000x?
  //D floating point




  return 0;
}

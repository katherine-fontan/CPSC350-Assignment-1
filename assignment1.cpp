#include <iostream>
#include <fstream>
using namespace std;

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

  int count = 0;


  //while loop to read from a file
  while(!inFS.eof()){

    inFS >> fileInfo;

    if(!inFS.fail()){
      //for loop to get each char of the file count how many strings there are in the file
      for(int i = 0; i < fileInfo.size(); ++i)
      {
        char strInput = toupper(fileInfo[i]); //toupper function to account for lower and upper case letters
        cout<< strInput<<endl;
        count++; //add each time to count
      }
    }

  }

  cout<<count<<endl; // check if count is correct
	inFS.close(); //close input file stream



  //math stuff idk how to do YET
  /*
  MATH/STATS THINGS TO COMPUTE
  The program will then compute the sum, mean, variance,
  and standard deviation of the length of the DNA strings in the list.
  It will also compute the relative probability of each nucleotide (A,C,T, or G),
   as well as the probability of each nucleotide bigram
   (AA, AC, AT, AG, CA, CC, CT, CG, etc) across the entire collection.*/

  //then work on counting DNA string
  //then probability



  //math library in c++
  //D represents the length of the string and generate that 1000x?
  //D floating point


/* FILE OUTPUT
The program will output the labeled results to a file called yourname.out.
At the top of the file, output your name, student id, etc.
After printing the summary statistics to yourname.out
Append the 1000 strings to the end of yourname.out.*/

ofstream outputFile; //object created **fout**
outputFile.open("katherinefontan.txt");

if (!outputFile.is_open()) {
  cout << "Could not open file myoutfile.txt." << endl;
  return 1;

}
else{
  outputFile<<"Katherine Fontan \n2290561\nluzfonta@chapman.edu\nCPSC350-Assignment 1\n\n" <<endl; //contents to be written at the top of the file
}
outputFile<< "Summary\n"<<endl; //append to the file

outputFile.close();

  return 0;
}

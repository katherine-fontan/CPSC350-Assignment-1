#include <iostream>
#include <fstream>


using namespace std;

//functions
void fileAnalysis(string fName);


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
  string userChoice = "y";

while(userChoice == "y")
{



    //calculate stuff
    //reprompt
    cout << "another file?";
    cin>> userChoice;

    if(userChoice == "y")
    {
      cout<< "what is the file name" <<endl;
      cin >> fName;
    }





}
  // Try to open file
  cout << "Opening file "<< fName << endl;

  inFS.open(fName);

  //check if file exist
  if (!inFS.is_open()) {
    cout << "Could not open file " << fName << endl;
    return 1; //error
  }


  int sum = 0; //keep track of how many characters in the file
  float lineCount = 0.0; //keep track of how many lines
  float mean = 0.0; // initialize mean variable
  float variance = 0.0;
  string sequence = "";

  //while loop to read from a file
  while(!inFS.eof()){

    inFS >> fileInfo;

    if(!inFS.fail()){
      //for loop to get each char of the file count how many strings there are in the file
      int lineSize = fileInfo.size();

      sequence += fileInfo; //probability thing
      sequence += ".";


      cout << "string ->    "<< fileInfo <<endl; //check if everything it being read in properly.
      lineCount++;

      sum += lineSize; //to calculate sum


      //sumIndividualLine += lineSize * lineSize; //to calculate variance

      /*for(int i = 0; i < lineSize; ++i)
      {
        char strInput = toupper(fileInfo[i]); //toupper function to account for lower and upper case letters
        cout << strInput <<endl;
        //count++; //add each time to count
      }*/


    }


  }

  cout<< "sum: "<< sum << endl; // check if count is correct
  cout<< "line count: "<< lineCount << endl;

  mean = sum/lineCount;
  cout<< "mean is: "<< mean << endl;

  int currentLength =0;
  float sumVariance = 0.0;
  for (int i = 0; i < sequence.size(); i++) {
    currentLength++;

    if (sequence[i] == '.'){
      currentLength--;
      sumVariance += ((currentLength - mean) * (currentLength - mean));
      currentLength = 0;

    }

  }

  variance = sumVariance/lineCount;
  //(sumIndividualLine/lineCount) - (2 * mean)  +  (mean * mean); //doesn't work.
  cout << "variance is: " << variance<<endl;
	inFS.close(); //close input file stream

  //cout << sequence << endl;
  //then work on counting DNA string
  //then probability



  //math library in c++
  //D represents the length of the string and generate that 1000x?
  //D floating point


  //math stuff idk how to do YET
  /*
  MATH/STATS THINGS TO COMPUTE
  The program will then compute the sum, mean, variance,
  and standard deviation of the length of the DNA strings in the list.
  It will also compute the relative probability of each nucleotide (A,C,T, or G),
   as well as the probability of each nucleotide bigram
   (AA, AC, AT, AG, CA, CC, CT, CG, etc) across the entire collection.*/

//SUM
//MEAN
  //line count (lc)
  //+ sum
  //sum/ lc
//VARIANCE



//STANDARD DEVIATION



//RELATIVE PROBABILITY OF NUCLEOTIDE



//PROBABILITY OF NUCLEOTIDE BIGRAM





//GENERATE 1000 DNA STRINGS whose lengths follow a Gaussian distribution
//RELATIVE FREQUENCY OF NUCLEOTIDE


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


void fileAnalysis(string fName){

}

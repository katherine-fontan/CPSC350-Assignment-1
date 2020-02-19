#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>


using namespace std;

/*
The program will accept as a command line argument
the name of a text file that will contain an arbitrary list of DNA strings.
(ie. ~/assign1/filename.txt) DNA strings consist of a sequence of nucleotides
(A,C,T, or G). There will be 1 string per line of the file.
No guarantees on capitalization.*/

//ofstream outputFile; //object created **fout**
//functtion
int fileAnalysis(string fName);
//int writeOuput (int sum, float mean, float variance);
int generatorDNA(float variance, float stdDev);

int main (int argc, char **argv){

//getting input from command line argument
  //check command line argument
  if(argc < 2){
    cout<< "Invalid command line parameters" <<endl;
    return 1;
  }

  //getting file name from command line argument
  string fName = argv[1];//file name from command line

  //analyze the file for the first time
  fileAnalysis(fName);

  string userChoice = "y"; //initialize a variable for user choice if they want to anayze another file or not


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
    outputFile<< "Summary\n"<<endl; //append to the file
  }



while(userChoice == "y")
{

    cout << "another file?";
    cin>> userChoice;

    if(userChoice == "y"){
      cout<< "what is the file name" <<endl;
      cin >> fName;

      fileAnalysis(fName);//call to function to read in the file and analyze it in order to do the necessary calculatios
      //writeOuput();
    }

}


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

  return 0;
}


int fileAnalysis(string fName){
  ifstream inFS;  // Input file stream
  string fileInfo; //file information

  // Try to open file
  cout << "Opening file "<< fName << endl;

  inFS.open(fName);

  //check if file exist
  if (!inFS.is_open()) {
    cout << "Could not open file " << fName << endl;
    return 1; //error
  }

  int countA = 0;//keep track of how many times each nucleotide appears
  int bigramAA = 0;
  int bigramAT = 0;
  int bigramAC = 0;
  int bigramAG = 0;


  float relProbabilityA = 0.0;
  float probBigramAA = 0.0;
  float probBigramAC = 0.0;
  float probBigramAT = 0.0;
  float probBigramAG = 0.0;

  int countT = 0;
  float relProbabilityT = 0.0;

  int countC = 0;
  float relProbabilityC = 0.0;

  int countG = 0;
  float relProbabilityG = 0.0;

  int sum = 0; //keep track of how many characters in the file

  float lineCount = 0.0; //keep track of how many lines
  float mean = 0.0; // initialize mean variable
  float variance = 0.0;
  float stdDev = 0.0;
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
    }
  }

  cout<< "sum: "<< sum << endl; // check if count is correct
  cout<< "line count: "<< lineCount << endl;

  mean = sum/lineCount;
  cout<< "mean is: "<< mean << endl;

  int currentLength = 0;
  float sumVarianceNumerator = 0.0;

  int bigramCount = 1;
  for (int i = 0; i < sequence.size(); i++) {
    currentLength++;
    char nucleotides = toupper(sequence[i]); //to account for upper and lower capitalization


    if(nucleotides == 'A'){
      countA++; //increase count of A in order to calculate probability

      //attempt to do probability bigram
      if(sequence[i + bigramCount] == 'A' || sequence[i + bigramCount] == 'a')
        bigramAA++;
      else if(sequence[i + bigramCount] == 'C' || sequence[i + bigramCount] == 'c')
        bigramAC++;
      else if(sequence[i + bigramCount]== 'G' || sequence[i + bigramCount] == 'g')
        bigramAG++;
      else if(sequence[i + bigramCount] == 'T' || sequence[i + bigramCount] == 't')
        bigramAT++;


    }
    else if(nucleotides == 'T')
      countT++;//to calculate probability
    else if(nucleotides == 'C')
      countC++;//to calculate probability
    else if (nucleotides == 'G')
      countG++; //to calculate probability

    if (sequence[i] == '.'){
      currentLength--; // decrease by 1 so it doesnt count .
      sumVarianceNumerator += ((currentLength - mean) * (currentLength - mean)); //calculates the numerator of variance calculation

      currentLength = 0; //resets current lenth because it is to keep track of length of each line, and once there is a new ine, we can reset it
    }
    bigramCount ++;
  }

  variance = sumVarianceNumerator / lineCount; //calculating variance
  cout << "variance is: " << variance<<endl;

  stdDev = sqrt(variance); //std dev is the sqrt of variance

  cout << "Standard deviaton is: " << stdDev <<endl;

  //writeOuput(sum, mean, variance);

  //calculating relative probability of each nucleotide

  relProbabilityA = countA / (float) sum;
  relProbabilityC = countC / (float) sum;
  relProbabilityG = countG / (float) sum;
  relProbabilityT = countT / (float) sum;

  cout << "rel. prob of A is "<< relProbabilityA<<endl;
  cout<< "rel. prob of T is "<< relProbabilityT <<endl;
  cout << "rel. prob of C is "<< relProbabilityC <<endl;
  cout << "rel. prob of G is "<< relProbabilityG <<endl;

  //calculating relative probability of each nucleotide bigram

  probBigramAA = bigramAA / (sum / 2.0);
  probBigramAC = bigramAC / (sum / 2.0);
  probBigramAT = bigramAT / (sum / 2.0);
  probBigramAG = bigramAG / (sum / 2.0);

  cout << "Here is the relative probability of each nucleotide bigram: " << endl;
  cout << "AA:          "<< probBigramAA <<endl;
  cout << "AC:          "<< probBigramAC <<endl;
  cout << "AT:          "<< probBigramAT <<endl;
  cout << "AG:          "<< probBigramAG <<endl;



  inFS.close(); //close input file stream

  return 0;
}


/*
int writeOuput(int sum, float mean, float variance){

  outputFile.open("katherinefontan.txt");


  outputFile << "The Sum of the length of the DNA strings is "<< sum << endl;
  outputFile << "The Mean of the length of the DNA strings is " << mean << endl;
  outputFile << "The variance of the length of the DNA strings is " << variance << endl;


  outputFile.close();


  return 0;
}
*/

int generatorDNA(float variance, float stdDev){


}

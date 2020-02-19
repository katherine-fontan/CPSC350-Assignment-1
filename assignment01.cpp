/*
Katherine Fontan
2290561
luzfonta@chapman.edu
CPSC350-02
Assignment 1 - DNA sequence
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;


//functions
double meanCalculation(int sum, int lineCount);
double variance (string sequence, double mean, int lineCount);
double standardDeviation(double variance);
string DNAgenerator(double mean, double stdDEv, double relProbabilityA, double relProbabilityC, double relProbabilityT, double relProbabilityG);


int main(int argc, char **argv){

  //check command line argument
  if(argc < 2){
    cout<< "Invalid command line parameters" <<endl;
    return 1;
  }
  string userChoice = "y"; //initialize a variable for user choice if they want to anayze another file or not

  //getting file name from command line argument
  string fName = argv[1];//file name from command line

  ofstream outputFile; //object created **fout**
  outputFile.open("katherinefontan.txt");
  outputFile<<"Katherine Fontan \n2290561\nluzfonta@chapman.edu\nCPSC350-Assignment 1" <<endl; //contents to be written at the top of the file


  while(userChoice == "y")
  {
      string fileName = fName; //reasign file name to another variable to be able to ask for new files.
      ifstream inFS;  // Input file stream
      string fileInfo; //file information

      // Try to open file
      cout << "Opening file "<< fName << endl;

      inFS.open(fName);

      int sum = 0; //keep track of how many characters in the file
      double lineCount = 0.0; //keep track of how many lines
      double mean = 0.0; // initialize mean variable
      string sequence = ""; //string to get

      //check if file exist
      if (!inFS.is_open()) {
        cout << "Could not open file " << fName << endl;
        return 1; //error
      }

      //while loop to read the file and get DNA sequence;
      while(!inFS.eof()){

        inFS >> fileInfo;

        if(!inFS.fail()){
          //for loop to get each char of the file count how many strings there are in the file
          int lineLength = fileInfo.size();

          sequence += fileInfo; //probability thing
          sequence += " ";

          cout << "string ->    "<< fileInfo <<endl; //check if everything it being read in properly.
          lineCount++; //keep track of the number of lines in the file

          sum += lineLength; //to calculate sum of the legth of each line
        }
      }


      outputFile<< "\nSummary statistics from file " << fName << ":\n"<<endl; //append to the file
      //output sum, mean, variance and std
      outputFile << "The Sum of the length of the DNA strings is " << sum << endl;

      double theMean = meanCalculation(sum, lineCount);
      double theVariance = variance (sequence, theMean, lineCount);
      double theStdDev = standardDeviation(theVariance);

      outputFile << "The Mean of the length of the DNA strings is "<< theMean <<endl;
      outputFile <<  "The Variance of the length of the DNA strings is "<< theVariance <<endl;
      outputFile <<  "The Standard Deviation of the length of the DNA strings is "<< theStdDev <<endl;

      //RELATIVE PROBABILITY OF EACH NUCLEOTIDE
      int countA = 0;//keep track of how many times each nucleotide appears
      int countT = 0;
      int countC = 0;
      int countG = 0;

      //initialize rel. prob variables
      double relProbabilityT = 0.0;
      double relProbabilityC = 0.0;
      double relProbabilityG = 0.0;
      double relProbabilityA = 0.0;

      //for loop to go through the DNA sequence to calculate rel. prob
      for (int i = 0; i < sequence.size(); i++) {
        char nucleotides = toupper(sequence[i]); //to account for upper and lower capitalization

        if(nucleotides == 'A')
          countA++; //increase count of A in order to calculate probability
        else if(nucleotides == 'T')
          countT++;//to calculate probability
        else if(nucleotides == 'C')
          countC++;//to calculate probability
        else if (nucleotides == 'G')
          countG++; //to calculate probability
      }


      relProbabilityA = countA / (double) sum;
      relProbabilityC = countC / (double) sum;
      relProbabilityG = countG / (double) sum;
      relProbabilityT = countT / (double) sum;

      outputFile << "\nHere is the relative probability of each nucleotide:" << endl;
      outputFile << "A:           " << relProbabilityA << endl;
      outputFile << "C:           " << relProbabilityC << endl;
      outputFile << "T:           " << relProbabilityT << endl;
      outputFile << "G:           " << relProbabilityG << endl;

      //variable initialization
      int countAA = 0;
      int countAC = 0;
      int countAT = 0;
      int countAG = 0;

      //probability of each bigram
      for (int i = 0; i < sequence.size(); i += 2) {
        char nucleotides = toupper(sequence[i]); //to account for upper and lower capitalization


        if(nucleotides == 'A'){
          if(sequence[i + 1] == 'A')
            countAA++;
          else if(sequence[i + 1] == 'C')
            countAC++;
          else if(sequence[i + 1] == 'T')
            countAT++;
          else if(sequence[i + 1] == 'G')
            countAG++;

        }

        else if(nucleotides == 'T')
          countT++;//to calculate probability
        else if(nucleotides == 'C')
          countC++;//to calculate probability
        else if (nucleotides == 'G')
          countG++; //to calculate probability
      }

      //calculates probability of bigrams
      double probAA = countAA / (sum / 2.0);
      double probAC = countAC / (sum / 2.0);
      double probAT = countAT / (sum / 2.0);
      double probAG = countAG / (sum / 2.0);

      cout << "prob of AA " << probAA << endl;
      cout << "prob of AC " << probAC << endl;
      cout << "prob of AT " << probAT << endl;
      cout << "prob of AG " << probAG << endl;



      //generate 1000 DNA strings whose lengths follow a Gaussian distribution with the same mean and variance calculated
      string randomDNA = DNAgenerator(theMean, theStdDev, relProbabilityA, relProbabilityC, relProbabilityT, relProbabilityG);


      //ask the user if they want to analyze another file
      cout << "\nWant to analyze another file? ";
      cin>> userChoice;

      if(userChoice == "y"){
        cout<< "What is the file name? ";
        cin >> fName;
      }
  }
  return 0;
}


double meanCalculation(int sum, int lineCount){

  double mean = sum / (double) lineCount;

  return mean;
}

double variance (string sequence, double mean, int lineCount){

  double variance = 0.0;
  int currentLength = 0;
  double sumVarianceNumerator = 0.0;

  for (int i = 0; i < sequence.size(); i++) {

    currentLength++;

    char nucleotides = toupper(sequence[i]); //to account for upper and lower capitalization
    if (sequence[i] == ' '){
      currentLength--; // decrease by 1 so the ' ' doesnt count

      sumVarianceNumerator += ((currentLength - mean) * (currentLength - mean)); //calculates the numerator of variance calculation

      currentLength = 0; //resets current lenth because it is to keep track of length of each line, and once there is a new ine, we can reset it
    }
  }

  variance = sumVarianceNumerator / lineCount; //calculating variance

  return variance;
}
double standardDeviation (double variance){

  double stdDev = sqrt(variance); //std dev is the sqrt of variance

  return stdDev;
}


string DNAgenerator(double mean, double stdDEv, double relProbabilityA, double relProbabilityC, double relProbabilityT, double relProbabilityG){
  string dna = "";
  //generated two random numbers
  int a = ((double) rand() /(RAND_MAX));
  int b = ((double) rand() /(RAND_MAX));

  //calculat C and D
  double C = sqrt(-2 * log (a)) * cos(2 * M_PI * b);
  double D = stdDEv* C + mean;


  return dna;
}

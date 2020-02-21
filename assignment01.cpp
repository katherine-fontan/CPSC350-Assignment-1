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
double probabilityBigram(int count, int sum);

int main(int argc, char **argv){

  //check command line argument
  if(argc < 2){
    cout<< "Invalid command line parameters!" <<endl;
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
      ifstream inputFile;  // Input file stream
      string fileInfo; //file information

      // Try to open file
      cout << "Opening file: "<< fName << endl;

      inputFile.open(fName);

      int sum = 0; //keep track of how many characters in the file
      double lineCount = 0.0; //keep track of how many lines
      double mean = 0.0; // initialize mean variable
      string sequence = ""; //string to get
      string dna = "";

      //check if file exist
      if (!inputFile.is_open()) {
        cout << "Could not open file " << fName << endl;
        return 1; //error
      }

      //while loop to read the file and get DNA sequence;
      while(!inputFile.eof()){

        inputFile >> fileInfo;

        if(!inputFile.fail()){
          //for loop to get each char of the file count how many strings there are in the file
          int lineLength = fileInfo.size();

          sequence += fileInfo; //probability thing
          sequence += " ";

          dna += fileInfo;

          lineCount++; //keep track of the number of lines in the file

          sum += lineLength; //to calculate sum of the legth of each line
        }
      }
      inputFile.close();
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

      outputFile << "\nHere is the relative probability of each nucleotide: \n" << endl;
      outputFile << "A:           " << relProbabilityA << endl;
      outputFile << "C:           " << relProbabilityC << endl;
      outputFile << "T:           " << relProbabilityT << endl;
      outputFile << "G:           " << relProbabilityG << endl;

      //variable initialization
      int countAA = 0;
      int countAC = 0;
      int countAT = 0;
      int countAG = 0;

      int countCA = 0;
      int countCC = 0;
      int countCT = 0;
      int countCG = 0;

      int countTA = 0;
      int countTC = 0;
      int countTT = 0;
      int countTG = 0;

      int countGA = 0;
      int countGC = 0;
      int countGT = 0;
      int countGG = 0;

      //probability of each bigram
      for (int i = 0; i < dna.size(); i += 2) { // += two so i is every other i is analyzed
        char nucleotides = toupper(dna[i]); //to account for upper and lower capitalization


        if(nucleotides == 'A'){
          if(dna[i + 1] == 'A')
            countAA++; // increase count for AA bigram...
          else if(dna[i + 1] == 'C')
            countAC++;
          else if(dna[i + 1] == 'T')
            countAT++;
          else if(dna[i + 1] == 'G')
            countAG++;
        }

        else if(nucleotides == 'C'){
          if(dna[i + 1] == 'A')
            countCA++;
          else if(dna[i + 1] == 'C')
            countCC++;
          else if(dna[i + 1] == 'T')
            countCT++;
          else if(dna[i + 1] == 'G')
            countCG++;
        }

        else if(nucleotides == 'T'){
          if(dna[i + 1] == 'A')
            countTA++;
          else if(dna[i + 1] == 'C')
            countTC++;
          else if(dna[i + 1] == 'T')
            countTT++;
          else if(dna[i + 1] == 'G')
            countTG++;

        }

        else if (nucleotides == 'G'){
          if(dna[i + 1] == 'A')
            countGA++;
          else if(dna[i + 1] == 'C')
            countGC++;
          else if(dna[i + 1] == 'T')
            countGT++;
          else if(dna[i + 1] == 'G')
            countGG++;
        }
      }

      //calculates probability of bigrams
      double probAA = probabilityBigram(countAA,sum);
      double probAC = probabilityBigram(countAC,sum);
      double probAT = probabilityBigram(countAT,sum);
      double probAG = probabilityBigram(countAG,sum);

      //outputs results to file
      outputFile << "\nHere is the relative probability of each nucleotide bigram: \n" << endl;
      outputFile << "AA:          " << probAA << endl;
      outputFile << "AC:          " << probAC << endl;
      outputFile << "AT:          " << probAT << endl;
      outputFile << "AG:          " << probAG << endl;

      double probCA = probabilityBigram(countCA, sum);
      double probCC = probabilityBigram(countCC, sum);
      double probCT = probabilityBigram(countCT, sum);
      double probCG = probabilityBigram(countCG, sum);

      outputFile << "CA:          " << probCA << endl;
      outputFile << "CC:          " << probCC << endl;
      outputFile << "CT:          " << probCT << endl;
      outputFile << "CG:          " << probCG << endl;

      double probTA = probabilityBigram(countTA, sum);
      double probTC = probabilityBigram(countTC, sum);
      double probTT = probabilityBigram(countTT, sum);
      double probTG = probabilityBigram(countTG, sum);

      outputFile << "TA:          " << probTA << endl;
      outputFile << "TC:          " << probTC << endl;
      outputFile << "TT:          " << probTT << endl;
      outputFile << "TG:          " << probTG << endl;

      double probGA = probabilityBigram(countGA, sum);
      double probGC = probabilityBigram(countGC, sum);
      double probGT = probabilityBigram(countGT, sum);
      double probGG = probabilityBigram(countGG, sum);

      outputFile << "GA:          " << probGA << endl;
      outputFile << "GC:          " << probGC << endl;
      outputFile << "GT:          " << probGT << endl;
      outputFile << "GG:          " << probGG << endl;


      //generate 1000 DNA strings whose lengths follow a Gaussian distribution with the same mean and variance calculated
      string randomDNA = DNAgenerator(theMean, theStdDev, relProbabilityA, relProbabilityC, relProbabilityT, relProbabilityG);

      outputFile << "\n\nDNA Generated following a Gaussian distribution: \n"<<endl;
      //output them into the file yourname.txt
      outputFile << randomDNA;


      //ask the user if they want to analyze another file
      cout << "\nWant to analyze another file (y or n)? ";
      cin>> userChoice;

      if(userChoice == "y"){
        cout<< "What is the file name? ";
        cin >> fName;
    }
  }
  cout << "bye then!\n" <<endl;
  outputFile.close();
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

double probabilityBigram(int count, int sum){

  double bigramProb = count / (sum / 2.0);

  return bigramProb;
}

string DNAgenerator(double mean, double stdDEv, double relProbabilityA, double relProbabilityC, double relProbabilityT, double relProbabilityG){
  string dna = "";

  int count = 0;

  while(count < 1000)
  {
    //append to the dna string
    //use stats of each nucleotide

    //generate two random numbers
    double a = ((double) rand() /(RAND_MAX +1.0));
    double b = ((double) rand() /(RAND_MAX +1.0));

    //use C and D formulas
    double C = (sqrt( -2* log(a))) * (cos(2 * M_PI * b));
    double D = (stdDEv * C) + mean; //line lengths


    for(int i = 0; i < D; ++i){

      double randProb = rand()/(RAND_MAX + 1.0);

      if(randProb <= relProbabilityA)
        dna += 'A';
      else if(relProbabilityA < randProb && randProb <= (relProbabilityG + relProbabilityA))
        dna += 'G';
      else if((relProbabilityG + relProbabilityA) < randProb && randProb <= (relProbabilityA + relProbabilityG + relProbabilityC))
        dna += 'C';
      else if ((relProbabilityA + relProbabilityG + relProbabilityC) < randProb && randProb <= 1)
        dna += 'T';

    }

    dna += "\n";
    count++;

  }

  return dna;
}

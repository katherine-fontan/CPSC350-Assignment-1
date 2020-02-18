#include <iostream>
#include <fstream>
using namespace std;

class FileAnalysis
{
  public:
    FileAnalysis();
    FileAnalysis(string fileName);

    string extractInfo(string fileName);
    /*
    this function will:
    compute the sum, mean, variance,
    and standard deviation of the length of the DNA strings in the list.
    It will also compute the relative probability of each nucleotide (A,C,T, or G),
     as well as the probability of each nucleotide bigram
     (AA, AC, AT, AG, CA, CC, CT, CG, etc) across the entire collection.*/

    //accessors and mutators
    string getFileName();
    void setFileName(string fileName);


    string fileInfo;
    //file info is the string of each line content in the file that is going to be read in

    int count; //keep track of how many characters in the file
    //is the variabel to keep track of the total characters in the file
    //it will help compute mean as well

    float lineCount; //keep track of how many lines
    //need this informaton to calculate mean and VARIANCE

    int sumIndividualLine;//sum of individual lines
    //need this to calculate variance (sum of each individual line in the file aka total number of characters in each line)

    int lineSize;
    //is the size of each line you get by using the .size() operator

    float mean; // initialize mean variable

    float variance;

  private:
    string fName;


};

#include "FileAnalysis.h"
#include <fstream>

FileAnalysis:: FileAnalysis()
{
  fName = ""; 
}

FileAnalysis:: FileAnalysis(string fileName)
{
  fName = fileName;
}

string FileAnalysis:: getFileName(){
  return fName;
}
void FileAnalysis:: setFileName(string fileName){
  fName = fileName;
}


string FileAnalysis:: extractInfo(string fileName)
{
  ifstream inFS;
  fileInfo;
  inFS.open(fileName);
  count = 0; //keep track of how many characters in the file
  lineCount = 0.0; //keep track of how many lines
  sumIndividualLine = 0;//sum of individual lines
  mean = 0.0;
  variance = 0.0;

  //while loop to read from a file
  while(!inFS.eof()){

    inFS >> fileInfo;

    if(!inFS.fail()){
      //for loop to get each char of the file count how many strings there are in the file
      int lineSize = fileInfo.size();

      cout << "string ->    "<< fileInfo <<endl; //check if everything it being read in properly.
      lineCount++;

      count += lineSize; //to calculate sum
      sumIndividualLine += lineSize * lineSize; //to calculate variance

      for(int i = 0; i < lineSize; ++i)
      {
        char strInput = toupper(fileInfo[i]); //toupper function to account for lower and upper case letters
        cout << strInput <<endl;
        //count++; //add each time to count
      }
    }

  }
  cout<< "Sum: "<<count<<endl; // check if count is correct
  cout<< "line count: "<<lineCount<< endl;
  cout << "individual line: "<< sumIndividualLine <<endl;

  mean = count/lineCount;
  cout<< "mean is: "<< mean << endl;

  variance = (sumIndividualLine/lineCount) - (2 * mean)  +  (mean * mean); //doesn't work.
  cout << "variance is: "<<variance<<endl;


	inFS.close(); //close input file stream
  return "";
}

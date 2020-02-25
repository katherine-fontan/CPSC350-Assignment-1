
CPSC350-Assignment-1

Katherine Fontan
2290561
luzfonta@chapman.edu
CPSC350-02


Source files:
Assignment01.cpp
README.txt

If you input a file that doesn't only contain ACTG (contains other letters), that letter will not be counted towards the probability of each nucleotide nor the probability of each nucleotide bigram, as it accounts for that with an else statement in the for loops. However, it is accounted for on the sum of the length, mean, standard deviation and variance, as those are based on the length of each line and the total length of the file.
To run the program:

g++ Assignment01.cpp filename

References:

Zybooks chapter on streams and rand()
- for pi, cos, log and sqrt: https://www.quantstart.com/articles/Mathematical-Constants-in-C/
Tutoring center: helped with variance, and DNA generator


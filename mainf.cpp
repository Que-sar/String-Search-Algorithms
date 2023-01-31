#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include "algorithms.h"

//small AUG, medium UGAUAG, long UGAUAGUAA, worst case UUUUUUUUU

using namespace std;

int main(){

    // running this "executable_file", will fill test.txt up, with microsecond values, for comparison, poll building
    // faster.sh on the other hand works with flags in the command line
    // faster.sh (size of string to create) (mainf.cpp to compile) (kmp.cpp to compile) (bmh.cpp to compile) (amount of times to run the executable for testing)
    //  eg.: ./faster.sh 1000000 mainf.cpp kmp.cpp bmh.cpp 500
    //  create a string of 1 million length, compile c++ files, run it 500 times for research
    // used Linux for the project

    string pattern = "AUG";
    string text;
    ifstream readMe("tryme.txt");

    getline (readMe, text);
        
    KMPalgorithm first;
    auto kmpstart = chrono::steady_clock::now();
    vector<int> res1 = first.KMP(pattern, text);//O(N+M)
    auto kmpend = chrono::steady_clock::now();
    auto kemp = chrono::duration_cast<chrono::microseconds>(kmpend - kmpstart).count();

    //cout << kemp << endl;

    BoMoHoalgorithm second;
    auto bmhstart = chrono::steady_clock::now();
    vector<int> res2 = second.BoMoHo(pattern, text);//O(NM)
    auto bmhend = chrono::steady_clock::now();

    auto bemh = chrono::duration_cast<chrono::microseconds>(bmhend - bmhstart).count();
    

    std::ofstream outfile;

    outfile.open("test.txt", std::ios_base::app); // append instead of overwrite
    outfile << kemp << " " << bemh << ","; 

    
    

    return 0;
}




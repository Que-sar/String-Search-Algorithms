#include <iostream>
#include <string>
#include <vector>
#include "algorithms.h"
using namespace std;

// Create Longest Prefix Suffix table
// Prepocess stage
// Takes O(N) space, N is the length of the pattern
// Takes O(N) time complexity as well

vector<int> KMPalgorithm::lps(string pattern){


    int lengthOfPat = pattern.length();
    int rang = 0; // start value
    int i = 1; // next value after start(at first)

    vector<int> largestPrefSufx(lengthOfPat);
    largestPrefSufx[0] = 0; // first is always 0(nothing to compare it to)

    while (lengthOfPat > i) // while the value that goes through reaches the end
    {

        if (pattern[i] == pattern[rang]) // if values match
        {

            rang++;
            largestPrefSufx[i] = rang; // index of "start value" + 1 to the correct place
            i++; // increase matched indexes of values

        }

        else{

            if (rang == 0) // not a match, and we already had put start value to beginning
            {

                largestPrefSufx[i] = 0;
                i++; // make sure table index is 0(no match), increase above value

            }

            else{

                rang = largestPrefSufx[rang-1]; // if not zero(length of prefix), we go back to previous prefix of the same char

            }   

        }  

    }

    return largestPrefSufx; // return LPS table

}

// Linear Complexity
// Its worst case is O(N + M) N is length of pattern, M is length of searched text
// Space complexity is O(N), because of the above LPS preprocessed table

vector<int> KMPalgorithm::KMP(string patt, string sequence){

    int M = patt.length();
    int N = sequence.length();

    vector<int> largestPrefSufx = lps(patt);
    vector<int> res; // result strings

    int i = 0;
    int k = 0;

    while (i < N) // while we are in the text
    {
        
        if (patt[k] == sequence[i]) // if match
        {

            i++;
            k++;

        }

        if (k == M) // if we are already at length of pattern(finished match)
        {
            
            res.push_back(i - M);
            k = largestPrefSufx[k - 1]; // since there may be other matches, we jump forward the value of the last match(since it may be a prefix or suffix too)

        }

        else if (i < N && patt[k] != sequence[i]) // if not matched and still in the text
        {
            
            if (k == 0) // not matched and we are already back at 0, go forward, increase i
            {

                i++;

            }
            
            else{

                k = largestPrefSufx[k - 1]; // update as last matched character(jump the correct amount back based on the table)

            }

        }
        

    }

    return res;     // return vector of result, found indexes.

}
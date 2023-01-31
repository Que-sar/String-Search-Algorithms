#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include "algorithms.h"
using namespace std;

// Based on the string pattern, will generate a Bad Character Heuristic.
// Returns an unordered map, which helps in accessing the necessary value faster on average, based on the key. 
// Time complexity is O(1) on average for searching, inserting (and deleting) the value, but on huge prime numbers, it could be O(n)
// This is if all values are present, need to be rewritten
// Space complexity is also O(N), but not all ascii characters are stored this way

unordered_map<char, int> BoMoHoalgorithm::badCharTableGen(string pattern)
{

    int patLen = pattern.length(); // Declare unordered Bad Char Hashtable
    unordered_map<char, int> badChars = {
    {'A', patLen},
    {'C', patLen},
    {'G', patLen},
    {'U', patLen}
};

    for (int i = 0; i < patLen-1; i++){

        int val = patLen - i - 1; // calculate with the rules of the algorithm
        char letter = badChars.find(pattern[i])->first;
        int currval = badChars.find(letter)->second;
        
        if (currval > val){ // add smallest value to table
            
            badChars.find(letter)->second = val;
        }

    }

    return badChars; // return unordered_map of badChartable

}


// Takes a pattern and a text string to search with/through.
// Returns vector of found locations.
// Uses Boyer-Moore-Horspool algorithm, with the unordered map, giving the lookup value an average of O(1)
// Overall, the algorithms worst case is O(nm) where the length of the pattern is m and the length of the search string is n.
// The best is the same as the Boyer-Moore algorithm, sub linear, but the average is around O(N)

vector<int> BoMoHoalgorithm::BoMoHo(string pattern, string text)
{

    int patLen = pattern.size();
    int textLen = text.size();
    int current = 0;

    vector<int> res;
    unordered_map<char, int> badcharacter = badCharTableGen(pattern);

    while (current <= (textLen - patLen)) // while we dont get to the end of the text minus the pattern
    {

        int j = patLen - 1; // the value we are currently checking, so that current will be able to move in the future as the table intends so

        while (j >= 0 && pattern[j] == text[current + j]) // while matching
        {

            j--;

        }

        if (j < 0) // we matched
        {

            res.push_back(current); // get index where value was seen

            if(current + patLen < textLen){ // there may be other occurrences, check if we still have room to go

                current += badcharacter[text[current + patLen]]; // move to the next place after match
                 
            }
                 
            else{ 

                current++; // if we are close to the end, we run out slowly, next time the table will handle the rest
            
            }

        }
        else{
            
            int valToAdd = badcharacter[text[current + j]]; // add the necessary shift to the current value we start counting downwards to
            current += valToAdd;

        }

    }

    return res; // return results

}
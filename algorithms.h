#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class KMPalgorithm
{

    public:

    vector<int> lps(string pattern); // Longest Prefix Suffix table
    vector<int> KMP(string patt, string sequence); // Knuth-Morris-Pratt algorithm

};

class BoMoHoalgorithm
{
    public:

    unordered_map<char, int> badCharTableGen(string pattern); // Bad Heuristic HashTable
    vector<int> BoMoHo(string pattern, string text); // Boyer-Moore-Horspool algorithm

};
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>

using namespace std;

int hashFunction(string, int);
int nextPrime(int);
bool isPrime(int);
void cleanWord(string&);

int main(int argc, char* argv[])
{
    string inStr = "";
    string inLine = "";
    int collisions = 0;
    int tblUtilization = 0;
    vector<list<string>> hashTable;

    // cout << "Enter string to hash: ";
    // getline(cin, inStr);

    ifstream fin;
    fin.open("frankenstein.txt");
    while(getline(fin, inLine))
    {
        inStr += inLine;
    }

    int inStrSize = inStr.length();

    hashTable.resize(nextPrime(inStrSize*2));

    istringstream iss;
    iss.str(inStr);
    string token;

    while(iss >> token)
    {
        cleanWord(token);
        int hashIdx = hashFunction(token, hashTable.size());
        if(!hashTable.at(hashIdx).empty())
        {
            for(string word : hashTable.at(hashIdx))
            {
                if(word != token)
                {
                    collisions++;
                    break;
                }
            }
        }
        hashTable.at(hashIdx).push_back(token);
    }

    // for(int i = 0; i < hashTable.size(); i++)
    // {
    //     if(hashTable.at(i).empty()) continue;
    //     cout << "hash[" << i << "]: ";
    //     for(string word : hashTable.at(i))
    //     {
    //         cout << word << ", ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < hashTable.size(); i++)
    {
        if(!hashTable.at(i).empty()) tblUtilization++;
    }

    cout << "Collisions: " << collisions << endl;
    cout << "Table size: " << hashTable.size() << endl;
    cout << "Table Util: " << tblUtilization << endl;

    return 0;
}

int hashFunction(string str, int tblSize)
{
    // SDBM hash
    // unsigned long hash = 0;
    // for(auto ch : str)
    // {
    //     hash = ch + (hash << 6) + (hash << 16) - hash;
    // }
    // return (hash % tblSize);

    //Bitwise hash (DJB2)
    // unsigned long hash = 5381;
    // for(auto ch : str)
    // {
    //     hash = ch + (hash << 5) + hash;
    // }
    // return (hash % tblSize);
    
    int p = 31;
    int hashval = 0;
    int p_pow = 1;

    for(char ch : str)
    {
        hashval = (hashval + (ch - 'a' + 1) * p_pow);
        p_pow = (p_pow * p) % tblSize;
    }
    return hashval % tblSize;

    // int hash = 0;
    // for(char ch : str)
    // {
    //     hash += ch;
    // }
    // return hash%tblSize;
}

void cleanWord(string& str)
{
    string cleanedWord = "";
    for(char ch : str)
    {
        if(isalpha(ch)) cleanedWord += tolower(ch);
    }
    str = cleanedWord;
}

int nextPrime(int n)
{
    while(!isPrime(n)) n++;
    return n;
}

bool isPrime(int n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i <= n; i += 6)
    {
        if(n%i == 0 || n%(i*2) == 0) return false;
    }
    return true;
}
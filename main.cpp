
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Filter.h"

using namespace std;

void open_inputFile(fstream& inputFile, char inFileName[]);
void open_outputFile(fstream& outputFile, char outFileName[]);
void printFile(fstream& file);
const int SIZE = 81;

int main()
{
    int filterType = 0;
    fstream inputFile;
    fstream outputFile;

    char inFileName[SIZE];
    char outFileName[SIZE];

    open_inputFile(inputFile, inFileName);
    open_outputFile(outputFile, outFileName);


    cout << "Enter 1 for Upper Case and 2 for Encryption: ";
    cin >> filterType;

    if (filterType == 1)
    {
        UpperCaseFilter upperFilter;
        upperFilter.doFilter(inputFile, outputFile);
    }
    else
    {
        EncryptionFilter encryptionfilter;
        encryptionfilter.doFilter(inputFile, outputFile);
    }

    inputFile.close();
    outputFile.close();

	return 0;
}


void open_inputFile(fstream& inputFile, char inFileName[])
{
    cout << "This program modifies an input file. " << endl << endl;
    cout << "Enter the name of input file (input.txt): ";
    cin >> inFileName;

    inputFile.open(inFileName, ios::in);

    if (!inputFile)
    {
        cout << "This file " << inFileName << " cannot be opened." << endl;
        exit(1);
    }

    cout << endl << "Original file contents is: " << endl;
    printFile(inputFile);
    cout << endl;
}

void printFile(fstream &file)
{
    file.clear();
    file.seekg(0, ios::beg);

    char ch = file.get();
    while (!file.eof())
    {
        cout << ch;
        ch = file.get();
    }

    file.clear();
    file.seekg(0, ios::beg);
}


void open_outputFile(fstream& outputFile, char outFileName[])
{
    cout << endl << "Enter name of output file (input.txt): ";
    cin >> outFileName;

    outputFile.open(outFileName, ios::out);
}


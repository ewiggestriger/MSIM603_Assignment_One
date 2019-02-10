/*
 * MSIM 603 Assignment One - Monte Carlo Simulation
 * Created 31 January 2019 by Steve Kostoff
 * This program simulates the process of manufacturing chips on silicon wafers by generating
 * and distributing defects via MCS from the manufacturing process onto the wafer, and then determining how many
 * usable chips can be produced from such wafers, and using this information to drive pricing decisions
 * for the chips (via external analysis).
 * The main function calls the wafer functions to initialize the wafer, generate and distribute defects,
 * and determine the number of good chips per wafer. This information is sent back to the main function,
 * which records it, performs output analysis on it, and displays it to the user.
*/
#include <iostream>
#include <fstream>
#include "wafer.h"

using namespace std;

int main() 
{
    // results will be written to a file for analysis
    ofstream mcsFile;
    mcsFile.open("mcs.csv"); //CSV format file for easy spreadsheet import
    cout << "Welcome to the CPU Manufacturing Simulator! This simulator models chip production from" << endl;
    cout << " silicon wafers with regards to the number of defective chips per wafer. Press any key to begin:" << endl;
    cin.get();
    // run the wafer simulations 30 times for each N(defects), from N = 10 to N = 100 in increments of 10
    mcsFile << "Defects,Good Chips,Rate,Chip Size\n";
    // run simulation for chip size 1.0 cm^2
    for (int i = 10; i < 110; i = i + 10) // outer loop increments number of defects
    {
        int good = 0; // variable holds the number of good chips counted in all the runs for a given N
        double rate = 0; // variable holds the percentage of good chips per wafer
        for (int j = 0; j < 30; ++j) // run 30 simulations per i
        {
            initializeWafer(1.0); // for chip size 1.0 cm^2
            generateDefects(i);
            good += countGoodChips();
        }
        good = good / 30; // calculate the average good chips over the 30 runs
        rate = good / 88.0; // calculate the percentage good chips per wafer
        // display results
        cout << "For " << i << " average defects per wafer, there are " << good << " good chips (";
        cout << rate * 100 << "%), for chip size 1.0 cm^2." << endl;
        mcsFile << i << "," << good << "," << rate << ",1.0" << endl;
    }
    // now run the simulation for chip size 1.5 cm^2
    mcsFile << "Defects,Good Chips,Rate,Chip Size\n";
    for (int i = 10; i < 110; i = i + 10) // outer loop increments number of defects
    {
        int good = 0; // variable holds the number of good chips counted in all the runs for a given N
        double rate = 0; // variable holds the percentage of good chips per wafer
        for (int j = 0; j < 30; ++j) // run 30 simulations per i
        {
            initializeWafer(1.5); // for chip size 1.5 cm^2
            generateDefects(i);
            good += countGoodChips();
        }
        good = good / 30; // calculate the average good chips over the 30 runs
        rate = good / 32.0; // calculate the percentage good chips per wafer
        // display results
        cout << "For " << i << " average defects per wafer, there are " << good << " good chips (";
        cout << rate * 100 << "%), for chip size 1.5 cm^2." << endl;
        mcsFile << i << "," << good << "," << rate << ",1.5" << endl;
    }
    // now run the simulation for chip size 2.0 cm^2
    mcsFile << "Defects,Good Chips,Rate,Chip Size\n";
    for (int i = 10; i < 110; i = i + 10) // outer loop increments number of defects
    {
        int good = 0; // variable holds the number of good chips counted in all the runs for a given N
        double rate = 0; // variable holds the percentage of good chips per wafer
        for (int j = 0; j < 30; ++j) // run 30 simulations per i
        {
            initializeWafer(2.0); // for chip size 2.0 cm^2
            generateDefects(i);
            good += countGoodChips();
        }
        good = good / 30; // calculate the average good chips over the 30 runs
        rate = good / 16.0; // calculate the percentage good chips per wafer
        // display results
        cout << "For " << i << " average defects per wafer, there are " << good << " good chips (";
        cout << rate * 100 << "%), for chip size 2.0 cm^2." << endl;
        mcsFile << i << "," << good << "," << rate << ",2.0" << endl;
    }
    mcsFile.close();

    return 0;
}
/*
 * MSIM 603 Assignment One - Monte Carlo Simulation
 * Created 31 January 2019 by Steve Kostoff
 * This program simulates the process of manufacturing chips on silicon wafers by generating
 * and distributing defects via MCS from the manufacturing process onto the wafer, and then determining how many
 * usable chips can be produced from such wafers, and using this information to drive pricing decisions
 * for the chips.
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
    mcsFile.open("mcs.csv");
    cout << "Welcome to the CPU Manufacturing Simulator! This simulator calculates chip pricing" << endl;
    cout << " based on a range of defects per silicon wafer. Press any key to begin the simulation" << endl;
    cin.get();
    // run the wafer simulations 30 times for each N(defects), from N = 10 to N = 100 in increments of 10
    mcsFile << "Defects,Good Chips\n";
    for (int i = 10; i < 100; i = i + 10) // outer loop increments number of defects
    {
        int good = 0; // variable holds the number of good chips counted in all the runs for a given N
        for (int j = 0; j < 30; ++j) // run 30 simulations per i
        {
            initializeWafer();
            generateDefects(i);
            good += countGoodChips();
        }
        // calculate average good chips for N and display result
        cout << "For " << i << " average defects per wafer, there are " << good / 30 << " good chips." << endl;
        mcsFile << i << "," << good / 30 << endl;
    }
    mcsFile.close();

    return 0;
}
/*
 * Wafer.cpp created by Steve Kostoff 9 Feb 2019
 * This source file implements all the wafer functions in wafer.h and conducts the
 * actual Monte Carlo Simulation (MCS).
 * (1) The initializeWafer() function marks as a good all chips completely within diameter of wafer
 * and marks as false all chips outside it
 * (2) it calls the checkCorners() function to perform the calculations on all four corners of the chip
 * (3) once set up, generateDefects(int) function takes the number of defects and uses MCS to place them
 * on the wafer, marking any good chip (true) as bad (false) that receives a defect
 * (4) finally countGoodChips() goes through the wafer array and returns the number of good chips
 * Notes -
 * (1) all chips are referenced by the coordinate of the lower left corner of the chip
*/

#include <cmath>
#include <cstdio>
#include <random>
#include <chrono>

using namespace std;

#define n 12

double chipSize;

bool wafer[n][n]; // true if chip i,j is good

void initializeWafer(double); // this function sets us the wafer prior to defects being applied
bool checkCorners(double, double); // this function checks that all four corners of a chip are within wafer diameter
void generateDefects(int); // this function takes the avg number of defects and returns a random number of defects
int countGoodChips(); // this function returns the number of good chips in the wafer array

// this function checks all four corners for each chip to ensure they are within wafer dimensions
// if any chip corner falls outside, chip is marked false, else it is marked true
void initializeWafer(double cs)
{
    chipSize = cs;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            wafer[i][j] = checkCorners(i, j);
        }
    }
}

// this function conducts the corner checking
// measures hypotenuse of triangle with endpoints origin and (i, j)
// if all 4 are less than wafer radius, returns true
bool checkCorners(double i, double j)
{
    if ( hypot((i * chipSize - 6.0), (j * chipSize - 6.0)) <= 6.0 )
    {
        if ( hypot( ((i + 1) * chipSize - 6.0), (j * chipSize - 6.0)) <= 6.0 )
        {
            if ( hypot((i * chipSize - 6.0), ((j + 1) * chipSize - 6.0)) <= 6.0 )
            {
                if ( hypot(((i + 1) * chipSize - 6.0), ((j + 1) * chipSize - 6.0)) <= 6.0 )
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// this function takes the number of defects and for each defect, generates a random x,y coordinate
// and marks the chip the coordinate appears in as "false" i.e. a bad chip
void generateDefects(int defects) {
    //create random number generator - first step need a seed
    unsigned seed = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    //create random number generator with this seed
    mt19937 generator(seed);
    uniform_real_distribution<double> distribution(0.0, 12.0);

    //apply the defects to the chip, note a chip can receive multiple defects
    for (int h = 0; h < defects; ++h) {
        int i,j;
        //generate a random x,y coordinate to place the defect
        double x = distribution(generator);
        double y = distribution(generator);
        //convert to i,j index, using floor since chip reference is lower left corner
        i = (int) floor(x / chipSize);
        j = (int) floor(y / chipSize);
        wafer[i][j] = false;
    }
};

// this function returns the number of good chips in array wafer (every array member is a separate chip)
int countGoodChips() {
    int good = 0; // declare counter and initialize it
    //nested for loops to iterate thru wafer array and return total count of good chips
    for (auto &i : wafer) {
        for (bool j : i) {
            if (j) {
                good++;
            }
        }
    }

    return good;
}
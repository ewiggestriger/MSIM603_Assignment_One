//
// Created by Steve Kostoff on 2019-02-09.
//

#ifndef MSIM603_ASSIGNMENT_ONE_WAFER_H
#define MSIM603_ASSIGNMENT_ONE_WAFER_H

#pragma once

/*
 * Name: void initializeWafer(double)
 * Functionality: sets up a wafer per the parameters of the assignment for chip simulation
 * Parameters: double cs - defines the chip size variable
 * Return value: none
 */
void initializeWafer(double);

/*
 * Name: void generateDefects(int)
 * Functionality: takes as input the desired number of defects and via MCS generates a uniformly distributed
 * defects on the wafer
 * Parameters: int defects - the number of defects you want to generate
 * Return value: none
 */
void generateDefects(int);

/*
 * Name: int countGoodChips()
 * Functionality: counts all the good chips in the wafer array and returns that number to the calling function
 * Parameters: none
 * Return value: int good - the number of good chips on the wafer
 */
int countGoodChips();

#endif //MSIM603_ASSIGNMENT_ONE_WAFER_H

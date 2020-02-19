//
//  main.cpp
//  WaysToMakeCoinChange
//
//  Created by adeeb mohammed on 13/02/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
// algorithm for making maximum no of coin change
// time complexity o(nd) n-> the target amount
// d-> no of denomination
#include <iostream>
#include <vector>
/*
 The algorithm behind this logic is as follows
 1) initialize an array which is having length of n+1 )
 (n is the total sum or money that we need to convert to small sums)
 2) The 0th position is assigned to 1 (This is the default case)
    ie the possible condition is that make no change such that
    we have the target sum
 3) if denomination is less than the target amount add the value
    in the amount-denom index of the array
 4) Repeat step for all denominations
 */

int numberOfWaysToMakeChange(int n, std::vector<int> denoms) {

    std::vector<int> possibleWays(n+1);
    possibleWays[0] = 1;
    for(int denom: denoms){
        for(int amount = 1 ; amount < n + 1;amount ++){
            if(denom <= amount){
                possibleWays[amount] += possibleWays[amount-denom];
            }
        }
    }
    return possibleWays[n];
}


int main(int argc, const char * argv[]) {
    std::cout << "Program for finding the no of ways we can make the change!"<< std::endl;
    std::cout << "In this program we have infinite amount of coin collection" << std::endl;
    std::cout << numberOfWaysToMakeChange(6, {1,5});
    return 0;
}

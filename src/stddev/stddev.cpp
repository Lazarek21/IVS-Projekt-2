#include "../math_lib.h"
#include <iostream>
#include <vector>

double StandardDev(std::vector<double> nums, double mean);
double Mean(std::vector<double>);

/**
 * @brief calculates mean value of an vector of doubles
 *        using arithmetic mean formula: https://en.wikipedia.org/wiki/Mean
 * 
 * @param nums vector of doubles with values to be calculated
 * @return double mean - calculated mean
 */
double Mean(std::vector<double> nums){
    math_lib_t res; //math_lib.h class instance, to use methods for calculation
    double mean = 0;
    for(int i = 0; i < (int)nums.size(); i++){
        mean = res.add(mean, nums[i]);
    } //calulates sum of all values
    mean = res.div(mean, (int)nums.size()); //divides sum by number of values
    return mean;
}

/**
 * @brief calculates standard deviation
 *        https://en.wikipedia.org/wiki/Standard_deviation
 * 
 * @param nums vector with values to be calculated
 * @param mean calculated mean of the same vector as <nums>
 * @return double sum - calculated stddeviation
 */
double StandardDev(std::vector<double> nums, double mean){
    math_lib_t res;
    double sum = 0.0;
    double stddeviation = 0.0;

    for(int i=0; i < (int)nums.size(); i++){
        sum += res.exp(res.sub(nums[i], mean), 2);
    }
    stddeviation = res.div(sum, (int)nums.size() - 1);
    stddeviation = res.my_sqrt(sum, 2);
    return stddeviation;
}

int main(){
    std::vector<double> nums;
    double input;
    
    while(std::cin >> input){
        nums.push_back(input);
    }//push back value from standard input into vector(until eof)
    //std::cout << StandardDev(nums, Mean(nums)) << "\n";
    return StandardDev(nums, Mean(nums));
}
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

//Define the exhaustive search function for the Knapsack problem
int knapsackExhaustive(int W, const vector<int>& weights, const vector<int>& values, int n){
    int max_value = 0;

    //Number of possible subsets (2^n)
    int totalSubsets = pow(2, n);

    //Iterate through all subsets
    for(int subset = 0; subset < totalSubsets; ++subset){
        int current_weight = 0;
        int current_value = 0;

        //Check each bit in the subset
        for(int i = 0; i < n; ++i){
            if(subset & (1 << i)){
                current_weight += weights[i];
                current_value += values[i];
            }
        }

        //Check if the current subset's weight is within the capacity
        if (current_weight <= W){
            max_value = max(max_value, current_value);
        }
    }
    return max_value;
}

int main(void){

    //Define knapsack problem parameters
    vector<int> values = {10, 20, 30, 40};
    vector<int> weights = {30, 10, 40, 20};
    int W = 100;
    int n = values.size();

    //Measure the time for the original capacity
    auto start = chrono::high_resolution_clock::now();
    int max_value = knapsackExhaustive(W, weights, values, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "............................................................" <<endl;
    cout << "Maximum value for capaity " << W << ": " << max_value << endl;
    cout << "Time taken: " << elapsed.count() << " seconds" << endl <<endl;


    //Double the capacity
    W *= 2;

    //Measure the time for the original capacity
    start = chrono::high_resolution_clock::now();
    max_value = knapsackExhaustive(W, weights, values, n);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;

 
    cout << "Maximum value for doubled capaity " << W << ": " << max_value << endl;
    cout << "Time taken for doubled capacity: " << elapsed.count() << " seconds" << endl;
    cout << "..........................................................." <<endl;

    // //Measurements for 10
    // W = 10;
    //  //Measure the time for the original capacity
    //  start = chrono::high_resolution_clock::now();
    //  max_value = knapsackExhaustive(W, weights, values, n);
    //  end = chrono::high_resolution_clock::now();
    //  elapsed = end - start;
    //  cout << "............................................................" <<endl;
    //  cout << "Maximum value for capaity 10 " << W << ": " << max_value << endl;
    //  cout << "Time taken 10: " << elapsed.count() << " seconds" << endl <<endl;
 
 
    //  //Double the capacity
    //  W *= 2;
 
    //  //Measure the time for the original capacity
    //  start = chrono::high_resolution_clock::now();
    //  max_value = knapsackExhaustive(W, weights, values, n);
    //  end = chrono::high_resolution_clock::now();
    //  elapsed = end - start;
 
 
    //  cout << "Maximum value for doubled capaity 10 " << W << ": " << max_value << endl;
    //  cout << "Time taken for doubled capacity 10: " << elapsed.count() << " seconds" << endl;
    //  cout << "..........................................................." <<endl;

    //      //Measurements for 10
    // W = 100;
    // //Measure the time for the original capacity
    // start = chrono::high_resolution_clock::now();
    // max_value = knapsackExhaustive(W, weights, values, n);
    // end = chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // cout << "............................................................" <<endl;
    // cout << "Maximum value for capaity 100 " << W << ": " << max_value << endl;
    // cout << "Time taken 100: " << elapsed.count() << " seconds" << endl <<endl;


    // //Double the capacity
    // W *= 2;

    // //Measure the time for the original capacity
    // start = chrono::high_resolution_clock::now();
    // max_value = knapsackExhaustive(W, weights, values, n);
    // end = chrono::high_resolution_clock::now();
    // elapsed = end - start;


    // cout << "Maximum value for doubled capaity 100" << W << ": " << max_value << endl;
    // cout << "Time taken for doubled capacity 100: " << elapsed.count() << " seconds" << endl;
    // cout << "..........................................................." <<endl;


    return 0;
}
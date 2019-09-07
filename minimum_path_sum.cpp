/******************************************************************************
 *                                                                            *
 *  Calculate minimum path 2D sum value                                       *
 *                                                                            *
 ******************************************************************************
 * Author: Joao Nuno Carvalho                                                 *
 * Date: 2019.09.07                                                           *
 * License: MIT Open Source License                                           *
 * Description: In this problem we calculate the minimum path sum (2D path).  *
 *              Problem: Given a grid, find a path from the top-left to the   *
 *              bottom-right corner that minimizes the sum of numbers along   *
 * the path. You can only move right or down.                                 *
 * First we give a simple and easy recursive algorithm, then we give a        *
 * dynamic programming algorithm.                                             *
 * First version - Calculate the minimum 2D path sum value recursively in the *
 * easiest way, but greatest time complexity because it will try every        *
 * combination of paths.                                                      *
 * Second version - Calculate the minimum 2D path sum value iteratively using *
 * dynamic programming. Construct an 2D vector of sums the min of the upper   *
 * and te left plus the current value of the map_2d path.                     *
 * ****************************************************************************
*/  

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

const int default_max_number = 9999999;

// Calculate the minimum 2D path sum value recursively in the easiest way, but
// greatest time complexity because it will try every combination of paths.
int minimum_2d_path_sum_recur(vector<vector<int>> map_2d, int row, int col){
    // cout << "( " << row << ", " << col << " )" << endl;
    int sum = 0;
    if (row == 0 && col == 0){
        sum = map_2d[0][0];
        return sum;
    }
    int min_up   = default_max_number;
    int min_left = default_max_number;    
    if (row > 0)
        min_up = minimum_2d_path_sum_recur(map_2d, row-1, col);
    if (col > 0)
        min_left = minimum_2d_path_sum_recur(map_2d, row, col-1);
    sum = min(min_left, min_up) + map_2d[row][col];
    return sum;
}

void printVec(vector<int> vec){
    cout << "{";
    bool first_flag {true};
    for(auto elem : vec){
        cout << ((first_flag)? "": ", ") << elem;
        first_flag = false;
    }
    cout << "}" << endl;
}

void printVec2d(vector<vector<int>> vec_2d, string vec_name){
    cout << vec_name << endl;
    for(auto inner_vec : vec_2d){
        for(auto elem : inner_vec){
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Calculate the minimum 2D path sum value iteratively using dynamic programming.
// Construct an 2D vector of sums the min of the upper and te left plus the
// current value of the map_2d path.
int minimum_2d_path_sum_dp_iter(vector<vector<int>> map_2d, int row, int col){
    // Create a 2D vector with the some dimensions that map_2d parameter.
    // Initialize one 1D vector line.
    vector<int> dp_vec_line(col+1, default_max_number);
    // Initialize the rows vector 2D with the previous vector line.
    vector<vector<int>> dp_vec(row+1, dp_vec_line);
    dp_vec[0][0] = map_2d[0][0];
    for(int r=0; r <= row; ++r){
        for(int c=0; c <= col; ++c){
            int min_up_path   = default_max_number;
            int min_left_path = default_max_number;    
            if (c > 0)
                min_left_path = dp_vec[r][c-1];
            if (r > 0)
                min_up_path = dp_vec[r-1][c];
            if (!(r == 0 && c == 0))                
                dp_vec[r][c] = min(min_left_path, min_up_path) + map_2d[r][c]; 
        }
    }
    printVec2d(dp_vec, "dp_vec");

    return  dp_vec[row][col];
}

// Measuring the calculation duration time of the different methods.
void measure_time(int n){
    cout << "Measure time" << endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    // Function A to test.
    // function_A();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration_a = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time duration - function_A( ) : " << duration_a << " micro seconds" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    // Function B to test.
    // function_B();
    t2 = std::chrono::high_resolution_clock::now();
    duration_a = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time duration - function_B( ) : " << duration_a << " micro seconds" << endl;
}

int main(){
    // 2D Map of path weight. This is the path that will be minimized.
    vector<vector<int>> map_2d = { {3, 2, 1, 3},
                                   {1, 9, 2, 3},
                                   {9, 1, 5, 4} };

    printVec2d(map_2d, "map_2d");


    cout << "Optimal minumum path: (0,0) (0,1) (0,2) (1,2) (1,3) (2,3)" << endl;
    cout << "Optimal minumum path sequence: 3, 2, 1, 2, 3, 4" << endl;
    cout << "Optimal minumum path sum: 15" << endl << endl;

    int x_max = static_cast<int>( map_2d.size() ) - 1;
    int y_max = static_cast<int>( map_2d[0].size() ) - 1;
    
    int sum = minimum_2d_path_sum_recur( map_2d, x_max, y_max);
    cout << "minimum_2d_path_sum_recur( map_2d, x_max, y_max ) : " << sum << endl;

    sum = minimum_2d_path_sum_dp_iter( map_2d, x_max, y_max);
    cout << "minimum_2d_path_sum_dp_iter( map_2d, x_max, y_max ) : " << sum << endl;

    return 0;
}

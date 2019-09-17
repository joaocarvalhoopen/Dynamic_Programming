/******************************************************************************
 *                                                                            *
 *  Dynamic Time Warping Algorithm                                            *
 *                                                                            *
 ******************************************************************************
 * Author: Joao Nuno Carvalho                                                 *
 * Date: 2019.09.17                                                           *
 * License: MIT Open Source License                                           *
 * Description: This is a simple implementation of the Dynamic Time Warping   *
 *              algorithm implemented using dynamic programming. It makes     *
 *              possible to calculate the distance between two time series A  *
 *              and B of floating point numbers (doubles).                    *
 *              The time complexity is O(NM) and space complexity is O(NM),   *
 *              where N is the length on time series A and M is the length    *
 *              of time series B.                                             *
 *              For textual details on the algorithm see references on        *
 *              project page.                                                 *
 ******************************************************************************
*/  

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void printVec2d_inverted(vector<vector<double>> vec_2d, string vec_name);

// Calculates the DTW between two time series, they can be of different length.
// The time complexity is O(NM) and space complexity is O(NM), where N is the
// length on time series A and M is the length of time series B.  
double dynamic_time_warping(vector<double> A, vector<double> B ){
    // Make the rectangle 2D dynamic vector N x M and initialize it to zeros.
    const size_t row_a_size = A.size();
    const size_t col_b_size = B.size();
    vector<vector<double>> dtw_vec(row_a_size, vector<double>(col_b_size));

    // Calculate the array with all the paths with dynamic programming.
    // Element filling order.
    //   8,9,10,11
    //   4,5,6,7,
    //   0,1,2,3,
    //
    for(size_t r = 0; r < row_a_size; ++r){
        for(size_t c = 0; c < col_b_size; ++c){
            double distance = abs(A[r] - B[c]);
            double minimum = 0;
            if (c==0 && r==0)
                minimum = 0.0;
            else if (c==0)
                minimum = dtw_vec[r-1][c];
            else if (r==0)
                minimum = dtw_vec[r][c-1]; 
            else{
                minimum = min(dtw_vec[r-1][c], dtw_vec[r][c-1]);
                minimum = min(minimum, dtw_vec[r-1][c-1]);  
            }
            dtw_vec[r][c] = distance + minimum;
        }
    }

    printVec2d_inverted(dtw_vec, "dtw_vec");

    // Calculate the best path of all the possible paths.
    // The one that minimizes the distance between the two time series. 
    size_t r = row_a_size - 1;
    size_t c = col_b_size - 1;
    double sum = dtw_vec[r][c];
    while(r != 0 && c != 0){
        if (c==0){
            r--;
            sum += dtw_vec[r][c];
        }else if (r==0){
                c--;
                sum = dtw_vec[r][c]; 
        }else{
            double minimum = min(dtw_vec[r-1][c], dtw_vec[r][c-1]);
            minimum = min(minimum, dtw_vec[r-1][c-1]);  
            
            if (minimum == dtw_vec[r-1][c-1]){
                c--;
                r--;
            }else if (minimum == dtw_vec[r-1][c]){
                r--;
            }else if (minimum == dtw_vec[r][c-1]){
                c--;
            }            
            sum += minimum;
        }
    }
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

void printVec2d_inverted(vector<vector<double>> vec_2d, string vec_name){
    cout << vec_name << endl;
    for(auto r = vec_2d.end()-1; r >= vec_2d.begin(); --r){
        for(auto c = r->begin(); c < r->end(); ++c){
            //cout << static_cast<double>(*c) << " ";
            cout << *c << " ";
        }
        cout << endl;
    }
    cout << endl;
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
    vector<double> A = {0,1,2,3,2,1,0};  // Time series A.
    vector<double> B = {1,1,2,2,2,1,1};  // Time series B.
    vector<double> C = {3,0,0,1,0,0,3};  // Time series C.

    double dist_A_B = dynamic_time_warping(A, B);
    double dist_A_C = dynamic_time_warping(A, C);
    cout << "Distance A_B = " << dist_A_B << endl;
    cout << "Distance A_C = " << dist_A_C << endl;
    if (dist_A_B < dist_A_C)
        cout << "Correct result!" << endl;
    else
        cout << "Incorrect result!" << endl;

    return 0;
}

/******************************************************************************
 *                                                                            *
 *  Calculate Fibonacci value or sequence                                     *
 *                                                                            *
 ******************************************************************************
 * Author: Joao Nuno Carvalho                                                 *
 * Date: 2019.09.07                                                           *
 * License: MIT Open Source License                                           *
 * Description: Calculate the Fibonacci value recursively with the simplest   *
 *              and easiest method ( O(2^n) time complexity), then calculate  *
 *              the dynamic programming method but with recursion ( O(n) time *
 * complexity). Then calculate it with a dynamic programming method ( O(n)    *
 * linear time and linear space),then calculate it with dynamic programming   *
 * method in constant space ( O(n) linear time and O(1) constant space).      *
 * ****************************************************************************
*/  

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Calculate Fibonacci value recursively in the easiest way.
int calc_fib_simpler(int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return calc_fib_simpler(n-1) + calc_fib_simpler(n-2); 
}

vector<int> vec_dp_recursive {}; // Initializes the vector object, to an empty vector.

void printVec(vector<int> vec){
    cout << "{";
    bool first_flag {true};
    for(auto elem : vec){
        cout << ((first_flag)? "": ", ") << elem;
        first_flag = false;
    }
    cout << "}" << endl;
}

// Calculate Fibonacci value recursively using dynamic programming (linear time
// and linear space, but the stack will grow).
int calc_fib_dp_recur(int n){
    // cout << "calc_fib_dp_recur_inner( " << n << " )" << endl;
    if (vec_dp_recursive.size() > static_cast<unsigned int>(n))
        return  vec_dp_recursive[n];
    if (n < 2){
        if (vec_dp_recursive.size() < 2 ){
            vec_dp_recursive.push_back(0);
            vec_dp_recursive.push_back(1);
        }    
        return vec_dp_recursive[n];
    }        
    int val = calc_fib_dp_recur(n-1) + calc_fib_dp_recur(n-2);
    // cout << "calc_fib_dp_recur_inner( " << n << " ) : " << val << endl;
    vec_dp_recursive.push_back(val);
    return val;
}

// Calculate Fibonacci value interactively using dynamic programming (linear
// time and linear space).
int calc_fib_dp_iter(int n){
    vector<int> vec_dp_iter {0, 1};
    for(int i = 2; i <= n; i++){
        vec_dp_iter.push_back(vec_dp_iter[i-1] + vec_dp_iter[i-2]);
    }
    // printVec(vec_dp_iter);
    return vec_dp_iter[n];
}

// Calculate Fibonacci value interactively using dynamic programming (linear
// time and constant space).
int calc_fib_dp_iter_const_space(int n){
    int n_minus_2 = 0;
    int n_minus_1 = 1;
    int val = -1;
    for(int i = 2; i <= n; i++){
        val = n_minus_1 + n_minus_2;
        n_minus_2 = n_minus_1;
        n_minus_1 = val;
    }
    return val;
}

// Measuring the calculation duration time of the different methods.
void measure_time(int n){
    cout << "Measure time" << endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    calc_fib_simpler(n);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration_a = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time duration - calc_fib_simpler( " << n << " ) : " << duration_a << " micro seconds" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    calc_fib_dp_recur(n);
    t2 = std::chrono::high_resolution_clock::now();
    duration_a = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time duration - calc_fib_dp_recur( " << n << " ) : " << duration_a << " micro seconds" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    calc_fib_dp_iter(n);
    t2 = std::chrono::high_resolution_clock::now();
    duration_a = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time duration - calc_fib_dp_iter( " << n << " ) : " << duration_a << " micro seconds" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    calc_fib_dp_iter_const_space(n);
    t2 = std::chrono::high_resolution_clock::now();
    duration_a = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    cout << "time duration - calc_fib_dp_iter_const_space( " << n << " ) : " << duration_a << " micro seconds" << endl;
}

int main(){
    cout << "Fibonacci value of 10 (55) - calc_fib_simpler(10):" << calc_fib_simpler(10) << endl;
    cout << "Fibonacci value of 10 (55) - calc_fib_dp_recur(10):" << calc_fib_dp_recur(10) << endl;
    printVec(vec_dp_recursive);
    cout << "Fibonacci value of 10 (55) - calc_fib_dp_iter(10):" << calc_fib_dp_iter(10) << endl;
    cout << "Fibonacci value of 10 (55) - calc_fib_dp_iter_const_space(10):" << calc_fib_dp_iter_const_space(10) << endl;

    // Measure the time duration for n = 45, 15 seconds for the slowest method
    // in my computer, instant on the other methods.
    measure_time(45);

    return 0;
}

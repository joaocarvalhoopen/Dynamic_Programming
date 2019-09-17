# Dynamic Programming
A algorithm technique to speed up your code.

## Description
I present here the code for several problems solved with dynamic programming. Typically the dynamic programming version of the code solves the problem orders of magnitude faster than the typical easier and more direct solution.<br> 
Dynamic programming is a method that uses memorization of previous results so that the algorithm doesn’t have to do the same calculations over and over again at each step. That normally turns into exponential and factorial run times. With dynamic programming in some cases you can reach linear time. And that is an incredible speed up for those algorithms that it is applicable.<br> 
Dynamic programming can be applied iteratively or recursively. The iteratively version is more powerful, but a little more complex, because in some cases order must be enforced, and that with the recursive method already comes naturally in the algorithm.<br>

## Reference links to see
* [Video Dynamic Programming lecture #1 - Fibonacci, iteration vs recursion - Errichto](https://www.youtube.com/watch?v=YBSt1jYwVfU)
* [Video Dynamic Programming lecture #2 - Coin change, double counting - Errichto](https://www.youtube.com/watch?v=1mtvm2ubHCY)
* [Video Dynamic Programming lecture #3 - Line of wines - Errichto](https://www.youtube.com/watch?v=pwpOC1dph6U)
* [Video Dynamic Programming - AtCoder educational dp contest - Errichto](https://www.youtube.com/watch?v=FAQxdm0bTaw)
* [Educational DP Contest](https://atcoder.jp/contests/dp)
* [Github Errichto DP AtCode Contest](https://github.com/Errichto/youtube/tree/master/atcoder-dp)
* [Free Book - Competitive Programmer's Handbook by Antti Laaksonen](https://github.com/pllk/cphb/)

## Fibonacci
Description: Calculate the Fibonacci value recursively with the simplest and easiest method ( O(2^n) time complexity), then calculate the dynamic programming method but with recursion ( O(n) time complexity). Then calculate it with a dynamic programming method ( O(n) linear time and linear space),then calculate it with dynamic programming method in constant space ( O(n) linear time and O(1) constant space). <br> 
[fibonacci.cpp](./fibonacci.cpp) <br>
![Fibonacci output](./fibonacci_output.png?raw=true "Fibonacci output") <br>

## Stairs  - Count ways to reach the s th stair with 1 step or 2 steps
Problem: You are climbing a staircase. It takes N steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? <br>
Solution: Equal to the Fibonacci solution but have to add the following function after the fibonacci value calculation. <br>
```
// The number of ways to reach s th stair 
int countWays(int s) 
{ 
    return fib(s + 1); 
} 
```

## Minimum path sum
Description: In this problem we calculate the minimum path sum (2D path). <br>
Problem: Given a grid, find a path from the top-left to the bottom-right corner that minimizes the sum of numbers along the path. You can only move right or down.<br>
First we give a simple and easy recursive algorithm, then we give a dynamic programming algorithm.<br>
First version - Calculate the minimum 2D path sum value recursively in the easiest way, but greatest time complexity because it will try every combination of paths.<br>
Second version - Calculate the minimum 2D path sum value iteratively using dynamic programming. Construct an 2D vector of sums the min of the upper and te left plus the current value of the map_2d path.<br>
[minimum_path_sum.cpp](./minimum_path_sum.cpp) <br>
![Minimum path sum](./minimum_path_sum_output.png?raw=true "Minimum path sum") <br>

## Dynamic Time Warping Algorithm
This is a implementation of the Dynamic Time Warping algorithm implemented using dynamic programming. It makes possible to calculate the distance between two time series A and B of floating point numbers (doubles). <br>
The time complexity is O(NM) and space complexity is O(NM), where N is the length on time series A and M is the length of time series B.<br> 
[dynamic_time_warping.cpp](./dynamic_time_warping.cpp) <br>
References:<br>
[How DTW (Dynamic Time Warping) algorithm works](https://www.youtube.com/watch?v=_K1OsqCicBY) <br>
[Wikipedia Dynamic time warping](https://en.wikipedia.org/wiki/Dynamic_time_warping) <br>
[Recognizing digits using dynamic time warping](http://tphinkle.github.io/MNIST-Digit-Recognizer/) <br>
[LB_Keogh makes retrieval of time-warped time series feasible even for large data sets](http://www.cs.ucr.edu/~eamonn/LB_Keogh.htm) <br>
[Paper Dynamic Programming Algorithm Optimization for Spoken Word Recognition](https://www.irit.fr/~Julien.Pinquier/Docs/TP_MABS/res/dtw-sakoe-chiba78.pdf) <br>
[Normalized measure of similarity from two time series, from dynamic time warping](https://cs.stackexchange.com/questions/53250/normalized-measure-from-dynamic-time-warping) <br>

## Soon there will be more implementation examples
TODO

## License
MIT Open Source License

## Have fun!
Best regards, <br>
Joao Nuno Carvalho
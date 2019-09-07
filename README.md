# Dynamic Programming
A algorithm technique to speed up your code.

## Description
I present here the code for several problems solved with dynamic programming. Typically the dynamic programming version of the code solves the problem orders of magnitude faster than the typical easier and more direct solution.<br> 
Dynamic programming is a method that uses memorization of previous results so that the algorithm doesn’t have to do the same calculations over and over again at each step. That normally turns into exponential and factorial run times. With dynamic programming in some cases you can reach linear time. And that is an incredible speed up for those algorithms that it is applicable.<br> 
Dynamic programming can be applied iteratively or recursively. The iteratively version is more powerful, but a little more complex, because in some cases order must be enforced, and that with the recursive method already comes naturally in the algorithm.<br>

## Reference links to see
* [Video Dynamic Programming lecture #1 - Fibonacci, iteration vs recursion - Errichto](https://www.youtube.com/watch?v=YBSt1jYwVfU)
* [Video Dynamic Programming lecture #2 - Coin change, double counting - Errichto](https://www.youtube.com/watch?v=1mtvm2ubHCY)
* [Video Dynamic Programming - AtCoder educational dp contest - Errichto](https://www.youtube.com/watch?v=FAQxdm0bTaw)
* [Educational DP Contest](https://atcoder.jp/contests/dp)
* [Github Errichto DP AtCode Contest](https://github.com/Errichto/youtube/tree/master/atcoder-dp)
* [Free Book - Competitive Programmer's Handbook by Antti Laaksonen](https://github.com/pllk/cphb/)

## Fibonacci
Description: Calculate the Fibonacci value recursively with the simplest and easiest method ( O(2^n) time complexity), then calculate the dynamic programming method but with recursion ( O(n) time complexity). Then calculate it with a dynamic programming method ( O(n) linear time and linear space),then calculate it with dynamic programming method in constant space ( O(n) linear time and O(1) constant space). <br> 
 [fibonacci.cpp](./fibonacci.cpp) <br>
![Fibonacci output](./fibonacci_output.png?raw=true "Fibonacci output") <br>

## Soon there will be more implementation examples
TODO

## License
MIT Open Source License

## Have fun!
Best regards, <br>
Joao Nuno Carvalho
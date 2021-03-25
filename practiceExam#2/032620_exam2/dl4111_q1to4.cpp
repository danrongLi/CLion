/*
 * Question 1
 *
 * Proof. By induction on n.
 *
 * Base case: n = 1.
 *
 * n^2+n = 1+1 = 2, and 2 divides 2, so the theorem holds true for the base case.
 *
 * Inductive step: Suppose we have positive integer k and 2 divides k^2+k, this means that k^2+k = 2m for some integer m,
 * which is an equivalent inductive hypothesis. We will show that 2 divides (k+1)^2+(k+1), which means we need to show
 * (k+1)^2+(k+1) can be written as 2 times some integer.
 *
 * (k+1)^2+(k+1) = k^2+1+2k+k+1 By algebra
 *               = k^2 + k + 2k + 2 By algebra
 *               = 2m + 2k + 2 By inductive hypothesis
 *               = 2* (m+k+1) By algebra
 * Since we know m and k are integers, m+k+1 is also integer. So we showed that (k+1)^2+(k+1) is the product of 2
 * and some integer (m+k+1), which means that 2 divides (k+1)^2+(k+1).
 *
 * Question 2
 *
 * number of ways that at least 1 girl selected = number of ways to select n students - number of ways to select without
 * any girls = C(5n,n)-C(3n,n)
 *
 * Question 3
 *
 * X situation            probability
 * 1 1,1                     1/9
 * 2 1,2 2,2 2,1              3/9
 * 3 1,3 2,3 3,3 3,2 3,1      5/9
 *
 * (1, 1/9), (2, 3/9), (3, 5/9)
 *
 * 1/8+6/9+15/9 = 22/9
 *
 * Question 4
 *
 * T(n) = theta(n^2)
 * There are 2 separate for loops. For the top for loop, since we are incrementing i from 0 to n, we are doing theta(n) work.
 * For the bottom for loop, the inner one is adding 1 to j from 1 to n+1 and there would be n terms in total.
 * so, the sum of 1+2+...+n+1 = theta(n^2). Considering both the top and bottom loops, theta(n)+theta(n^2) = theta(n^2)
 *
 * T(n) = theta(2^n)
 * There are 2 separate for loops. For the top for loop, since we are incrementing i from 0 to n, we are doing theta(n) work.
 * For the bottom for loop, the inner one is adding 1 to j from 1 to 2^n, and there would be n terms in total.
 * so, the sum of 2^0+2^1+...+2^n = theta(2^n). Considering both the top and bottom loops, theta(n)+theta(n^2) = theta(n^2)
 *
 *
 *
 */

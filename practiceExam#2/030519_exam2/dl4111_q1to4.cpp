/*
 * Question 1
 *
 * Proof. By induction on n.
 *
 * Base case: n = 2
 * a2 = a1+a0 = 1+1 = 2 < (7/4)^(2-1) = 1.75
 * So the theorem holds true for the base case
 *
 * Inductive step:
 * Suppose for every positive integer k>=2, we have ak < (7/4)^(k-1), we will show that a(k+1) < (7/4)^(k)
 *
 * ak+1 = ak + ak-1, since k>=2, ak and ak-1 would be at least a2 and a1, which fall in the inductive hypothesis criteria.
 * ak+ak-1 < (7/4)^(k-1) + (7/4)^(k-1-1) By inductive hypothesis
 *         = (7/4)^k * ((7/4)^(-1) + (7/4)^(-2)) By algebra
 *         = (7/4)^k * 0.898 By algebra, even if we did not calculate the result, we know that the (7/4)^k is multiplying
 *         some value < 1
 *         < (7/4)^k
 *
 * Thus, we showed that a(k+1) < (7/4)^(k)
 *
 * Question 2
 *
 * number of ternary string with at least 4 0s = total number of possible strings - number of strings with 0 0s
 *                                             - number of strings with 1 0s - number of strings with 2 0s - number
 *                                             of strings with 3 0s
 *                                             = 3^n - 2^n - 2^(n-1) - 2^(n-2) - 2^(n-3)
 *
 * Question 3
 *
 * a. toss X   situation
 *      1         H
 *      2         TH
 *      3         TTH
 *      4         TTTT, TTTH
 *
 *      so, we have (1, 1/5), (2, 1/5), (3, 1/5), (4, 2/5)
 *
 * b. 1*1/5 + 2*1/5 + 3*1/5 + 4*2/5 = 2.8
 * this is because we need to multiply the probability p(s) with toss number X(s)
 *
 * Question 4
 *
 * func1, T(n) = theta(n)
 * There are 2 separate for loops. The first one is theta(n), since we are iterating n from 0 to n with 1 step each time.
 * The second for loop has 2 loops. The outer one is theta(n) with the similar logic as the previous one, but the inner one
 * is theta(1) since the we are incrementing from 1 to 7 with 1 step each time and 7 is constant. The entire second for
 * loops is theta(n). Considering the entire algorithm, we have T(n) = theta(n).
 *
 * func2, T(n) = theta(n)
 * func2 is calling reverseArray n times, and reverseArray is doing i work each time.
 * i is n initially then become n-1, n-2, until 1. So we have the theta(n^2).
 *
 *
 *
 */
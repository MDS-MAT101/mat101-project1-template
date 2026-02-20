/***********************************************************************  
Bachelor of Software Engineering
Media Design School, 
Auckland,    New Zealand
(c) [Year] Media Design School                          <-- DO NOT FORGET TO FILL THIS OUT
Author      :   [Your name as it appears in the LMS]    <-- DO NOT FORGET TO FILL THIS OUT
Mail        :   [Your MDS email address]                <-- DO NOT FORGET TO FILL THIS OUT
File Name   :	exercises.cpp
Description :	Source implementation file for exercises as part of MAT101 Project I
**************************************************************************/

#include "exercises.h"
#include <cmath>

namespace mat101 {

// ============================================================
// PART A - Operators
// ============================================================

//--------- EXERCISE A1 --------
//---- Arithmetic Operators ----
//
// Learning goal:
// - practise building an algebraic expression using +, -, and *.
//
// Task:
// - compute the algebraic expression "(a + b) × (c - d)" and return it
//
// Tip:
// - use brackets exactly like the algebra.
double exA1_expression(double a, double b, double c, double d)
{
    // TODO: compute and return the expression result
    return 0.0;
}

// Part 2 of A1:
//
// Learning goal:
// - practise rearranging a simple equation and choosing values that satisfy it.
//
// Task:
// - choose four values (a,b,c,d) such that:
//     (a + b) * (c - d) == -2
//
// IMPORTANT:
// - You must SET the output parameters (out_a, out_b, out_c, out_d).
//
// Hints:
// - Think of it as:
//      X * Y = -2
//   where X = (a+b) and Y = (c-d)
// - Choose small integers for X and Y, like (1 and -2) or (2 and -1).
// - Then pick a,b that add to X and pick c,d that subtract to Y.
float exA1_find_values_for_minus_two(double& out_a, double& out_b, double& out_c, double& out_d)
{
    // TODO:
    // set values for each of the variables out_a, out_b, out_c, and out_d below
    // such that they result in the expression resolving to be -2
    out_a = 0.0;
    out_b = 0.0;
    out_c = 0.0;
    out_d = 0.0;

    return (float)exA1_expression(out_a, out_b, out_c, out_d);
}

//--------- EXERCISE A2 --------
//---- Relational Operators ----
//
// Learning goal:
// - practise comparing two expressions using >.
//
// Task:
// - return true if (a + b) is greater than (c - d), otherwise false.
//
// Tip:
// - compute the left side and right side into variables first (readability).
bool exA2_sum_greater_than_diff(double a, double b, double c, double d)
{
    // TODO: return whether (a + b) is greater than (c - d)
    return false;
}

//--------- EXERCISE A3 --------
//---- Logical Operators ----
//
// Learning goal:
// - practise combining conditions using && (AND).
//
// Task:
// - return true when:
//     (a + b) is non-zero  AND  (c - d) is zero
//
// Tip:
// - "non-zero" means: expression != 0
bool exA3_nonzero_and_zero(double a, double b, double c, double d)
{
    // TODO: return whether (a + b) is non-zero  AND  (c - d) is zero
    return false;
}

//--------- EXERCISE A4 --------
//---- Increment/Decrement + Integer Division ----
//
// Learning goal:
// - practise ++ and --, and integer division behaviour.
//
// Task:
// 1) increment a by 1
// 2) decrement d by 1
// 3) return (a * b) - (c / d) using integer division
//
// Important:
// - after decrementing, d could become 0 (divide-by-zero is a crash).
// - if d becomes 0, treat (c / d) as 0.
int exA4_inc_dec_calc(int a, int b, int c, int d)
{
    // TODO implement as per task instructions above
    return 0;
}

//--------- EXERCISE A5 --------
//---- Ternary Operator ----
//
// Learning goal:
// - practise the ternary operator (condition ? valueIfTrue : valueIfFalse).
//
// Task:
// - return the larger of (a + b) and (c - d) using ONE ternary expression.
int exA5_larger_sum_or_diff(int a, int b, int c, int d)
{
    // TODO
    return 0;
}

//--------- EXERCISE A6 --------
//---- Bitwise Operators ----
//
// Learning goal:
// - practise using bitwise AND (&) to test for even numbers.
//
// Tip:
// - An integer is even when its least significant bit is 0:
//       ie. (n & 1) is zero (hint: check it for equality with 0)
bool exA6_both_even_bitwise(int a, int b)
{
    // TODO
    return false;
}

//--------- EXERCISE A7 --------
//---- Modulo Operator ----
//
// Learning goal:
// - practise using % to check divisibility.
//
// Task:
// - return true if a is divisible by b
// - if b == 0, return false (divide-by-zero is a crash).
bool exA7_divisible(int a, int b)
{
    // TODO
    return false;
}

//--------- EXERCISE A8 --------
//---- Shift Operators ----
//
// Learning goal:
// - practise bit shifting.
// - use bit shift left <<
// - and bit shift right >>
//
// Task:
// 1) bit shift a left 2 times
// 2) bit shift b right 2 times
// 3) return the result of (1) minus (2)
//
// Note:
// - shifting left by 2 is like multiplying by 4 (for ints)
// - shifting right by 2 is like dividing by 4 (for ints, truncates)
int exA8_shift_subtract(int a, int b)
{
    // TODO
    return 0;
}

//--------- EXERCISE A9 --------
//---- Compound Assignment Operators ----
//
// Learning goal:
// - practise += and *=.
//
// Task:
// - add 5 to a and set a as the result using compound assignment
// - multiply b by 2 and set b as the result using compound assignment
// - return a / b using integer division
// - if b becomes 0, return 0 (divide-by-zero is a crash).
int exA9_compound_div(int a, int b)
{
    // TODO
    return 0;
}

//--------- EXERCISE A10 --------
//---- Lines + Simultaneous Equations ----
//
// Learning goal:
// - practise using y = mx + c (slope-intercept form)
// - practise solving two equations to find an intersection point
// - practise returning a struct (Point)
//
// This exercise is in TWO parts:
//
// Part 1) exA10_line(_m, _x, _c)
// - Implement the slope-intercept equation for a line
// - ie. Given m, x, and c, return the y value.
//
// Part 2) exA10_intersection(...)
// - You are given TWO lines in slope-intercept form (m and c for each line).
// - Find the point where both lines have the same x and y.
// - Return the result as a Point struct.
//
// Hint:
// Use your understanding of solving systems of simultaneous equations
// Algebraically rearrange before writing equations to calculate and store single variables
// ie. you may need to rearrange to "find x"
//
// Notes:
// - For this project, make sure you check the lines are NOT parallel (mA != mB).
// in such a case as they are parallel, you may return a Point struct of 0x, 0y
// - The parameters named _LineA_x and _LineB_x exist to match the “m, x, c” pattern,
//   but the intersection calculation should use the x you solve for 
// - hint: You can ignore the _LineA_x, and _LineB_x if you wish as only one is required to find the 
// y coord in the final step and it is neither of the Line's x values (depending on your approach) 
//
// Tip (about structs):
// - You can do either:
//     Point p; p.x = x; p.y = y; return p;
//   OR
//     return Point{ x, y };

// Part 1 implement y-slope intercept calcuation for a line
double exA10_line(double _m, double _x, double _c)
{
    // TODO: calculate and return the y axis value given the y-slope 
    // intercept form of a line equation
    double y = (_m * _x) + _c;
    return y;
}

// Part 2 for Lines + Simultaneous Equations, find and return point
Point exA10_intersection(double _LineA_m, double _LineA_x, double _LineA_c, double _LineB_m, double _LineB_x, double _LineB_c)
{
    // TODO return the Point struct containing the coordinate of the intersection
    // between the lines formed from by the given line equations for line A and line B
    return Point{0.0, 0.0};
}

// ============================================================
// PART B - Algebra + Conditionals + Loops
// ============================================================

//--------- EXERCISE B1 --------
//---- Simple Interest ----
//
// Simple Interest = Principal Amount × Interest Rate × Time
double exB1_simple_interest(double P, double R, double T)
{
    // TODO calculate the simple interest and return the result
    return 0.0;
}

//--------- EXERCISE B2 --------
//---- Nature of Quadratic Roots ----
//
// return -1 for any errors or unexpected results
// return 0 if there are no real roots
// return 1 if there is exactly 1 root
// return 2 if there are exactly 2 roots
//
// Remember, if a == 0, it is NOT a quadratic. (ie. return -1)
int exB2_quadratic_nature(double a, double b, double c)
{
    // TODO
    return -1;
}

//--------- EXERCISE B3 --------
//---- Perfect Square ----
//
// Task:
// - return true if n is a perfect square (0,1,4,9,16,...)
//
// Tip:
// - Use sqrt(n), truncate to int, and square back to compare.
bool exB3_is_perfect_square(int n)
{
    // TODO
    return false;
}

//--------- EXERCISE B4 --------
//---- Divisibility Classification ----
//
// Return:
// 0 : divisible by 2 and 3
// 1 : divisible by 2 but not 3
// 2 : neither divisible by 2 nor by 3
int exB4_divisibility_class(int n)
{
    // TODO
    return 2;
}

//--------- EXERCISE B5 --------
//---- Counting with a Loop ----
//
// Task:
// - count evens and odds in [lower, upper]
// - if lower > upper, treat as empty range
void exB5_count_even_odd(int lower, int upper, int& evenCount, int& oddCount)
{
    // TODO
    evenCount = 0;
    oddCount = 0;
}

//--------- EXERCISE B6 --------
//---- Loop + Sum ----
//
// Task:
// - Loop from 0 to n (inclusive), summing the numbers as you go.
// - Return the final sum.
// - If n < 0, return 0.
double exB6_sum_0_to_n(int n)
{
    // TODO
    return 0.0;
}

//--------- EXERCISE B7 --------
//---- Logical Expressions ----
//
// Task:
// - use the following logical operators to resolve the
// specified formal logic statements as boolean statements
// in C++
//
// Logical operators to be used: AND (&&), OR (||), NOT (!)
void exB7_logical_expr(bool p, bool q,
                       bool& out_and,
                       bool& out_or,
                       bool& out_not_p,
                       bool& out_xor)
{
    // TODO modify the below statements so that they resolve the corresponding formal logic statements
    out_and = false;    // p AND q
    out_or = false;     // p OR q
    out_not_p = false;  // NOT p
    out_xor = false;    // XOR: true iff p and q have different truth values
}

//--------- EXERCISE B8 --------
//---- DO-WHILE Loop + Digits ----
//
// Task:
// - Use a DO-WHILE loop.
// - Return the sum of the decimal digits of n.
// - For negative n, use the absolute value.
//
// Examples:
//  123 -> 6
//  0   -> 0
//  -45 -> 9
int exB8_sum_digits_do_while(int n)
{
    // TODO
    return 0;
}

//--------- EXERCISE B9 --------
//---- Consecutive Integers ----
//
// Task:
// - Find four consecutive integers a,b,c,d such that they sum to 110
// 
// - HINT:
//     b = a + 1
//     c = b + 1
//     d = c + 1
//     a + b + c + d = 110
//
// Requirements:
// - Set a, b, c, and d.
// - Return the sum (should be 110).
//
// Note:
// - Your instructor will check in the interview that you found them programmatically.
int exB9_four_consecutive_sum_110(int& a, int& b, int& c, int& d)
{
    // TODO
    a = b = c = d = 0;
    return 0;
}

//--------- EXERCISE B10 --------
//---- Prime Numbers (Range) ----
//
// Learning goal:
// - practise writing a helper function (is_prime)
// - practise loops, conditionals, and working with an output array
//
// Part 1) exB10_is_prime(int n)
// - Return true if n is prime, otherwise false.
// - Use the approach shown in class materials:
//   * handle n <= 1
//   * test divisors from 2 up to sqrt(n)
//
// Part 2) exB10_primes_in_range(int start, int end, int out[], int maxOut)
// - Find prime numbers from start to end (inclusive).
// - Store primes into out[] until you run out of space.
// - Return how many primes you stored.
//
// Rules / Input contract (used by tests):
// - If start > end, return 0!
// - start and end will be in a reasonable range for this course (0..100000).
// - maxOut will be >= 0.
// - If maxOut == 0, you must not write to out[] and should return 0.
//
// How the output array works (important):
// - Think of out[] as a row of boxes in memory.
// - maxOut tells you how many boxes you are allowed to fill.
// - Example:
//     maxOut = 3 means you can store at most 3 primes: out[0], out[1], out[2].
//
// IMPORTANT:
// - exB10_primes_in_range MUST call exB10_is_prime (don't duplicate logic).
bool exB10_is_prime(int n)
{
    // TODO
    return false;
}

int exB10_primes_in_range(int start, int end, int out[], int maxOut)
{
    // TODO:
    // - if start > end, return 0
    // - loop i from start to end inclusive
    // - if exB10_is_prime(i), store into out[] (if space remains)
    // - return how many you stored
    //
    // Reminder about arrays:
    // - out[] is a block of memory already created by the caller.
    // - maxOut is how many "slots" you are allowed to write into.
    //   Valid indexes are 0 up to (maxOut - 1).
    (void)start; (void)end; (void)out; (void)maxOut;
    return 0;
}

} // namespace mat101

/***********************************************************************  
Media Design School Games Department
Auckland,    New Zealand
(c) 2026 Media Design School                          
Author      :   Jeremy Teal
Mail        :   jeremy.teal@mediadesignschool.com              
File Name   :	exercises.h
Description :	Header file for declaration of all exercises (Part A and 
                Part B) as part of MAT101 Project I
**************************************************************************/

#pragma once

namespace mat101 {

struct Point {
    double x;
    double y;
};

// ============================================================
// MAT101 — Project 1 
//
// Edit ONLY: src/exercises.cpp
// Do NOT edit: include/, tests/, scripts/, CMakeLists.txt
//
// Each exercise is a function so the autograder can test it.
// ============================================================

// -----------------------------
// PART A: C++ operators
// -----------------------------

//--------- EXERCISE A1 --------
// Compute the algebraic expression "(a + b) × (c - d)" and return it.
double exA1_expression(double a, double b, double c, double d);

// Part 2 of A1:
// Choose four values (a,b,c,d) such that:
//     (a + b) * (c - d) == -2
//
// Set out_a/out_b/out_c/out_d, then RETURN the result of exA1_expression
// using those values (should be -2 when correct).
float exA1_find_values_for_minus_two(double& out_a, double& out_b, double& out_c, double& out_d);

//--------- EXERCISE A2 --------
// Return true if (a + b) is greater than (c - d).
bool exA2_sum_greater_than_diff(double a, double b, double c, double d);

//--------- EXERCISE A3 --------
// Return true when:
//     (a + b) is non-zero  AND  (c - d) is zero
bool exA3_nonzero_and_zero(double a, double b, double c, double d);

//--------- EXERCISE A4 --------
// 1) increment a by 1
// 2) decrement d by 1
// 3) return (a * b) - (c / d) using integer division
//
// If d becomes 0 after decrement, DO NOT divide (treat c/d as 0).
int exA4_inc_dec_calc(int a, int b, int c, int d);

//--------- EXERCISE A5 --------
// Return the larger of (a + b) and (c - d) using ONE ternary expression.
int exA5_larger_sum_or_diff(int a, int b, int c, int d);

//--------- EXERCISE A6 --------
// Use bitwise AND (&) to check BOTH numbers are even.
bool exA6_both_even_bitwise(int a, int b);

//--------- EXERCISE A7 --------
// Return true iff a is divisible by b.
// If b == 0, return false.
bool exA7_divisible(int a, int b);

//--------- EXERCISE A8 --------
// 1) bit shift a left 2 times
// 2) bit shift b right 2 times
// 3) return (1) minus (2)
int exA8_shift_subtract(int a, int b);

//--------- EXERCISE A9 --------
// - add 5 to a using compound assignment
// - multiply b by 2 using compound assignment
// - return a / b using integer division
// - if b becomes 0, return 0
int exA9_compound_div(int a, int b);

//--------- EXERCISE A10 --------
// Lines + Intersection Point (Systems of Equations)
//
// Part 1) Implement the slope-intercept form of a line:
//     y = m*x + c
//
// Part 2) Find the intersection point of TWO lines.
// You are given the line parameters (m and c) for each line.
// At the intersection both lines share the same (x, y).
//
// You may return a point of 0x, 0y if the lines are parallel (mA == mB).
//
// Note: _LineA_x and _LineB_x are included to match the “m, x, c” pattern,
// but the intersection calculation should use the x value you solve for.


// Part 1 implement y-slope intercept calcuation for a line
double exA10_line(double _m, double _x, double _c);

// Part 2 for Lines + Simultaneous Equations, find and return point
Point exA10_intersection(double _LineA_m, double _LineA_x, double _LineA_c, double _LineB_m, double _LineB_x, double _LineB_c);


// -----------------------------
// PART B: algebra + conditionals + loops
// -----------------------------

//--------- EXERCISE B1 --------
// Simple Interest = Principal Amount × Interest Rate × Time
double exB1_simple_interest(double P, double R, double T);

//--------- EXERCISE B2 --------
// Return values:
// -1 for errors or unexpected results
//  0 if there are no real roots
//  1 if there is exactly 1 real root
//  2 if there are exactly 2 real roots
//
// Remember: if a == 0, it is NOT a quadratic (return -1).
int exB2_quadratic_nature(double a, double b, double c);

//--------- EXERCISE B3 --------
// Return true if n is a perfect square (0,1,4,9,16,...)
bool exB3_is_perfect_square(int n);

//--------- EXERCISE B4 --------
// 0 : divisible by 2 and 3
// 1 : divisible by 2 but not 3
// 2 : neither divisible by 2 nor by 3
int exB4_divisibility_class(int n);

//--------- EXERCISE B5 --------
// Count evens and odds in [lower, upper]. If lower > upper, treat as empty range.
void exB5_count_even_odd(int lower, int upper, int& evenCount, int& oddCount);

//--------- EXERCISE B6 --------
// Loop from 0 to n (inclusive), sum the values, and return the sum.
// If n < 0, return 0.
double exB6_sum_0_to_n(int n);

//--------- EXERCISE B7 --------
// Use AND (&&), OR (||), NOT (!) to set outputs.
// XOR should be true iff p and q are different.
void exB7_logical_expr(bool p, bool q,
                       bool& out_and,
                       bool& out_or,
                       bool& out_not_p,
                       bool& out_xor);

//--------- EXERCISE B8 --------
// DO-WHILE LOOP practice.
// Return the sum of the decimal digits of n.
//
// Examples:
// - n = 123  -> 1+2+3 = 6
// - n = 0    -> 0
// - n = -45  -> 4+5 = 9   (use absolute value)
int exB8_sum_digits_do_while(int n);

//--------- EXERCISE B9 --------
// Find four consecutive integers a,b,c,d such that a+b+c+d = 110,
// and b=a+1, c=b+1, d=c+1.
//
// Return the sum (should be 110) and also set a,b,c,d.
// (Your instructor will check in the interview that you found them programmatically.)
int exB9_four_consecutive_sum_110(int& a, int& b, int& c, int& d);

//--------- EXERCISE B10 --------
// Prime numbers.
// Part 1: implement primality test.
bool exB10_is_prime(int n);

// Part 2: fill out[] with primes in [start, end] inclusive, in ascending order.
//
// - out[] is an array of ints the caller has already created.
// - maxOut tells you how many spaces are available inside out[].
//   (Think: maxOut is the "length" of the out array.)
//
// Return how many primes you actually wrote.
// If there are more primes than maxOut, write as many as fit.
int exB10_primes_in_range(int start, int end, int out[], int maxOut);

} // namespace mat101

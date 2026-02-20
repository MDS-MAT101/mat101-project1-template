#include "doctest.h"
#include "exercises.h"
#include <cmath>

using namespace mat101;

// -----------------------------
// PART A
// -----------------------------

TEST_CASE("A1::expression computes (a+b)*(c-d)") {
    CHECK(exA1_expression(1,2,3,4) == doctest::Approx(-3.0));
    CHECK(exA1_expression(2,3,10,6) == doctest::Approx(20.0));
}

TEST_CASE("A1::find values that make expression == -2") {
    double a=0,b=0,c=0,d=0;
    float result = exA1_find_values_for_minus_two(a,b,c,d);

    auto is_whole = [](double v){
        return std::abs(v - std::round(v)) < 1e-9;
    };

    CHECK(std::abs(a) <= 100);
    CHECK(std::abs(b) <= 100);
    CHECK(std::abs(c) <= 100);
    CHECK(std::abs(d) <= 100);

    CHECK(is_whole(a));
    CHECK(is_whole(b));
    CHECK(is_whole(c));
    CHECK(is_whole(d));

    CHECK(result == doctest::Approx(-2.0));
    CHECK(exA1_expression(a,b,c,d) == doctest::Approx(-2.0));
}

TEST_CASE("A2::(a+b) > (c-d)") {
    CHECK(exA2_sum_greater_than_diff(1,2,3,4));
    CHECK(!exA2_sum_greater_than_diff(1,1,10,0));
}

TEST_CASE("A3::non-zero AND zero check") {
    CHECK(exA3_nonzero_and_zero(1,2,5,5));
    CHECK(!exA3_nonzero_and_zero(-1,1,5,5));
    CHECK(!exA3_nonzero_and_zero(1,2,6,5));
}

TEST_CASE("A4::inc/dec calc handles division") {
    CHECK(exA4_inc_dec_calc(1,2,9,4) == (2*2 - 9/3));
}

TEST_CASE("A4::must avoid divide by zero if d becomes 0") {
    // d=1 -> 0 (after decrement). Correct behaviour: treat c/d as 0.
    // If a student divides by 0, this process will crash and the command will fail.
    CHECK(exA4_inc_dec_calc(1,2,9,1) == ((1+1)*2 - 0));
}

TEST_CASE("A5::returns larger of sum and diff") {
    CHECK(exA5_larger_sum_or_diff(1,2,3,4) == 3);
    CHECK(exA5_larger_sum_or_diff(1,1,10,0) == 10);
}

TEST_CASE("A6::both even using bitwise") {
    CHECK(exA6_both_even_bitwise(2,4));
    CHECK(!exA6_both_even_bitwise(2,3));
    CHECK(!exA6_both_even_bitwise(1,4));
}

TEST_CASE("A7::divisible") {
    CHECK(exA7_divisible(10,5));
    CHECK(!exA7_divisible(10,3));
    // If a student tries a % 0, this process will crash and the command will fail.
    CHECK(!exA7_divisible(10,0));
}

TEST_CASE("A8::shift subtract") {
    CHECK(exA8_shift_subtract(3,16) == ((3<<2) - (16>>2)));
}

TEST_CASE("A9::compound ops + safe division") {
    CHECK(exA9_compound_div(10,2) == 3); // (10+5)/(2*2)=15/4=3
    // If student divides by 0, this process will crash and the command will fail.
    CHECK(exA9_compound_div(10,0) == 0);
}

TEST_CASE("A10::line computes y = m*x + c") {
    using doctest::Approx;

    CHECK(exA10_line(2.0, 3.0, 4.0) == Approx(10.0));    // 2*3 + 4
    CHECK(exA10_line(-1.0, 5.0, 2.0) == Approx(-3.0));   // -1*5 + 2
    CHECK(exA10_line(0.5, 8.0, -1.0) == Approx(3.0));    // 0.5*8 - 1
}

TEST_CASE("A10::intersection returns a point that lies on both lines") {
    using doctest::Approx;

    // Line A: y = 2x + 3
    const double mA = 2.0;
    const double cA = 3.0;

    // Line B: 2x + 3y = 5  ->  y = (-2/3)x + 5/3
    const double mB = -2.0 / 3.0;
    const double cB =  5.0 / 3.0;

    // _LineA_x and _LineB_x are not needed for the intersection math;
    // pass 0.0 to keep the call simple.
    Point p = exA10_intersection(mA, 0.0, cA, mB, 0.0, cB);

    // Check it satisfies both lines (using the student's line function)
    const double yA = exA10_line(mA, p.x, cA);
    const double yB = exA10_line(mB, p.x, cB);

    CHECK(p.y == Approx(yA).epsilon(1e-9));
    CHECK(p.y == Approx(yB).epsilon(1e-9));
    CHECK(yA  == Approx(yB).epsilon(1e-9));

    // Optional: also check the known exact intersection for these specific lines
    CHECK(p.x == Approx(-0.8).epsilon(1e-9));
    CHECK(p.y == Approx( 1.4).epsilon(1e-9));
}

// -----------------------------
// PART B
// -----------------------------


TEST_CASE("B1::simple interest") {
    CHECK(exB1_simple_interest(1000, 0.05, 2) == doctest::Approx(100.0));
}

TEST_CASE("B2::quadratic nature return values") {
    CHECK(exB2_quadratic_nature(1, 0, -1) == 2);
    CHECK(exB2_quadratic_nature(1, 2, 1) == 1);
    CHECK(exB2_quadratic_nature(1, 0, 1) == 0);
    CHECK(exB2_quadratic_nature(0, 2, 1) == -1);
}

TEST_CASE("B3::perfect squares") {
    CHECK(exB3_is_perfect_square(0));
    CHECK(exB3_is_perfect_square(1));
    CHECK(exB3_is_perfect_square(16));
    CHECK(!exB3_is_perfect_square(2));
    CHECK(!exB3_is_perfect_square(-4));
}

TEST_CASE("B4::divisibility class") {
    CHECK(exB4_divisibility_class(12) == 0);
    CHECK(exB4_divisibility_class(8) == 1);
    CHECK(exB4_divisibility_class(7) == 2);
}

TEST_CASE("B5::count even odd inclusive range") {
    int e=0, o=0;
    exB5_count_even_odd(1, 5, e, o);
    CHECK(e == 2);
    CHECK(o == 3);
}

TEST_CASE("B5::empty range when lower>upper") {
    int e=123, o=456;
    exB5_count_even_odd(10, 1, e, o);
    CHECK(e == 0);
    CHECK(o == 0);
}

TEST_CASE("B6::sum 0..n") {
    CHECK(exB6_sum_0_to_n(0) == doctest::Approx(0.0));
    CHECK(exB6_sum_0_to_n(3) == doctest::Approx(6.0));
    CHECK(exB6_sum_0_to_n(10) == doctest::Approx(55.0));
    CHECK(exB6_sum_0_to_n(-5) == doctest::Approx(0.0));
}

TEST_CASE("B7::logical expressions") {
    bool a=false,o=false,np=false,x=false;
    exB7_logical_expr(true, false, a, o, np, x);
    CHECK(a == false);
    CHECK(o == true);
    CHECK(np == false);
    CHECK(x == true);
}

TEST_CASE("B8::sum digits using do-while") {
    CHECK(exB8_sum_digits_do_while(123) == 6);
    CHECK(exB8_sum_digits_do_while(0) == 0);
    CHECK(exB8_sum_digits_do_while(-45) == 9);
}

TEST_CASE("B9::four consecutive sum to 110") {
    int a=0,b=0,c=0,d=0;
    int sum = exB9_four_consecutive_sum_110(a,b,c,d);

    CHECK(sum == 110);
    CHECK(b == a + 1);
    CHECK(c == b + 1);
    CHECK(d == c + 1);
    CHECK(a + b + c + d == 110);
}

TEST_CASE("B10_prime::basic primality") {
    CHECK(!exB10_is_prime(-7));
    CHECK(!exB10_is_prime(0));
    CHECK(!exB10_is_prime(1));
    CHECK(exB10_is_prime(2));
    CHECK(exB10_is_prime(3));
    CHECK(!exB10_is_prime(4));
    CHECK(exB10_is_prime(29));
    CHECK(!exB10_is_prime(49));
}

// Reference prime checker for test validation (fast enough for small checks)
static bool ref_is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

TEST_CASE("B10_range::primes in range basic") {
    int out[16]{};
    int n = exB10_primes_in_range(1, 20, out, 16);

    CHECK(n == 8); // 2,3,5,7,11,13,17,19
    CHECK(out[0] == 2);
    CHECK(out[1] == 3);
    CHECK(out[2] == 5);
    CHECK(out[7] == 19);

    // sanity: all stored values are prime and increasing
    for (int i = 0; i < n; ++i) CHECK(ref_is_prime(out[i]));
    for (int i = 1; i < n; ++i) CHECK(out[i] > out[i - 1]);
}

TEST_CASE("B10_range::handles start>end") {
    int out[8]{};
    int n = exB10_primes_in_range(20, 1, out, 8);
    CHECK(n == 0);
}

TEST_CASE("B10_range::respects maxOut") {
    int out[3]{};
    int n = exB10_primes_in_range(1, 100, out, 3);

    CHECK(n == 3);
    CHECK(out[0] == 2);
    CHECK(out[1] == 3);
    CHECK(out[2] == 5);
}

TEST_CASE("B10_range::maxOut==0 writes nothing") {
    int out[3]{111, 222, 333};
    int n = exB10_primes_in_range(1, 100, out, 0);

    CHECK(n == 0);
    CHECK(out[0] == 111);
    CHECK(out[1] == 222);
    CHECK(out[2] == 333);
}

// Performance sanity suite:
// - Keep it separate so CI can run it with a timeout.
// - This should be fast with a sqrt(n) prime test.
TEST_CASE("B10_perf::performance sanity (range up to 50000)") {
    constexpr int START = 1;
    constexpr int END   = 50000;

    int out[64]{};
    int n = exB10_primes_in_range(START, END, out, 64);

    CHECK(n == 64); // there are far more than 64 primes <= 50000

    // values must be within range, prime, and strictly increasing
    for (int i = 0; i < n; ++i) {
        CHECK(out[i] >= START);
        CHECK(out[i] <= END);
        CHECK(ref_is_prime(out[i]));
        if (i > 0) CHECK(out[i] > out[i - 1]);
    }
}

int main(int argc, char** argv) {
    return doctest::run_all(argc, argv);
}

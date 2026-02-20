#ifndef DOCTEST_LIBRARY_INCLUDED
#define DOCTEST_LIBRARY_INCLUDED

#include <cmath>
#include <exception>
#include <iostream>
#include <string>

namespace doctest {

    // -----------------------------
    // Approx (very small subset)
    // -----------------------------
    struct Approx {
        double v;
        double eps;

        explicit Approx(double value) : v(value), eps(1e-12) {}
        Approx& epsilon(double e) { eps = e; return *this; }
    };

    inline bool approx_equal(double a, double b, double eps) {
        // relative+absolute style tolerance
        double diff = std::fabs(a - b);
        double scale = std::max(1.0, std::max(std::fabs(a), std::fabs(b)));
        return diff <= eps * scale;
    }

    inline bool operator==(double lhs, const Approx& rhs) { return approx_equal(lhs, rhs.v, rhs.eps); }
    inline bool operator==(const Approx& lhs, double rhs) { return approx_equal(lhs.v, rhs, lhs.eps); }
    inline bool operator!=(double lhs, const Approx& rhs) { return !(lhs == rhs); }
    inline bool operator!=(const Approx& lhs, double rhs) { return !(lhs == rhs); }

    // -----------------------------
    // Tiny test registry
    // -----------------------------
    using TestFunc = void(*)();

    struct TestCase {
        const char* name;
        TestFunc func;
        TestCase* next;
    };

    inline TestCase*& registry_head() {
        static TestCase* head = nullptr;
        return head;
    }

    struct Reg {
        Reg(const char* n, TestFunc f) {
            auto* tc = new TestCase{n, f, registry_head()};
            registry_head() = tc;
        }
    };

    inline int& failures() {
        static int f = 0;
        return f;
    }

    inline void check(bool ok, const char* expr, const char* file, int line) {
        if (!ok) {
            ++failures();
            std::cerr << file << ":" << line << " FAILED: " << expr << "\n";
        }
    }

    inline const char* find_test_suite_arg(int argc, char** argv) {
        for (int i = 1; i < argc; ++i) {
            const std::string a = argv[i];
            const std::string key = "--test-suite=";
            if (a.rfind(key, 0) == 0) {
                return argv[i] + key.size();
            }
        }
        return nullptr;
    }

    inline bool matches_suite(const char* testName, const char* suite) {
        if (!suite || !suite[0]) return true;

        std::string prefix = std::string(suite) + "::";
        std::string prefix2 = std::string(suite) + ":";

        std::string tn = testName ? testName : "";
        return tn.rfind(prefix, 0) == 0 || tn.rfind(prefix2, 0) == 0;
    }

    inline int run_all(int argc, char** argv) {
        const char* suite = find_test_suite_arg(argc, argv);

        for (auto* tc = registry_head(); tc; tc = tc->next) {
            if (!matches_suite(tc->name, suite)) continue;

            try { tc->func(); }
            catch (...) {
                ++failures();
                std::cerr << "Unhandled exception in test: " << tc->name << "\n";
            }
        }

        if (failures() == 0) {
            std::cout << "All tests passed.\n";
            return 0;
        }
        std::cout << failures() << " test(s) failed.\n";
        return 1;
    }
}

#define DOCTEST_CONCAT_IMPL(s1, s2) s1##s2
#define DOCTEST_CONCAT(s1, s2) DOCTEST_CONCAT_IMPL(s1, s2)

#define TEST_CASE(name)     static void DOCTEST_CONCAT(test_, __LINE__)();     static doctest::Reg DOCTEST_CONCAT(reg_, __LINE__)(name, &DOCTEST_CONCAT(test_, __LINE__));     static void DOCTEST_CONCAT(test_, __LINE__)()

#define CHECK(expr) doctest::check(!!(expr), #expr, __FILE__, __LINE__)

#endif // DOCTEST_LIBRARY_INCLUDED

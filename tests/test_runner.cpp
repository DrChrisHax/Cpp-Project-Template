#include "test_helpers.hpp"

#include "sample_tests.hpp"
// Add other test headers above this line

#include "timer.hpp"

#include <iostream>
#include <iomanip>
#include <string_view>

using core::Timer;

static int total_tests = 0;
static int passed_tests = 0;
static int failed_tests = 0;

static Timer::Duration total_test_time_ns{};

void Run(test_result (*test)(), std::string_view name) {
    ++total_tests;

    std::cout << CYAN << "[TEST]" << RESET << ' ' << name << '\n';

    Timer timer;
    timer.start();
    test_result result = test();
    timer.stop();
    total_test_time_ns += timer.elapsed();

    if (result.passed()) {
        ++passed_tests;
        std::cout << GREEN << "[PASS]" << RESET;
    } else {
        ++failed_tests;
        std::cout << RED << "[FAIL] Expected: " << RESET << result.expected() << '\n';
        std::cout << RED << "[FAIL] Result:   " << RESET << result.result() << '\n';
    }

    std::cout << CYAN << "[TIME] " << RESET << timer.elapsed_str() << '\n' << std::endl; // Flush the buffer between tests
}

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    Timer timer;
    timer.start();

    std::cout << "========================================\n";
    std::cout << "Running Test Suite\n";
    std::cout << "========================================\n\n";

    // =============================================================================
    // Sample Tests
    // =============================================================================
    
    Run(SampleTest1, "Sample Test 1"); // This test will pass
    Run(SampleTest2, "Sample Test 2"); // This test will fail

    // =============================================================================
    // Future Tests
    // =============================================================================

    // =============================================================================
    // Test Summary
    // =============================================================================
     
    std::cout << "========================================\n";
    std::cout << "Test Summary\n";
    std::cout << "========================================\n";
    std::cout << CYAN  << "[TOTAL]  " << RESET << total_tests << '\n';
    std::cout << GREEN << "[PASSED] " << RESET << passed_tests << '\n';
    std::cout << RED   << "[FAILED] " << RESET << failed_tests << '\n';

    // Time 1: sum of individual test times
    // Time 2: total test suite run time
    timer.stop();

    std::string time_1 = timer.elapsed_str(total_test_time_ns);
    std::string time_2 = timer.elapsed_str();

    std::cout << "Individual tests time sum: " << time_1 << '\n';
    std::cout << "Total test suite run time: " << time_2 << std::endl;

    return 0;
}
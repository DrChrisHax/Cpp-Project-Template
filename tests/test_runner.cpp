#include "test_helpers.hpp"

#include "sample_tests.hpp"
// Add other test headers above this line

#include <iostream>
#include <iomanip>
#include <string_view>

static int total_tests = 0;
static int passed_tests = 0;
static int failed_tests = 0;

void Run(test_result (*test)(), std::string_view name) {
    ++total_tests;

    std::cout << CYAN << "[TEST]" << RESET << ' ' << name << '\n';

    test_result result = test();

    if (result.passed()) {
        ++passed_tests;
        std::cout << GREEN << "[PASS]" << RESET;
    } else {
        ++failed_tests;
        std::cout << RED << "[FAIL] Expected: " << RESET << result.expected() << '\n';
        std::cout << RED << "[FAIL] Result:   " << RESET << result.result() << '\n';
    }

    std::cout << std::endl; // Flush the buffer between tests
}

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    std::cout << "========================================" << std::endl;
    std::cout << "Running Test Suite" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    // =============================================================================
    // Sample Tests
    // =============================================================================
    
    Run(SampleTest1, "Sample Test 1"); // This test will pass
    Run(SampleTest2, "Sample Test 2"); // This test will fail

    std::cout << std::endl;

    // =============================================================================
    // Future Tests
    // =============================================================================

    //std::cout << std::endl;
      
    // =============================================================================
    // Test Summary
    // =============================================================================
    std::cout << "========================================" << std::endl;
    std::cout << "Test Summary" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total: " << total_tests << std::endl;
    std::cout << "Passed: " << passed_tests << std::endl;
    std::cout << "Failed: " << failed_tests << std::endl;
    std::cout << std::endl;
}
#ifndef TESTS_SAMPLE_TESTS_HPP_
#define TESTS_SAMPLE_TESTS_HPP_

#include "test_helpers.hpp"

#include <string_view>

test_result SampleTest1() {
    int input = 1;
    std::string expected = "1";
    std::string result = std::to_string(input);

    return test_result(std::move(expected), std::move(result)); // This test will pass
}

test_result SampleTest2() {
    int input = 2;
    std::string expected = "1";
    std::string result = std::to_string(input);

    return test_result(std::move(expected), std::move(result)); // This test will fail
}

#endif // TESTS_SAMPLE_TESTS_HPP_
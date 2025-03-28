#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void runTest(const std::string& testName, void (*testFunc)()) {
    std::cout << YELLOW << "\n=== " << testName << " ===" << END << std::endl;
    try {
        testFunc();
        std::cout << GREEN << "✓ Test passed" << END << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Test failed: " << e.what() << END << std::endl;
    }
}

void basicTest() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    if (sp.shortestSpan() != 2 || sp.longestSpan() != 14)
        throw std::runtime_error("Incorrect span values");
}

void errorHandlingTest() {
    Span sp = Span(3);

    try {
        std::cout << "Testing empty span..." << std::endl;
        Span emptySp(5);
        emptySp.shortestSpan();
        throw std::runtime_error("Should have thrown exception for empty span");
    } catch (const std::invalid_argument&) {
        std::cout << "Correctly caught exception for empty span" << std::endl;
    }

    try {
        std::cout << "Testing span with one element..." << std::endl;
        Span oneSp(5);
        oneSp.addNumber(42);
        oneSp.shortestSpan();
        throw std::runtime_error("Should have thrown exception for span with one element");
    } catch (const std::invalid_argument&) {
        std::cout << "Correctly caught exception for span with one element" << std::endl;
    }

    try {
        std::cout << "Testing capacity limit..." << std::endl;
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        throw std::runtime_error("Should have thrown exception for exceeding capacity");
    } catch (const std::length_error&) {
        std::cout << "Correctly caught exception for exceeding capacity" << std::endl;
    }
}

void largeNumbersTest() {
    const int SIZE = 30000;
    Span sp = Span(SIZE);

    std::srand(std::time(NULL));
    for (int i = 0; i < SIZE; i++) {
        sp.addNumber(std::rand() % 10000);
    }

    std::cout << "Added " << SIZE << " random numbers" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void specialCasesTest() {
    Span sp = Span(5);

    sp.addNumber(-10);
    sp.addNumber(INT_MAX);
    sp.addNumber(45);
    sp.addNumber(0);
    sp.addNumber(INT_MIN);

    std::cout << "Span with extreme values:" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    if (sp.shortestSpan() != 10 || sp.longestSpan() != long(INT_MAX) - long(INT_MIN))
        throw std::runtime_error("Incorrect span values for extreme numbers");
}

void copyTest() {
    Span original = Span(5);
    original.addNumber(1);
    original.addNumber(3);
    original.addNumber(5);

    Span copy(original);
    if (copy.shortestSpan() != original.shortestSpan())
        throw std::runtime_error("Copy constructor failed");

    Span assigned = Span(10);
    assigned = original;
    if (assigned.longestSpan() != original.longestSpan())
        throw std::runtime_error("Assignment operator failed");

    std::cout << "Copy tests passed successfully" << std::endl;
}

int main() {
    std::cout << BLUE << "SPAN CLASS TESTS" << END << std::endl;

    runTest("Basic Functionality", basicTest);
    runTest("Error Handling", errorHandlingTest);
    runTest("Large Numbers (10,000)", largeNumbersTest);
    runTest("Special Cases", specialCasesTest);
    runTest("Copy Constructor & Assignment", copyTest);

    return 0;
}


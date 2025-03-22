#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

void runTest(const std::string& testName, void (*testFunc)()) {
    std::cout << YELLOW << "\n=== " << testName << " ===" << END << std::endl;
    try {
        testFunc();
        std::cout << GREEN << "✓ Test passed" << END << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Test failed: " << e.what() << END << std::endl;
    }
}

// 基本的な機能テスト
void basicTest() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // 期待値チェック
    if (sp.shortestSpan() != 2 || sp.longestSpan() != 14)
        throw std::runtime_error("Incorrect span values");
}

// エラーハンドリングテスト
void errorHandlingTest() {
    Span sp = Span(3);

    // 空のSpanでのspanチェック
    try {
        std::cout << "Testing empty span..." << std::endl;
        Span emptySp(5);
        emptySp.shortestSpan();
        throw std::runtime_error("Should have thrown exception for empty span");
    } catch (const std::invalid_argument&) {
        std::cout << "Correctly caught exception for empty span" << std::endl;
    }

    // 要素一つでのspanチェック
    try {
        std::cout << "Testing span with one element..." << std::endl;
        Span oneSp(5);
        oneSp.addNumber(42);
        oneSp.shortestSpan();
        throw std::runtime_error("Should have thrown exception for span with one element");
    } catch (const std::invalid_argument&) {
        std::cout << "Correctly caught exception for span with one element" << std::endl;
    }

    // 容量を超えたaddNumber
    try {
        std::cout << "Testing capacity limit..." << std::endl;
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // この時点で例外が発生するはず
        throw std::runtime_error("Should have thrown exception for exceeding capacity");
    } catch (const std::length_error&) {
        std::cout << "Correctly caught exception for exceeding capacity" << std::endl;
    }
}

// 10,000個の数字をテスト
void largeNumbersTest() {
    const int SIZE = 10000;
    Span sp = Span(SIZE);

    // ランダムな数字を追加
    std::srand(std::time(nullptr));
    for (int i = 0; i < SIZE; i++) {
        sp.addNumber(std::rand() % 1000000);
    }

    std::cout << "Added " << SIZE << " random numbers" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

// 特殊なケースのテスト（負の数、大きな数など）
void specialCasesTest() {
    Span sp = Span(5);

    sp.addNumber(-10);
    sp.addNumber(5);
    sp.addNumber(0);
    sp.addNumber(INT_MAX);
    sp.addNumber(INT_MIN);

    std::cout << "Span with extreme values:" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

// コピーコンストラクタとオペレータのテスト
void copyTest() {
    Span original = Span(5);
    original.addNumber(1);
    original.addNumber(3);
    original.addNumber(5);

    // コピーコンストラクタのテスト
    Span copy(original);
    if (copy.shortestSpan() != original.shortestSpan())
        throw std::runtime_error("Copy constructor failed");

    // 代入演算子のテスト
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


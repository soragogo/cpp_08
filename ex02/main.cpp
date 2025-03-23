#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << CYAN << "=== MutantStack Basic Test ===" << END << std::endl;

    MutantStack<int> mstack;

    std::cout << "Pushing elements: 12, 1, 3, 12, 23, 0" << std::endl;
    mstack.push(12);
    mstack.push(1);
    mstack.push(3);
    mstack.push(12);
    mstack.push(23);
    mstack.push(0);

    std::cout << "Stack size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;

    if  (mstack.size() == 6 && mstack.top() == 0) {
        std::cout << GREEN << "OK" << END << std::endl;
    } else {
        std::cout << RED << "KO" << END << std::endl;
    }

    std::cout << "Popping top element" << std::endl;
    mstack.pop();
    std::cout << "New size: " << mstack.size() << std::endl;
    std::cout << "New top element: " << mstack.top() << std::endl;

    std::cout << "Is stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;

    if  (mstack.size() == 5 && mstack.top() == 23) {
        std::cout << GREEN << "OK" << END << std::endl;
    } else {
        std::cout << RED << "KO" << END << std::endl;
    }

    std::cout << CYAN << "\n=== Copy Constructor & Assignment Test ===" << END << std::endl;

    MutantStack<int> copy_stack(mstack);
    std::cout << "Copied stack size: " << copy_stack.size() << std::endl;
    std::cout << "Copied stack top: " << copy_stack.top() << std::endl;

    if  (mstack.size() == 5 && mstack.top() == 23) {
        std::cout << GREEN << "OK" << END << std::endl;
    } else {
        std::cout << RED << "KO" << END << std::endl;
    }

    MutantStack<int> assigned_stack;
    assigned_stack = mstack;
    std::cout << "Assigned stack size: " << assigned_stack.size() << std::endl;
    std::cout << "Assigned stack top: " << assigned_stack.top() << std::endl;

    if  (mstack.size() == 5 && mstack.top() == 23) {
        std::cout << GREEN << "OK" << END << std::endl;
    } else {
        std::cout << RED << "KO" << END << std::endl;
    }

    mstack.push(999);
    std::cout << "Original stack size after push: " << mstack.size() << std::endl;
    std::cout << "Copied stack size: " << copy_stack.size() << std::endl;
    std::cout << "Assigned stack size: " << assigned_stack.size() << std::endl;

    if  (mstack.size() == 6 && copy_stack.size() == 5 && assigned_stack.size() == 5) {
        std::cout << GREEN << "OK" << END << std::endl;
    } else {
        std::cout << RED << "KO" << END << std::endl;
    }

    std::cout << CYAN << "\n=== Iterator Test ===" << END << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it) {
        std::cout << *it << std::endl;
    }

    
    return 0;
}

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack {

public:
    MutantStack() : std::stack<T>;
    ~MutantStack();
    MutantStack(MutantStack & ms) : std::stack<T>(ms);
    MutantStack & operator=(MutantStack & ms);

    bool empty();
    void pop();
    void push(T elem);
    size_t size();
    T & top();
    std::

    class iterator<T> {
        std::iterator<T>  begin();
        std::iterator<T> end();
        //prefix
        std::MutantStack<T>::iterator operator++();
        std::MutantStack<T>::iterator operator--();

        //postfix
        std::MutantStack<T>::iterator operator++(T);
        std::MutantStack<T>::iterator operator--(T);
    }

private:

};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack & ms) {
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack & ms) {
    if (*this != ms) {
        std::stack<T>::operator=(ms);
    }
    return *this;
}


template <typename T>
bool MutantStack<T>::empty() {
    return std::stuck<T>::empty();
}

template <typename T>
void MutantStack<T>::pop() {
    return std::stuck<T>::pop();
}

template <typename T>
void MutantStack<T>::push(T elem) {
    return std::stuck<T>::push(elem);
}

template <typename T>
size_t MutantStack<T>::size() {
    return std::stuck<T>::size();
}

template <typename T>
T & MutantStack<T>::top() {
    return std::stuck<T>::top();
}



# define END             "\033[0m"
# define BOLD            "\033[1m"
# define BLACK           "\033[30m"
# define RED             "\033[31m"
# define GREEN           "\033[32m"
# define YELLOW          "\033[33m"
# define BLUE            "\033[34m"
# define MAGENTA         "\033[35m"
# define CYAN            "\033[36m"
# define WHITE           "\033[37m"
# define UNDERLINE       "\033[4m"
# define BOLD_UNDERLINE  "\033[1;4m"
#endif

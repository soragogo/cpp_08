#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
    MutantStack() : std::stack<T>() {};
    ~MutantStack();
    MutantStack(MutantStack & ms) : std::stack<T>(ms) {};
    MutantStack & operator=(MutantStack & ms);

    typedef typename std::stack<T> stack;
    typedef typename stack::container_type container;
    typedef typename container::iterator iterator;

    MutantStack<T>::iterator begin();
    MutantStack<T>::iterator end();
    MutantStack<T>::iterator rbegin();
    MutantStack<T>::iterator rend();


private:

};


template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack & ms) {
    if (this != &ms) {
        stack::operator=(ms);
    }
    return *this;
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend() {
    return this->c.rend();
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

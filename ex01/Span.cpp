#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int const & n) : _cap(n) {
    _v.reserve(n);
}

Span::~Span(){

}

Span::Span(Span const & span) : _cap(span._cap), _v(span._v) {}

Span & Span::operator=(Span const & span) {
    if (this != &span) {
        this->_cap = span._cap;
        this->_v = span._v;
    }
    return *this;
}

void Span::addNumber(int const & num) {
    if (_cap <= _v.size())
        throw std::length_error("The span is full.");
    _v.push_back(num);
}

long Span::shortestSpan() {
    if (_v.size() <= 1 || _v.capacity() <= 1)
        throw std::invalid_argument("Add a number first.");
    long ans = long(INT_MAX) - long(INT_MIN);
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    for (std::vector<int>::iterator it = tmp.begin(); it < tmp.end() - 1; ++it) {
        if (abs(*it - *(it + 1)) < ans) ans = abs(*it - *(it + 1));
    }
    return ans;
}

long Span::longestSpan() {
    if (_v.size() == 0 || _v.capacity() == 0)
        throw std::invalid_argument("Add a number first.");
    int max = INT_MIN;
    int min = INT_MAX;
    for (std::vector<int>::iterator it = _v.begin(); it < _v.end(); ++it) {
        if (*it < min) min = *it;
        if (*it > max) max = *it;
    }
    return (long(max) - long(min));
}

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span{

public:
    Span(unsigned int const & n);
    ~Span();
    Span(Span const & span);
    Span & operator=(Span const & span);
    void addNumber(int const & num);
    long shortestSpan();
    long longestSpan();

private:
    Span();
    unsigned int _cap;
    std::vector<int> _v;
};


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

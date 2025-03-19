#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {

        std::vector<int> v;
        for (int i = 0; i < 10; i++)
            v.push_back(i);

        std::list<int> l;
        for (int i = 0; i < 10; i++)
            l.push_back(i);

        try{
            std::vector<int>::iterator it_v = easyfind(v, 5);
            if (it_v != v.end())
                std::cout << GREEN << "5 found in it_v" << END << std::endl;
            else
                std::cout << RED << "5 not found in it_v" << END << std::endl;
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }

                try{
            std::vector<int>::iterator it_v = easyfind(v, 15);
            if (it_v != v.end())
                std::cout << GREEN << "15 found in it_v" << END << std::endl;
            else
                std::cout << RED << "15 not found in it_v" << END << std::endl;
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }

        try{
            std::list<int>::iterator it_l = easyfind(l, 5);
            if (it_l != l.end())
                std::cout << GREEN << "5 found in it_l" << END << std::endl;
            else
                std::cout << RED << "5 not found in it_l" << END << std::endl;
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }

        try{
            std::list<int>::iterator it_l = easyfind(l, 15);
            if (it_l != l.end())
                std::cout << GREEN << "15 found in it_l" << END << std::endl;
            else
                std::cout << RED << "15 not found in it_l" << END << std::endl;
        }
        catch(std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }

}

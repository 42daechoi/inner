#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <stack>
#include <list>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "top : " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size : " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::riter rit = mstack.rbegin();
		MutantStack<int>::riter rite = mstack.rend();
		MutantStack<int>::iter it = mstack.begin();
		MutantStack<int>::iter ite = mstack.end();
		
		++it;
		--it;
		
		std::cout << "list : ";
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << "\nlist : ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "\n\n";
	{
		std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "back : " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "size : " << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;

		std::cout << "list : ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
	}
	return 0;
}
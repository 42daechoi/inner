#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <list>
# include <deque>
# include <algorithm>
# include <sstream>
# include <iterator>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &			operator=( PmergeMe const & rhs );

		void				print();
		void				listPrint();
		void				dqPrint();

		std::list<int> 		getList() const;
		std::deque<int> 	getDeque() const;

	private:
		std::list<int>		insert(std::list<int> &list);
		std::deque<int>		insert(std::deque<int> &dq);
		std::list<int>		merge(std::list<int> &ll, std::list<int> &rl);
		std::deque<int>		merge(std::deque<int> &lq, std::deque<int> &rq);
		std::list<int>		mergeInsertSort(std::list<int> &list);
		std::deque<int>		mergeInsertSort(std::deque<int> &dq);

		std::list<int>		list;
		std::deque<int>		dq;
};


#endif /* ******************************************************** PMERGEME_H */
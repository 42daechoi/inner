#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <vector>
# include <deque>
# include <algorithm>
# include <sstream>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &			operator=( PmergeMe const & rhs );

		void				print();
		void				vecPrint();
		void				dqPrint();

		std::vector<int> 	getVector() const;
		std::deque<int> 	getDeque() const;

	private:
		std::vector<int>	insert(std::vector<int> &vec);
		std::deque<int>		insert(std::deque<int> &dq);
		std::vector<int>	merge(std::vector<int> &lv, std::vector<int> &rv);
		std::deque<int>		merge(std::deque<int> &lq, std::deque<int> &rq);
		std::vector<int>	mergeInsertSort(std::vector<int> &vec);
		std::deque<int>		mergeInsertSort(std::deque<int> &dq);

		std::vector<int>	vec;
		std::deque<int>		dq;
};


#endif /* ******************************************************** PMERGEME_H */
#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	int n;

	for (int i = 1; i < ac; i++) {
		std::stringstream ss(av[i]);
		ss >> n;
		list.push_back(n);
		dq.push_back(n);
	}
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->list = rhs.getList();
		this->dq = rhs.getDeque();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::list<int> PmergeMe::insert(std::list<int> &list) {
	std::list<int>::iterator it;

	for (it = ++list.begin(); it != list.end(); it++) {
		int temp = *it;
		std::list<int>::iterator prev = std::prev(it);
		while (std::next(prev) != list.begin() && *prev > temp) {
			*std::next(prev) = *prev;
			prev--;
		}
		*std::next(prev) = temp;
  	}
	return list;
}

std::deque<int> PmergeMe::insert(std::deque<int> &dq) {
	for (int i = 1; i < (int)dq.size(); i++) {
		int temp = dq[i];
		int j = i;
		while (j > 0 && dq[j - 1] > temp) {
			dq[j] = dq[j - 1];
			j--;
		}
		dq[j] = temp;
	}
	return dq;
}

std::list<int> PmergeMe::merge(std::list<int> &ll, std::list<int> &rl) {
	std::list<int>::iterator	itl = ll.begin();
	std::list<int>::iterator	itr = rl.begin();
	std::list<int>				res;

	for (int i = 0; i < (int)(ll.size() + rl.size()); i++) {
		if (itr == rl.end()) {
			res.push_back(*itl);
			itl++;
		}
		else if (itl == ll.end()) {
			res.push_back(*itr);
			itr++;
		}
		else if (*itr > *itl) {
			res.push_back(*itl);
			itl++;
		}
		else {
			res.push_back(*itr);
			itr++;
		}
	}
	return res;
}

std::deque<int> PmergeMe::merge(std::deque<int> &lq, std::deque<int> &rq) {
	std::deque<int>	res;
	std::deque<int>::iterator	itl = lq.begin();
	std::deque<int>::iterator	itr = rq.begin();

	for (int i = 0; i < (int)(lq.size() + rq.size()); i++) {
		if (itr == rq.end()) {
			res.push_back(*itl);
			itl++;
		}
		else if (itl == lq.end()) {
			res.push_back(*itr);
			itr++;
		}
		else if (*itr > *itl) {
			res.push_back(*itl);
			itl++;
		}
		else {
			res.push_back(*itr);
			itr++;
		}
	}
	return res;
}

std::list<int> PmergeMe::mergeInsertSort(std::list<int> &list) {
	std::list<int>::iterator	it = list.begin();

	if (list.size() <= 10)
		return insert(list);
	std::advance(it, list.size() / 2);
	std::list<int> ll(list.begin(), it);
	std::list<int> rl(it, list.end());

	ll = mergeInsertSort(ll);
	rl = mergeInsertSort(rl);
	return merge(ll, rl);
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> &dq) {
	std::deque<int>::iterator	it = dq.begin();
	if (dq.size() <= 10)
		return insert(dq);
	std::advance(it, dq.size() / 2);
	std::deque<int> lq(dq.begin(), it);
	std::deque<int> rq(it, dq.end());

	lq = mergeInsertSort(lq);
	rq = mergeInsertSort(rq);
	return merge(lq, rq);
}

void PmergeMe::print() {
	std::deque<int>				temp(dq.begin(), dq.end());
	clock_t						start, end;

	std::cout << "Before :";
	for (int i = 0; i < (int)dq.size(); i++)
		std::cout << " " << dq[i];
	sort(temp.begin(), temp.end());

	std::cout << "\nAfter :";
	for (int i = 0; i < (int)temp.size(); i++)
		std::cout << " " << temp[i];
	std::cout << "\n";
	
	start = clock();
	list = mergeInsertSort(list);
	end = clock();

	std::cout << list.size() << " elements with list " << end - start << "ms\n";

	start = clock();
	dq = mergeInsertSort(dq);
	end = clock();

	std::cout << dq.size() << " elements with deque " << end - start << "ms\n";
}

void PmergeMe::listPrint() {
	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
}

void PmergeMe::dqPrint() {
	for (int i = 0; i < (int)dq.size(); i++)
		std::cout << dq[i] << " ";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::list<int> PmergeMe::getList() const {
	return this->list;
}

std::deque<int> PmergeMe::getDeque() const {
	return this->dq;
}

/* ************************************************************************** */
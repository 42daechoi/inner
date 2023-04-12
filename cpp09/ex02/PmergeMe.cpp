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
		vec.push_back(n);
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
		this->vec = rhs.getVector();
		this->dq = rhs.getDeque();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::vector<int> PmergeMe::insert(std::vector<int> &vec) {
	for (int i = 1; i < (int)vec.size(); i++) {
		int temp = vec[i]; 
		int j = i;
		while (j > 0 && vec[j - 1] > temp) {
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = temp;
	}
	return vec;
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

std::vector<int> PmergeMe::merge(std::vector<int> &lv, std::vector<int> &rv) {
	std::vector<int>	res;
	int					lidx = 0, ridx = 0;

	for (int i = 0; i < (int)vec.size(); i++) {
		if (ridx == (int)rv.size()) {
			res.push_back(lv[lidx]);
			lidx++;
		}
		else if (lidx == (int)lv.size()) {
			res.push_back(rv[ridx]);
			ridx++;
		}
		else if (rv[ridx] > lv[lidx]) {
			res.push_back(lv[lidx]);
			lidx++;
		}
		else {
			res.push_back(rv[ridx]);
			ridx++;
		}
	}
	return res;
}

std::deque<int> PmergeMe::merge(std::deque<int> &lq, std::deque<int> &rq) {
	std::deque<int>	res;
	int				lidx = 0, ridx = 0;

	for (int i = 0; i < (int)dq.size(); i++) {
		if (ridx == (int)rq.size()) {
			res.push_back(lq[lidx]);
			lidx++;
		}
		else if (lidx == (int)lq.size()) {
			res.push_back(rq[ridx]);
			ridx++;
		}
		else if (rq[ridx] > lq[lidx]) {
			res.push_back(lq[lidx]);
			lidx++;
		}
		else {
			res.push_back(rq[ridx]);
			ridx++;
		}
	}
	return res;
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> &vec) {
	if (vec.size() <= 5)
		return insert(vec);
	std::vector<int> lv(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> rv(vec.begin() + vec.size() / 2, vec.end());

	lv = mergeInsertSort(lv);
	rv = mergeInsertSort(rv);
	return merge(lv, rv);
}

std::deque<int> PmergeMe::mergeInsertSort(std::deque<int> &dq) {
	if (dq.size() <= 5)
		return insert(dq);
	std::deque<int> lq(dq.begin(), dq.begin() + dq.size() / 2);
	std::deque<int> rq(dq.begin() + dq.size() / 2, dq.end());

	lq = mergeInsertSort(lq);
	rq = mergeInsertSort(rq);
	return merge(lq, rq);
}

void PmergeMe::print() {
	std::vector<int>	temp(vec.begin(), vec.end());
	clock_t				start, end;

	std::cout << "Before :";
	for (int i = 0; i < (int)vec.size(); i++) 
		std::cout << " " << vec[i];
	sort(temp.begin(), temp.end());

	std::cout << "\nAfter :";
	for (int i = 0; i < (int)temp.size(); i++) 
		std::cout << " " << temp[i];
	std::cout << "\n";
	
	start = clock();
	vec = mergeInsertSort(vec);
	end = clock();

	std::cout << vec.size() << " elements with vector " << end - start << "ms\n";

	start = clock();
	dq = mergeInsertSort(dq);
	end = clock();

	std::cout << dq.size() << " elements with deque " << end - start << "ms\n";
}

void PmergeMe::vecPrint() {
	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << " ";
}

void PmergeMe::dqPrint() {
	for (int i = 0; i < (int)dq.size(); i++)
		std::cout << dq[i] << " ";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int> PmergeMe::getVector() const {
	return this->vec;
}

std::deque<int> PmergeMe::getDeque() const {
	return this->dq;
}

/* ************************************************************************** */
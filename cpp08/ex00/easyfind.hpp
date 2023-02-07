#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>

typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator ret = std::find(container.begin(), container.end(), n);
	return (ret);
}

#endif
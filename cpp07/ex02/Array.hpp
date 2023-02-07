#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>

class Array
{

	public:

		Array() {
			arr = new T[0];
			this->n = 0;
		}
		Array(unsigned int n) {
			arr = new T[n];
			this->n = n;
		}
		Array( Array const & src ) {
			*this = src;
		}
		~Array() {
			delete [] arr;
		}

		T &operator[](unsigned int idx) {
			if (idx < 0 || idx >= n)
				throw std::out_of_range("Wrong index.");
			else
				return (arr[idx]);
		}

		Array &		operator=( Array const & rhs ) {
			if (this != &rhs) {
				this->arr = new T[n];
				this->n = rhs.n;
				for (unsigned int i = 0; i < n; i++)
					this->arr[i] = rhs.arr[i];
			}
			return (*this);
		}

		void size(void) {
			return (n);
		}

	private:
		T *arr;
		unsigned int n;
};

#endif /* *********************************************************** ARRAY_H */
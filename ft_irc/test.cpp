# include <iostream>
# include <vector>
# include <string>
class A {
	public:
		void setArr() { 
			arr.push_back("1");
			arr.push_back("2");
			arr.push_back("3");
		}
		std::vector<std::string> getArr() { return arr; };
	private:
		std::vector<std::string> arr;
};

void fix(std::vector<std::string> &arr) {
	arr.erase(arr.begin() + 2);
}

int main() {
	A a;
	a.setArr();
	fix(a.getArr());
	std::cout << a.getArr()[0] << std::endl;
	std::cout << a.getArr()[1] << std::endl;
	std::cout << a.getArr()[2] << std::endl;
}
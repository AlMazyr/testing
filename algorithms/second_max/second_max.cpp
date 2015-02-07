#include <iostream>
#include <vector>
#include <utility>

template<class T> 
std::pair<T,T> find_two_max(const std::vector<T> &arr) {
	std::pair<T, T> maxs(0, 0);
	for(const auto i : arr) {
		if(i > maxs.first){
			maxs.second = maxs.first;
		   	maxs.first = i;
		}
		else if(i > maxs.second) maxs.second = i;
	}
	return maxs;
}


int main(int argc, char *argv[]) {
	std::vector<int> arr = {10, 11, 2, 4, 54, 2, 0};
	std::pair<int, int> answ = find_two_max(arr);
	
	std::cout << "The first max = " << answ.first << ", second max = " << answ.second << std::endl;	

	return 0;
}

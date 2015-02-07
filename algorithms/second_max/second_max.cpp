#include <iostream>
#include <vector>
#include <utility>

template<class T> 
std::pair<std::pair<T, int>, std::pair<T, int> > find_two_max(const std::vector<T> &arr) {
	std::pair<std::pair<T, int>, std::pair<T, int> > maxs(std::make_pair(0, 0), std::make_pair(0, 0));
	for(const auto i : arr) {
		if(i > maxs.first.first){
			maxs.second.first = maxs.first.first;
		   	maxs.first.first = i;
			maxs.second.second = maxs.first.second;
			maxs.first.second = 1;
		} else if(i == maxs.first.first) {
			maxs.first.second++;
		} else if(i > maxs.second.first) { 
			maxs.second.first = i;
			maxs.second.second = 1;
		} else if(i == maxs.second.first) {
			maxs.second.second++;
		}
	}
	return maxs;
}


int main(int argc, char *argv[]) {
	std::vector<int> arr = {10, 11, 2, 11, 4, 54, 2, 54, 5, 7, 54, 54};
	std::pair<std::pair<int, int>, std::pair<int, int> > answ = find_two_max(arr);
	
	std::cout << "First max = " << answ.first.first << ", count =  "<< answ.first.second << std::endl;
	std::cout << "Second max = " << answ.second.first << ", count = "<< answ.second.second << std::endl;	

	return 0;
}

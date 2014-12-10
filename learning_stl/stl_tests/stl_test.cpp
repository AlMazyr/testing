#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
   
    vector<int> test;
    vector<int>::iterator it;

    // entering the numbers into vector.
    cout << "Please input count of numbers:\n";
    int n, value;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cout << "Please input " << i << " number: ";
        cin >> value;
        test.push_back(value);
    }
    
    // Search for the minimum.
    it = min_element(test.begin(), test.end());
    cout << "min: " << *it << endl;

    // Search for the maximum.
    it = max_element(test.begin(), test.end());
    cout << "max: " << *it << endl;

    // Sorting.
    sort(test.begin(), test.end());

    // Searching 3.
    it = find(test.begin(), test.end(), 3);

    // reverse of all elements from 3 to end.
    reverse(it, test.end());

    // printing all elements.
    for (it = test.begin(); it != test.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;



    return 0;
}

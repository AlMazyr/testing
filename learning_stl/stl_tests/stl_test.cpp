#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
   
    // vector 
    vector<int> v;

    for(int i = 0; i < 5; ++i) {
        v.push_back(i);
    }

    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;


    // deque
    deque<int> d;
    for(int i = 0; i < 10; ++i) {
        d.push_back(i);
        d.push_front(10 - i);
    }

    for(int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
    

    //queue
    queue<int> q;
    for(int i = 0; i < 10; ++i) {
        q.push(i);
    }

    for(int i = 0; i < q.size(); ++i) {
        cout << q.front() << " " << q.back() << " ";
        q.pop();
    }
    cout << endl;

    // stack
    stack<int> s;
    for(int i = 0; i < 6; ++i) {
        cout << "Push " << i << " to stack.\n";
        s.push(i);
    }

    for(int i = 0; i < s.size(); ++i) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

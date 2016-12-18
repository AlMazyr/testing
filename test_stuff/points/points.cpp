#include <iostream>
#include <map>
#include <string>
#include <cmath>

#include "points.h"

using namespace std;

class Point {
	int x;
	int y;
	int Balls() {
		return 0;
	}
};

int foo(Point p_current) {
	return p_current.y * p_current.y;
}

int main(int argc, char *argv[]) {

	int count_2 = 0;
	Point p_current;
	map<int, Point> points_arr;
	int vector_len = 0;

	cin >> count_2;

	for(int i = 0; i < count_2; ++i) {
		cin >> p_current.x;
		cin >> p_current.y;
		int sq = p_current.x * p_current.x;
		vector_len = sqrt((sq) + (foo(p_current)));
		points_arr[vector_len] = p_current;
	}

	for(map<int, Point>::iterator it = points_arr.begin(); it != points_arr.end(); ++it) {
		cout << it->second.x << ' ' << it->second.y << '\n';
	}

	return 0;
}

// KMP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i<n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
	string s, t;

	s = "ababababababbbbbabbbababaa";
	t = "baba";
	//cin >> s1 >> t;

	vector<int> pi = prefix_function(t + '#' + s);

	int t_len = t.length();

	for (int i = 0; i < s.length(); i++) {
		if (pi[t_len + 1 + i] == t_len) {
			cout << "s[" << i - t_len + 1 << ".." << i << "] = t" << endl;
		}
	}
	system("pause");
}



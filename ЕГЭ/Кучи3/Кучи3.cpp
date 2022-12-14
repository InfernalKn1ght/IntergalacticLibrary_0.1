#include <iostream>
#include <vector>
#include <map>
using namespace std;
void print(vector <pair<int, int>> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << "    ";
}
void print1(vector <bool> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
vector <pair <int, int>> create_moves(pair <int, int> values) {
	vector <pair <int, int>> v;
	v.push_back(make_pair(values.first+1, values.second));
	v.push_back(make_pair(values.first*2, values.second));
	v.push_back(make_pair(values.first, values.second+1));
	v.push_back(make_pair(values.first, values.second * 3));
	return v;
}
vector <pair<int, int>>game(vector <pair<int, int>> moves) {
	vector <pair<int, int>> v;
	for (int i = 0; i < moves.size(); i++) {
		vector <pair <int, int>> buf = create_moves(moves[i]);
		for (int j = 0; j < buf.size(); j++) {
			v.push_back(buf[j]);
		}
	}
	return v;
}
vector <bool> conditions(vector<pair <int, int>> moves, int value) {
	vector <bool> v;
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i].first + moves[i].second >= value) v.push_back(1);
		else v.push_back(0);
	}
	return v;
}
vector <bool> logic(vector <bool> wins) {
	bool l = 0;
	vector <bool> v;
	for (int i = 0; i < wins.size(); i++) {
		l = l || wins[i];
		if ((i + 1) % 4 == 0) v.push_back(l), l = 0;
	}
	return v;
}
vector <bool> logic1(vector <bool> wins) {
	bool l = 1;
	vector <bool> v;
	for (int i = 0; i < wins.size(); i++) {
		l = l && wins[i];
		if ((i + 1) % 4 == 0) v.push_back(l), l = 1;
	}
	return v;
}
int main()
{
	int S1 = 16;
	int value = 84;
	for (int i = 1; i <= 67; i++) {
		vector <pair<int, int>> start = { make_pair(S1, i) };
		vector <pair<int, int>> P1;
		vector <pair<int, int>> B1;
		vector <pair<int, int>> P2;
		vector <pair<int, int>> B2;
		P1 = game(start);
		int k = 0;
		while (k < P1.size()) {
			vector <pair<int, int>> buf = { P1[k] };
			if (logic(conditions(game(buf), value))[0] == 1) {
				P1.erase(P1.begin() + k);
			}
			else k++;
		}
		P2 = game(game(P1));
		cout << i << ": ";
		print1((logic1(logic(conditions(P2, value)))));
		cout << endl << endl;
	}
}
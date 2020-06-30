/* authors:
 152120151005 - Yusuf Furkan Yücesoy
 */
 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<stack>
using namespace std;

// Grid uzerinde stringlerin yerlesebilecegi hucrelerin kontrolunu yapan fonksiyon
bool placeString(vector<string>& grid, const string& l) {
	int len = l.length();
	
	// yatay hucrelerin kontrolu
	bool placed = false; 
	for (int i = 0; i < 10; i++) {		//her bir satirin kontrolu
		if (placed)
			break;
		else
			placed = true;

		for (int j = 0; j <= (10 - len); j++) {	// her bir satirdaki uygun hucrelerin (eksilerin) kontrolu
			placed = true;

			for (int k = j; k < (len + j); k++) {
				if (grid[i][k] == '+') {
					placed = false;		// dolu hucre (uygun olmayan hucre), break
					break;
				} else if (grid[i][k] == '-') {
					// uygun hucre, continue
				} else if (l[k - j] != grid[i][k]) {
					placed = false;		// uygun olmayan hucre, break
					break;
				}
			}

			if (placed) {					// yatayda kelime uzunlugu kadar hucre uygunsa kelimeyi uygun hucrelere yaz
				for (int k = j; k < (len + j); k++)
					grid[i][k] = l[k - j];
				break;
			}
		}
	}
// dikey hucrelerin kontrolu
	if (!placed) {
		for (int i = 0; i < 10; i++) {		// her bir sutunun kontrolu
			if (placed)
				break;
			else
				placed = true;

			for (int j = 0; j <= (10 - len); j++) {	// her bir sutundaki uygun hucrelerin (eksilerin) kontrolu

				placed = true;
				for (int k = j; k < (len + j); k++) {

					if (grid[k][i] == '+') {
						placed = false;	// dolu hucre (uygun olmayan hucre), break
						break;
					} else if (grid[k][i] == '-') {
						// uygun hucre, continue
					} else if (l[k - j] != grid[k][i]) {
						placed = false;	// uygun olmayan hucre, break
						break;
					}
				}

				if (placed) {				// dikeyde kelime uzunlugu kadar hucre uygunsa kelimeyi uygun hucrelere yaz
					for (int k = j; k < (len + j); k++)
						grid[k][i] = l[k - j];
					break;
				}
			}
		}
	}
	return placed; //kelime yerlestirilebiliyorsa true; yerlestirilemiyorsa false 
}

// verilen sira ile kelimeleri uygun yerlere yerlestirmeyi dener
vector<string> finishGrid(vector<string> grid, vector<string> placesNames) {
	vector<string> completedGrid;
	int len = placesNames.size();

	bool success = true;
	for (int i = 0; i < len; i++) {
		string l = placesNames[i];

		if (!placeString(grid, l)) { //eger kelime yerlestirilemiyorsa basarısız, break
			success = false;
			completedGrid.push_back(" ");
			break;
		}
	}
	if (success) //eger kelime yerlestirilebiliyorsa basarılı grid, completedGrid'e eklenir
		completedGrid = grid;
	return completedGrid;
}

int main() {

	vector<string> grid;
	string s;

	for (int i = 0; i < 10; i++) { // bulmaca haritasındaki artı ve eksiler alınır
		cin >> s;
		grid.push_back(s);
	}

	cin >> s;
	vector<string> placesNames;

	int len = s.length();
	int start = 0;
	
	//kelimeler (;) ile ayrılır, vektore eklenir
	for (int i = 0; i < len; i++) { 
		if (s[i] == ';') {
			string temp(s.begin() + start, s.begin() + i);
			placesNames.push_back(temp); 
			start = i + 1;
		}
	}

	string temp(s.begin() + start, s.end());
	placesNames.push_back(temp);

	sort(placesNames.begin(), placesNames.end());
	vector<string> finishedGrid;

	do {

		finishedGrid = finishGrid(grid, placesNames);

		if (finishedGrid[0] != " ")
			break;
	} while (next_permutation(placesNames.begin(), placesNames.end())); // kelimelerin siralamalarinin tüm permutasyonlari denenir


	for (int i = 0; i < 10; i++)
		cout << finishedGrid[i] << endl;
}

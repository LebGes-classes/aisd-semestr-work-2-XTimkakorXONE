#include "patienceSort.hpp"

using namespace std;

void patientSort(vector<int>& array) {
    vector<int> result;
    vector<vector<int>> piles;
    for (int i = 0; i < array.size(); ++i) {
        if (piles.empty()) {
            vector<int> temp;
            temp.push_back(array[i]);
            piles.push_back(temp);
        }
        else {
            int flag = 1;
             for (int j = 0; j < piles.size(); ++j) {
                if (array[i] < piles[j][piles[j].size()-1]) {
                    piles[j].push_back(array[i]);
                    flag = 0;
                    break;
                }
             }
             if (flag) {
                vector<int> temp;
                temp.push_back(array[i]);
                piles.push_back(temp);
             }
        }
    }
    while (1) {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < piles.size(); ++i) {
            if (piles[i][piles[i].size() - 1 ] < min ) {
                min = piles[i][piles[i].size() - 1];
                index = i;
            }
        }
        result.push_back(min);
        piles[index].pop_back();
        if (piles[index].empty()) {
            piles.erase(piles.begin() + index);
        }
        if (piles.size() == 0) break;
    }
    
    array = result;
}

int main() {
    vector<int> array = {7, 4, 2, 6, 3, 2, 6, 1};
    patientSort(array);
    for (int x : array) {
        cout << x << " ";
    }
}



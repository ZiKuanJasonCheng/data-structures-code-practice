# include <iostream>
using namespace std;

/*
    Given a set of denominations and an amount, find out number of least notes to be exchanged
*/

int num_least_notes(int N) {
    int arr_denomination[] = {1, 3, 4};  // Set of denominations. Denomination 1 must exists or otherwise the following method does not work
    int M = 3;  // Number of denominations
    if (N == 0) {
        return 0;
    }
    else if (N == 1) {
        return 1;
    }
    // arr_money[i] stores least number of notes for amount i
    int arr_money[N+1];  // Space from 0 to N

    arr_money[0] = 0;
    arr_money[1] = 1;

    for (int i=2; i<N+1; i++) {
        int cur_min_num = i;  // In this case, we have to make sure there is a denomination of 1
        for (int j=0; j<M; j++) {
            if (i >= arr_denomination[j]) {
                cur_min_num = min(cur_min_num, arr_money[i - arr_denomination[j]] + 1);
            }
        }
        arr_money[i] = cur_min_num;
    }
    return arr_money[N];
}


int main() {
    int N = 0;
    cout << "Enter the amount of money you want to exchange: ";
    do {
        cin >> N;
    }
    while (N < 0);

    int result = num_least_notes(N);
    cout << result << endl;
}
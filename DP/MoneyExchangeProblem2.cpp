# include <iostream>
# include <vector>
using namespace std;

/*
    Given a set of denominations and an amount, find out number of least notes to be exchanged, 
    as well as its combination of denominations
*/


int sum(int arr[], int size) {
    int result = 0;
    for (int i=0; i<size; i++) {
        result += arr[i];
    }
    return result;
}

void list_least_notes(int N) {
    int arr_denomination[] = {1, 3, 4};  // Set of denominations. Denomination 1 must exists or otherwise the following method does not work
    int M = 3;  // Number of denominations
    if (N == 0) {
        cout << "No bill to exchange!" << endl;
    }

    // arr_money[i] stores a set of least number of notes for amount i
    // arr_money[i][j] stores number of domonination j for the set of least number of notes for amount i
    /*  0    1    2    3    4        5         ... N
        0    1x1  1x2  3x1  4x1      4x1,1x1   ... 
    */

    int arr_set[N+1][M];
    memset(arr_set[0], 0, sizeof(arr_set[0]));
    memset(arr_set[1], 0, sizeof(arr_set[1]));
    arr_set[1][0] = 1;

    int cur_min_num;
    int min_deno;
    int num;

    for (int i=2; i<N+1; i++) {
        memset(arr_set[i], 0, sizeof(arr_set[i]));  // Initialize each element of arr_set[i] to be 0
        cur_min_num = i;  // In this case, we have to make sure there is a denomination of 1
        min_deno = 0;
        for (int j=0; j<M; j++) {
            if (i >= arr_denomination[j]) {
                num = sum(arr_set[i - arr_denomination[j]], M) + 1;
                if (num < cur_min_num) {
                    cur_min_num = num;
                    min_deno = j;
                }
            }
        }
        for (int k=0; k<M; k++) {
            arr_set[i][k] = arr_set[i - arr_denomination[min_deno]][k];
        }
        arr_set[i][min_deno]++;
    }

    // Print the final results
    cout << "Number of notes: " << sum(arr_set[N], M) << endl;
    for (int j=0; j<M; j++) {
        cout << "Number of " << arr_denomination[j] << ": " << arr_set[N][j] << endl;
    }
}


int main() {
    int N = 0;
    cout << "Enter the amount of money you want to exchange: ";
    do {
        cin >> N;
    }
    while (N < 0);
    list_least_notes(N);
}
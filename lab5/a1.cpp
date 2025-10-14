#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int k) {
    int smallest = k;
    int l = 2 * k + 1;
    int r = 2 * k + 2;

    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }

    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if (smallest != k) {
        swap(arr[k], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void build_heap(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
}

int extract_min(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return -1;

    int root = arr[0];
    arr[0] = arr[n - 1];
    arr.pop_back();
    heapify(arr, arr.size(), 0);
    return root;
}

void insert_heap(vector<int>& arr, int val) {
    arr.push_back(val);
    int i = arr.size() - 1;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    build_heap(arr, arr.size());

    long long total_cost = 0;

    while (arr.size() > 1) {
        int min1 = extract_min(arr);
        int min2 = extract_min(arr);
        int new_val = min1 + min2;
        total_cost += new_val;
        insert_heap(arr, new_val);
    }

    cout << total_cost << endl;

    return 0;
}

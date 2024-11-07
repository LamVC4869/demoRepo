#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void bubbleSort (int arr[], int n);
void InsertionSort (int arr[], int n);
void selectionSort (int arr[], int n);
void shellSort (int arr[], int n);
void merge (int arr[], int left, int middle, int right);
void mergeSort (int arr[], int left, int right);
void Lomuto_quickSort (int arr[], int left, int right);
void Hoare_quickSort (int arr[], int left, int right);
int LomutoPartition (int arr[], int left, int right);
int HoarePartition (int arr[], int left, int right);
void printArray (int arr[], int n);

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    srand(time(0));
    int a[n], b[n], c[n], d[n], e[n], f[n], g[n];
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
        c[i] = rand() % 100;
        d[i] = rand() % 100;
        e[i] = rand() % 100;
        f[i] = rand() % 100;
        g[i] = rand() % 100;
    }
    cout << "Array A: ";
    printArray(a, n);
    bubbleSort(a, n);
    cout << "Bubble Sort A: ";
    printArray(a, n);
    cout << '\n';
    cout << "Array B: ";
    printArray(b, n);
    InsertionSort(b, n);
    cout << "Insertion Sort B: ";
    printArray(b, n);
    cout << '\n';
    cout << "Array C: ";
    printArray(c, n);
    selectionSort(c, n);
    cout << "Selection Sort C: ";
    printArray(c, n);
    cout << '\n';
    cout << "Array D: ";
    printArray(d, n);
    shellSort(d, n);
    cout << "Shell Sort D: ";
    printArray(d, n);
    cout << '\n';
    cout << "Array E: ";
    printArray(e, n);
    mergeSort(e, 0, n - 1);
    cout << "Merge Sort E: ";
    printArray(e, n);
    cout << '\n';
    cout << "Array F: ";
    printArray(f, n);
    Lomuto_quickSort(f, 0, n - 1);
    cout << "Lomuto Quick Sort F: ";
    printArray(f, n);
    cout << '\n';
    cout << "Array G: ";
    printArray(g, n);
    Hoare_quickSort(g, 0, n - 1);
    cout << "Hoare Quick Sort G: ";
    printArray(g, n);
    cout << '\n';
    return 0;
}

void bubbleSort (int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = true;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                swapped = false;
                swap(arr[i], arr[j]);
            }
        }
        if (swapped) break;
    }
}

void InsertionSort (int arr[], int n) {
    int key, value;
    for (int i = 1; i < n; ++i) {
        key = i;
        value = arr[i];
        while (key > 0 && arr[key - 1] > value) {
            arr[key] = arr[key - 1];
            --key;
        }
        arr[key] = value;
    }
}

void selectionSort (int arr[], int n) {
    int indexMin = 0;
    for (int i = 0; i < n - 1; ++i) {
        indexMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[indexMin] > arr[j]) {
                indexMin = j;
            }
        }
        if (i != indexMin) swap(arr[i], arr[indexMin]);
    }
}

void shellSort (int arr[], int n) {
    for (int interval = n/2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

void merge (int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[middle + i + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort (int arr[], int left, int right) {
    if (left >= right) return;
    int middle = (left + right)/2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void Lomuto_quickSort (int arr[], int left, int right) {
    if (left < right) {
        int p = LomutoPartition(arr, left, right);
        Lomuto_quickSort(arr, left, p - 1);
        Lomuto_quickSort(arr, p + 1, right);
    }
}

void Hoare_quickSort (int arr[], int left, int right) {
    if (left < right) {
        int p = HoarePartition(arr, left, right);
        Hoare_quickSort(arr, left, p);
        Hoare_quickSort(arr, p + 1, right);
    }
}

int LomutoPartition (int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int HoarePartition (int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left - 1, j = right + 1;
    while (true) {
        do { --j; } while (arr[j] > pivot);
        do { ++i; } while (arr[i] < pivot);
        if (i < j) swap(arr[i], arr[j]);
        else return j;
    }
}

void printArray (int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
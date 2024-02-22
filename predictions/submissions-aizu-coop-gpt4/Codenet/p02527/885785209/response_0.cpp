#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int arr[1000010];

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
void quickSortIterative(int arr[], int l, int h)
{
    int stack[h - l + 1];
  
    int top = -1;
  
    stack[++top] = l;
    stack[++top] = h;
  
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
  
        int p = partition(arr, l, h);
  
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSortIterative(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    return 0;
}
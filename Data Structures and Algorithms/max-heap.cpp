// http://quiz.geeksforgeeks.org/heap-sort/
// used it as reference, may not be exactly the same
#include <iostream>
using namespace std;

void heapify(int arr[], int sizeofarray, int i)
{
    int largest = i;
    int left = 2 * i + 1; // left is the index and so is i
    int right = 2 * i + 2;

    if (left < sizeofarray && arr[left] > arr[largest])
        largest = left;

    if (right < sizeofarray && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, sizeofarray, largest);

    }

}

int main()
{
    int heap[15] = {12, 2, 4, 5, 6, 7, 10, 72, 1, 4, 32, 3, 2, 1, 7};

    for (int i = 0; i < 15; i++)
        cout << heap[i] << "  ";

    cout << endl;

    for (int i = 15/2 - 1; i > -1; i--)
        heapify(heap, 15, i);

    for (int i = 0; i < 15; i++)
        cout << heap[i] << "  ";

    cout << "\nAscending Order :\n";

    for (int i = 14, temp = 0; i > -1; i--)
    {
        cout << heap[0] << "  ";
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        heapify(heap, i, 0);

    }
    return 0;
}

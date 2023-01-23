/*
194. Code : In-place heap sort: Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
*/

void heapSort(int arr[], int n) {
    
//Placing element in heap in-place
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    //Removing element from heap inplace(Actually we remove element and place it at the end)
    int size = n;
    while (size > 1)
    {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (arr[minIndex] > arr[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && arr[minIndex] > arr[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            parentIndex = minIndex;

            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}
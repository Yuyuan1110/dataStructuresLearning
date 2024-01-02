#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    cout << "\nElement are" << endl;
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << endl;
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index > 0 && index <= arr->length)
        ;
    for (i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
}

void Delete(struct Array *arr, int x)
{
    int i;
    if (x >= 0 && x <= arr->length)
    {
        for (i = x; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

int RBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return RBinarySearch(a, l, mid - 1, key);
        }
        else
        {
            return RBinarySearch(a, mid + 1, h, key);
        }
    }
}

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Reserve(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {

            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
}

int LinearSearch(struct Array arr, int x)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == x)
        {
            return i;
        }
    }
    return -1;
}

struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = new struct Array;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    // struct Array arr = {{2, 3, 4, 5, 7}, 10, 5};
    // Append(&arr, 10);
    // Delete(&arr, 0);
    // Reserve(&arr);
    struct Array arr1 = {{1,3,5,7,9},10,5};
    struct Array arr2 = {{0,2,4,6,8},10,5};
    struct Array *arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
    // int a = linearSearch(arr, 3);
    // int a = binarySearch(arr, 7);
    // cout << a << endl;
    return 0;
}
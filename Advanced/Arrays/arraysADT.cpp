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

void Insert(struct Array *arr, int index,int x){
    int i;
    if(index > 0 && index <= arr->length);
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
}

void Delete(struct Array *arr, int x){
    int i;
    if(x >= 0 && x <= arr->length){
        for(i = x; i < arr->length; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}
int main()
{
    struct Array arr = {{2, 3, 4}, 10, 3};
    Append(&arr, 10);
    Delete(&arr, 0);
    Display(arr);
    return 0;
}
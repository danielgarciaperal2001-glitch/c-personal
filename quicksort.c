#include <stdio.h>

int pivoting(int data[], int low, int high){
    int pivot = data[high];
    int i = low - 1;

    for(int j = low; j<high; ++j) {
        if(data[j] <= pivot){
            ++i;
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    int tmp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = tmp;

    return i + 1;
}

void quick_sort(int data[], int low, int high){
    if (low < high){
        int pivot = pivoting(data, low, high);
        quick_sort(data, low, pivot - 1);
        quick_sort(data, pivot + 1, high);
    }
}

int main(){
    int data[] = {25,32,10,7,6,98,34,100,289,4,128,3};
    int ndata = sizeof(data) / sizeof(data[0]);

    quick_sort(data, 0, ndata - 1);
    for (int i = 0; i < ndata; ++i){
        printf("%d ", data[i]);
    }
    return 0;
}

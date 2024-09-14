#include<stdio.h>
void updateArray(int *arr, int n){
  for(int i=0; i<n; i++){
    arr[i] = arr[i] + 10;
  }
  printf("The elements of the array after calling the function are: \n");
    for(int i=0; i<5; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[5] = {1,2,3,4,5};
    printf("The elements of the array before calling the function are: \n");
    for(int i=0; i<5; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    // call the function
    updateArray(arr, 5);
    // Print the array elements in the calling function
    printf("Array elements in the calling function:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

#include <iostream>
using namespace std;
 
// Fusiona dos subarreglos de arr [].
// El primer subarreglo es arr [l..m]
// El segundo subarreglo es arr [m + 1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Crear matrices temporales
    int L[n1], R[n2];
 
    // Copiar datos en matrices temporales L [] y R []
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Fusionar las matrices temporales de nuevo en arr [l..r]
 
    // Índice inicial del primer subarreglo
    int i = 0;
 
    // Índice inicial del segundo subarreglo
    int j = 0;
 
    // Índice inicial de subarreglo combinado
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copie los elementos restantes de L [], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copie los elementos restantes de R [], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l es para el índice izquierdo y r es índice derecho de la submatriz de arr a ordenar 
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    //Cada dato esta solo, solin, solito
    merge(arr,l,m,r);
}
 

// Impresion de números
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
// Inicio del código
int main()
{
	//la funcion sizeof nos da la cantidad de bytes de cada tipo de dato
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "El arreglo de numeros es: \n";
    
    printArray(arr, arr_size);
    
    mergeSort(arr, 0, arr_size - 1);
    
    cout << "\nArreglo ordenado \n";
    printArray(arr, arr_size);
    return 0;
}


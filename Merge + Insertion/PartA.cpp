/*Merge sort without use of insertion sort*/

#include "MergeSort.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
	ifstream fin;
	ofstream fout;
	fin.open("data1.txt");
	fout.open("out1.txt");
	string line;
	int linNum;
	while(getline(fin, line)){
		double arr[500];
		int arrSize = 0;
		stringstream separator(line);
		double temp;
		linNum++;
		
		while(separator>>temp){
			arr[arrSize++] = temp;	
		}
		
		mergeSort(arr, 0, arrSize-1);
		printf("Sorted line number %i: ", linNum);
		for(int i = 0; i < arrSize; i++){
			fout << fixed;
			fout.precision(2);
			fout << arr[i] << " "; 
			printf("%.2f ", arr[i]);
		}
		fout << endl;
		cout << endl;
	}
	fout.close();
	fin.close();
	
	
	
}


void merge(double *arr, int l, int m, int h) 
{ 
    int i, j, k;
	double t[500];
	
    i = l; // Initial index of first subarray 
    k = l; // Initial index of second subarray 
    j = m+1; // Initial index of merged subarray 
    while (i <= m && j <= h) 
    { 
        if (arr[i] < arr[j]) 
        { 
            t[k] = arr[i];
            i++; 
			k++;
        } 
        else
        { 
            t[k] = arr[j]; 
            j++;
			k++;
        } 
    } 
  
    while (i <= m) 
    { 
        t[k] = arr[i]; 
        i++; 
        k++; 
    } 
  

    while (j <= h) 
    { 
        t[k] = arr[j]; 
        j++; 
        k++; 
    } 
	for(i = l; i < k; i++){
		arr[i] = t[i];
	}
} 
  

void mergeSort(double arr[], int l, int h) 
{ 
    if (l < h) 
    { 
	 
        int m = (l+h-1)/2; 
  
        // Sort first and second halves 
		
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, h); 
        merge(arr, l, m, h); 
    } 
} 

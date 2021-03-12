/*Merge sort without use of insertion sort*/

#include "HeapSort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
	ifstream fin;
	ofstream fout;
	fin.open("data3.txt");
	fout.open("output3.txt");
	string line;
	int linNum;
	while(getline(fin, line)){
		double arr[100];
		int arrSize = 0;
		stringstream separator(line);
		double temp;
		linNum++;
		
		while(separator>>temp){
			arr[arrSize++] = temp;	
		}
		
		heapSort(arr, arrSize);
		printf("Sorted line: ");
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

void heapSort(double arr[], int n) 
{ 
    for(int i = n/2-1; i >= 0; i--){
		heapify(arr, n, i);
	}
	for(int i = n-1; i >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
} 

void heapify(double arr[], int n, int i){
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;
	
	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i], arr[largest]);
		
		heapify(arr, n, largest);
	}
}

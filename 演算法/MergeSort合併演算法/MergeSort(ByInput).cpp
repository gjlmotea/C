#include <iostream>
#include <climits>
using namespace std;

void merge(int array[], int L, int M, int R){	//合併
	/*
	   合併:

	   __  VS  __
	   1       2
	   L       R
	   n1 = 1
	   n2 = 1

	   __ __  VS  __ __
	   1  2       3  4
	   L  M          R
	   n1 = 2
	   n2 = 2

	 */ 
	int n1 = M - L + 1;		//n1、n2: number of integer in List1 and List2
	int n2 = R - M;
	int* L1 = new int [n1 +2];
	int* L2 = new int [n2 +2];
	L1[0] = 0;
	L2[0] = 0;
	for(int i = 1; i <= n1; i++){
		L1[i] = array[L + i - 1];
	}
	for(int i = 1; i <= n2; i++){
		L2[i] = array[M + i];
	}
	L1[n1 + 1] = INT_MAX;
	L2[n2 + 1] = INT_MAX;

	int p1 = 1, p2 = 1;	 //p1、p2: pointer of L1 and L2
	for(int i = L; i <= R; i++){
		if(L1[p1] <= L2[p2]){
			array[i] = L1[p1];
			p1++;
		}else{
			array[i] = L2[p2];
			p2++;
		}
	}
	//delete[] L1, L2;
}

void merge_sort(int array[], int L, int R){	//切割 
	if(R > L){
		int M = (L + R) / 2;
		//cout << "M:" << M <<endl;
		merge_sort(array, L, M);		//從最左側到中間
		merge_sort(array, M + 1, R);		//從中間到最右側
		merge(array, L, M, R); 			//將左右的切割合併
	}

}

int main() {
	int input_size = 0;
	cin >> input_size;
	int array[input_size + 1] = {0};
	for(int i = 1; i <= input_size; i++){
		cin >> array[i];
	}

	// L:left、R:right、M:middle
	// 為符合merge sort pseudocode，陣列 index從1開始 
	// 如果input_size是10 => L = 1、R = 10

	int L = 1;
	int R = input_size;

	merge_sort(array, L, R);

	for(int i = 1; i < R+1; i++){
		cout<< i << ":\t " << array[i]<< endl;
	}
	return 0;
}

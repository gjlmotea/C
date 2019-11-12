#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L1 = new int [n1+1];
	int* L2 = new int [n2+1];
	L1[0] = 0;
	L2[0] = 0;
	for(int i = 1; i <= n1; i++){
		L1[i] = A[p + i - 1];
	}
	for(int i = 1; i <= n2; i++){
		L2[i] = A[q + i];
	}
	L1[n1+1] = 99999999;
	L2[n2+1] = 99999999;
	
	int p1 = 1, p2 = 1;
	for(int i = p; i <= r; i++){
		if(L1[p1] <= L2[p2]){
			A[i] = L1[p1];
			p1++;
		}else{
			A[i] = L2[p2];
			p2++;
		}
	}
	
}

void merge_sort(int A[], int p, int r){
	if(r > p){
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
	
}

int main() {
	int A[16] = {11, 3, 70, 66, 7771, 20, 123, 100, 650, 99, 446, 1200, 777, 502, 23, 102};	
	int p = 0;
	int r = sizeof(A) / sizeof(A[0]);
	
	merge_sort(A, p, r);
	
	for(int i = 1; i < r+1; i++){
		cout<< A[i]<< " ";
	}
	return 0;
}

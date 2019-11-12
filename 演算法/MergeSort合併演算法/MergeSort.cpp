#include <iostream>
#include <climits> 
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
	L1[n1+1] = INT_MAX;
	L2[n2+1] = INT_MAX;
	
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
	
	//delete[] L1, L2;
	
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
	// int A[16] = {11, 3, 70, 66, 7771, 20, 123, 100, 650, 99, 446, 1200, 777, 502, 23, 102};	
	int A[100] = {856,483,971,918,167,78,772,815,493,731,165,954,724,247,32,313,914,687,785,764,530,411,446,516,309,807,237,95,232,431,8,243,638,101,897,328,449,297,251,65,19,235,491,549,927,791,990,343,743,650,912,711,554,547,327,461,747,734,363,503,512,763,107,162,513,72,923,81,158,244,931,193,61,877,741,852,783,553,658,58,55,840,636,310,880,804,220,206,866,486,329,539,751,403,408,427,268,776,517,987};
	int p = 0;
	int r = sizeof(A) / sizeof(A[0]);
	
	merge_sort(A, p, r);
	
	for(int i = 1; i < r+1; i++){
		cout<< A[i]<< " ";
	}
	return 0;
}

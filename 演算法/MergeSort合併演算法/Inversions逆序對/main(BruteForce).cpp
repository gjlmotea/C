#include <iostream>
using namespace std;

int main(){
	int input_num = 0;
	cin >> input_num;
	int array[input_num] = {0};
	
	for(int i = 0; i < input_num; i++){
		cin >> array[i];
	}
	
	int inverse_count = 0;
	for(int i = 0; i < input_num; i++){
		for(int j = i; j < input_num; j++){
			if(array[i] > array[j])	inverse_count++;
		}
	}
	
	cout << inverse_count;
	return 0;
} 


/*
時間複雜度: n^2
*/

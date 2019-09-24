#include <iostream>
#include <stdio.h>
using namespace std;
int sub();
int add();
int c_test(int);

int c=10;
int sub(int var1){
	c=c+50;//對全域變數做運算 (全域變數int c(8行)宣告在 function sub之前)
	var1 = var1 - 50;
	//d=d-10;//出錯 因為int d(36行)宣告在function sub之後
	//雖然全域變數c已宣告(8行)，且先前也已在add funcion宣告區域變數c(40行)
	//但add function傳入的變數c作為var1 進入sub function，是命名為var1 而不是命名為c，所以在這個區塊中call c僅看的到全域變數c
	cout<<"sub function中的第一次變數c: "<<c<<endl;//全域變數c目前僅看的到全域變數c
	int c=20000;//仍然可在sub function這個區塊中宣告區域變數c
	cout<<"sub function中的第二次變數c: "<<c<<endl;//區域變數c在這個區塊中使用變數c的話，會優先使用這個區塊宣告的區域變數c
	return var1;
	cout<<"hi"<<endl;//return後面的程式碼不會被執行
}

int main(int argc, char** argv) {
	//程式會從這裡開始執行，隨後進入add function(38行)，再從add function進入sub function(9行) 並return var1給add function，
	//再從add function return d+1給主程式main
	int a = 5;//int a 為主程式main的區域變數
	int b = a+7;//int b 為主程式main的區域變數
	cout<<"main中的第一次變數c: "<<c<<endl;//在這個區塊僅看到全域變數c
	cout<<"main中的 add(): "<<add()<<endl;//輸出d+1 (48行) (d經36行，41行，47行執行)
	cout<<"main中的第二次變數c: "<<c<<endl;//在這個區塊僅看到全域變數c
	//cout<<e<<endl;//出錯 因為int e(56行)宣告在主程式main之後
	return 0;
}
int d=99;//全域變數(?)區域變數(?)非全域變數(?)可以宣告在這   效用不是全域，我不太清楚這要叫啥   
//d=d+1;不能在這個區塊執行變數操作
int add(){
	cout<<"add function中的第一次變數c:"<<c<<endl;//目前僅看的到全域變數c
	int c=30000;//雖然全域變數c已宣告(8行)，但仍然可在add function裡宣告區域變數c
	cout<<"add function中的第二次變數c: "<<c<<endl;//在這個區塊中使用變數c的話，會優先使用這個區塊宣告的區域變數c
	d = d+100;
	cout<<"add function中的 sub(c): "<<sub(c)<<endl;//把區域變數c(40行)帶入sub function(9行)做運算得到的return值var1
	c_test(c);//把區域變數c(40行)帶入c_test function(50行)做運算得到的return值c  並未賦值
	cout<<"add function中 經c_test(c)運算:"<<c<<endl;
	c = c_test(c);//把區域變數c(40行)帶入c_test function(50行)做運算得到的return值c  並且賦值給在此的區域變數c
	cout<<"add function中 經c_test(c)運算後並賦值:"<<c<<endl;
	return d+1;
}
int c_test(int c){
	cout<<"c_test function中的變數c: "<<c<<endl;//在這裡因為add function呼叫c_test並傳變數c進入作為c
	//這一步(50行)等於是在c_test中宣告區域變數c   "int c= add function的c"，   此c的位址和add function的c的位址並不相等
	c=c-500000; //僅在c_test的區域變數c做運算，並不影響到全域變數c以及其他function中的局部變數c
	return c;
}
int e=9999;

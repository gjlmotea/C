#include <iostream>
#include <stdio.h>
using namespace std;
int sub();
int add();
int c_test(int);

int c=10;
int sub(int var1){
	c=c+50;//������ܼư��B�� (�����ܼ�int c(8��)�ŧi�b function sub���e)
	var1 = var1 - 50;
	//d=d-10;//�X�� �]��int d(36��)�ŧi�bfunction sub����
	//���M�����ܼ�c�w�ŧi(8��)�A�B���e�]�w�badd funcion�ŧi�ϰ��ܼ�c(40��)
	//��add function�ǤJ���ܼ�c�@��var1 �i�Jsub function�A�O�R�W��var1 �Ӥ��O�R�W��c�A�ҥH�b�o�Ӱ϶���call c�Ȭݪ�������ܼ�c
	cout<<"sub function�����Ĥ@���ܼ�c: "<<c<<endl;//�����ܼ�c�ثe�Ȭݪ�������ܼ�c
	int c=20000;//���M�i�bsub function�o�Ӱ϶����ŧi�ϰ��ܼ�c
	cout<<"sub function�����ĤG���ܼ�c: "<<c<<endl;//�ϰ��ܼ�c�b�o�Ӱ϶����ϥ��ܼ�c���ܡA�|�u���ϥγo�Ӱ϶��ŧi���ϰ��ܼ�c
	return var1;
	cout<<"hi"<<endl;//return�᭱���{���X���|�Q����
}

int main(int argc, char** argv) {
	//�{���|�q�o�̶}�l����A�H��i�Jadd function(38��)�A�A�qadd function�i�Jsub function(9��) ��return var1��add function�A
	//�A�qadd function return d+1���D�{��main
	int a = 5;//int a ���D�{��main���ϰ��ܼ�
	int b = a+7;//int b ���D�{��main���ϰ��ܼ�
	cout<<"main�����Ĥ@���ܼ�c: "<<c<<endl;//�b�o�Ӱ϶��Ȭݨ�����ܼ�c
	cout<<"main���� add(): "<<add()<<endl;//��Xd+1 (48��) (d�g36��A41��A47�����)
	cout<<"main�����ĤG���ܼ�c: "<<c<<endl;//�b�o�Ӱ϶��Ȭݨ�����ܼ�c
	//cout<<e<<endl;//�X�� �]��int e(56��)�ŧi�b�D�{��main����
	return 0;
}
int d=99;//�����ܼ�(?)�ϰ��ܼ�(?)�D�����ܼ�(?)�i�H�ŧi�b�o   �ĥΤ��O����A�ڤ��ӲM���o�n�sԣ   
//d=d+1;����b�o�Ӱ϶������ܼƾާ@
int add(){
	cout<<"add function�����Ĥ@���ܼ�c:"<<c<<endl;//�ثe�Ȭݪ�������ܼ�c
	int c=30000;//���M�����ܼ�c�w�ŧi(8��)�A�����M�i�badd function�̫ŧi�ϰ��ܼ�c
	cout<<"add function�����ĤG���ܼ�c: "<<c<<endl;//�b�o�Ӱ϶����ϥ��ܼ�c���ܡA�|�u���ϥγo�Ӱ϶��ŧi���ϰ��ܼ�c
	d = d+100;
	cout<<"add function���� sub(c): "<<sub(c)<<endl;//��ϰ��ܼ�c(40��)�a�Jsub function(9��)���B��o�쪺return��var1
	c_test(c);//��ϰ��ܼ�c(40��)�a�Jc_test function(50��)���B��o�쪺return��c  �å����
	cout<<"add function�� �gc_test(c)�B��:"<<c<<endl;
	c = c_test(c);//��ϰ��ܼ�c(40��)�a�Jc_test function(50��)���B��o�쪺return��c  �åB��ȵ��b�����ϰ��ܼ�c
	cout<<"add function�� �gc_test(c)�B���ý��:"<<c<<endl;
	return d+1;
}
int c_test(int c){
	cout<<"c_test function�����ܼ�c: "<<c<<endl;//�b�o�̦]��add function�I�sc_test�ö��ܼ�c�i�J�@��c
	//�o�@�B(50��)����O�bc_test���ŧi�ϰ��ܼ�c   "int c= add function��c"�A   ��c����}�Madd function��c����}�ä��۵�
	c=c-500000; //�Ȧbc_test���ϰ��ܼ�c���B��A�ä��v�T������ܼ�c�H�Ψ�Lfunction���������ܼ�c
	return c;
}
int e=9999;

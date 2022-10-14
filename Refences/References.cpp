// Персональный шаблон
#include <iostream>
#include <cstdlib>
#include <ctime>
void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void p_swap(int *pn1, int *pn2) {
	int tmp = *pn1;
	*pn1 = *pn2;
	*pn2 = tmp;
}
void ref_swap(int &nref1, int &nref2) {
	int tmp = nref1;
	nref1 = nref2;
	nref2 = tmp;
}
int matrix[10][2];
int& func(int index) {
	return matrix[index][1];
}
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % end;
}
template <typename T>
T& max_arr(T arr[], const int length) {
	int i_max = 0;
	for (int i = 1; i < length; i++)
		if (arr[i_max] < arr[i])
			i_max = i;
	return arr[i_max];
}
int main() {
	setlocale(LC_ALL, "Russian");
	int a = 10, b = 20, c = 30,n=15,m=25;
	//нейтральный указатель
	int* pn=0;	   //первый способ
	//int* pn = NULL;  //второй способ
	int* pn = nullptr; //третий способ
	if (pn == nullptr)
		std::cout << "Указатель неинициализирован\n";
	else
		std::cout << *pn<<'\n';
	
	//указатель на константу
	
	int a = 10, b = 20, c = 30;
	int const* pa;
	pa = &a;
	std::cout << *pa << '\n';
	pa = &b;
	std::cout << *pa << '\n';
	///*pa = 15;//ошибка
	std::cout << *pa << '\n';
	
	//константный указатель
	
	int* pb;
	const int *pb;
	pb = &b;
	std::cout << *pb << '\n';
	pb = &c;
	std::cout << *pb << '\n';
	*pb = 35;//ошибка
	
	//константный указатель на константу
	
	const int* const pc=&c;
	std::cout << *pc << '\n';
	//pc = &a;  //ошибка
	//*pc = 15; //ошибка
	
	//СЫЛКИ
	
	int& refn=n;//создаем ссылку связанную с переменной n
	std::cout << "n= "<<n << '\n';
	std::cout<<"refn= " << refn << '\n';
	refn = 7;
	std::cout << "Новая n = "<<n << '\n';
	
	//ссылки как параметры функций
	
	std::cout << n << ' ' << m << ' ' << '\n';
	//my_swap(n, m);//удобно, но не работает
	//p_swap(&n, &m);// работает,но неудобно
	ref_swap(n, m);
	std::cout << n << ' ' << m << ' ' << '\n';
	
	
	for (int i = 0; i < 10; i++) {
		std::cout << "Ряд №" << i + 1 << "->";
		std::cin >> matrix[i][0];
		func(i) = matrix[i][0];
	}
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < 10; i++)
		std::cout << matrix[i][0] << '\t' << func(i) << '\n';
	
	const int size = 5;
	int arr[size]{ 4,2,1,5,6 };
	std::cout << "Начальный массив:\n";
	show_arr(arr, size);
	std::cout << "Максимум = " << max_arr(arr, size) << std::endl;
	std::cout << "Обнуляем максимальный элемент..\n";
	max_arr(arr, size) = 0;
	std::cout << "Итоговый массив:\n";
	show_arr(arr, size);



	return 0;
}
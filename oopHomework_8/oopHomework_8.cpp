#include <iostream>
#include<string>
using namespace std;
#include"Vectorr.h"
#include"Studentt.h"


int main() {
	//Vector<int*, 3>vec;
	//vec.push_back(new int(5)).
	//	push_back(new int(10)).
	//	push_back(new int(15)).
	//	push_back(new int(20));
	//vec.push_front(new int(25));
	////vec.pop_back();
	////vec.pop_front();
	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	//cout << *vec[i] << ' ';
	//}
	//vec.sort(true);
	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	cout << *vec[i] << ' ';
	//}

	Student s1;
	Student s2;
	Student s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	Vector<Student, 3>vec;
	vec.push_back(s1).
		push_back(s2).
		push_back(s3);
	/*for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}*/
	cout << endl;
	cout << endl;
	vec.sort();
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}

}

#include<iostream>
using namespace std;

struct dreptunghi { int lungime,latime; } d1,d2;

template<class T> void schimba(T *a,T *b)
{
	T c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a=1,b=2;
	schimba<int>(&a,&b);

	float c=0.5,d=3.4;
	schimba<float>(&c,&d);

	schimba<dreptunghi>(&d1,&d2);

	return 0;
}

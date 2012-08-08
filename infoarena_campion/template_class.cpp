#include<iostream>
using namespace std;

template<class T> class mypair
{
	private:
		T *a,*b;
	public:
		mypair(T x,T y)
		{
			a = new T; b = new T;
			*a=x; *b=y;
		}
		~mypair() { delete a; delete b; }

		T getmax();
		T getmin();
		T getfirst(); T getsecond();
		void swap();
};

template<class T> T mypair<T> :: getmax() { return ( *a>*b ? *a : *b ); }

template<class T> T mypair<T> :: getmin() { return ( *a<*b ? *a : *b ) ; }

template<class T> T mypair<T> :: getfirst() { return *a; }

template<class T> T mypair<T> :: getsecond() { return *b; }

template<class T> void mypair<T> :: swap()
{
	T c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	mypair<int> m(1,2);
	cout<< m.getmax() <<" "<< m.getmin() <<" "<< m.getfirst() <<" "<< m.getsecond()	<<"\n";
	m.swap();
	cout<< m.getfirst() <<" "<< m.getsecond() <<"\n";
	return 0;
}

#include<iostream>
using namespace std;

class dubla
{
	private :
		struct nod
		{
			int info; nod *prev,*next;
			nod(int _info,nod* _prev,nod* _next)
			{
				info = _info;
				prev = _prev;
				next = _next;
			}
		};
		nod *st,*sf,*cur;
		int count;

	public :
		~dubla()
		{
			if( count )
			{
				nod *c = st;
				while( c ) { nod *aux = c; c = c->next; delete aux; }
			}
		}
		bool search(int nr)
		{
			nod *c = st;
			while( c && c->info!=nr ) c = c->next;
			if( c ) { cur = c; return true; }
			return false;
		}
		void show()
		{
			nod *c = st;
			while( c ) { cout << c->info <<" "; c = c->next; }
			cout << "\n";
		}
		int howmany() { return count; }
		void add(int nr,int directie) //0-dreapta 1-stanga
		{
			if( directie<0 || directie>1 ) return;
			if( count==0 )
			{
				st = sf = cur = new nod(nr,NULL,NULL);
				count++;
				return;
			}
			if( search(nr) ) return;
			if( cur==st )
			{
				if( directie==0 )
				{
					nod *c = new nod(nr,st,NULL);
					st->next = c;
					cur = c;
					count++;
				}
				else
				{
					nod *c = new nod(nr,NULL,st);
					sf = st;
					st = c;
					cur = c;
					count++;
					return;
				}
				return;
			}
			if( cur==sf )
			{
				if( directie==0 )
				{
					nod *c = new nod(nr,sf,NULL);
					cur = c;
					sf->next = c;
					sf = c; count++;
					return;
				}
				else
				{
					nod *c = new nod(nr,sf->prev,sf);
					cur = c;
					sf->prev->next = c;
					count++;
					return;
				}
				return;
			}

			if( directie==0 )
			{
				nod *c = new nod(nr,cur,cur->next);
				cur->next->prev = c;
				cur->next = c;
				cur = c; count++;
				return;
			}

			nod *c = new nod(nr,cur->prev,cur);
			cur->prev->next = c;
			cur->prev = c;
			cur = c;
			count++;
		}

		void del(int nr)
		{
			if( !search(nr) ) return;
			nod *c = st;
			while( c->info!=nr ) c = c->next;

			if( c==st )
			{
				st = st->next; st->prev = NULL;
				delete c;
				count--;
				return;
			}
			if( c==sf )
			{
				sf = sf->prev; sf->next = NULL;
				delete c;
				count--;
				return;
				return;
			}

			c->prev->next = c->next;
			c->next->prev = c->prev;
			delete c;
			count--;
		}
};

dubla d;

int main()
{
	for(int i=1; i<=10; i++) d.add(i,0);
	d.show();
	d.search(5); d.add(51,0); d.search(5); d.add(52,1);
	d.show();
	return 0;
}

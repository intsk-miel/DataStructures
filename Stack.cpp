#include <iostream>
typedef int object;
using namespace std;
struct Node{
	public:
		object Value;
		Node *Next;
		Node(){Value=0;Next=0;}
		~Node(){}
};
class Stack{
	private:
		Node *First=0;
		Node *x=0;
		int n=0;
	public:
		int Count(){return n;}
		Stack(){First=0;x=0;n=0;}
		Stack(Node Elem){First=&Elem;}
		Stack(Node *Elem){First=Elem;}
		Stack(int Elem){
			x=new Node();
			x->Value=Elem;
			x->Next=0;
			First=x;
		}
		~Stack(){delete x;}
	void Add(Node Elem){               // adding element by object               
		Elem.Next=First;
		First=&Elem;n++;
	}
	void Add(Node Elem[],int k){             // adding element by array
		for(int i=0;i<k;i++){
			Elem[i].Next=First;
			First=&Elem[i];n++;	
		}	
	}
	void Add(Node *Elem){                                                // adding element by address
		cout<<" Elem="<<&Elem<<" Elem->value="<<Elem->Value<<endl;
		Elem->Next=First;
		First=Elem;n++;
	}
	void Add(int k){                               // adding element by number
		Node *Elem=new Node();
		Elem->Value=k;
		
		Elem->Next=First;
		First=Elem;n++;
	}
	Node *Remove(){                            // deleting element 
		Node *y=0;
		Node *p=First;
		if (First!=0){
			y=First->Next;
			First->Next=0;
			First=y;
			n--;
		}
		return p;
	} 
	void Display(){                             // display
		x=First;
		cout<<"{";
		while(x!=0){
			cout<<x->Value;
			x=x->Next;
			if (x!=0) cout<<"->";
		}
		cout<<"}"; 
	}
};
int main(int argc, char** argv) {
	Node x,y,z;
	Node s[4];
	Node *p=new Node();
	Node *q=new Node();
	x.Value=2;
	y.Value=7;
	z.Value=3;
	
	p->Value=9;
	q->Value=11;
	
	x.Next=&y;
	y.Next=&z;
	
	s[0].Value=2;
	s[1].Value=7;
	s[2].Value=3;
	s[3].Value=6;
	Stack A;

	A.Add(x);
	A.Add(q);
	cout<<"q="<<q<<" q->value="<<q->Value<<endl;

	
	A.Display();
	cout<<" k="<<A.Count()<<endl;
	
	p=A.Remove();
	A.Display();
	cout<<" k="<<A.Count()<<" p="<<p<<endl;
	
	return 0;
}

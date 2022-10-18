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
class Queue{
	private:
		Node *First=0;
		Node *Last=0;
		Node *x=0;
		int n=0;
	public:
		int Count(){return n;}
		Queue(){First=0;Last=0;x=0;n=0;}
		Queue(Node &Elem){First=&Elem;Last=&Elem;}
		Queue(Node *Elem){First=Elem;Last=Elem;}
		Queue(object Elem){
			x=new Node();
			x->Value=Elem;
			x->Next=0;
			First=x;
			Last=x;
		}
		~Queue(){delete x;}
	void Add(Node &Elem){                     // adding element by object  
		if (First!=0){
			Last->Next=&Elem;
			Last=&Elem;
		}
		else{
			First=&Elem;
			Last=&Elem;
		}
		n++;
	}
	void Add(Node *Elem){                     // adding element by address
		if (First!=0){
			Last->Next=Elem;
			Last=Elem;
		}
		else{
			First=Elem;
			Last=Elem;
		}
		n++;
	}
	void Add(object k){                    //adding by number
		Node *Elem=new Node();
		Elem->Value=k;
		
		if (First!=0){
			Last->Next=Elem;
			Last=Elem;
		}
		else{
			First=Elem;
			Last=Elem;
		}
		n++;
	}
	Node *Remove(){                      // deleting first element
		Node *y=0;
		Node *p=First;
		if (First==Last){
			First=0;
			Last=0;
			return 0;
		}
		if (First!=0){
			y=First->Next;
			First->Next=0;
			First=y;
			n--;
		}
		return p;
	}
	bool Search(object k){                       // searching element by value
		x=First;
		while(x!=0){
			if (x->Value==k) return true;
			x=x->Next;
		}
		return false; 
	}
	bool IsEmpty(){return First==0;}               // if stack is empty        
	void Display(){                                 // display
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
	
	Queue A;
	A.Add(x);
	A.Add(y);
	A.Add(z);
	
	A.Add(p);
	A.Add(q);

	
	A.Add(6);
	
	A.Display();
	cout<<" k="<<A.Count()<<endl;
	
	p=A.Remove();
	A.Display();
	cout<<" k="<<A.Count()<<endl;
	
	return 0;
}

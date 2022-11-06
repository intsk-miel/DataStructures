#include <iostream>
using namespace std;
typedef int object;

struct Node{
	public:
		object Value;
		Node *Next;
		Node *Prev;
		Node(){Value=0;Next=0;Prev=0;}
		~Node(){}
};
class DRList{
	private:
		Node *First;
		Node *Last;
		int n;
	public:
		DRList(){First=0;Last=0;n=1;}
		Node *GetFirst(){return First;}
		Node *GetLast(){return Last;}
		int Count(){return n;}
		void Add(Node& Elem){
			Node *p, *q;
			if (First==0){
				Elem.Next=&Elem;
				Elem.Prev=&Elem;
				First=&Elem;
				Last=&Elem;
				n++;
				return ;
			}
			if (First->Value>=Elem.Value) {
				Elem.Next=First;
				First->Prev=&Elem;
				First=&Elem;
				Last->Next=&Elem;
				Elem.Prev=Last;
				n++;
				return ;
			}
			if (Last->Value<=Elem.Value) {
				Last->Next=&Elem;
				Elem.Prev=Last;
				First->Prev=&Elem;
				Elem.Next=First;
				Last=&Elem;
				n++;
				return ;
			}
			p=0;
			q=First;
			while(q!=0){
				if (Elem.Value>q->Value){
					p=q;
					q=q->Next;
				}
				else
					break;
			}
			Elem.Next=q;
			q->Prev=&Elem;
			p->Next=&Elem;
			Elem.Prev=p;
			n++;
		}
		void Add(Node* Elem){
			Node *p, *q;
			if (First==0){
				Elem->Next=Elem;
				Elem->Prev=Elem;
				First=Elem;
				Last=Elem;
				n++;
				return ;
			}
			if (First->Value>=Elem->Value) {
				Elem->Next=First;
				First->Prev=Elem;
				First=Elem;
				Last->Next=Elem;
				Elem->Prev=Last;
				First=Elem;
				n++;
				return ;
			}
			if (Last->Value<=Elem->Value) {
				Last->Next=Elem;
				Elem->Prev=Last;
				First->Prev=Elem;
				Elem->Next=First;
				Last=Elem;
				n++;
				return ;
			}
			p=0;
			q=First;
			while(q!=0){
				if (Elem->Value>q->Value){
					p=q;
					q=q->Next;
				}
				else
					break;
			}
			Elem->Next=q;
			q->Prev=Elem;
			p->Next=Elem;
			Elem->Prev=p;
			n++;
		}
		void Add(object k){
			Node* Elem=new Node();
			Elem->Value=k;
			
			Node *p, *q;
			if (First==0){
				Elem->Next=Elem;
				Elem->Prev=Elem;
				First=Elem;
				Last=Elem;
				n++;
				return ;
			}
			if (First->Value>=Elem->Value) {
				Elem->Next=First;
				First->Prev=Elem;
				First=Elem;
				Last->Next=Elem;
				Elem->Prev=Last;
				First=Elem;
				n++;
				return ;
			}
			if (Last->Value<=Elem->Value) {
				Last->Next=Elem;
				Elem->Prev=Last;
				First->Prev=Elem;
				Elem->Next=First;
				Last=Elem;
				n++;
				return ;
			}
			p=0;
			q=First;
			while(q!=0){
				if (Elem->Value>q->Value){
					p=q;
					q=q->Next;
				}
				else
					break;
			}
			Elem->Next=q;
			q->Prev=Elem;
			p->Next=Elem;
			Elem->Prev=p;
			n++;
		}
		void Remove(Node& Elem){
			Node *p, *q, *x;
			if (First==0) return ;
			if (First->Value>Elem.Value) return ;
			if (Last->Value<Elem.Value) return ;
	
			p=0;
			q=First;
			while(q!=0){
				if (Elem.Value>q->Value){
					p=q;
					q=q->Next;
				}
				else
					break;
			}
			if (q->Value!=Elem.Value) return ;
			p->Next=q->Next;
			q->Prev=p;
			Elem.Next=0;
			Elem.Prev=0;
			n--;
		}
		void Remove(Node* Elem){
			Node *p, *q, *x;
			if (First==0) return ;
			if (First->Value>Elem->Value) return ;
			if (Last->Value<Elem->Value) return ;
	
			p=0;
			q=First;
			while(q!=0){
				if (Elem->Value>q->Value){
					p=q;
					q=q->Next;
				}
				else
					break;
			}
			if (q->Value!=Elem->Value) return ;
			p->Next=q->Next;
			q->Prev=p;
			Elem->Next=0;
			Elem->Prev=0;
			n--;
		}
		Node* Remove(object k){
			Node* Elem=new Node();
			Elem->Value=k;
			
			Node *p, *q, *x;
			if (First==0) return 0;
			if (First->Value>Elem->Value) return 0;
			if (Last->Value<Elem->Value) return 0;
			p=0;
			q=First;
			while(q!=0){
				if (Elem->Value>q->Value){
					p=q;
					q=q->Next;
				}
				else
					break;
			}
			if (q->Value!=Elem->Value) return 0;
			p->Next=q->Next;
			q->Prev=p;
			Elem->Next=0;
			Elem->Prev=0;
			n--;
			return p;	
		}
		void Display(){
			Node *x;
			x=First;
			cout<<"{";
			while(x->Next!=First){
				cout<<x->Value;
				x=x->Next;
				if (x!=0) cout<<"->";
		}
		cout<<x->Value<<"}"; 
		}
};


int main(int argc, char** argv) {
	DRList A,B; DRList *C;
	Node x,y,z,u,v;
	Node *x1=new Node();
	Node *y1=new Node();
	Node *z1=new Node();
	Node *u1=new Node();
	x.Value=2;	y.Value=3;	z.Value=5;	 u.Value=10;	  v.Value=23;
	x1->Value=6;y1->Value=9;z1->Value=15;u1->Value=12;
		
	A.Add(x);A.Add(y);A.Add(z);A.Add(u);A.Add(v);
	A.Add(x1);A.Add(y1);A.Add(z1);A.Add(u1);
	A.Add(16);A.Add(20);A.Add(17);
	cout<<"A="<<&A<<" ";
	A.Display();
	cout<<endl;
	
	A.Remove(2);
	cout<<"A="<<&A<<" ";
	A.Display();
	cout<<endl;

	
	return 0;
}
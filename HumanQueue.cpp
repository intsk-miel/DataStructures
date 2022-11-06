#include <iostream>
#include <cstring>
using namespace std;

struct Date{
	public:
		unsigned int Day;
		unsigned int Month;
		int Year;
		Date(){Day=1;Month=1;Year=0;}
};
struct Person{
	public:
		string PersonalID;
		string FirstName;
		string LastName;
		Date DOB;
		Person(){
			PersonalID="";FirstName="";LastName="";
			DOB.Day=1;DOB.Month=1;DOB.Year=0;
		}
		Person operator = (int k){
			PersonalID="";
			FirstName="";
			LastName="";
			DOB.Day=1;DOB.Month=1;DOB.Year=0;
			return *this;
		}
		bool operator ==(Person y){
			return PersonalID==y.PersonalID;
		}
	friend ostream& operator << (ostream &os, Person &y);	
};

ostream& operator << (ostream &os, Person &y){
	os <<y.PersonalID<<" "<<y.FirstName<<" "<<y.LastName;
}

typedef Person object;

struct Node{
	public:
		object Value;
		Node *Next;
		Node(){Value=0;Next=0;}
		~Node(){}
};
class Queeue{
	private:
		Node *First=0;
		Node *Last=0;
		Node *x=0;
		int n=0;
	public:
		int Count(){return n;}
		Queeue(){First=0;Last=0;x=0;n=0;}
		Queeue(Node &Elem){First=&Elem;Last=&Elem;}
		Queeue(Node *Elem){First=Elem;Last=Elem;}
		Queeue(object Elem){
			x=new Node();
			x->Value=Elem;
			x->Next=0;
			First=x;
			Last=x;
		}
		~Queeue(){delete x;}
	void Add(Node &Elem){
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
	void Add(Node Elem[],object k){
		/*
		if (First!=0){
			for(int i=0;i<k;i++){
				Elem[i].Next=First;
				First=&Elem[i];	
			}	
		}
		else{
			First=&Elem;
			Last=&Elem;
		}
		n+=k;
		*/
	}
	void Add(Node *Elem){
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
	void Add(object k){
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
	Node *Remove(){
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
	bool Search(object k){
		x=First;
		while(x!=0){
			if (x->Value==k) return true;
			x=x->Next;
		}
		return false; 
	}
	bool IsEmpty(){return First==0;}
	void Display(){
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
	Queeue A;
	//A.Add(s,4);
	//for(int i=0;i<4;i++) {
	//	A.Add(s[i]);
	//}	
	A.Add(x);
	A.Add(y);
	A.Add(z);
	
	A.Add(p);
	A.Add(q);
	//cout<<"q="<<q<<" q->value="<<q->Value<<endl;
	
	//A.Add(6);
	
	A.Display();
	cout<<" k="<<A.Count()<<endl;
	
	p=A.Remove();
	A.Display();
	cout<<" k="<<A.Count()<<endl;
	
	return 0;
}
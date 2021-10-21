#include<iostream>
#include"list.h"

#include<cstdbool>
using namespace std;
int main() {
	/*data_structure::node<int> n1(1);
	data_structure::list<int> l;
	data_structure::list<int> l1;
	
	l.add(1);
	l.add(2);
	//l.pop();
	l.reverse();
	int a = 5;
	l[1] = a;
	cout << l;
	l1 = l;
	
	int b = 1 + l1;
	cout << "b = " << b << endl;
	l1 += l;
	cout << l1;
	data_structure::list<int> l2 = l + l1;
	if (l != l1) 
		cout << "not same" << endl; 
	else 
		cout << "same" << endl;
	
	cout << l2;
	cout << "-----------" << l.size() << endl;
	l.clean();
	//l.print();
	//cout << l;
	cout << "----------------boucle--------------" << endl;
	data_structure::list<int>::list_it it(l1);*/

	data_structure::list<int> l;
	l.add(0); l.add(1); l.add(2);
	data_structure::list<int> l1(l);
	//cout << l1;
	//data_structure::list<int>::list_it it = l1.begin();
	//cout << *it << endl;
	for(data_structure::list<int>::list_it it = l1.begin() ; it != l1.end() ; it++ )
		cout << *it << endl;
	return 0;
}
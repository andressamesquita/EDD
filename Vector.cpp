#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> myVector;
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(15);
	myVector.push_back(8);
	myVector.push_back(5);
	myVector.pop_back(); 
	
	cout<<"Vector: ";
	
	for (unsigned int i = 0; i < myVector.size();i++){
		cout<<myVector[i]<< " ";
	}
	
	cout<<endl;
		
	myVector.insert(myVector.begin()+1,7);
	
	cout<<"Vector: ";
	
	for (unsigned int i = 0;i < myVector.size();i++){
		cout<<myVector[i]<< " ";
	}
	
	cout<<endl;
	
	myVector.erase(myVector.begin()+4);
	
	cout<<"Vector: ";
	
	for (unsigned int i = 0;i < myVector.size();i++){
		cout<<myVector[i]<< " ";
	}
	
	cout<<endl;
	
	
	if (myVector.empty()){
		cout<<endl<<"Is Empty!";
	}else{
		cout<<endl<<"Isn't Empty Yet";
	}
	
	myVector.clear();
	
		if (myVector.empty()){
		cout<<endl<<"Is Empty!";
	}else{
		cout<<endl<<"Isn't Empty";
	}
	
}
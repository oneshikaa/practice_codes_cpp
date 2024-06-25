#include <iostream> 
#include<fstream> 
using namespace std;
int main() { 
char c; 
ifstream fin("MySecrets.txt"); 
	if(!fin) {cout<<"File Does not Exist";  return 0; } 
	while(!fin.eof()) { // eof – end of the file
		fin.get(c); cout<<c;   // print text on screen
	}
fin.close();}
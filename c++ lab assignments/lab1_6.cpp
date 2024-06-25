#include<iostream>
using namespace std;

class student{
    char name[30];
    int roll,marks;

    public :

    void setData(){
        cout<<"enter the name of the student ";
        cin>>name;
        cout<<"enter the roll ";
        cin>>roll;
        cout<<"enter the marks harr";
        cin>>marks;
      
    }

    void getData(){
        cout<<"the value of roll number is "<<roll<<"\n and the value of marks is "<<marks<<"\n and the name of the student is "<<name<<endl;
    }
};

int main(){
    student s[3];
    for(int i = 0; i<3; i++){
        s[i].setData();
        s[i].getData();

    }

    return 0;
}
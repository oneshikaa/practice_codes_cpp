#include<iostream>
using namespace std ;

struct Student{
    char name[20];
    int roll;
    float marks;

    void setData( ){
        cout<<"enter the name of student"<<endl;
        cin>>name;
        cout<<"enter the roll number"<<endl;
        cin>>roll;
        cout<<"enter the marks"<<endl;
        cin>>marks;

    }

    void getData(){
        cout<<"the value of roll number is"<<roll<<endl;
         cout<<"the value of marks is"<<marks<<endl;
         cout<<"te name of the student is"<<name<<endl;

    }
};

int main(){

    Student s[3];
    for(int i=0;i<3;i++){
         s[i].setData();
    s[i].getData();
    }

   

    return 0;
}
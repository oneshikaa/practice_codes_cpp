#include<iostream>
using namespace std;

class stack{
    public :

    int *arr;
    int top;
    int size;

    stack(){
        top = -1;
        cout<<"enter the size :"<<endl;
        cin>>size;
        arr = new int[size];
    }

    ~stack(){
        delete []arr;
        arr = 0;
    }

    void push(){
        int x;
        for(int i =0;i<size;i++){
            top++;
            cout<<"enter the element :"<<endl;
            cin>>x;
            arr[top] = x;
         
        }
    }

    void display(){
        for(int i =top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
    }

    int pops(){
        int x = arr[top];
        top--;
        return x;
    }

    int insert_bottom(){
    
       for(int i =0;i<size;i++){
       int a  = pops();
       arr[i]  = a ;
       cout<< arr[i]<<" ";
       }
       
    }

   /* void reverse(){

        for(int i =size;i>0;i--){
            cout<<insert_bottom();
            
        }

      
  
    }*/

};

int main(){
    stack st;
    st.push();
   
   // st.display();
    //cout<<"\n";
    //cout<<"after reversal"<<endl;
    st.insert_bottom();
   // st.reverse();
    
}
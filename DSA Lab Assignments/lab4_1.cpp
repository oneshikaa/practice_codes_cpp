#include<iostream>
using namespace std;

int num,num1;

struct stack{
    int size;
    int top;
    int *s;

};

    void create(struct stack *st){
        cout<<("enter size : ");
        cin>>st->size;
        st->top=-1;
        st->s=(int *)malloc(st->size*sizeof(int));
    }

    void display(struct stack st)
{
 int i;
 for(i=st.top;i>=0;i--){
 cout<<("%d ",st.s[i]);
 cout<<("\n");
}

}



    void push(stack*st,int x){
        if(st->top==st->size-1)
        cout<<"Stack overflow "<<endl;
        else{
            st->top++;
            st->s[st->top] = x;
        }
    }

    int pop(stack*st){
        int x =-1;
        if(st->top==-1)
        cout<<"underflow"<<endl;
        else{
            x =st->s[st->top];
            st->top--;

        }
        return x;

    }

    int peek(struct stack st,int pos){
        int x =-1; 
        if((st.top)-pos+1<0)
        cout<<"invalid position"<<endl;
        else
        x = st.s[st.top-pos+1];

        return x;
    }

    int stackTop(struct stack st){
        if(st.top == -1)
        return -1;
        else
        return st.s[st.top];
    }

    int isEmpty(struct stack st){
        if(st.top == -1)
        return 1;
        else 
        return 0;
    }

    int isFull(struct stack st){
        if(st.top == st.size -1)
        return 1;
        else
        return 0; 
    }




int main(){
    struct stack st;
  

   while(1){
    int choice;
	cout<<"enter the choice"<<endl;
    cin>>choice;

  switch(choice){
      case 1 : create(&st);
      break;
      
      case 2 : display(st);
      break;
      
      case 3 :
      cout<<"enter the number to be pushed : "<<endl;
      cin>>num;
      push(&st,num);
      break;
      
      case 4 : 
      cout<<"enter the position "<<endl;
      cin>>num1;
      peek(st,num1);
      break;
      
      case 5 : pop(&st);
      break;
      
      case 6 : isFull(st);
      break;

      
      case 7 : isEmpty(st);
      break;
      
  }
  
}
  

   }




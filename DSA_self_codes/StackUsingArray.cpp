#include<iostream>
using namespace std;

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
        cout<<"Stack overflow ";
        else{
            st->top++;
            st->s[st->top] = x;
        }
    }

    int pop(stack*st){
        int x =-1;
        if(st->top==-1)
        cout<<"underflow";
        else{
            x =st->s[st->top];
            st->top--;

        }
        return x;

    }

    int peek(struct stack st,int pos){
        int x =-1; 
        if((st.top)-pos+1<0)
        cout<<("invalid position");
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
    cout<<"enter the size of the stack : ";
    cin>>st.size;
    st.s = new int[st.size];
    st.top =-1;

    push(&st,10);
    push(&st,20);
   

  

   // cout<<pop(&st)<<endl;
    //cout<<pop(&st)<<endl;
    //cout<<pop(&st)<<endl;

    cout<<"peek at 0th element : "<<peek(st,1)<<endl;


      display(st);



}


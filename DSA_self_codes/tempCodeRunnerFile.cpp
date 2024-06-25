#include<iostream>
using namespace std;


class Solution {
public:
    int fun(string s) {
        int left = 0;
        int right = 0;
        int star = 0;

        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                left++;
            }
            else if(s[i]==')'){
                right++;
            }
            else{
                star++;
            }
        }
        cout<<"left:"<<left<<" right:"<< right<<endl;
        cout<<"star:"<<star<<endl;
        if(left==right){
            return 1;
        }
        if(abs(left-right)<=star){
            return 1;
        }  
        return -1;      
    }
};

int main(){
    Solution  S;
    cout<<S.fun("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())");
}
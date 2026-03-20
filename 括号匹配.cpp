#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char> s;
    bool flag=true;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]=='}'){
            if(s.empty()||s.top()!='{'){
                flag=false;
                break;
            }
            else{
                s.pop();
            }
        }
        else if(str[i]==']'){
            if(s.empty()||s.top()!='['){
                flag=false;
                break;
            }
            else{
                s.pop();
            }
        }
        else if(str[i]==')'){
            if(s.empty()||s.top()!='('){
                flag=false;
                break;
            }
            else{
                s.pop();
            }
        }
    }
    if(flag&&s.empty()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
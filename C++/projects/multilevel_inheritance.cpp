//multilevel inheritance
#include<iostream>
using namespace std;
class a{
    protected:
    int i;
};
class b:public a{
    protected:
    int j;
    // public:
    void input(){
        cout<<"Enter j: ";
        cin>>j;
    }
    void output(){
        cout<<" j is "<<j<<endl;
    }
};
class c: public b{
    protected:
    int k;
    public:
    void get(){
        cout<<"Enter i  k: ";
        cin>>i>>k;
        input();
    }
    void show(){
        cout<<"i = "<<i<<" k = "<<k;
        output();
    }
};
int main(){
    c c1;
    c1.get();
    c1.show();
    return 0;
}
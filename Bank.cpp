#include<iostream>
#include<string>
using namespace std;

class Bank{
    int acn[5]={124,2,3,4,5};
    string acna[5]={"Amit","Rashmi","Kia","Aarti","Julia"};
    int acb[5]={100,150,200,120,500};
    int pin[5]={1245,1234,9876,4594,1111};
    int currentIndex = -1;

    public:
    void check(int acnum, int pass){
        bool isFound = 0;
        for(int i= 0; i<5; i++){
            if(acnum==acn[i] and pass==pin[i]){
                isFound = 1;
                currentIndex = i;
                show(currentIndex);
                break;
            }
        }
        if(!isFound){
            cout<<"You entered wrong pin or Ac n.";
            currentIndex = -1; // reset if wrong
        }
    }

    void show(int index){
        // cout<<"Account no. is : "<<acn[index]<<endl;
        cout<<"Account Holder name is : "<<acna[index]<<endl;
        cout<<"Balance : "<<acb[index]<<endl;
    }

    public:
    void trans(int amt){
        if(currentIndex == -1){
            cout<<"No acc is authenticate, Transaction Failed";
        return;
        }
        if(amt>acb[currentIndex]){
            cout << "Insufficient balance. Transaction failed.\n";
        }
        else{
            acb[currentIndex] = acb[currentIndex] - amt;
            cout << "Transaction successful.\n"<<" Remaining balance: ";
            remain();
        }
        
    }
    
    public:
    void remain(){
        if (currentIndex != -1) {
            cout << acb[currentIndex];
        } else {
            cout << "No account authenticated.\n";
        }
    }


};
int main(){
    int n,p;
    cout<<"Welcome\n";
    cout<<"Enter AC n. : ";cin>>n;
    cout<<"Enter pin n. : ";cin>>p;
    Bank a;
    a.check(n,p);
    
    if (n < 1 || n > 5) { // Ensures valid account range
        cout << "Invalid Account Number.\n";
        return 0;
    }

    string d;
    cout<<"You want to withdrow money?\n"<<"(yes/no) : ";cin>>d;

    if(d =="yes"){
        int x;
        cout<<"Enter Amount : ";cin>>x;
        a.trans(x);
    }
    else{
        cout<<"Thank you for your Time ";
    }
return 0;
}
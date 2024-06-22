#include<bits/stdc++.h>
using namespace std;
string sanitizeCreditCard(const string& creditCard) {
    string sanitized = "";
    for (char c : creditCard) {
        if (c != '-' && c != ' ') {
            sanitized += c;
        }
    }
    return sanitized;
}
int getdigit(const int number){

    return number%10+(number/ 10 % 10);
}
int evensum(const string Creditcardnum){
    int esum=0;
    for(int i= Creditcardnum.size()-1;i>=0;i-=2){
        esum+=getdigit(Creditcardnum[i]-'0');
    }
    return esum;
}
int oddsum(const string Creditcardnum){
    int osum=0;
    for(int i= Creditcardnum.size()-2;i>=0;i-=2){
        osum+=getdigit((Creditcardnum[i]-'0')*2);
    }
    return osum;
}
int main(){
    char choice;
    do {
        cout << "***************************** CREDIT CARD VALIDATOR ***************************" << endl;
            int sum=0;
            string Creditcardnum;
            cout<<"Enter a credit card number :";
            getline(cin,Creditcardnum);
            // Remove '-' and ' ' characters
            string sanitizedCreditCardNum = sanitizeCreditCard(Creditcardnum);
            sum = evensum(sanitizedCreditCardNum) + oddsum(sanitizedCreditCardNum);
            if(sum%10==0){
            cout<<"THE ENTERED CREDIT CARD NUMBER "<<Creditcardnum<<" IS VALID"<<endl<<endl;
            }
            else{
            cout<<"THE ENTERED CREDIT CARD NUMBER "<<Creditcardnum<<" IS NOT VALID"<<endl<<endl;
            }
            cout << "Do you want to check another credit card number? (y/n): ";
            cin >> choice;
            cout<<endl;
            cin.ignore(); // to clear the newline character from input buffer

        }

     while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the Credit Card Validator!" << endl;
    
    return 0;
}
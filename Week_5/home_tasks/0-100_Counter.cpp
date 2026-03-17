#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n == 100){
      cout << "one hundred";
        return 0;
      }
      
      if(n >= 20){
        int tens = n / 10;
        n = n % 10;
        
        if(tens==2) cout<<"twenty ";
        else if(tens==3) cout<<"thirty ";
        else if(tens==4) cout<<"forty ";
        else if(tens==5) cout<<"fifty ";
        else if(tens==6) cout<<"sixty ";
        else if(tens==7) cout<<"seventy ";
        else if(tens==8) cout<<"eighty ";
        else if(tens==9) cout<<"ninety ";

    }

    if(n==0) cout<<"zero";
    else if(n==1) cout<<"one";
    else if(n==2) cout<<"two";
    else if(n==3) cout<<"three";
    else if(n==4) cout<<"four";
    else if(n==5) cout<<"five";
    else if(n==6) cout<<"six";
    else if(n==7) cout<<"seven";
    else if(n==8) cout<<"eight";
    else if(n==9) cout<<"nine";
    else if(n==10) cout<<"ten";
    else if(n==11) cout<<"eleven";
    else if(n==12) cout<<"twelve";
    else if(n==13) cout<<"thirteen";
    else if(n==14) cout<<"fourteen";
    else if(n==15) cout<<"fifteen";
    else if(n==16) cout<<"sixteen";
    else if(n==17) cout<<"seventeen";
    else if(n==18) cout<<"eighteen";
    else if(n==19) cout<<"nineteen";

}
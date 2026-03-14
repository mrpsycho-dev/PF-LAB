#include <iostream>
#include <cmath>
using namespace std;

int main(){
  float area;
  string fig;
  cout<<"Enter figure name: "; cin>> fig;
  
  
  if (fig == "square"){float s;      cin>>s; area = s*s;}
  if (fig == "rectangle"){float l,w;   cin>>l,w;area = l*w;}
  if (fig == "circle"){float r;      cin>>r;area = 3.14159 *r*r;}
  if (fig == "triangle"){float b,h;    cin>> b,h;area= 0.5*b*h;}
  
  
  cout<<" Area: ";
  cout << area;
}
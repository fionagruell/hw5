#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
void Eulerback(double* y,const int N, const double dt);
void Eulerfor(double* y,const int N, const double dt);

int main(){
const double pi= M_PI;
const double dt=pi/100;
const int N= 2000;
double y[2*N];
y[0]=1;
y[N]=0;

Eulerback(y,N,dt);
//Eulerfor(y,N,dt);
for(int i=0; i<N; i++) {
  cout << i*dt <<"\t"<< y[i]<< "\t"<<y[N+i] << endl;
}
  
  
  
return 0;  
}
void Eulerback(double* y,const int N, const double dt){
  for(int i=0; i<N; i++){
    y[i+1]=(y[i]-dt*y[N+i])/(1+dt*dt);
    y[N+i+1]=(dt*y[i]+y[N+i])/(1+dt*dt);
  }
}
void Eulerfor(double* y, const int N, const double dt){
  for(int i=0; i<N; i++){
    y[i+1]=y[N+i]*dt+y[i];
    y[N+i+1]=-y[i]+y[N+i];
  }
    
    
}
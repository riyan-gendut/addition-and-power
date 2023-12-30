#include <iostream>
#include <stdlib.h>
#include <string.h>


double powex (double a, double b){
    double i,c;
    c=a;
    for(i=1; i<b; i++){
        c=c*a;
    }
return c;
}

void expocal(double elte){
    double i,x,y,resg,finre;
     for( i=1; i<elte; i++){
        x=i;
        y=elte-i;
        resg=powex(x,y);
        std::cout<<x<<","<<y<<","<<resg<<"\n";
    }
}

void erka (double xin){
    try{
        if(xin==0) throw 0;
        else expocal(xin);
        }
    catch(int x){
        if (x==0) std::cout<<"  Input cannot be zero or not a number."<<std::endl;
        else std::cout<<"   Unexpected error."<<std::endl;
        }
}

int main(int argc, char** argv){
    double el;
    el=std::stod(argv[1]);
    erka(el);
    return 0;
}

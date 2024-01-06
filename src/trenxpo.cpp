#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

double powex (double a, double b){
    double i,c;
    c=a;
    for(i=1; i<b; i++){
        c=c*a;
    }
return c;
}

void expocal(double elte){
    double i,x,y,resg,finre,percod;
    std::vector<double> jangkr;
    finre=0;
    for( i=1; i<elte; i++){
        x=i;
        y=elte-i;
        resg=powex(x,y);
        jangkr.push_back(resg);
        finre=std::max(finre,resg);
    }
    for(i=0; i<jangkr.size(); i++){
        resg=jangkr.at(i);
        if(resg==finre){
            x=i+1;
            y=elte-x;
            break;
        }
    }
    percod=100*(x/elte);
    std::cout<<percod<<std::endl;
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

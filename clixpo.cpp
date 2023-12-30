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
    double i,x,y,resg,finre;
    std::vector<double> jangkr;
    std::cout<<"Calculating maximum x^y for x+y="<<elte<<"\n \n";
    finre=0;
    for( i=1; i<elte; i++){
        x=i;
        y=elte-i;
        resg=powex(x,y);
        jangkr.push_back(resg);
        finre=std::max(finre,resg);
        std::cout<<"For x="<<x<<" and y="<<y<<" x^y ="<<resg<<"\n";
    }
    for(i=0; i<jangkr.size(); i++){
        resg=jangkr.at(i);
        if(resg==finre){
            x=i+1;
            y=elte-x;
            break;
        }
    }
    std::cout<<"\n"<<"The largest value of x^y is "<<finre<<" for x="<<x<<" and y="<<y<<"."<<std::endl;
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

void help(){
    std::cout<<"Simple CLI program to calculate maximum x^y given a value of x+y. \n \n";
    std::cout<<"Usage: \n \n";
    std::cout<<"    Use clixpo -h or --help to show this message \n";
    std::cout<<"    Use clixpo [NUMBER] to calculate maximum x^y for x+y=[NUMBER].\n";
    std::cout<<"        (Extraneous arguments will be ignored.) \n";
    std::cout<<"    Otherwise you will be prompted to input a number"<<std::endl;
}


int main(int argc, char** argv){
    double el;
    std::cout<<"I'm distracting myself from work by solving random math equation on the internet! \n Use -h or --help for help \n \n";
    if(argc==1){
        std::cout<<"Please input a number:";
        std::cin>>el;
        erka(el);
    }
    else if (argc>=2){
        if(strcmp(argv[1],"-h")==0||strcmp(argv[1],"--help")==0) help();
        else {
            el=std::stod(argv[1]);
            erka(el);
        }
    }
    return 0;
}

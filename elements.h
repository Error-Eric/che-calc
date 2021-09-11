//header file for class element

#ifndef _ELEMENTS
#define _ELEMENTS
#endif

#ifndef _GLIBCXX_STRING
#include"string"
#endif

#ifndef _GLIBCXX_MATH_H
#include"math.h"
#endif

class element{
    private:
        int __atomic_number;
        std::string __name;
        double __relative_mass;
        double __relative_mass_simplefied;
        bool __have_radiation;
        bool __is_artificial;

    public:

        //constructor

        #define _RM_ relative_mass
        #define ___RM_ __relative_mass
        #define _RM__S relative_mass_simplefied
        #define ___RM__S __relative_mass_simplefied

        element(int atomic_number,std::string name,double relative_mass,double relative_mass_simplefied,bool have_radiation)
        :__atomic_number(atomic_number),__name(name),___RM_(_RM_),___RM__S(_RM__S),__have_radiation(have_radiation){}
        element(int atomic_number,std::string name,double relative_mass,int relative_mass_simplefied)
        :__atomic_number(atomic_number),__name(name),___RM_(_RM_),___RM__S(_RM__S){}
        element(int atomic_number,std::string name,double relative_mass,double relative_mass_simplefied)
        :__atomic_number(atomic_number),__name(name),___RM_(_RM_),___RM__S(_RM__S){}
        element(int atomic_number,std::string name,int relative_mass_simplefied)
        :__atomic_number(atomic_number),__name(name),___RM__S(_RM__S){}
        element(int atomic_number,std::string name,double relative_mass)
        :__atomic_number(atomic_number),__name(name),___RM_(_RM_){__relative_mass_simplefied=round(relative_mass);}
        element(){}

        #undef _RM_
        #undef ___RM_
        #undef _RM__S
        #undef ___RM__S

        //get the atomic number of the element.
        const int AtomicNumber(void){return __atomic_number;}
        const int an(void){return __atomic_number;}

        //get the name of the element.
        const std::string Name(void){return __name;}
        const std::string n(void){return __name;}

        //get the relative mass of the element.
        const double RelativeMass(void){return __relative_mass;}
        const double rw(void){return __relative_mass;}
        const double RelativeMassJunior(void){return __relative_mass_simplefied;}
        const double rw(bool junior_school){
            if(junior_school)return __relative_mass_simplefied;
            else return __relative_mass;
        }

};

#ifndef _GLIBCXX_VECTOR
#include"vector"
#endif

#ifndef ELETABLE
#define ELETABLE
std::string __ele_en[]=
{"","H","He","Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn",
"Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr",
"Nb","Mo","Tc","Ru","Rh","Pb","Ag","Cd","In","Sn",
"Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd",
"Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb",
"Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg",
"Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th",
"Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",
"Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds",
"Rg","Cp","Uut","Uuq","Uup","Uuh","Uus","Uuo"   
};
const double __ele_ew[]=
{0,1.00794,4.002602,6.941,9.012182,10.811,12.0107,14.00674,15.9994,18.99740332,20.1797,
22.989770,24.3050,28.981538,28.0855,30.973761,32.066,35.453,39.948,39.0983,40.078,
44.955910,47.867,50.9415,51.9961,54.938049,55.8457,58.933200,58.6934,63.546,65.409,
69.723,72.64,74.92160,78.96,79.904,83.798,85.4678,87.62,88.90585,91.224,
92.90638,95.94,98,101.07,102.90550,106.42,107.8682,112.411,114.818,118.710,
121.760,127.60,126.90447,131.298,132.90545,137.327,138.9055,140.116,140.90765,114.24,
145,150.35,151.964,157.25,158.92534,162.500,164.93032,167.259,168.93421,173.04,
174.967,178.49,180.9479,183.84,186.207,190.23,192.217,195.078,196.96655,200.59,
204.3833,207.2,208.98038,209,210,222,223,226,227,232.0381,
231.03588,238.02891,237,244,243,247,247,251,252,257,
258,259,262,261,262,266,264,269,268,271,
272,277,284,289,288,292,292,293
};
#endif

#ifndef __NOTREAL
#define _PTABLE
#define __NOTREAL
 #ifndef PTABLESIZE
 #define PTABLESIZE 118
 #endif
class __ptable{
    public:
        std::string ElementNames[PTABLESIZE+1];
        double ElementMass[PTABLESIZE+1];
        __ptable(){
            for(register int _I=1;_I<=PTABLESIZE;_I++){
                ElementMass[_I]=__ele_ew[_I];
                ElementNames[_I]=__ele_en[_I];
            }
        }
        element operator[](int AtomicNumber){
            return element(AtomicNumber,ElementNames[AtomicNumber],ElementMass[AtomicNumber]);
        }
};
__ptable ptable;

//get the atomic number of an element by its name or ralative atomic mass.
int eleid(std::string Name){
    for(register int _I=1;_I<=PTABLESIZE;_I++){
        if(ptable.ElementNames[_I]==Name){
            return _I;
        }
    }
    return -1;
}
int eleid(double RelativeMass){
    if(RelativeMass==35.5)return 17;
    else {
        for(register int _I=1;_I<=PTABLESIZE;_I++){
            if(ptable.ElementMass[_I]==RelativeMass or
            round(ptable.ElementMass[_I])==RelativeMass)
                return _I;
        }
        return -1;
    }
}

//get the name of an element by its atomic number.
std::string elename(int AtomicNumber){
    if(1<= AtomicNumber and AtomicNumber<=PTABLESIZE){
        return ptable.ElementNames[AtomicNumber];
    }
    else return "*Error";
}

//get the relative atomic mass of an element by its atomic number.
int elemass(int AtomicNumber){
    if(1<= AtomicNumber and AtomicNumber<=PTABLESIZE){
        return ptable.ElementMass[AtomicNumber];
    }
    else return -1;
}

#endif //ifndef __NOTREAL


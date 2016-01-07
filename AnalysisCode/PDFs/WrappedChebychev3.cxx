/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "WrappedChebychev3.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

ClassImp(WrappedChebychev3) 

 WrappedChebychev3::WrappedChebychev3(const char *name, const char *title, 
                        RooAbsReal& _x,
                        RooAbsReal& _p0,
                        RooAbsReal& _p1,
                        RooAbsReal& _p2,
                        RooAbsReal& _p3,
                        RooAbsReal& _p4,
                        RooAbsReal& _p5) :
   RooAbsPdf(name,title), 
   x("x","x",this,_x),
   p0("p0","p0",this,_p0),
   p1("p1","p1",this,_p1),
   p2("p2","p2",this,_p2),
   p3("p3","p3",this,_p3),
   p4("p4","p4",this,_p4),
   p5("p5","p5",this,_p5)
 { 
 } 


 WrappedChebychev3::WrappedChebychev3(const WrappedChebychev3& other, const char* name) :  
   RooAbsPdf(other,name), 
   x("x",this,other.x),
   p0("p0",this,other.p0),
   p1("p1",this,other.p1),
   p2("p2",this,other.p2),
   p3("p3",this,other.p3),
   p4("p4",this,other.p4),
   p5("p5",this,other.p5)
 { 
 } 



 Double_t WrappedChebychev3::evaluate() const 
 { 
   Double_t result=1e-6;
   
   if (x>p0 && x<p1)
   {
     Double_t x_eff=(x-(p0+p1)/2.)/(p1-p0);
     
     Double_t s1=p2;
     Double_t s2=p3*x_eff;
     Double_t s3=p4*(2.*x_eff*x_eff-1.);
     Double_t s4=p5*(4.*x_eff*x_eff*x_eff-3.*x_eff);
     
     Double_t sum=s1+s2+s3+s4;
     if (sum>0) result=sum;
   }
   
   // std::cout<<"result = "<<result<<std::endl;
   
   return result;
 } 

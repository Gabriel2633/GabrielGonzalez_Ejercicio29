#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void funcion(double rho,double ten,int N,double dn,int Nt, double dt,string filename);

int main()
{
    
    funcion(0.01,40.0,101,0.01,101,0.5,"datos.dat");
    
    return 0;
}

void funcion(double rho,double ten,int N,double dn,int Nt, double dt,string filename)
{
    ofstream outfile;
    outfile.open(filename);
    double c = pow((ten/rho),0.5);
    double c1= dn/dt;
    double ratio=c*c/(c1*c1);
        
    double xi[3][N];    
    for(int i=0; i<81;i++)
    {
        xi[0][i]=0.00125*i; 
    }
    for(int i=81; i<N;i++)
    {
        xi[0][i]=0.1-0.005*(i-80); 
    }
   
    xi[0][0]=0.0;
    xi[0][N-1]=0.0;
    
    xi[1][0]=0.0;
    xi[1][N-1]=0.0;
    
    for(int i=1;i<N-1;i++)
    {
        xi[1][i]=xi[0][i]+0.5*ratio*(xi[0][i+1]+xi[0][i-1]-2*xi[0][i]);     
    }
    
    for(int i=0;i<N;i++)
    {
      outfile << xi[0][i] << " ";
    }
      outfile << "\n";
    
    // para los t 
    
      for(int i=1;i<Nt;i++)
    {
        for(int j=1;j<N-1;j++)
        {
            xi[2][j]=2*xi[1][j]-xi[0][j]+ratio*(xi[1][j+1]+xi[1][j-1]-2*xi[1][j]);
        }
        
        for(int j=0;j<N;j++)
        {
          outfile << xi[1][j] << " ";
        }
        outfile << "\n";    
          
        for(int j=0;j<N;j++)
        {
            xi[0][j]=xi[1][j];
            xi[1][j]=xi[2][j];
        }  
                
    }
    
    outfile.close();
}








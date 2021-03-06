// Guilherme Maciel de Aguiar Nunes Coelho
// Universidade Federal de Ouro Preto - 2017

#include <cstdio>

using namespace std;

//includes the heuristic
#include "Driver.hpp"
							
//how many runs for each instance?
#define RUNS 1							

int main()
{
	int solutionValue;					//stores the result 
	int i = 0, j;
    
	double runningTime;					//stores the running time

	string inputFileName;			//stores the name of the input file

	ifstream fpIndex("Index/index.txt");
    
	ofstream fpOut("Results/RESULTS_SUMMARY.txt");
    
	while(fpIndex>>inputFileName)
	{
		i++;
        
        for(j=0; j<RUNS; j++)
		{
			printf("Run %d\n", j+1);
      
			multiRun(&solutionValue,
               &runningTime,
               inputFileName,
               j+1);
      
			printf("PROBLEM %d: %s %d\n",
             i,
             inputFileName.c_str(),
             solutionValue);
      
			fpOut<<inputFileName<<" ; "<<j+1<<" ; "<<solutionValue<<" ; "<<runningTime<<" ; "<<endl;
		}
	}
    printf("FIM ");
}

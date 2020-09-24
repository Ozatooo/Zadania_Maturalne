#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct uczen
{
        int numer;
};

class klasa
{
                vector <struct uczen> spis;
       
        public:
        		void wczytajZPliku(const char *);  
                void wypisz();
                void zapiszDoPliku(const char *);
                void porownanie();
                void sort();

                              
};

void klasa::wczytajZPliku(const char *nazwa)
{
        struct uczen dane;
ifstream plik1;
plik1.open(nazwa);  

   if(plik1.good())  
            while(!plik1.eof())  
            
                 {
                 plik1  >> dane.numer;
                 
                         spis.push_back(dane); 
                     
                         
                 }
                   plik1.close();  

}



void klasa::wypisz()
{
		string napis;
		ifstream plik;
		    plik.open("a.txt");
		    if(plik.good())
		     while(!plik.eof())
		    {
		        plik>>napis;
		    }
		    plik.close();
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.end()-1; it != spis.begin()-1; --it)
        {
                plik<<it->numer<<" ";
            	cout<<it->numer<<" ";

        }
        plik.close();  
}

void klasa::porownanie()
{
	int poprzednia;
	
	for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
        	if(it!=spis.begin() && it!=spis.end())
        	{
        		
			
			if(it->numer == poprzednia +1 || it->numer == poprzednia || it->numer == poprzednia - 1)
			{
				
				cout<<poprzednia<<",";
				cout<<it->numer<<" ";
			}
			poprzednia=it->numer;
		}
        }
	
	
}
int func(const void * a, const void * b)
{
	struct uczen * liczba1=(struct uczen*)a;
	struct uczen * liczba2=(struct uczen*)b;
   return (liczba1->numer-liczba2->numer);
 
}

void klasa::sort()
{	
	qsort(&spis[0],spis.size(), sizeof(struct uczen), func); 
	 for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
            	cout<<it->numer<<" ";

        }
}




int main(int argc, char** argv) {
		    klasa TI;
        TI.wczytajZPliku("b.txt");
		int wybor;
		cout<<"Co chcesz zrobic?"<<endl;
		cout<<"1. porownanie"<<endl;
		cout<<"2. sortowanie"<<endl;
		cout<<"3. zapisanie do pliku od tylu"<<endl;
		cout<<"aby zakonczyc wciœnij 0"<<endl;
		do{
			cout<<endl;
		cin>>wybor;
		switch(wybor)
		{
        case 1:
        	
        	TI.porownanie();
        	
        	break;
        
        case 2:
        	
           	TI.sort();

        	break;
        
        case 3:
        	
        	TI.zapiszDoPliku("a.txt");

        	break;
        }
    }while(wybor==1 || wybor==2 || wybor==3);
        
        return 0;
}

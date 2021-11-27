#define HashMod 97
#include<iostream>
using namespace std;

unsigned long long Entrada(char entrada)
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
}
unsigned long long Numero(string entrada, string entradaM, string entradaMo, int entradaYear)
{
	unsigned long long Salida=0;
	for(int i=0;entrada[i] != '\0';i++)
	{
		if(entrada[1+i] == '\0' && i==0)
			Salida+=Entrada(entrada[i]);
		else
		{
			if(i==0)
			{
				Salida += Entrada(entrada[i]);
				continue;
			}
			else
			{
				
				int miChar = Entrada(entrada[i]);
				if(miChar>99)
				{
					Salida*=1000;
				}
				else if(miChar>9)
				{
					Salida*=100;
				}
				
				Salida += miChar;
			}
				
			
		}
	}
	return Salida;
}

int  ins(string entrada, string entradaM,string entradaMo,int entradaYear)
{
	unsigned long long Amodular = Numero(entrada, entradaM, entradaMo, entradaYear);
	int Salida = Amodular%HashMod;
	return Salida;
}


main()
{
	string Tabla[97];
	for(int i = 0; i<97; i++)
	{
		Tabla[i]="";
	}
			
	int OpcMen=0;
	do
	{
		cout<<"---Menu hash---\n";
		cout<<"1. insertar Placa\n";
		cout<<"2. ver elementos Placa\n";
		cout<<"Ingrese su opcion:";
		
		cin>>OpcMen;
		
		if(OpcMen == 1)
		{
			string Placa, Marca, Modelo; 
			int year;

			cout<<"ingrese su Placa: ";
			cin>>Placa>>Marca>>Modelo>>year;
			int Pos = ins(Placa, Marca, Modelo, year);
			cout<<"\nValor hash: "<<Pos<<" "<<Placa<<" "<<Marca<<" "<<Modelo<<" "<<year;
			if(Tabla[Pos]=="null" || Tabla[Pos]==Placa, Marca, Modelo, year)
				Tabla[Pos]=Placa, Marca, Modelo, year;
			else
				for(int i=Pos;i<HashMod;i++)
					if(Tabla[i]=="NULL")
					{
						Tabla[i]=Placa, Marca, Modelo, year;
						break;
					}
						
			
		}
		
		if(OpcMen == 2)
		{
			for(int i = 0; i<97; i++)
			{
				cout<<i<<" "<<Tabla[i]<<"\n";
			}
		}

	cout<<"\n\n";
		
	}while(OpcMen!=0);
	
	
}

/*El programa tiene que ser capaz de ingresar las fechas en una cadena, 
usando una cadena y después la tenemos que dividir. El programa tiene que 
ser capaz de diferenciar los años biciestos. 
- Para separar la cadena tenemos que buscar split string c++
- El usuario ingresa los datos manualmente y juntos
- Ingresa los datos por Año/mes/día */
//------------------------------------------------------------------------------------------------------
/*            Links consultados:
1. https://www.javatpoint.com/how-to-split-strings-in-cpp
2. https://www.delftstack.com/es/howto/cpp/how-to-convert-
string-to-int-in-cpp/#:~:text=en%20C%2B%2B.-,Usa%20el%20
método%20std%3A%3Astoi%20para%20convertir%20la%20cadena,del%2
0tipo%20string%20para%20operar.         */
//------------------------------------------------------------------------------------------------------
/* COMO SABER SI UN AÑO ES BISIESTO: sacado de un programa que hicimos en 1ero
Para determinar si un año es bisiesto, siga estos pasos:

1. Si el año es uniformemente divisible por 4, vaya al paso 2. De lo contrario, vaya al paso 5.
2. Si el año es uniformemente divisible por 100, vaya al paso 3. De lo contrario, vaya al paso 4.
3. Si el año es uniformemente divisible por 400, vaya al paso 4. De lo contrario, vaya al paso 5.
4. El año es un año bisiesto (tiene 366 días).
5. El año no es un año bisiesto (tiene 365 días).
*/
//------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Date{
    private: //Atributos
        int Day, Month, Year, Bisiesto;
    public: //Metodos
        Date(char date[11]){ //Constructor
            char *p;            
            p = strtok(date, "/");  //Separa los strings usando el / y los guarda en p
    		Year = stoi(p); //Toma la primera string separada (Año) de p y convierte a int
    		p = strtok(NULL, "/"); //Valida que haya un / (delimitador) despues del string
    		Month = stoi(p); //Detetcta un /, convierte la segunda string de p a int
    		p = strtok(NULL, "/");//Valida que haya un / (delimitador) despues del string
    		Day = stoi(p); //Detecta un /, convierte la tercera string de p a int
    		p = strtok(NULL, "/");//Valida que haya un / (delimitador) despues del string
        }
        void validaciones(){
        	if(Year >1999 && Year <2100){
        		anioBisiesto();
        		if(Month >0 && Month <13){
					validarMonth();
        			if(Day >0 && Day <32){
        				showDate();
					}
					else{
					cout<<"\nDato fuera de rango"<<endl;
					}
				}
				else{
				cout<<"\nDato fuera de rango"<<endl;
				}
			}
			else{
				cout<<"\nDato fuera de rango"<<endl;
			}
		}
		void anioBisiesto(){
			if(Year %4 == 0){
				if(Year %100 ==0){
					if(Year %400 == 0){
						cout<<endl;
						cout<<"El anio "<<Year<<" es bisiesto"<<endl;
						Bisiesto = 1; 
					}
					else{
						cout<<endl;
						cout<<"El anio "<<Year<<" no es bisiesto"<<endl;
						Bisiesto = 2;
					}
				}
				else{
					cout<<endl;
					cout<<"El anio "<<Year<<" es bisiesto"<<endl;
					Bisiesto = 1; 
				}				
			}
			else{
				cout<<endl;
				cout<<"El anio "<<Year<<" no es bisiesto"<<endl;
				Bisiesto = 2;
			}
		}
		void validarMonth(){
			if(Month<0){
				Month = 1;
			}
			else if(Month >12){
				Month = 12;
			}switch(Month){
				case 1: //ENERO
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
				case 2: //FEBRERO
					if(Bisiesto = 1){
						if(Day >29){
							Day = 29;
						}
					}
					else if(Bisiesto = 2){
						if(Day > 28){
							Day = 28;
						}
					}
				break;
				case 3: //MARZO
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
				case 4: //ABRIL
					if(Day <1){
						Day = 1;
					}
					if(Day >30){
						Day = 30;
					}
				break;
				case 5: //MAYO
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
				case 6: //JUNIO
					if(Day <1){
						Day = 1;
					}
					if(Day >30){
						Day = 30;
					}
				break;
				case 7: //JULIO
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
				case 8: //AGOSTO
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
				case 9: //SEPTIEMBRE
					if(Day <1){
						Day = 1;
					}
					if(Day >30){
						Day = 30;
					}
				break;
				case 10: //OCTUBRE
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
				case 11: //NOVIEMBRE
					if(Day <1){
						Day = 1;
					}
					if(Day >30){
						Day = 30;
					}
				break;
				case 12: //DICIEMBRE
					if(Day <1){
						Day = 1;
					}
					if(Day >31){
						Day = 31;
					}
				break;
			}
		}
		void showDate(){
			cout<<endl;
			cout<<"Sus numeros enteros son: "<<endl;
			cout<<"Anio: "<<Year<<endl;
    		cout<<"Mes: "<<Month<<endl;
    		cout<<"Dia: "<<Day<<endl;
		} 
};

int main(){
	int opc = 1;
	while(opc == 1){
		char date[11];
		system("cls");
		cout<<"=================================================================="<<endl;
		cout<<"                 Separador de fechas - Luis Mendoza"<<endl;
		cout<<"=================================================================="<<endl;
		cout<<endl;
		cout<<"Informacion a tener en cuenta: "<<endl;
		cout<<"- Dato de anio entre 2000 - 2099\n- Dato de mes entre 1 - 12\n- Dato de dia entre 1-31"<<endl;
		cout<<endl;
		cout<<"Formato YYYY/MM/DD"<<endl;
		cout<<"Ingrese la fecha: ";
		fflush(stdin);
		cin.getline(date, 11); //Leemos el string

    	//Creamos el objeto y le asignamos el valor
    	Date a = Date(date);
    	
    	a.validaciones();

    	cout<<endl;
    	cout<<"Desea repetir el programa?"<<endl;
    	cout<<"1. Si \n2. No"<<endl;
    	cin>>opc;
	}	
	return 0;
}   
#include <iostream>
#include <cstdlib>


using namespace std;

int main (){
	
	setlocale(LC_ALL, "spanish"); //Permite utilizar tildes en la consola de C++
	
	// Variables constantes para el ahorro energ�tico seg�n la hora del d�a
	const float ModoAhorroMax = 0.80;  // 80% de ahorro durante la noche
	const float ModoAhorroMin = 0.25;    // 25% de ahorro durante el d�a
	
	// Declaracion de variables
	int horaInicioAhorro = 0;
	int horaFinAhorro = 0;         
	float consumoElectrico = 0.0;            
	float iluminacion = 0.0;                
	float climatizacion = 0.0;             
	float temperatura = 0.0;              
	float consumoAhorrado = 0.0;         
	int hora, opcionMenu;
	float ahorroIluminacion = 0.0;
	float ahorroClimatizacion = 0.0;
	float ahorroConsumoElectrico = 0.0;
	string modoAhorro;

	// Configuraci�n inicial
	printf("Configuraci�n inicial del sistema de gesti�n energ�tica\n");
	printf("Horario de inicio del modo ahorro (24h): ");
	scanf("%i", &horaInicioAhorro);
	printf("Horario de fin del modo ahorro (24h): ");
	scanf("%i", &horaFinAhorro);
	
	system("pause");
	system("cls");
	
	printf("********************************************************** \n");
	printf("*                                                        * \n");
	printf("*         Sistema de Gesti�n de Edificios (BMS)          * \n");
	printf("*                                                        * \n");
	printf("********************************************************** \n");
	
	do{
		
		printf("Ingrese la hora actual (en formato 24h): \n");
		scanf("%i", &hora);
		printf("Ingrese la temperatura actual (en �C): \n");
		scanf("%f", &temperatura);
		printf("Ingrese el consumo de la iluminaci�n (En kWh): \n" );
		scanf("%f", &iluminacion);
		printf("Ingrese el consumo de la climatizaci�n: \n");
		scanf("%f", &climatizacion);
		printf("Ingrese el consumo el�ctrico: \n");
		scanf("%f", &consumoElectrico);
		printf("\n");
		
		
		printf("\n");
		printf("****************************************************\n");
		printf("Datos Actuales Ingresados:\n");
		printf("Consumo Iluminacion: %0.2f kWh\n",iluminacion);
		printf("Consumo Calefaccion: %0.2f kWh\n",climatizacion);
		printf("Consumo Electrico: %0.2f kWh\n",consumoElectrico);
		printf("Temperatura: %0.2f �C\n",temperatura);
		printf("****************************************************\n");
		
		if (hora>=horaInicioAhorro || hora < horaFinAhorro){
			modoAhorro = "Activado";
			ahorroIluminacion += (iluminacion*ModoAhorroMax);
			ahorroClimatizacion += (climatizacion*ModoAhorroMax);
			ahorroConsumoElectrico += (consumoElectrico*ModoAhorroMax);
			consumoAhorrado += consumoElectrico * ModoAhorroMax + climatizacion * ModoAhorroMax;
			consumoElectrico *= (1 - ModoAhorroMax);
			iluminacion *= (1 - ModoAhorroMax); //menos luces encendidas
			climatizacion *= (1 - ModoAhorroMax);
			
		}else{
			modoAhorro = "Desactivado";
			ahorroClimatizacion += (climatizacion*ModoAhorroMin);
			ahorroConsumoElectrico += (consumoElectrico*ModoAhorroMin);
			ahorroIluminacion += (iluminacion*ModoAhorroMin);
			consumoAhorrado += consumoElectrico * ModoAhorroMin + iluminacion * ModoAhorroMin + climatizacion * ModoAhorroMin;
			consumoElectrico *= (1 - ModoAhorroMin);
			iluminacion *= (1 - ModoAhorroMin);
			climatizacion *= (1 - ModoAhorroMin);
			if(temperatura <20 || temperatura > 28) {
				temperatura = 24;
				cout << "Ajustando Temperatura para mayor confort\n";
			}
		}
		printf("\n");
		printf("****************************************************\n");
		printf("Consumo Energetico con Ahorros Aplicados:\n");
		printf("Modo ahorro: %s\n", modoAhorro.c_str());
		printf("Consumo Iluminacion: %0.2f kWh\n",iluminacion);
		printf("Consumo Calefaccion: %0.2f kWh\n",climatizacion);
		printf("Consumo Electrico: %0.2f kWh\n",consumoElectrico);
		printf("Temperatura: %0.2f �C\n",temperatura);
		printf("****************************************************\n");
		
		printf("\n");
		printf("�Desea ingresar otros valores? \n");
		printf("1. Si \n");
		printf("2. Salir\n");
		scanf("%i", &opcionMenu);
		printf("\n");
		
	} while(opcionMenu == 1);
	
	printf("\n");
	printf("****************************************************\n");
	printf("Estad�sticas \n");
	printf("Consumo de Iluminacion Ahorrado: %0.2f kWh\n",ahorroIluminacion);
	printf("Consumo de Climatizaci�n Ahorrado: %0.2f kWh\n",ahorroClimatizacion);
	printf("Consumo de Energ�a El�ctrica Ahorrado: %0.2f kWh\n",ahorroConsumoElectrico);
	printf("Consumo Total Ahorrado: %0.2fkWh\n",consumoAhorrado);
	printf("****************************************************\n");
	
	return 0;
}


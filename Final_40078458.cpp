/*Final 01.12.21. (17)   Apellido y nombre: García Santiago Daniel     DNI: 40078458   

Una empresa dedicada a la venta de artículos varios, con 30 sucursales,
desea conocer la comisión que debe abonar a c/u de sus vendedores, de acuerdo
al monto de sus ventas en el mes, que sera del 5%, en caso de ser menor a
$ 100.000 y del 10% en los casos de que sus ventas mensual sean >= $ 100.000.
Se solicita se informe los Totales por:  Vendedor y Sucursal.
Se dispone de los siguientes datos:  Nro. Sucursal (1/30), Nro. de Vendedor (1/200)
e Importe de cada una de sus ventas.

Los datos se encuentran ordenados por Nro. de Sucursal y Nro. de vendedor,
ambos en orden ascendente. Para finalizar Sucursal = 999.    
Por cada corte de control, se deberá informar:

Total por cada vendedor:
    a)  Nro. de Sucursal.
    b)  Nro. de vendedor.
    c)  Cantidad de facturas emitidas en el mes.
    d   Importe total de sus ventas en el mes.
    e)  Comisión  a abonar  (5% o 10% según corresponda, del total de sus ventas).
Total por cada Sucursal:
    a)  Nro. de Sucursal.
    b)  Cantidad de facturas emitidas en el mes.
    c)  Importe total de ventas en el mes.
    d)  Importe total de Comisión a abonar.  

Se requiere: Codificación en lenguaje C++, aplicando cortes de control  por:
Sucursal y Vendedor (utilizando funciones de Sucursal y Vendedor en caso de considerarlo
necesario o conveniente).*/

#include<stdio.h> 
#include<conio.h> 
#include<cstring>
#include<stdlib.h>
#include <iostream>
using namespace std;

//Sector funciones
fsucursal (int a, int b) {
int sucursal;
do {cout << "\n\nIngrese numero de sucursal (Minimo 1 - Maximo 30 - Cerrar programa con 999): "; cin >> sucursal; cout << "\nHa ingresado: " << sucursal;}	
while (sucursal < a && sucursal > b);
return sucursal;
}
//Fin Sector funciones

main (){

//Sector vaiables globales
int sucursal, presucursal, nvendedor = 0, facturasven, factsuc = 0;
double comision = 0, ventasven = 0, ventasuc = 0, comisuc = 0;
string negocio, salida;
//Fin Sector variables globales

cout << "Bienvenido/a a mi examen final. Espero sea de su agrado." << "\n\nEn esta oportunidad voy a ayudarle a gestionar su negocio.";
cout << "\n\nDigame el nombre de su negocio: "; cin >> negocio;
cout << "\nMuy bien, empecemos la gestion para: " << negocio;

sucursal = fsucursal (1,30);

while (sucursal > 0  && sucursal <= 30 && sucursal != 999){ //W1 

presucursal = sucursal;

while (sucursal == presucursal && sucursal != 999){ //W2 

cout << "\n\nIngrese numero de vendedor (Minimo 1 - Maximo 200): "; cin >> nvendedor; 

if (nvendedor >= 200 or nvendedor == 0) {
cout << "\nEl numero vendedor - " << nvendedor << " - Es incorrecto.";	
cout << "\nIngrese numero de vendedor (Minimo 1 - Maximo 200): "; cin >> nvendedor; 
} 

cout << "\nIngrese el numero de facturas mensuales emitidas por dicho vendedor: "; cin >> facturasven; 
cout << "\nIngrese el importe total de facturacion mensual de dicho vendedor: "; cin >> ventasven;

if (ventasven < 100000){
comision = 5*ventasven/100;		
} else {
comision = 10*ventasven/100;		
}

cout << "\n\nIMPRESION DE VALORES DEL VENDEDOR NUMERO - " << nvendedor << " - " << "AL SERVICIO DE " << negocio;
cout << "\n\nNumero de sucursal: " << presucursal;
cout << "\nCantidad de facturas emitidas durante el mismo mes: " << facturasven;
cout << "\nImporte total de ventas mensuales: " << ventasven;
cout << "\nComision a abonar: " << comision;	

factsuc += facturasven; ventasuc += ventasven; comisuc += comision; facturasven = 0;

sucursal = fsucursal (1,30);
} //W2 

cout << "\n\nIMPRESION DE VALORES DE LA SUCURSAL NUMERO - " << presucursal << " - " << "AL SERVICIO DE " << negocio;
cout << "\n\nCantidad de facturas emitidas durante el mismo mes: " << factsuc;
cout << "\nImporte total de ventas mensuales: " << ventasuc;
cout << "\nComision total a abonar: " << comisuc;
factsuc = 0; ventasuc = 0; comisuc = 0;
cout << "\n\nSi desea continuar, escriba 'continuar'. Si prefiere detener el programa, escriba '999': "; cin >> salida;

if (salida == "continuar") {sucursal = fsucursal (1,30);}
else {cout << "\n\nGracias por utilizar nuestro servicios."; exit (1);}
} //W1
cout << "\n\nGracias por utilizar nuestro servicios.";
return(0); 
}


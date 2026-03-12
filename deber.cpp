/*

 Documentación de uso de IA (Copilot) y ademas obtuve ayuda del learning center.

Herramienta usada:
Microsoft Copilot
Propósito del uso:
- Asistencia en el formateo de separadores de miles en la salida del programa.
- Generación de un timestamp formateado a partir de los datos ingresados por el usuario.
Qué acepté:
1.	La sugerencia de std::cout.imbue(locale("")) para aplicar formato local en separadores de miles, 
ya que ni iomanip ni la impresión directa de un double agregan separadores de miles por sí mismos. 
El uso de locale permite que los números se adapten automáticamente a la configuración regional del sistema. 
De esta forma, el programa ofrece una salida más clara, estandarizada y portable para el usuario.
2.	El uso de snprintf para construir un timestamp con formato consistente (AAAA-MM-DD HH:MM AM/PM).
Qué rechacé:
- El uso de put_money, numpunct y stringstream para el formateo de decimales.
- El uso de ostringstream para el formateo del timestamp.
Cómo integré el resultado:
- Las secciones aceptadas se marcaron explícitamente en el código con comentarios:
//copilot [AI-START] ... [AI-END]
- Se mantuvo la estructura original del programa, incorporando las mejoras de Copilot únicamente en los puntos de formato de salida y timestamp.

*/
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <locale>


using namespace std;




int main() { 
    string base, cotizada;
    double montoBase, montoCotizado;
    long double tasa;
    char continuar = 'C';

    //copilot, formateo de separador de miles [AI-START]
    std::cout.imbue(locale(""));  
    //[AI-END]


    //Bienvenida del usurio
    std:: cout << "Bienvenido"<< endl;
    std:: cout << "Este es un programa creador por FinTech que convierte divisas entre EUR y USD (euros y dolares)."<< endl;

    while (continuar == 'C' or continuar == 'c') {
    

    base = ""; cotizada = "";

    // Ingreso de la divisas 
    // divisa base
     while (base!= "USD" and base!= "EUR") {
        std:: cout << "Ingrese la divisa base (USD o EUR): ";
        cin >> base;
     bool valido = true;
        if (base.size() != 3) { 
            std:: cout << "Error: debe ingresar unicamente 3 caracteres." << endl; base = ""; continue; }
        for (char c : base) { if (!isalpha(c)) { 
            std:: cout << "Error: solo se permiten letras, no números ni símbolos." << endl; base = ""; 
            valido = false; break; }
        }
        if (valido and base != "USD" and base != "EUR") {
            std:: cout << "Error: debe ingresar exactamente 'USD' o 'EUR'." << endl; base = ""; continue;
        }
     }
        
    

    //divisa cotizada

     while (cotizada!= "USD" and cotizada!= "EUR") {
        std:: cout << "Ingrese la divisa cotizada (USD o EUR): ";
        cin >> cotizada;
     bool valido = true;
        if (cotizada.size() != 3) { 
            std:: cout << "Error: debe ingresar unicamente 3 caracteres." << endl; cotizada = ""; continue; }
        for (char c : cotizada) { if (!isalpha(c)) { 
            std:: cout << "Error: solo se permiten letras, no números ni símbolos." << endl; cotizada = ""; 
            valido = false; break;}
        }
        if (valido and cotizada != "USD" and cotizada != "EUR") {
            std:: cout << "Error: debe ingresar exactamente 'USD' o 'EUR'." << endl; cotizada= "";}
        
     }

    std:: cout << "Par seleccionado: " << base << "/" << cotizada << endl;

   // ingreso de la tasa de cambio

  tasa = 0.0; 
  while (tasa <= 0.0) {
    std:: cout << "Ingrese la tasa de cambio (" << base << "/" << cotizada << "): "; 
   string entrada; 
   cin >> entrada; 
   for (char &c : entrada) { 
    if (c == ',') c = '.'; } 
    try { tasa = stod(entrada); } 
    catch (...) { tasa = 0.0; }
    if (tasa <= 0.0) { 
    std:: cout << "Error: la tasa debe ser un número positivo mayor que cero." << endl; }
      }
    // ingreso del montos base (mejora 1: multiples escenarios de monto)
    vector<double> montos;
    string entradamonto;
    montoBase = 0.0;


    while (true) {
            std:: cout << "Ingrese los montos base en " << base << " (o X para dejar de insertar montos): ";
            cin >> entradamonto;

            if (entradamonto == "X" or entradamonto == "x") {
                break;
            }

            bool Numero = true;
            for (char c : entradamonto) {
            if (!isdigit(c) and c != '.') {
                Numero = false;
                break;
            }
            }
           if (Numero) {
            montoBase = stod(entradamonto);
            if (montoBase > 0.0) {
                montos.push_back(montoBase);
            } else {
               std:: cout << "Error: el monto debe ser positivo." << endl;
            }
           } else {
           std:: cout << "Error: entrada inválida, debe ser un número mayor que cero o X para salir." << endl;
        }
    
    }


    // calculo mejora 2: conversion inversa automatica de la divisa



            double tasa2;
            tasa2= 1/tasa;


            

    //timestamp

     int year, mes, dia, hora, minuto; 
     string ampm;

     std:: cout << "Ingrese el año: "; 
     cin >> year; 
     std:: cout << "Ingrese el mes (1-12): "; 
     cin >> mes; 
     std:: cout << "Ingrese el día (1-31): "; 
     cin >> dia;
     std:: cout << "Ingrese la hora (1-12): "; 
     cin >> hora; 
     std:: cout << "Ingrese los minutos (0-59): "; 
     cin >> minuto; 
     std:: cout << "Ingrese AM o PM: "; 
     cin >> ampm;

     // copilot, formateada corecta del valor que ingrese el usuario en el timestamp [AI-START]
    char buffer[30]; 
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02d:%02d %s", year, mes, dia, hora, minuto, ampm.c_str()); 
    string timestamp(buffer);
    // [AI-END] 

    //reporte 
    std:: cout << "-----Reporte----" << endl;
    std::cout << "Timestamp: " << timestamp << endl;
    std::cout << "Par seleccionado: " << base << "/" << cotizada << endl;
    std::cout << fixed << setprecision(5); 
    std::cout << "Tasa: 1 " << base << " = " << tasa << " " << cotizada << endl;
    std::cout << "Tasa: 1 " << cotizada << " = " << tasa2 << " " << base << endl;
    std::cout << fixed << setprecision(2); 
    std::cout << "Montos base ingresados:" << endl;
    for (double monto : montos) {
    std:: cout << monto << " " << base << endl; }
    std::cout << "Montos cotizados:" << endl;
    for (double monto : montos) {
    montoCotizado = monto * tasa;
    std::cout << montoCotizado << " " << cotizada << endl;
    }



    std::cout << "¿Desea continuar? (C para continuar, cualquier otra tecla para salir): "; 
    cin >> continuar; 
}

    //final
    
   std:: cout << "Gracias por usar el conversor de divisas." << endl; 
   return 0;

}

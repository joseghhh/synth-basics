# Synth Basics
 
Un generador de ondas basico en C++, construido desde cero para entender como funciona el audio digital.
 
## Que es esto
 
La idea es entender como funciona el audio digital desde la base: generar ondas (senoidal, sierra, cuadrada) matematicamente, sin usar ninguna libreria que ya resuelva la sintesis.
 
El programa es simple: se ingresa un tipo de onda y la frecuencia en consola,
y se reproduce ese tono en tiempo real. Por debajo usa miniaudio para conectarse
con la tarjeta de sonido.
 
## Que aprendi
 
- Integrar una libreria externa (miniaudio) en un proyecto propio
- Como funciona un callback de audio en tiempo real
- Matematica basica de sintesis de audio (fase, frecuencia, sample rate)
- Organizar un proyecto en varios archivos (headers, separacion de responsabilidades)

## Estado del proyecto
 
Este es un proyecto activo, todavia en desarrollo. Los proximos pasos son:
 
- Resolver el aliasing en las ondas sierra y cuadrada (PolyBLEP)
- Agregar onda triangular

## Como compilar y correr
 
```
g++ -std=c++17 -Wall -Wextra main.cpp engine.cpp -o bin/synth
./bin/synth
```
 
El programa va a pedir un tipo de onda (sin, saw, sqr) y una frecuencia en Hz.
Por ejemplo: `saw 440`
 
## Estructura del proyecto
 
- **main.cpp** - Interaccion del programa con el usuario (lee el tipo de onda y frecuencia)
- **engine.h / engine.cpp** - Llamadas al dispositivo de audio usando miniaudio
- **oscillator.h** - El struct `Oscillator`, que genera el sonido matematicamente
- **miniaudio.h** - Libreria externa para acceso al hardware de audio

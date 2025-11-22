# F1548516_Examen_1

# PREGUNTA 2
## Desde la carpeta P2
export PATH="/c/ProgramData/mingw64/mingw64/bin:$PATH"
gcc -O2 -Wall -o p2_divisores p2_divisores.c
## Verificar ejecución
./p2_divisores.exe
## Genera ensamblador x86-64 en AT&T por defecto
gcc -O2 -Wall -S p2_divisores.c -o p2_divisores_x86.s
## Generar ensamblador ARM targeting Cortex-M4
arm-none-eabi-gcc -O2 -Wall -mcpu=cortex-m4 -mthumb -S p2_divisores.c -o p2_divisores_arm.s

# PREGUNTA 3
## La tabla completa se muestra en el archivo tabla_microcontroladores
## Los punteros se encuentran en el archivo punteros_nrf52840.c

# PREGUNTA 4
## Archivos incluidos
- regs.h
- buttons.c
- led.c
- adc.c
- main.c
## Compilación (sugerencia)
Este código está escrito con accesos directos a registros. Recomendado compilar dentro de ESP-IDF o con toolchain que soporte ESP32.
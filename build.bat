@echo off

g++ -std=c++17 -Wall -I".\include" -c ".\src\Vendedor.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\VendedorParticular.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\VendedorProfesional.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\VendedorEmpresa.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\Sucursal.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\main.cpp"


g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I".\include" Vendedor.o VendedorParticular.o VendedorProfesional.o VendedorEmpresa.o Sucursal.o main.o -o app.exe


DEL *.o

app.exe
pause




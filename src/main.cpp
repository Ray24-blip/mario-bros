#include<iostream>
#include<Porcentaje.hpp>

int main(){
    Porcentaje foco1,foco2,foco3;
  
    
    foco1.Incrementar(10);
    foco1.Incrementar(10);
    foco1.Disminuir(4);

    std::cout
    <<"Foco1: "
    <<foco1.Imprimir()
    <<std::endl;
}
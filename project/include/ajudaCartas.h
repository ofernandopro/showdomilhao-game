#ifndef AJUDA_CARTAS
#define AJUDA_CARTAS

using namespace std;
#include <string>
#include "ajuda.h"

class AjudaCartas : public Ajuda {
  
  	private: 
  		int *cartas;


    public:
        AjudaCartas(Pergunta*);        

        virtual string get_options() override;
        virtual void choose_option(int) override;
        virtual PerguntaComAjuda* get_perguntaComAjuda() override;
};

#endif // AJUDA_CARTAS
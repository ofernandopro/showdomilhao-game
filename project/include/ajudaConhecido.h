#ifndef AJUDA_CONHECIDO
#define AJUDA_CONHECIDO

using namespace std;
#include <string>
#include "ajuda.h"

class AjudaConhecido : public Ajuda {
  

    public:
        AjudaConhecido(Pergunta*);        

        virtual string get_options() override;
        virtual void choose_option(int) override;
        virtual PerguntaComAjuda* get_perguntaComAjuda() override;
};

#endif // AJUDA_CONHECIDO
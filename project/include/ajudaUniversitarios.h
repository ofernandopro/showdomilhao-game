#ifndef AJUDA_UNIVERSITARIOS
#define AJUDA_UNIVERSITARIOS

using namespace std;
#include <string>
#include "ajuda.h"

class AjudaUniversitarios : public Ajuda {
  

    public:
        AjudaUniversitarios(Pergunta*);                
        virtual PerguntaComAjuda* get_perguntaComAjuda() override;
};


#endif // AJUDA_UNIVERSITARIOS
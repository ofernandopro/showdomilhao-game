#ifndef PERGUNTA_COM_AJUDA_H
#define PERGUNTA_COM_AJUDA_H

using namespace std;
#include <string>
#include "pergunta.h"

class PerguntaComAjuda : public Pergunta {

    private:
        string ajuda;

    public:                
        PerguntaComAjuda(Pergunta*, string);
        PerguntaComAjuda();
        string get_ajuda();      
        void mostraAlternativas() override;  
};

#endif // PERGUNTA_COM_AJUDA_H
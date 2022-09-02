#ifndef AlfaCesar
#define AlfaCesar

#define MAXLEN 100

/*Tipos do TAD cases*/
typedef struct beto * cesar;

/********************************************************************
ConverterStringsMatriz   --> irá converter as strings individuais para uma única

Parâmetros de entrada    --> str: uma determinada escrita pelo usuário

Output                   --> fraseunificada: um vetor de caracteres que contém todos as frases escritas pelo utilizador
                         --> frases: numero de frases (linhas) que a matriz irá conter
                         --> z: 

Pre-condições            --> o comprimento do vetor "fraseunificada" não pode conter mais que 100 caracteres
********************************************************************/
cesar CriarCesar(char * str, int  code, int n_linhas);

int DeslocaSize(unsigned numero);

void Cifragem(cesar z);

char * MensagemCesariana(cesar z);

void DeleteCesar(cesar z);



#endif
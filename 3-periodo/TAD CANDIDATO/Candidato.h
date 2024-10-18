typedef struct candidato Candidato;

// Criar
Candidato* cad_cria (char* nome, int idade, int nota1, int nota2);

// liberar
void cad_libera (Candidato* cand);

// exibir 
void cad_exibe (Candidato* cand);

// get
char* cad_getCandidato(Candidato* cand);

// get para cada atributo (desejável)
// set para cada atributo  (desejável)

/* ehTestador: recebe a pontuação para cada jogo  do testador ideal  e um limiar. Retorna True  se o candidato pode 
ser um testador do novo jogo ou 0, caso contrário. (nesse exemplo: nota 5 ao primeiro jogo e nota 8  ao 2º) Para ser 
testador, as notas do candidato  devem estar a uma distância menor ou igual ao limiar das notas do testador ideal.*/
int cad_ehTestador (Candidato* cand, int ntJ1, int ntJ2, float limiar);

// Compara : recebe dois candidatos e  retorna -1, se o primeiro é mais jovem que o segundo, 0 se tem a mesma idade e +1,caso contrário
int cad_compara (Candidato* cand1, Candidato* cand2);
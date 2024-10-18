typedef struct retangulo Retangulo;

Retangulo* rtg_cria (float xie, float yie, float xsd, float ysd);

void rtg_libera (Retangulo* R);

float rtg_area (Retangulo* R);

void rtg_exibe (Retangulo* R);

char* rtg_getRetangulo (Retangulo* R);
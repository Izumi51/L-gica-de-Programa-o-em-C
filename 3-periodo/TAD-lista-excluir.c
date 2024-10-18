void excluir (tLista *lista, int valor)
{
    int pos;
    int st;
    
    if(lista_vazia(lista))
    {
        return;
    }
    
    if(!lista_classif(lista) && lista_repet(lista))  // sem classi e com rep
    {
        busca_des_srep(lista, valor, &pos);
        /*while(busca_des_srep(lista, valor, &pos))
        {
            int qt = lista->qtnos - pos - 1;
            memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
            lista->qtnos -= 1;
        }*/
        
    }else{
        if(lista_classif(lista))
        {
            if (lista_repet(lista)) // classi e com rep
            {
                busca_bin(lista, valor, &pos);
                /*while(busca_bin(lista, valor, &pos))
                {
                    // int qt = lista->qtnos - pos - 1;
                    // memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
                    // lista->qtnos -= 1;
                    // return;
                }*/
                
                // if (busca_bin(lista, valor, &pos) == 1) // classi e sem rep
                // {
                //     printf("entrou");
                    
                //     int qt = lista->qtnos - pos - 1;
                //     printf("\n%d, %d\n", pos, qt);
                //     memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
                //     lista->qtnos -= 1;
                // }
                
            }
            
            st = busca_bin(lista, valor, &pos) == 1 // classi e sem rep

        }else{
            st = busca_des_srep(lista, valor, &pos) // sem classi e sem rep
        }
    }

    if (!lista_repet(lista) && (st == 1))
    {
        int qt = lista->qtnos - pos - 1;
        memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
        lista->qtnos -= 1;
        return;
    }else{
        teste (lista, pos);
        return;
    }
}

    teste (tLista *lista, int posIn)
{
int posfim = pos;

while ((posfim < lista->qtnos-1) && (lista->vnos[posfim+1] == valor))
{
    posfim++;
}


memcpy(lista->vnos+pos, lista->vnos[posfim], (qtnos - posfim) * sizeof(int));

if (lista_classi)
}



/*void excluir (tLista *lista, int valor)
{
    int pos;
    int st;
    
    if(lista_vazia(lista))
    {
        return;
    }
    
    if(!lista_classif(lista) && lista_repet(lista))  // sem classi e com rep
    {
        while(busca_des_srep(lista, valor, &pos))
        {
            int qt = lista->qtnos - pos - 1;
            memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
            lista->qtnos -= 1;
        }
        return;
    }else{
        if(lista_classif(lista))
        {
            if (lista_repet(lista)) // classi e com rep
            {
                while(busca_bin(lista, valor, &pos))
                {
                    int qt = lista->qtnos - pos - 1;
                    memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
                    lista->qtnos -= 1;
                    return;
                }
                
                // if (busca_bin(lista, valor, &pos) == 1) // classi e sem rep
                // {
                //     printf("entrou");
                    
                //     int qt = lista->qtnos - pos - 1;
                //     printf("\n%d, %d\n", pos, qt);
                //     memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
                //     lista->qtnos -= 1;
                // }
                
            }
            
            if (busca_bin(lista, valor, &pos) == 1) // classi e sem rep
            {
                printf("entrou");
                
                int qt = lista->qtnos - pos - 1;
                printf("\n%d, %d\n", pos, qt);
                memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
                lista->qtnos -= 1;
                return;
            }
            
        }else{
            if(busca_des_srep(lista, valor, &pos)) // sem classi e sem rep
            {
                int qt = lista->qtnos - pos - 1;
                memcpy(lista->vnos+pos, lista->vnos+pos+1, qt * sizeof(int));
                lista->qtnos -= 1;
                return;
            }
        
        }
    }
}*/

typedef struct{
 char CIN[255];
 char Nom[255];
 char Prenom[255];
 double Montant;
}card;

typedef struct{
    int len;
    card* array;
}bank;


//campreCard
//@params void* a
//@params void* b
//return int

int campreCard(const void* a, const void* b){
    if( ((card*)a)->Montant > ((card*)b)->Montant)
        return 1;
    else if( ((card*)a)->Montant < ((card*)b)->Montant)
        return -1;
    else
        return 0;
}
//nombre total des cards
//@params f FILE*
//return int
int taille(FILE *f){
    int cpt = 0;
    char CIN[255], Nom[255], Prenom[255];
    double Montant;
    while((fscanf(f, "%s %s %s %lf", CIN, Nom, Prenom, &Montant)) == 4){
        cpt++;
    }
    return cpt;
}

// initialisation pour la banque
//@params f FILE*
//return bank

bank init(FILE* f, int n){
    char CIN[255], Nom[255], Prenom[255];
    double Montant;
    int i = 0;
    bank tmp_bank;
    tmp_bank.len = n;
    tmp_bank.array = malloc(sizeof(card)*n);
    while((fscanf(f, "%s %s %s %lf", CIN, Nom, Prenom, &Montant)) == 4 && i<n){
        card tmp = {.Montant = Montant};
        strcpy(tmp.CIN, CIN);
        strcpy(tmp.Nom, Nom);
        strcpy(tmp.Prenom, Prenom);
        tmp_bank.array[i++] = tmp;
    }
    fclose(f);
    return tmp_bank;
}

//affichage de tableau trier dans nouveau fichier
//@params f FILE*
//@params bank_unsorted bank

void print_bank(FILE* f, bank bank_unsorted){
    qsort(bank_unsorted.array, bank_unsorted.len, sizeof(card), campreCard);
    for(int i = 0;i < bank_unsorted.len;i++)
        fprintf(f, "%s %s %s %.2lf\n", bank_unsorted.array[i].CIN, bank_unsorted.array[i].Nom, bank_unsorted.array[i].Prenom, bank_unsorted.array[i].Montant);
    fclose(f);
}

//retrait
//@params CIN char*
//@params Montant double

void Retrait(bank* cards, char* CIN, double Montant){
    for(int i=0;i<(*cards).len;i++){
        if(!strcmp((*cards).array[i].CIN, CIN))
            if((*cards).array[i].Montant < Montant){
                printf("erreur!!!\n");
                return;
            }else{
                printf("Montant actuel de compte %d: %.2lf", i, (*cards).array[i].Montant-Montant);
                (*cards).array[i].Montant -= Montant;
                return;
            }
    }
} 


//depot
//@params CIN char*
//@params Montant double



void Depot(bank* cards, char* CIN, double Montant){
    for(int i=0;i<(*cards).len;i++){
        if(!strcmp((*cards).array[i].CIN, CIN))
            if(Montant < 0){
                printf("erreur!!!\n");
                return;
            }else{
                printf("Montant actuel de compte %d: %.2lf", i, (*cards).array[i].Montant+Montant);
                (*cards).array[i].Montant += Montant;
                return;
            }
    }
}



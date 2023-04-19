#include <stdio.h>
#include <stdlib.h>
struct drzewo{
    int klucz;
    int wartosc;
    struct drzewo *lewy,*prawy;
};
void dodaj(struct drzewo **korzen,int klucz,int wartosc){
    if(*korzen==NULL){
        *korzen=(struct drzewo*)malloc(sizeof(struct drzewo));
        if(*korzen!=NULL){
            (*korzen)->klucz=klucz;
            (*korzen)->wartosc=wartosc;
            (*korzen)->lewy=(*korzen)->prawy=NULL;
        }

    }else{
        if((*korzen)->klucz>=klucz){
            dodaj(&(*korzen)->lewy,klucz,wartosc);
        }else{
            dodaj(&(*korzen)->prawy,klucz,wartosc);
        }
    }
}
void szukaj(struct drzewo *korzen,int liczba){
    if(korzen!=NULL){
        if((korzen->klucz)==liczba){
            printf("Klucz: %d\nWartosc: %d\n\n",korzen->klucz,korzen->wartosc);
        }
        szukaj(korzen->lewy,liczba);
        szukaj(korzen->prawy,liczba);
    }

}
void dodaj_iteracja(struct drzewo **korzen,int klucz,int wartosc){
    while(*korzen!=NULL){
        if((*korzen)->klucz>=klucz){
            korzen= &(*korzen)->lewy;
        }else{
            korzen= &(*korzen)->prawy;
        }
    }
    *korzen =(struct drzewo*)malloc(sizeof(struct drzewo));
    if(*korzen){
        (*korzen)->klucz=klucz;
        (*korzen)->wartosc=wartosc;
        (*korzen)->lewy=(*korzen)->prawy=NULL;
    }
}
void inorder(struct drzewo *korzen){
    if(korzen!=NULL){
        inorder(korzen->lewy);
        printf("Klucz: %d\nWartosc: %d\n\n",korzen->klucz,korzen->wartosc);
        inorder(korzen->prawy);
    }
}
void odwrotnie_inorder(struct drzewo *korzen){
    if(korzen!=NULL){
        odwrotnie_inorder(korzen->prawy);
        printf("Klucz: %d\nWartosc: %d\n\n",korzen->klucz,korzen->wartosc);
        odwrotnie_inorder(korzen->lewy);
    }
}
void preorder(struct drzewo *korzen){
    if(korzen!=NULL){
        printf("Klucz: %d\nWartosc: %d\n\n",korzen->klucz,korzen->wartosc);
        preorder(korzen->lewy);
        preorder(korzen->prawy);
    }
}
void postorder(struct drzewo *korzen){
    if(korzen!=NULL){
        postorder(korzen->lewy);
        postorder(korzen->prawy);
        printf("Klucz: %d\nWartosc: %d\n\n",korzen->klucz,korzen->wartosc);
    }
}
void levelorder(struct drzewo *korzen,int wielkosc){
    for(int i=1;i<=wielkosc;i++){
        wypisz_poziom(korzen,i);
    }
}
int wypisz_poziom(struct drzewo *korzen,int poziom){
    //printf("%d\n",poziom);
    if(korzen==NULL){
        return 1;
    }
    if(poziom==1){
        //printf("%d\n",korzen->wartosc);
        printf("Klucz: %d\nWartosc: %d\n\n",korzen->klucz,korzen->wartosc);
    }else{
        wypisz_poziom(korzen->lewy,poziom-1);
        wypisz_poziom(korzen->prawy,poziom-1);
    }
}
int ilosc(struct drzewo *korzen){
    int wartosc=0;
    if(korzen!=NULL){
        wartosc+=ilosc(korzen->prawy);
        wartosc+=ilosc(korzen->lewy);
        if(korzen->prawy!=NULL || korzen->lewy!=NULL){
            wartosc++;
        }
    }
    return wartosc;
}
int main()
{
    srand(time(NULL));
    int wielkosc=8;
    struct drzewo *korzen=NULL;
    for(int i=0;i<wielkosc;i++)
    {
        int klucz;
        int wartosc;
       //wartosc=10+i;
        wartosc=10+rand()%15;
        klucz=wartosc;
        //dodaj(&korzen,klucz,wartosc);
        dodaj_iteracja(&korzen,klucz,wartosc);
    }
    printf("inorder\n");
    inorder(korzen);
    printf("odwrotnie inorder\n");
    odwrotnie_inorder(korzen);
    printf("\n -------------\n");
    printf("preorder\n");
    preorder(korzen);
    printf("\n -------------\n");
    printf("postorder\n");
    postorder(korzen);
    printf("\n -------------\n");
    printf("levelorder\n");
    levelorder(korzen,wielkosc);
    printf("-----------\n");
    printf("%d",ilosc(korzen));
    printf("\n-----------\n");
    int t;
    t=10+rand()%15;
    printf("Szukamy klucza %d\n",t);
    szukaj(korzen,t);
    return 0;
}

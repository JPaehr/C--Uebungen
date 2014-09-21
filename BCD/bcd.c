#include <stdio.h>
#include <stdlib.h>
#define ABS(x) x >= 0 ? x: -x
#define MAXLENGTH 2000


struct bcd {
    unsigned int k; // Anzahl der Vorkommastellen
    unsigned int l; // Anzahl der Nachkommastellen
    char vorzeichen;
    unsigned char *ziffern;
};

struct bcd * clean(struct bcd *a);

struct bcd *long2bcd(long int x){
    //printf("%ld", x);
    struct bcd * ptr;
    int i;
    long int xCopy;
    ptr = malloc(sizeof(struct bcd));
    ptr->k = 0;



    if(x >= 0){
        ptr->vorzeichen = '+';
    }
    else {
        ptr->vorzeichen = '-';
    }

    xCopy = ABS(x);
    x = ABS(x);

    ptr->l = 0;

    //stellen bestimmen;
    do{
        xCopy /= 10;
        ptr->k++;
    }
    while (xCopy != 0);


    ptr->ziffern = malloc((1+ptr->k)*sizeof(char));
    for(i = ptr->k-1; i >=0; i--){
        ptr->ziffern[i] = (x%10);
        x/=10;
    }


    return ptr;
}

struct bcd * add(struct bcd * c, struct bcd * d){
    struct bcd *ptr = malloc(sizeof(struct bcd));
    struct bcd *a, *b;
    struct bcd *ptr2;
    unsigned int i;
    a = clean(c);
    b = clean(d);
    unsigned int maxVor = a->k >= b->k ? a->k : b->k;
    unsigned int maxNach = a->l >= b->l ? a->l : b->l;
    ptr->k = maxVor+1;
    ptr->l = maxNach;
    int zahlOben, zahlUnten, uebertrag = 0;

    ptr->ziffern = malloc((maxNach+maxVor+2)*sizeof(char));
    for(i = 0;  i <  maxNach+maxVor+1; i++){
        ptr->ziffern[i] = 0;
    }

    //Vorzeichen gleich
    if((a->vorzeichen == '+' && b->vorzeichen == '+') || (a->vorzeichen == '-' && b->vorzeichen == '-')){
        ptr->vorzeichen = a->vorzeichen;
        for(i = maxNach; i > 0; i--){
            if(a->l < i){
                zahlOben = 0;
            }
            else{
                zahlOben = a->ziffern[a->k+i-2];
            }
            if(b->l < i){
                zahlUnten = 0;
            }
            else{
                zahlUnten = b->ziffern[b->k+i-2];
            }
            ptr->ziffern[maxVor+i] = (zahlOben+zahlUnten+uebertrag)%10;
            uebertrag = (zahlOben+zahlUnten+uebertrag)/10;
        }

        for(i = 0; i < maxVor;i++){
            if(a->k > i){
                zahlOben = a->ziffern[a->k-i-1];
            }
            else{
                zahlOben = 0;
            }
            if(b->k > i){
                zahlUnten = b->ziffern[b->k-i-1];
            }
            else{
                zahlUnten = 0;
            }
            ptr->ziffern[maxVor-i] = (zahlOben+zahlUnten+uebertrag)%10;
            uebertrag = (zahlOben+zahlUnten+uebertrag)/10;
        }
    }
    else{
        //Vorzeichen ungleich
        if(biggerThan(a, b) != 2){

            struct bcd * ptrBigger, *ptrSmaller;

            if(biggerThan(a, b) == 1){
                ptr->vorzeichen = a->vorzeichen;
                ptrBigger = a;
                ptrSmaller = b;
            }
            else{
                ptr->vorzeichen = b->vorzeichen;
                ptrBigger = b;
                ptrSmaller = a;
            }




            ////////////////
            if(maxNach > 0){
                for(i = maxNach-1; i >=0 ; i--){
                    if(ptrBigger->l <= i){
                        zahlOben = 0;
                    }
                    else{
                        zahlOben = ptrBigger->ziffern[ptrBigger->k+i];
                    }
                    if(ptrSmaller->l <= i){
                        zahlUnten = 0;
                    }
                    else{
                        zahlUnten = ptrSmaller->ziffern[ptrSmaller->k+i];
                    }
                    if(zahlOben >= zahlUnten+uebertrag){
                        ptr->ziffern[maxVor+i] = zahlOben-zahlUnten-uebertrag;
                        uebertrag = 0;
                    }
                    else{
                        ptr->ziffern[maxVor+i] = zahlOben-zahlUnten-uebertrag+10;
                        uebertrag = 1;
                    }
                }
            }

            for(i = 0; i < maxVor;i++){
                if(ptrBigger->k > i){
                    zahlOben = ptrBigger->ziffern[ptrBigger->k-i-1];
                }
                else{
                    zahlOben = 0;
                }
                if(ptrSmaller->k > i){
                    zahlUnten = ptrSmaller->ziffern[ptrSmaller->k-i-1];
                }
                else{
                    zahlUnten = 0;
                }
                if(zahlOben >= zahlUnten+uebertrag){
                    ptr->ziffern[maxVor-i] = zahlOben-zahlUnten-uebertrag;
                    uebertrag = 0;
                }
                else{
                    ptr->ziffern[maxVor-i] = zahlOben-zahlUnten-uebertrag +10;
                    uebertrag = 1;
                }

            }
            ////////////////


        }
        else{
            ptr->vorzeichen = '+';
            ptr->k = 1;
            ptr->ziffern[0] = 0;
            ptr->l = 0;
        }

    }
    //ptr = clean(ptr);
    free(a->ziffern);
    free(a);
    free(b->ziffern);
    free(b);
    ptr2 = clean(ptr);
    free(ptr->ziffern);
    free(ptr);
    return ptr2;
}
int biggerThan(struct bcd *c, struct bcd *d){
    //betragsmaessig!!!
    //0 c < d
    //1 c> d
    //2 c == d
    struct bcd *a, *b;
    unsigned int i;
    a = clean(c);
    b = clean(d);

    if(a->k > b->k){
        free(a->ziffern);
        free(a);
        free(b->ziffern);
        free(b);
        return 1;
    }
    if(b->k > a->k){
        free(a->ziffern);
        free(a);
        free(b->ziffern);
        free(b);
        return 0;
    }
    if(a->k == b->k){
        for(i = 0; i < ((a->k) + (a->l >= b->l ? a->l : b->l)) ;i++){

            if(a->k+a->l > i && b->k+b->l > i){
                if(a->ziffern[i] > b->ziffern[i]){
                    free(a->ziffern);
                    free(a);
                    free(b->ziffern);
                    free(b);
                    return 1;
                }
                else if (a->ziffern[i] < b->ziffern[i]) {
                    free(a->ziffern);
                    free(a);
                    free(b->ziffern);
                    free(b);
                    return 0;
                }
                else{
                    //beide einzelziffern gleich gross
                }
            }
            else{
                if(a->k+a->l > i){
                    free(a->ziffern);
                    free(a);
                    free(b->ziffern);
                    free(b);
                    return 1;
                }
                else{
                    free(a->ziffern);
                    free(a);
                    free(b->ziffern);
                    free(b);
                    return 0;
                }
            }
        }
    }

    free(a->ziffern);
    free(a);
    free(b->ziffern);
    free(b);
    return 2;
}

struct bcd * clean(struct bcd *a){

    struct bcd * b = malloc(sizeof(struct bcd));

    unsigned int i = 0, offsetVorne = 0, nurNullenVorne = 1, offsetHinten = 0, nurNullenHinten = 1;
    if(a->k > 1){
        for(i = 0; i < a->k; i++){
            if(a->ziffern[i] == 0 && nurNullenVorne == 1){
                offsetVorne += 1;
            }
            else{
                nurNullenVorne = 0;
            }
        }
    }
    if(a->l > 0){
        for(i = 0; i < a->l; i++){
            if(a->ziffern[a->k+a->l-1-i] == 0 && nurNullenHinten == 1){
                offsetHinten += 1;
            }
            else{
                nurNullenHinten = 0;
            }
        }
    }
    b->ziffern = malloc((a->k - offsetVorne + a->l - offsetHinten+1)*sizeof(char));
    for(i = 0; i < a->k - offsetVorne + a->l - offsetHinten; i++){
        b->ziffern[i] = a->ziffern[i+offsetVorne];
    }

    b->k = a->k - offsetVorne;
    b->l = a->l - offsetHinten;
    b->vorzeichen = a->vorzeichen;

    return b;
}

void aufraeumen(struct bcd * a){
    free(a->ziffern);
}

void printer(struct bcd * x){
    unsigned int i;
    printf("Vorzeichen: %c\n", x->vorzeichen);
    printf("Vorkommastellen: %d\n", x->k);
    printf("Nachkommastellen: %d\n", x->l);
    printf("Zahl: ");
    for(i = 0; i <= x->k-1; i++){
        printf("%d", x->ziffern[i]);
    }
    if(x->l > 0){
        printf(", ");
    }
    for(i = x->k; i <= x->k+x->l-1; i++){
        printf("%d", x->ziffern[i]);
    }
    printf("\n");
}
struct bcd * negate(struct bcd * a){
    struct bcd * ptr = clean(a);
    if(ptr->vorzeichen == '-'){
        ptr->vorzeichen = '+';
    }
    else{
        ptr->vorzeichen = '-';
    }
    return ptr;
}

int main(void)
{
    struct bcd * zahl, *zahl2, *zahl3, *zahl4, *zahl5;
    //int i=0;
    zahl = long2bcd(7);
    zahl5 = negate(zahl);

    zahl2 = long2bcd(1);
    zahl4 = negate(zahl2);

    //printer(zahl);

    zahl3 = add(zahl5, zahl2);
    printer(zahl3);

    //printf("%d", biggerThan(zahl, zahl2));
    free(zahl4->ziffern);
    free(zahl4);
    free(zahl5->ziffern);
    free(zahl5);
    free(zahl->ziffern);
    free(zahl);
    free(zahl2->ziffern);
    free(zahl2);
    free(zahl3->ziffern);
    free(zahl3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int am;
    char name[50];
    char surname[50];
    int semester;
    float mo;
} student_t;

void add_student(student_t A[50], int *s);
void menu(int *op);
int search_by();
void search_am(student_t A[50], int *s);
void search_name(student_t A[50], int *s);
void search_surname(student_t A[50], int *s);
int delete_name(student_t A[50], int s);
int delete_surname(student_t A[50], int s);
void find_max_mo(student_t A[50], int *s);
void find_min_mo(student_t A[50], int *s);
int sort_by();
void sort_am(student_t A[50], int *s);
void sort_mo(student_t A[50], int *s);
void sort_surname(student_t A[50], int *s);
int which_sort();
void show(student_t A[50], int *s);
void info(student_t A[50], int i);
int delete_am(student_t A[50], int s);

int main (int argc, char *argv [])
{
    student_t A[50]; 
    int i, s, op, op1;

    s = -1; // αριθμός μαθητών που υπάρχουν 
    menu(&op);

    while( op != 0 ){ // έξοδος

        if(op == 1){ // προσθήκη μαθητών
            add_student(A, &s);
        }

        else if(op == 2){ // αναζήση
            op1 = search_by(); // ως προς α.μ. , όνομα ή επίθετο
            if(op1 == 1){
                search_am(A, &s);
            }
            else if(op1 == 2){
                search_name(A, &s);
            }
            else{
                search_surname(A, &s);
            }
        }

        else if(op == 3){ // διαγραφή
            op1 = search_by(); // ως προς α.μ. , όνομα ή επίθετο
            if(op1 == 1){
                s = delete_am(A, s);
            }
            else if(op1 == 2){
                s = delete_name(A, s);
            }
            else{
                s = delete_surname(A, s);
            }
        }

        else if(op == 4){ // μέγιστος μέσος όρος όλων των μαθητών
            find_max_mo(A, &s);
        }

        else if(op == 5){ // ελάχιστος μέσος όρος όλων των μαθητών
            find_min_mo(A, &s);
        }

        else if(op == 6){ // ταξινόμηση
           op1 = sort_by(); // ως προς α.μ. , μ.ο. ή επιθέτου
           if(op1 == 1){
               sort_am(A, &s);
           }
           else if(op1 == 2){
               sort_mo(A, &s);
           }
           else{
               sort_surname(A, &s);
           }
        }

        else if(op == 7){ // εμφάνηση λίστας στοιχείων μαθητών
            show(A, &s);
        }

        menu(&op);
    }
    
return 0;
}

void add_student(student_t A[50], int *s){

    if (*s <= 50){ // αν υπάρχει χώρος για προσθήκη μαθητή

        *s = *s + 1; // αυξάνω το μέγεθος των μαθητών που υπάρχουν στο σύστημα
        printf("am:\n");
        scanf("%d", &A[*s].am);
        printf("\n");
        printf("name:\n");
        scanf("%s", &A[*s].name);
        printf("\n");
        printf("surname:\n");
        scanf("%s", &A[*s].surname);
        printf("\n");
        printf("semester:\n");
        scanf("%d", &A[*s].semester);
        printf("\n");
        printf("mo:\n");
        scanf("%f", &A[*s].mo);
    }

    else{ // δεν υπάρχει επιπλέον χώρος
        printf("THERE IS NO MORE MEMORY FOR ANOTHER STUDENT!");
    }
}

void menu(int *op){

    printf(" 1. Add student\n 2. Search student\n 3. Delete student\n 4. Max average\n 5. Min average\n 6. Sort array\n 7. Show array\n 0. Exit\n");
    printf("Choose an option:\n"); // εμφανίζω επαναληπτικά το μενού επιλογών
    scanf("%d", &*op);
    while(*op < 0 || *op > 7){ // έλεγχος αν η επιλογή είναι έγκυρη 
        printf("YOU GAVE A WRONG OPTION. TRY AGAIN. CHOOSE BETWEEN 0-7.\n");
        scanf("%d", &*op); // Αν δεν είναι σωστή ξανά δίνει τιμή
    }
}

int search_by(){

    int op1;

    printf("DO YOU WANT TO EXECUTE THE SEARCH BY AM, NAME OR SURNAME? CHOOSE 1, 2 or 3\n");
    scanf("%d", &op1);
    while (op1 != 1 && op1 != 2 && op1 != 3){ //έλεγχος αν η επιλογή ειναι σωστή
        printf("YOU GAVE A WRONG OPTION. TRY AGAIN. CHOOSE BETWEEN: 1, 2 OR 3\n");
        scanf("%d", &op1);
    }
    return op1;
}

void search_am(student_t A[50], int *s){

    int found, i, key, loc;

    printf("GIVE THE AM:\n");
    scanf("%d", &key);

    found = 0; //βρέθηκε ο α.μ.
    i = 0;
    while( found == 0 && i <= *s){
        if( A[i].am == key){
            found = 1;
            loc = i; // που βρέθηκε
        }
        else{
            i++;
        }
    }
    if( found == 1){ // αν βρέθηκε
        printf("\n\nAM:\tName:\tSURNAME:\tSEMESTER:\tMO:\n");
        info(A, loc); // εμφάνισε τα στοιχεία που ανήκουν στον συκεκριμένο α.μ.
    }
    else{ // αν δεν βρέθηκε
        printf("THERE IS NO STUDENT WITH AM: %d\n", key);
    }
}

void search_name(student_t A[50], int *s){

    int i, found;
    char key[50];

    printf("GIVE THE NAME:\n");
    scanf("%s", key);

    found = 0; //βρέθηκε
    printf("\n\nAM:\tName:\tSURNAME:\tSEMESTER:\tMO:\n");
    for( i = 0; i <= *s; i++){ // για όλους τους μαθητές που υπάρχουν στην λίστα
        if( !strcmp (A[i].name, key)){ // αν είναι ίδιες οι 2 τιμές
            found = 1;
            info(A, i); // εμφάνισε συγκεκριμένα στοιχεία
        }
    }

    if(found == 0){ // δεν βρέθηκε
        printf("THERE IS NO STUDENT WITH THAT NAME\n");
    }
}

void search_surname(student_t A[50], int *s){

    int i, found;
    char key[50];

    printf("GIVE THE SURNAME:\n");
    scanf("%s", key);

    found = 0; // βρέθηκε
    printf("\n\nAM:\tName:\tSURNAME:\tSEMESTER:\tMO:\n");
    for( i = 0; i <= *s; i++){ // για όλους τους μαθητές
        if( !strcmp( A[i].surname, key)){ // αν ειναι ίδιες οι 2 τιμές
            found = 1;
            info(A, i); // εμφάνισε συγκεκριμένα στοιχεία
        }
    }

    if(found == 0){ // δεν βρέθηκε
        printf("THERE IS NO STUDENT WITH THAT SURNAME\n");
    }
}

void find_max_mo(student_t A[50], int *s){

    int i;
    float max;

    if(*s != -1){ // αν υπάρχουν στοιχεία στο σύστημα

        max = A[0].mo; // θέτων max το 1ο απο αυτά
        for(i = 1; i <= *s; i++){
            if(A[i].mo > max){ // αν βρεθεί μεγαλυτερο

                max = A[i].mo; // άλλαξε τιμή
            }
        }
        printf("\n\nAM:\tName:\tSURNAME:\tSEMESTER:\tMO:\n");
        for(i = 0; i <= *s; i++){
            if(A[i].mo == max){
                info(A, i); // εμφάνισε στοιχεία μαθητών με μεγαλύτερο μ.ο.
            }
        }
    }
    else{ // το σύστημα είναι άδειο
        printf("THE ARRAY IS EMPTY");
    }
}

void find_min_mo(student_t A[50], int *s){

    int i;
    float min;

    if(*s != -1){ // αν έχουν καταχωρηθεί μαθητές

        min = A[0].mo; // θέτων min το 1ο σοιχείο
        for(i = 1; i <= *s; i++){
            if(A[i].mo < min){ // αν βρεθεί μικρότερο 

                min = A[i].mo; // άλλαξε τιμή
            }
        }
        printf("\n\nAM:\tName:\tSURNAME:\tSEMESTER:\tMO:\n");
        for(i = 0; i <= *s; i++){
            if(A[i].mo == min){
                info(A, i); // εμφάνισε στοιχεία μαθητών με μικρότερο μέσο όρο
            }
        }
    }
    else{ // δεν έχουν καταχωρηθεί μαθητές στο σύστημα
        printf("THE ARRAY IS EMPTY");
    }
}

void show(student_t A[50], int *s){

    int i;

    printf("\n\nAM:\tName:\tSURNAME:\tSEMESTER:\tMO:\n");
    for(i = 0; i <= *s; i++){ // εμφάνισε όλα τα στοιχεία όλων των μαθητών

        info(A, i);
    }
}

void info(student_t A[50], int i){
    
    printf("%d\t%s\t%s\t\t%d\t\t%.3f\n", A[i].am, A[i].name, A[i].surname, A[i].semester, A[i].mo); // εμφάνισε στοιχεία μαθητή

}

int sort_by(){

    int op1;

    printf("DO YOU WANT TO EXECUTE THE SORT BY AM, MO OR SURNAME? CHOOSE 1, 2 or 3\n");
    scanf("%d", &op1);
    while (op1 != 1 && op1 != 2 && op1 != 3){ // έλεγχος αν ειναι σωστή η επιλογή
        printf("YOU GAVE A WRONG OPTION. TRY AGAIN. CHOOSE BETWEEN: 1, 2 OR 3\n");
        scanf("%d", &op1);
    }
    return op1;
}

void sort_am(student_t A[50], int *s){

    int op, i, j;
    student_t temp; // δηλώνω temp μεταβλήτη που δέχετε όλα τα στοιχεία 1 μαθητή

    if(*s != -1){ // αν έχουν καταχωρηθεί μαθητές

        op = which_sort(); // είδος ταξινόμησης

        if(op == 1){ //αύξουσα

            for( i= 1; i <= *s;i++){ // συγκρίνω ανά 2 διαδοχικά τα στοιχεία των μαθητών βάση του α.μ.
                for(j = *s; j >= i; j--){ 
                    if( A[j-1].am > A[j].am ){ // αν ο α.μ. του προηγούμενου είναι μεγαλύτερος από του επόμενου

                        temp = A[j-1]; // αντιμετάθεσε όλα τα στοιχεία των 2 μαθητών
                        A[j-1] = A[j];
                        A[j] = temp;
                    }
                }
            }
        }
        else{ // φθίνουσα

            for( i= 1; i <= *s;i++){ // συγκρίνω ανά 2 τους α.μ. μαθητών
                for(j = *s; j >= i; j--){  // από το τέλος προς την αρχή
                    if( A[j-1].am < A[j].am ){  // αν ο α.μ. του προηγούμενου ειναι μικρότερος απο αυτόν του επόμενου

                        temp = A[j-1]; // αντιμετάθεσε όλα τα στοιχεία των 2 μαθητών
                        A[j-1] = A[j];
                        A[j] = temp; 
                    }
                }
            }
        }
    }
    else{ // δεν υπάρχουν μαθητές στο σύστημα
        printf("THE ARRAY IS EMPTY");
    }
}

void sort_mo(student_t A[50], int *s){

    int op, i, j;
    student_t temp;

    if(*s != -1){ // αν υπάρχουν μαθητές στο σύστημα

        op = which_sort();
        if(op == 1){ //αύξουσα

            for( i= 1; i <= *s;i++){ // βάση μέσου όρου 
                for(j = *s; j >= i; j--){ 
                    if( A[j-1].mo > A[j].mo ){ 

                        temp = A[j-1]; // αντιμετάθεσε όλα τα στοιχεία των 2 μαθητών
                        A[j-1] = A[j];
                        A[j] = temp;
                    }
                }
            }
        }
        else{ // φθίνουσα

            for( i= 1; i <= *s;i++){ 
                for(j = *s; j >= i; j--){ 
                    if( A[j-1].mo < A[j].mo ){ 

                        temp = A[j-1]; 
                        A[j-1] = A[j];
                        A[j] = temp; 
                    }
                }
            }
        }
    }
    else{ // δεν υπάρχουν μαθητές στο σύστημα
        printf("THE ARRAY IS EMPTY");
    }

}

void sort_surname(student_t A[50], int *s){

    int op, i, j;
    student_t temp;

    if(*s != -1){

        op = which_sort();
        if(op == 1){ //αύξουσα

            for( i= 1; i <= *s;i++){  // βάση επιθέτου
                for(j = *s; j >= i; j--){ 
                    if( strcmp( A[j-1].surname, A[j].surname) > 0 ){ // αν είναι μεγαλύτερο αλφαβητικά το επίθετο του προηγούμενου

                        temp = A[j-1]; // αντιμετάθεσε όλα τα στοιχεία των 2 μαθητών
                        A[j-1] = A[j];
                        A[j] = temp;
                    }
                }
            }
        }
        else{ // φθίνουσα

            for( i= 1; i <= *s;i++){ 
                for(j = *s; j >= i; j--){ 
                    if( strcmp( A[j-1].surname, A[j].surname) < 0 ){ // αν ειναι μικρότερο

                        temp = A[j-1]; 
                        A[j-1] = A[j];
                        A[j] = temp; 
                    }
                }
            }
        }
    }
    else{
        printf("THE ARRAY IS EMPTY");
    }
    
}

int which_sort(){
    int op;

    printf("CHOOSE BETWEEN 1.INCREASING OR 2.DECREASING SORT:\n");
    scanf("%d", &op);
    if(op < 1 || op > 2){ // έλεγχος αν η επιλογή ειναι σωστή
        printf("YOU GAVE A WRONG OPTION. TRY AGAIN. COOSE BETWEEN 1-2.\n");
        scanf("%d", &op);
    }

    return op;
}

int delete_am(student_t A[50], int s){

    int found, i, loc, key;
    student_t temp;

    printf("GIVE THE AM:\n");
    scanf("%d", &key);

    found = 0; // βρέθηκε 
    i = 0;
    loc = -1; // θέση
    while( found == 0 && i <= s){ // όσο δεν βρέθηκε ο α.μ. και δεν έχω προσπελάσει όλους τους μαθητές
        if( A[i].am == key){ // αν είανι ίδιες οι τιμές
            found = 1; // βρέθηκε ο α.μ.
            loc = i; // σε ποιά θέση
        }
        else{
            i++;
        }
    }
    if(found == 1){ // αν βρέθηκε

        for(i = loc; i < s; i++){ // απο την θέση που βρέθηκε μέχρι το τέλος του αριθμού των μαθητών που υπάρχουν στο σύστημα

            temp = A[i]; // αντιμετάθεσε όλα τα στοιχεία του μαθητή με τον ζητόυμενο α.μ. με τον επόμενο του
            A[i] = A[i+1];// ώστε να βρεθεί στο τέλος του πίνακα
            A[i+1] = temp;
        
        }
        s--; // διαγραφή του τελευταίου μαθητή με τον ζητούμενο α.μ.
        printf("THE STUDENT GOT DELETED FROM THE ARAY SUCCESSFULLY\n");
    
    }
    else{
        printf("THERE IS NO STUDENT WITH THAT AM!\n");
    }
    return s; // επέστεψε το αριθμό μαθητών
}

int delete_name(student_t A[50], int s){

    int i, found;
    char key[50];
    student_t temp;

    printf("GIVE THE NAME:\n");
    scanf("%s", key);

    found = 0;
    i = 0;

    while( i <= s ){ // όσο δεν έχω προσπελάσσει όλους του μαθητές

        if( !strcmp( A[i].name , key) ){ // αν είναι ίσες οι 2 τιμές

            found = 1; //βρέθηκε
            temp = A[i]; // αντιμετάθεσε τους μαθητές με το ζητούμενο όνομα με τον τελευταίο μαθητή του συστήματος 
            A[i] = A[s];
            A[s] = temp;
            s--; // διέγραψε όσους μαθητές βρεις με το συγκεκριμένο όνομα
        }
        else{
            i++;
        }
    }

    if(found == 0){ //δεν βρέθηκε 
        printf("THERE IS NO STUDENT WITH THAT NAME\n");
    }
    else{
        printf("THE STUDENT/S GOT DELETED FROM THE ARRAY SUCCESSFULLY\n");
    }

    return s; // επέστρεψε τον νέο αριθμό μαθητών
}

int delete_surname(student_t A[50], int s){

    int i, found;
    char key[50];
    student_t temp;

    printf("GIVE THE SURNAME:\n"); // ακολουθώ την ίδια διαδικασία με αυτή της διαγραφής του/των μαθητή/ων
    scanf("%s", key);

    found = 0;
    i = 0;

    while( i <= s ){
        if( !strcmp( A[i].surname , key) ){

            found = 1;
            temp = A[i];
            A[i] = A[s];
            A[s] = temp;
            s--; 
        }
        else{
            i++;
        }
    }

    if(found == 0){
        printf("THERE IS NO STUDENT WITH THAT SURNAME\n");
    }
    else{
        printf("THE STUDENT/S GOT DELETED FROM THE ARRAY SUCCESSFULLY\n");
    }

    return s;
}
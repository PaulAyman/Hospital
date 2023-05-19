#include <stdio.h>
#include <stdlib.h>


struct node{
int id;
char name[20];
int type;
struct node * link
};
struct node *front,*rear;



void enqueue(int id, char name[20], int type){

struct node* newnode=(struct node*)malloc(sizeof(struct node));

newnode->id=id;
strcpy(newnode->name,name);
newnode->type=type;
newnode->link=NULL;

if( front ==NULL ){
    front=rear=newnode;
}else{
    rear->link=newnode;
    rear=newnode;
    }

}

display(int id){
struct node* ptr =front;
while(ptr!=NULL){
    if(ptr-> id == id){
    printf("Ur id is : %d\n", ptr->id);
    printf("Ur name is : %s\n", ptr->name);
    printf("Ur clinic type is : %d\n", ptr->type);
    printf("DONE!\n");
    break;
    }
ptr = ptr->link;
}

if(ptr== NULL){
    printf("(-1)\n");
    printf("the patient (id) is not found\n");
    }

}



void dequeue(int id){
struct node* ptr = front;
while(ptr!=NULL){

    if(ptr-> id == id){
    printf("the id : %d is available now\n", ptr->id);
    FILE* fptr1 = fopen("ped_del.txt","a");
    FILE* fptr2 = fopen("der_del.txt","a");
    FILE* fptr3 = fopen("den_del.txt","a");

    if(ptr-> type == 1){ //ped
        fprintf(fptr1, "%d\t", ptr->id);
        fprintf(fptr1, "%s\t", ptr->name);
        fprintf(fptr1, "%d\n", ptr->type);
    }else if(ptr-> type == 2){ //der
        fprintf(fptr2, "%d\t", ptr->id);
        fprintf(fptr2, "%s\t", ptr->name);
        fprintf(fptr2, "%d\n", ptr->type);
    }else if(ptr-> type == 3){ //den
        fprintf(fptr3, "%d\t", ptr->id);
        fprintf(fptr3, "%s\t", ptr->name);
        fprintf(fptr3, "%d\n", ptr->type);}

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);

     printf("Saved\n");

    if(ptr->id == front->id){
        front = front->link;
        free(ptr);
    }else{free(ptr);}

    printf("the id : %d is deleted successfully!\n");
    break;
    }

ptr = ptr->link;

}

if(ptr== NULL){
    printf("(-1)\n");
    printf("the patient (id) is not found\n");
    }

}


save(){
struct node* ptr = front;
FILE* fptr1 = fopen("ped.txt","a");
FILE* fptr2 = fopen("der.txt","a");
FILE* fptr3 = fopen("den.txt","a");

while(ptr!=NULL){
    //if(ptr-> id == id){
    if(ptr-> type == 1){
        fprintf(fptr1, "%d", ptr->id);
        fprintf(fptr1, "%s", ptr->name);
        fprintf(fptr1, "%d", ptr->type);
    }else if(ptr-> type == 2){
        fprintf(fptr2, "%d", ptr->id);
        fprintf(fptr2, "%s", ptr->name);
        fprintf(fptr2, "%d", ptr->type);
    }else if(ptr-> type == 3){
        fprintf(fptr3, "%d", ptr->id);
        fprintf(fptr3, "%s", ptr->name);
        fprintf(fptr3, "%d", ptr->type);}

    ptr = ptr->link;
    }



fclose(fptr1);
fclose(fptr2);
fclose(fptr3);

 printf("Save completed!\n");

}


/*void instructions(){
    printf("Enter 1 to insert a patient info into the list\n");
    printf("Enter 2 to delete an element from the list\n");
}*/

/*void dequee(){
    struct node *temp=front;
    printf("\nelement dequuess\n");
    front=front->next;
    free(temp);
}*/

int main()
{
    int choose;
    int id;
    char name[20];
    int type;

    printf("**while inserting patient info,\n please enter 1 for pediatric clinic\n please enter 2 for dermatologistclinic\n");
    printf(" please enter 3 for dentist**\n\n\n\n\n");

    printf("Enter 1 to insert a patient info into the list\n");
    printf("Enter 2 to delete a patient from the list\n");
    printf("Enter 3 to display a patient from the list\n");
    printf("Enter 4 to save all...\n");
    printf("----------------------------------------------------------------\n");

while(1){

    printf("\nplease enter ur choice: ");
    scanf("%d",&choose);

    if(choose == 1){
        printf("\n\nplease enter ur id :\n");
        scanf("%d",&id);
        printf("please enter ur name :\n");
        scanf("%s",name);
        printf("please enter the clinic number :\n");
        scanf("%d",&type);
        enqueue(id, name, type);   // au3a t7ot ([20]) goua function!!!    Ex:  display(name[20]) xxx
    }else if(choose == 2){
        printf("please enter ur id :\n");
        scanf("%d",&id);
        dequeue(id);   // au3a t7ot (&) goua function!!!    Ex:  display(&id) xxx
    }else if(choose == 3){
        printf("please enter ur id :\n");
        scanf("%d",&id);
        display(id);  // au3a t7ot (&) goua function!!!    Ex:  display(&id) xxx
    }else if(choose==4){
        save();
    }
    printf("----------------------------------------------------------------\n");

}



    return 0;
}


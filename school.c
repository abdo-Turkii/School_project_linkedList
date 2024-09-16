#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define grade 5

typedef struct node
{
    char f_name[MAX];
    char l_name[MAX];
    int score;
    char arabic_g[grade];
    char english_g[grade];
    char math_g[grade];
    struct node* next;
}node;
typedef struct 
{
    node* head;
    int size;
}list;

void init_list(list* ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->size = 0;
}
void add(list* ptr_list)
{
    int score;
    //node* ptr_prv;
    node* ptr_new =(node*)malloc(sizeof(node));
    printf("First Name                \t"); 
    scanf("%s",ptr_new->f_name);
    //fprintf(data,"%s,",student.f_name);         // To add First Name in file 
    printf("Last Name                 \t");
    scanf("%s",ptr_new->l_name);
    //fprintf(data,"%s,",student.l_name);         // To add Last Name in file 
    printf("Total score of 100        \t");
    scanf("%d",&score);                         // whyyyyyyyyyyyyyyyyyyyyyyy
    ptr_new->score = score;
    //fprintf(data,"%d,",student.score);          // To add total score in file 
    printf("Arabic grade (pass/fail)  \t");
    scanf("%s",ptr_new->arabic_g); 
    while((getchar()) != '\n'){}//To flush input buffers with fgets
    //fprintf(data,"%s,",student.arabic_grade);   // To add Arabic grade in file
    printf("English grade (pass/fail) \t");
    scanf("%s",ptr_new->english_g); 
    while((getchar()) != '\n'){}//To flush input buffers with fgets
    //fprintf(data,"%s,",student.arabic_grade);   // To add English grade in file
    printf("Math grade (pass/fail)    \t");
    scanf("%s",ptr_new->math_g);
    while((getchar()) != '\n'){}//To flush input buffers with fgets
    if(!ptr_list->head)
    {
        ptr_list->head = ptr_new;
        ptr_new->next= NULL;
    }
    else
    {
        ptr_new->next = ptr_list->head;
        ptr_list->head=ptr_new; 
    }          
    ptr_list->size++;
}
void display(char* data)
{
    printf("%s\t",data);
}
void print(list* ptr_list, void (*ptr_fun)(char*))
{
    int score;
    node* ptr_cur;
    ptr_cur = ptr_list->head;
    while(ptr_cur)
    {
        (*ptr_fun)(ptr_cur->f_name);
        (*ptr_fun)(ptr_cur->l_name);
        score = (ptr_cur->score);
            printf("%d\t",score);
        (*ptr_fun)(ptr_cur->arabic_g);
        (*ptr_fun)(ptr_cur->english_g);
        (*ptr_fun)(ptr_cur->math_g);
        printf("\n");

        ptr_cur = ptr_cur->next;
    }
}
void search(list* ptr_list)
{
    node* ptr_search;
    ptr_search = ptr_list->head;
    char* name[MAX];
    printf("please, Enter First Name                \t");
    scanf("%s",name);
    printf ("Loading... \n");
    while(ptr_search)
    {
        if(strncmp(ptr_search->f_name , name ,strlen(ptr_search->f_name)) == 0)
        {
            printf("%s\t",ptr_search->f_name);
            printf("%s\t",ptr_search->l_name);
            printf("%d\t",ptr_search->score);
            printf("%s\t",ptr_search->arabic_g);
            printf("%s\t",ptr_search->english_g);
            printf("%s.\n",ptr_search->math_g);
        }
        ptr_search = ptr_search->next;    
    }
    printf("End of Search\n");


}

int main(int argc, char const *argv[])
{
    list ptr_list;
    void* data;
    char choice;
    int i =0;
    init_list(&ptr_list);
    while ( i == 0 )
    {
        printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name.\nPress 'e' to edit the entries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\nPress 'x' to exit program.\nPlease enter your option then press enter:\n");
        scanf(" %c",&choice);       // Input the selection form menu 
        //fflush(stdin); // to flush input buffers(not working)
        while ((getchar()) != '\n'){}//To flush input buffers with fgets
        switch (choice) // Status of menu
        {
            case ('a'): // To add new name 
                add ( &ptr_list );     // Function of addition
                    break;
            case ('p'): // To print all data
                print( &ptr_list,&display );    // Function of Print all data
                    break;
            case ('s'): // To search for a name
                search( &ptr_list );  // Function To search for a name
                    break;
            case ('e'): // To edit data of the student
                //edit(data ,file_name);   // Function To edit data of the student
                    //data = fopen(file_name,"a+");
                    break;
            case ('t'): // To print top 10 students
                //top(data );    // Function To print top 10 students
                    break; 
            case ('d'): // To delete a student
                //del(data ,file_name );   // Function To delete a student
                    //data = fopen(file_name,"a+");
                    break;
            case ('x'): // To exit a student
                printf("The end \n");    // message in the end 
                    i++;  //to exit loop
                    break;
    }   }
    
    










    return 0;
}


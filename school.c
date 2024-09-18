#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    char name[MAX];
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
void edit(list* ptr_list)
{
    char name1[MAX],name2[MAX];
    int score;
    node  *ptr_cur ;
    ptr_cur = ptr_list->head;
    printf("please,Enter the first name you need to edit\n");
    scanf("%s",name1);
    printf("please,Enter the last name you need to edit\n");
    scanf("%s",name2);
    while(ptr_cur)
    {
        if(strncmp(ptr_cur->f_name, name1 , strlen(ptr_cur->f_name) ) == 0 )
        {
            if(strncmp(ptr_cur->l_name, name2 , strlen(ptr_cur->l_name) ) == 0  )
            {
                printf("New First Name                \t");
                scanf("%s",ptr_cur->f_name);
                //fprintf(temp,"%s,",student.f_name);
                printf("New Last Name                 \t");
                scanf("%s",ptr_cur->l_name);
                //fprintf(temp,"%s,",student.l_name);
                printf("New Total score of 100        \t");
                scanf("%d",&score);
                ptr_cur->score = score;
                //fprintf(temp,"%d,",student.score);
                printf("New Arabic grade (pass/fail)  \t");
                scanf("%s",ptr_cur->arabic_g);
                //fprintf(temp,"%s,",student.arabic_grade);
                printf("New English grade (pass/fail) \t");
                scanf("%s",ptr_cur->english_g);
                //fprintf(temp,"%s,",student.english_grade);
                printf("New Math grade (pass/fail)    \t");
                scanf("%s",ptr_cur->math_g);
                //fprintf(temp,"%s\n",student.math_grade);
            
            }
        }
        ptr_cur=ptr_cur->next;
    }
    printf("Process Succeeded\n");
}
void del(list* ptr_list)
{
    char fname[MAX],lname[MAX];
    node* ptr_prv, *ptr_cur;
    ptr_cur =ptr_list->head;
    printf("please,Enter the first name you need to delete\n");
    scanf("%s",fname);
    printf("please,Enter the last name you need to delete\n");
    scanf("%s",lname);
    while(ptr_cur)
    {
        if (strncmp((ptr_cur->f_name), fname , strlen(ptr_cur->f_name)) == 0 )
        {
            if (strncmp((ptr_cur->l_name), lname , strlen(ptr_cur->l_name) ) == 0  )
            {
                if(ptr_cur == ptr_list->head)
                {
                    ptr_list->head=ptr_cur->next;
                    free(ptr_cur);
                    break;
                }
                else
                {
                ptr_prv->next = ptr_cur->next;
                free(ptr_cur);
                break;
                }
            }    

        }
        ptr_prv = ptr_cur;
        ptr_cur =ptr_cur->next;
    }
    printf("Item is deleted\n");

}
/*void top(list* ptr_list)
{
    char name1[MAX];
    int score0,score1=0,score2;
    node* ptr_cur, *ptr_prv,*ptr_str;
    ptr_cur = ptr_list->head;
    ptr_prv = ptr_list->head;
    while(ptr_cur)
    {
        while (ptr_cur->next)
        {
            if(ptr_cur->next == NULL)
            {
                strncpy (name1 , (ptr_str->f_name), strlen(ptr_str->f_name));
                printf("%s",name1);
                strncpy (name1 , (ptr_str->l_name), strlen(ptr_str->f_name));
                printf(" %s",name1);
                score0 = (ptr_str->score);
                printf(" %d\t",score0);
                printf("\n");              
                    ptr_cur->next = ptr_str; 
                score1++;
                if (score1 == 10 )
                    break;       
            }
            if((ptr_cur->score) < (ptr_cur->next->score))
            {
                ptr_str = ptr_list->head;
                ptr_list->head = ptr_cur;
                ptr_prv->next = ptr_cur->next ;
                ptr_cur->next = ptr_str;
            }
            ptr_prv = ptr_cur;
            ptr_cur->next= ptr_cur->next->next;
        }
        ptr_cur = ptr_cur->next;
    }

              
}*/
void top(list* ptr_list)
{
    node* ptr_cur = ptr_list->head;
    int top1 = 100,counter=1;
    while(ptr_cur)
    {
        
        for(int i=0 ;i < ptr_list->size; i++ )
        {
            if(ptr_cur->score == top1)
            {
                printf("%d-%s %s %d\n",counter,ptr_cur->f_name,ptr_cur->l_name,ptr_cur->score);
                counter++;   
            }
            ptr_cur= ptr_cur->next;
        } 
        if(counter == 11)
            break;   
        top1--;
        ptr_cur = ptr_list->head;   
    }
    printf("Congratulation(^_^)\n");
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
        printf("============================================\n");
        printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name.\nPress 'e' to edit the entries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\nPress 'x' to exit program.\nPlease enter your option then press enter:\n");
        scanf(" %c",&choice);       // Input the selection form menu 
        //fflush(stdin); // to flush input buffers(not working)
        while ((getchar()) != '\n'){}//To flush input buffers with fgets
        printf("============================================\n");
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
                edit(&ptr_list);   // Function To edit data of the student
                    //data = fopen(file_name,"a+");
                    break;
            case ('t'): // To print top 10 students
                top(&ptr_list );    // Function To print top 10 students
                    break; 
            case ('d'): // To delete a student
                del(&ptr_list);   // Function To delete a student
                    //data = fopen(file_name,"a+");
                break;
            case ('x'): // To exit a student
                printf("The end \n");    // message in the end 
                    i++;  //to exit loop
                break;
        }   
    }    
    










    return 0;
}


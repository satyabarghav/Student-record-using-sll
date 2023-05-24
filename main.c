#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
      char first[10],last[10],cc[10],grade[3];
      struct student *next;
};
typedef struct student s;
s *head=NULL,*tail=NULL,*ptr,*newstudent;
void create();
void display();
void update();
void deletestudent();
void main(){
      int opt;
      while(1){
            printf("1.Create Student Record\n2.Display Student Record\n3.Update Student Record\n4.Delete Student Record");
            printf("\nEnter Option: ");
            scanf("%d",&opt);
            switch(opt){
                  case 1:
                        create();
                        break;
                  case 2:
                        display();
                        break;
                  case 3:
                        update();
                        break;
                  case 4:
                        deletestudent();
                        break;
            }
      }
}
void create(){
      newstudent = (s *)malloc(sizeof(s));
      printf("Enter First Name: ");
      scanf("%s",newstudent->first);
      printf("Enter Last Name: ");
      scanf("%s",newstudent->last);
      printf("Enter Course Code: ");
      scanf("%s",newstudent->cc);
      printf("Enter Grade: ");
      scanf("%s",newstudent->grade);
      if(head==NULL){
            head=newstudent;
            tail=newstudent;
            newstudent->next=NULL;
      }
      else{
            tail->next=newstudent;
            tail = newstudent;
            newstudent->next=NULL;
      }
}
void display(){
      ptr = head;
      while(ptr!=NULL){
            printf("\nFirst Name: %s",ptr->first);
            printf("\nLast Name: %s",ptr->last);
            printf("\nCourse code: %s",ptr->cc);
            printf("\nGrade: %s\n",ptr->grade);
            ptr=ptr->next;
      }
      printf("\n");
}
void update(){
      char f[10],l[10];
      printf("Enter First name: ");
      scanf("%s",f);
      printf("Enter Last Name: ");
      scanf("%s",l);
      ptr=head;
      while(strcmp(ptr->first,f)!=0&&strcmp(ptr->last,l)!=0){
            ptr=ptr->next;
      }
      printf("Enter the updates: ");
      printf("\nEnter First Name: ");
      scanf("%s",ptr->first);
      printf("Enter Last Name: ");
      scanf("%s",ptr->last);
      printf("Enter Course Code: ");
      scanf("%s",ptr->cc);
      printf("Enter Grade: ");
      scanf("%s",ptr->grade);
}
void deletestudent(){
            char f[10],l[10];
      printf("Enter First name: ");
      scanf("%s",f);
      printf("Enter Last Name: ");
      scanf("%s",l);
      ptr=head;
      int pos=0,i;
      while(strcmp(ptr->first,f)!=0&&strcmp(ptr->last,l)!=0){
            pos++;
            ptr=ptr->next;
      }
      ptr=head;
      for (i = 0; i < pos - 1; i++) {
            ptr=ptr->next;
        }
        s *del= ptr->next;
        ptr->next = ptr->next->next;
        del->next = NULL;
        free(del);
      
}
void searchstudent(){
	char f[10],l[10];
    printf("Enter First name: ");
    scanf("%s",f);
  	printf("Enter Last Name: ");
    scanf("%s",l);
    ptr=head;
    while(strcmp(ptr->first,f)!=0&&strcmp(ptr->last,l)!=0){
        ptr=ptr->next;
    }
    printf("\nFirst Name: %s",ptr->first);
    printf("\nLast Name: %s",ptr->last);
    printf("\nCourse code: %s",ptr->cc);
    printf("\nGrade: %s\n",ptr->grade);
}

#include <stdio.h>
void clean_stdin(void){ int c; do { c = getchar(); } while (c != '\n' && c != EOF); }
struct student{ int roll, age; char name[50], gender; };
int main(){
    struct student s[10], temporary;
    int i, choice, numberOfStudents, pos,rollNumberToSearch, flag;

    Menu:

    printf("1. Creation \n2. Insertion\n3. Deletion\n4. Search\n5. Show All\n6. Exit\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter Number of Students to add ");
            scanf("%d", &numberOfStudents);
            printf("Enter information of students:\n");
            for (int j = 0; j < numberOfStudents ; j++){
                printf("\nFor Student %d\n",j+1);
                printf("Enter name: "); scanf("%s",s[j].name);
                printf("Enter Roll Number: "); scanf("%d",&s[j].roll);
                printf("Enter Gender: "); clean_stdin(); scanf("%c",&s[j].gender);
                printf("Enter age: "); scanf("%d",&s[j].age);
                printf("\n");
            }
            goto Menu;
        case 2:
            if (numberOfStudents >= 10) {
                printf("Array is completely full. No more entries can be added. Press Any Key to return to Main Menu\n"); getchar(); goto Menu;
            }
            printf("Enter The Details of Student to be added\n");
            printf("Enter name: "); scanf("%s",temporary.name);
            printf("Enter Roll Number: "); scanf("%d",&temporary.roll);
            printf("Enter Gender: "); clean_stdin(); scanf("%c",&temporary.gender);
            printf("Enter age: "); scanf("%d",&temporary.age);
            printf("Enter Position where the Student is to be added"); scanf("%d", &pos);
            if (pos <= numberOfStudents){
                for (int j = numberOfStudents - 1 ; j > pos -1 ; j++) s[j + 1] = s[j];
                s[pos -1] = temporary;
            }
            goto Menu;
        case 3:
            flag = 0;
            printf("Enter Roll Number of student to delete: ");
            scanf("%d", rollNumberToSearch);
            for (int i = 0 ; i < numberOfStudents; i++) {
              if (s[i].roll == rollNumberToSearch){
                printf("%d\t%s\t%c\t%d\n", s[i].roll, s[i].name, s[i].gender, s[i].age);
                char ch;
                printf("Are you sure you want to delte this element(y/n)?");
                clean_stdin();
                scanf("%c", &ch);
                switch(ch){
                    case 'y' : flag = 1; pos = i; break;
                    case 'n' : 
                    default: break;
                }
              }
              if (flag == 1) {
                for (int j = pos; j < numberOfStudents; j++) s[j]  = s[j+1]; numberOfStudents--;
              }
            }
            goto Menu;
        case 4:
            flag = 0;
            printf("Search By Roll No. \n Enter Roll Number");
            scanf("%d", rollNumberToSearch);
            for (int i = 0 ; i < numberOfStudents; i++) {
              if (s[i].roll == rollNumberToSearch) {
                flag = 1; printf("%d\t%s\t%c\t%d\n", s[i].roll, s[i].name, s[i].gender, s[i].age);
              }
            }
            if (flag == 0) printf("Student not Found\n");
            goto Menu;
        case 5:
            printf("S.No.\tRoll\tName\tGender\tAge\n");
            for (int i = 0; i < numberOfStudents; i++) printf("%d)\t%d\t%s\t%c\t%d\n", i+1, s[i].roll, s[i].name, s[i].gender, s[i].age);
            getchar();
            goto Menu;
        case 6: return 0;
        default: goto Menu;
    }
   return 0;
}
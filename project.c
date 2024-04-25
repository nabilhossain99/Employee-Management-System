#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

struct person
{
    char name[100];
    int empID;
    float salary;

};
void add_record()
{
    int a;
    FILE *file;
    struct person s;
    printf("\t\t How you want to add record?\n\t\t (1:Full New Record)\t(2: Add New Record with Existing): ");
    scanf("%d",&a);
    if(a==1)
    {
        file=fopen("file1.txt","w");
        if(file==NULL)
        {
            printf("File does not exist\n");
        }
        else
        {
            printf("\t\t Input employee details:\n");
            int n;
            printf("\t\t How many member you want to add: ");
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
            {
                printf("\t\t Name of employee %d: ",i);
                scanf("%s",s.name);
                printf("\t\t ID of employee %d: ",i);
                scanf("%d",&s.empID);
                printf("\t\t Salary of employee %d: ",i);
                scanf("%f",&s.salary);
                fwrite(&s,sizeof(s),1,file);


            }
            fclose(file);

        }

    }
    else if(a==2)
    {
        file=fopen("file1.txt","a+");
        if(file==NULL)
        {
            printf("File does not exist\n");
        }
        else
        {
            printf("\t\t Input employee details:\n");
            int n;
            printf("\t\t How many member you want to add: ");
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
            {
                printf("\t\t Name of employee %d: ",i);
                scanf("%s",s.name);
                printf("\t\t ID of employee %d: ",i);
                scanf("%d",&s.empID);
                printf("\t\t Salary of employee %d: ",i);
                scanf("%f",&s.salary);
                fwrite(&s,sizeof(s),1,file);


            }
            fclose(file);



        }
    }
}
void display()
{

    FILE *file;
    struct person s;

    file=fopen("file1.txt","rb");
    if(file==NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        printf("\n\n\t\t Name\t ID\t Salary\n");

        while(fread(&s,sizeof(s),1,file)==1)
        {
            printf("\t\t %s\t",s.name);
            printf(" %d\t",s.empID);
            printf(" %.2f\n",s.salary);
        }



        fclose(file);
    }

}

void deletion()
{
    char name[40];
    int a,empID;
    struct person s;
    FILE *file,*f;
    file=fopen("file1.txt","rb");
    f=fopen("file2.txt","ab+");
    if(file==NULL)
    {
        printf("File does not exist\n");
        return;
    }
    printf("\t\t How you  want to search & delete\n\t\t (1:By Name),\t (2:By Employee ID) : ");
    scanf("%d",&a);
    if(a==1)
    {
        printf("\n\t\t Enter Employee name: ");
        scanf("%s",name);
        while(fread(&s,sizeof(s),1,file)==1)
        {
            if(strcmp(name,s.name)!=0)
            {
                printf("\n\t\t Record deleted successfully\n");
                fwrite(&s,sizeof(s),1,f);
            }

        }

    }
    else if(a==2)
    {
        printf("\n\t\t Enter Employee ID: ");
        scanf("%d",&empID);
        while(fread(&s,sizeof(s),1,file)==1)
        {
            if(s.empID!=empID)
            {
                printf("\n\t\t Record deleted successfully\n");
                fwrite(&s,sizeof(s),1,f);
            }

        }

    }

    fclose(file);
    fclose(f);
    remove("file1.txt");
    rename("file2.txt","file1.txt");



}


void update_record()
{
    int empID;
    FILE *file,*f;
    struct person s,s1;

    file=fopen("file1.txt","r+");
    f=fopen("file2.txt","a+");
    if(file==NULL)
    {
        printf("File does not exist\n");
        return;
    }

    printf("\n\t\t Enter ID: ");
    scanf("%d",&empID);

    while(fread(&s,sizeof(struct person),1,file)==1)
    {
        if(s.empID!=empID)
        {
            fwrite(&s,sizeof(struct person),1,f);
        }


    }
    printf("\n\t\t Employee New Name: ");
    scanf("%s",s1.name);
    printf("\n\t\t Employee New ID: ");
    scanf("%d",&s1.empID);
    printf("\n\t\t New Salary: ");
    scanf("%f",&s1.salary);
    fwrite(&s1,sizeof(struct person),1,f);
    fclose(file);
    fclose(f);
    remove("file1.txt");
    rename("file2.txt","file1.txt");
    printf("\n\t\t Update Successful\n");

}


void bonus()
{
    int salary;
    FILE *file,*f;
    struct person s,s1;

    file=fopen("file1.txt","r+");
    f=fopen("file2.txt","a+");
    if(file==NULL)
    {
        printf("File does not exist\n");
        return;
    }


    while(fread(&s,sizeof(struct person),1,file)==1)
    {
        s.salary=s.salary+(s.salary*.1);
        fwrite(&s,sizeof(struct person),1,f);


    }

    fclose(file);
    fclose(f);
    remove("file1.txt");
    rename("file2.txt","file1.txt");
    printf("\n\t\t Bonus successfully added\n");


}
void searching()
{
    int empID,a;
    char name[100];
    struct person s;

    FILE *file;
    file=fopen("file1.txt","rb");
    if(file==NULL)
    {
        printf("File does not exist\n");
    }

    else
    {
        printf("\t\t How you  want to search \n\t\t (1:By Name),\t (2:By Employee ID) : ");
        scanf("%d",&a);
        if(a==1)
        {
            printf("\t\t Enter Employee Name: ");
            scanf("%s",name);
            printf("\n\n\t\t Name\t ID\t Salary\n");
            while(fread(&s,sizeof(s),1,file)==1 )
            {
                if(strcmp(s.name,name)==0)
                {
                    printf("\t\t %s\t",s.name);
                    printf(" %d\t",s.empID);
                    printf(" %.2f\n",s.salary);
                }
            }

        }
        else if(a==2)
        {
            printf("\t\t Enter Employee ID: ");
            scanf("%d",&empID);
            printf("\n\n\t\t Name\t ID\t Salary\n");
            while(fread(&s,sizeof(s),1,file)==1 )
            {
                if(s.empID==empID)
                {
                    printf("\t\t %s\t",s.name);
                    printf(" %d\t",s.empID);
                    printf(" %.2f\n",s.salary);
                }
            }

        }


    }
}

int main()
{

    int choise;
    while(choise!=7)
    {
        printf("\n\n\t\t  #Employee Record System#\n");
        printf("\t\t****************************\n\n");

        printf("\t\t 1. Add Record\n");
        printf("\t\t 2. Display Record\n");
        printf("\t\t 3. Delete Record\n");
        printf("\t\t 4. Update Record\n");
        printf("\t\t 5. Add Bonus\n");
        printf("\t\t 6. Search Record\n");
        printf("\t\t 7. Exit.\n");
        printf("\t\t Enter Your Choice:");
        scanf("%d",&choise);
        switch(choise)
        {
        case 1:system("cls");
            add_record();
            break;
        case 2:system("cls");
            display();
            break;
        case 3:system("cls");
            display();
            deletion();
            break;
        case 4:system("cls");
            display();
            update_record();
            break;
        case 5:system("cls");
            bonus();
            break;
        case 6:system("cls");
            display();
            searching();
            break;
        case 7:
            exit(1);
        default:
            printf("Wrong choice entered\n");
        }

    }
    return 0;

}


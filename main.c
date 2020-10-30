//Developed By Tushar S Agrawal AND Devarsh RiteshKumar Shah

//Last Updated: 12:15   20-05-2020



/*how to Save in Complete_Student.txt file-
      Registration Number
      Student's Name
      Student's Gender
      Student's BirthDate(DD/MM/YYYY)
      Student's Age
      Student's City
      Studet's State
      Student's PhoneNumber
      Student's E-Mail
      Student's School
      student's Field
      Block
      Room Number
      Father's Name
      Father's Phone Number
 */


//including header files


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
void new_data();
void menu();
void view_block();
void delete_acc();
void closer();
void check_details();
void room_allotment(char a[10]);
int checkdate(int date,int month, int year);
void arrow(int rlptn, int arptn);
int naive(char reg[], char match[]);
int main_exit;
int Approxdist(char x[30], char y[30]);
//defining structures
struct student_details {
        char regno[9];
        char name[30];
        int age;
        char gender[10];
        int date,month,year;
        char phone[11];
        char mail_id[30];
        char city[20];
        char state[20];
        char block;
        char school[10];
        char branch[4];
       // float cgpa;
        int room;
        char fname[30];
        char fphone[11];
} naya,upd,check,rem,sort;
//defining Global Variable For Arrow Menu
int position=0,choice=0;

//Main Function
int main()
{
        menu();
        return 0;
}

//Arrow
void arrow(int rlptn, int arptn)
{
        if(rlptn==arptn)
                printf("\t\t\t       ----->>  ");
        else
                printf("\t\t\t           ");
}

//Programme to Display Menu
void menu()
{
        choice=0,position=1;
        while(choice != 13) {
                system("cls");
                printf("\n\n\t\t\t      HOSTEL MANAGEMENT SYSTEM");
                printf("\n\n\n\t\t\t    WELCOME TO THE MAIN MENU\n\n");
                printf("\n\n\t\t\tSelect an Option:\n\n\n");
                arrow(1,position); printf("1Enter new Student's data \n\n");
                arrow(2,position); printf("Update information of existing account \n\n");
                arrow(3,position); printf("1Check the details of existing account \n\n");
                arrow(4,position); printf("1View all Students of a particlar Hostel \n\n");
                arrow(5,position); printf("Removing existing account \n\n");
                //  arrow(6,position); printf("View all students list \n\n");
                arrow(6,position); printf("Exit \n\n");
                //  printf("\n\n\n\n\n\t\t Enter your choice:");
                choice=getch();
                if ((choice==80) && (position!=6))
                        position++;
                else if ((choice ==72)&&(position!=1))
                        position--;
        }

        switch(position)
        {

        case 1: new_data();
                //      printf("\nSelected First\n");
                break;
        case 2: updatedata();
                //printf("\nSelected 2nd\n");
                break;
        case 3: check_details();
                //printf("\nSelected 3rd\n");
                break;
        case 4: view_block();
                //  printf("\nSelected 4th\n");
                break;
        case 5: delete_acc();
                break;
        //    case 6:
        //            printf("\nSelected 6th\n");
        //            break;
        case 6: closer();
                break;
        default:
                menu();
        }
}

void new_data()
{
        int choice;
        FILE *recfile, *block;

        recfile=fopen("Hostel_Management.dat","a+");
check_reg:

        printf("\t\t\t    ADD STUDENT'S DATA ");
        printf("\nEnter Student's Registration Number :");
        scanf("%s",check.regno);
        if (strlen(check.regno)!=8)
        {printf("Invalid Registration Number!!!\nTry Again\n\n\n");
         goto check_reg;}
        while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
        {
                if (naive(check.regno,naya.regno)==0)
                { fseek(recfile,0,SEEK_SET);
                  printf("Student Already Exists\nOR \nIncorrect Registration Number Entered\n");
                  goto check_reg;}
        }
        strcpy(naya.regno,check.regno);
        printf("\n Enter the Name :");
        scanf(" %[^\n]",naya.name);

        printf("\n Enter Student's Gender :");
        scanf("%s",naya.gender);
check_date:
        printf("\n Enter student's Date of Birth(DD/MM/YYYY) :");
        scanf("%d/%d/%d",&naya.date,&naya.month,&naya.year);
        if (checkdate(naya.date,naya.month,naya.year)==0)
        {
                printf("Invalid Date of Birth Entered\n\nTry Again!!\n\n");
                goto check_date;
        }
        printf("\n Enter the Age :");
        scanf("%d",&naya.age);
        printf("\n Enter the City :");
        scanf(" %[^\n]",naya.city);
        printf("\n Enter the State :");
        scanf(" %[^\n]",naya.state);
naya_phone:
        printf("\n Enter Student's Phone Number :");
        scanf("%s",naya.phone);
        if(strlen(naya.phone)!=10)
        {
                printf("\nInvalid phone number!!!\nTry Again\n\n\n ");
                goto naya_phone;
        }
        printf("\n Enter Student's E-Mail ID :");
        scanf("%s",naya.mail_id);
        printf("\n Enter Student's Father's Name :");
        scanf(" %[^\n]",naya.fname);
naya_fphone:
        printf("\n Enter Student's Father's Phone Number :");
        scanf("%s",naya.fphone);
        if(strlen(naya.fphone)!=10)
        {
                printf("\nInvalid phone number!!!\nTry Again\n\n\n ");
                goto naya_fphone;
        }
        if((naive(naya.gender,"Female")==0)||(naive(naya.gender,"female")==0))
        {printf("\n Student Will be Allotted GIRLS Hostel-A\n");
         naya.block='A';
         block=fopen("A-Block.dat","a+");
         fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
         fclose(block);  }
        else
        {
                choice=0,position=1;
                while(choice != 13) {
                        system("cls");
                        printf("\n\n\t\t\tChoose the BOYS Hostel to be allotted :\n\n");
                        //  printf("\n\n\t\t\tSelect an Option:\n\n\n");
                        arrow(1,position); printf("M-Block \n\n");
                        arrow(2,position); printf("N-Block \n\n");
                        arrow(3,position); printf("P-Block \n\n");
                        choice=getch();
                        if ((choice==80) && (position!=3))
                                position++;
                        else if ((choice ==72)&&(position!=1))
                                position--;
                }
                printf("%d\n",position);
                //  scanf(" %c",&bch);
                switch(position)
                {
                case 1:
                        naya.block='M';
                        block=fopen("M-Block.dat","a+");
                        /*printf("Opening M\n");*/
                        fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
                        break;
                case 2:
                        naya.block='N';
                        block=fopen("N-Block.dat","a+");
                        fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
                        break;
                case 3:
                        naya.block='P';
                        block=fopen("P-Block.dat","a+");
                        fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
                        break;
                }
                fclose(block);
        }


        strcpy(naya.school,"SCOPE");
        strcpy(naya.branch,"BCE");
        //naya.cgpa=33;
        fprintf(recfile,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);
        fclose(recfile);
        printf("\n\t\t Student Added successfully!!\n\n");
sort_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        main_exit=getch();
        if (main_exit==49)
                menu();
        else if(main_exit==48)
                closer();
        else
        {    printf("\nInvalid!\a");
             goto sort_list_invalid;}


}

void update_data()
{
	system("CLS");
        FILE *recfile,*newrec;
        int choice,test=0;
         recfile=fopen("Hostel_Management.dat","r");
        newrec=fopen("new.dat","w");
        printf("\nEnter the registration no. of student whose data you want to update: ");
        scanf("%s",rem.regno);
        while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
        {
        	if(strcmp(naya.regno,rem.regno)!=0)
        	{
        		test=1;
        		printf("\nWhich information do you want to change?\n1.Name\n2.Phone\n\nEnter your choice:");
            scanf("%d",&choice); 
             if(choice==1)
                {printf("Enter the new name:");
                scanf(" %[^\n]",rem.name);
                fprintf(newrec,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, rem.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone);
                printf("Changes saved!");
                }
            
             else if(choice==3)
			    {
			    	printf("Enter student's new number:");
			    	scanf("%d",rem.phone);
			    	printf("Enter Father's new number:");
			    	scanf("%d",rem.fphone);
			    	fprintf(newrec,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, rem.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, rem.fphone);
			    	printf("Changes saved!");
			 	
				}   
			}
			else
			fprintf(newrec,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone);
			
		}
		fclose(recfile);
    fclose(newrec);
    remove("Hostel_Management.dat");
    rename("new.dat","Hostel_Management.dat");
    
    if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    
    edit_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);  
        if (main_exit==1)
			menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            update_data();
        else
        {
        	printf("\nInvalid!\a");
            goto edit_invalid;
        }
       
        
}

void check_details()
{
        //Check Based on Registration Number
        FILE *recfile;
        int flag=0;
        char reg[9];
        char name[30];
        recfile=fopen("Hostel_Management.dat","r");
        choice=0,position=1;
        while(choice != 13) {
                system("cls");
                printf("\n\n\t\t\tDo you want to Check By :\n\n");
                arrow(1,position); printf("Registration Number \n\n");
                arrow(2,position); printf("Name \n\n");
                choice=getch();
                if ((choice==80) && (position!=2))
                        position++;
                else if ((choice ==72)&&(position!=1))
                        position--;
        }        switch(position) {
        case 1:
check_dreg:
                printf("\n Enter the Registration Number :");
                scanf("%s",reg);
                if (strlen(reg)!=8)
                {printf("Invalid Registration Number!! Try Again!!");
                 goto check_dreg;}
                while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",check.regno, check.name, check.gender, &check.date, &check.month, &check.year, &check.age, check.city, check.state, check.phone, check.mail_id, check.school, check.branch, &check.block, &check.room, check.fname, check.fphone)!=EOF)
                {if (naive(reg,check.regno)==0)
                 {   printf("\n\tRegistration No.\tNAME\tBlock\tROOM NO.\n");
                     printf("\n\t%s\t%s\t%c\t %d", check.regno, check.name, check.block, check.room);
                     flag=1;
                     break;}}
                break;
        case 2:

                printf("\nEnter the Name Of the Student :");
                scanf(" %[^\n]",name);
                int count=0;
                while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",check.regno, check.name, check.gender, &check.date, &check.month, &check.year, &check.age, check.city, check.state, check.phone, check.mail_id, check.school, check.branch, &check.block, &check.room, check.fname, check.fphone)!=EOF)
                {if (Approxdist(name,check.name)<5)
                 { flag=1;
                   if(count==0)
                   { printf("\t\tFollowing is the list of Students:");
                     printf("\n\tRegistration No.\t\tNAME\t\tBlock\t\tRoom No.\n");}
                   printf("\n\t%s\t\t%s\t\t %c\t\t %d", check.regno, check.name, check.block, check.room);
                   count++;}}
                fclose(recfile);
                break;
        }
        if (flag==0)
        {
                printf("\nNo Student Found");
        }
sort_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        main_exit=getch();
        if (main_exit==49)
                menu();
        else if(main_exit==48)
                closer();
        else
        {    printf("\nInvalid!\a");
             goto sort_list_invalid;}

}
/////////////////////////PAste After this
void view_block()
{
        choice=0; position=1;
        while(choice!=13) {
                system("CLS");
                printf("\t\t\tEnter year choice:\n\n\n");
                arrow(1,position); printf(" M-Block\n\n");
                arrow(2,position); printf(" N-Block\n\n");
                arrow(3,position); printf(" P-Block\n\n");
                arrow(4,position); printf(" A-Block\n\n");
                choice=getch();
                if ((choice==80) && (position!=4))
                        position++;
                else if ((choice ==72)&&(position!=1))
                        position--;
        }
        FILE *block;
        int test=0;
        switch(position)
        {
        case 1: block=fopen("M-Block.dat","a+"); break;
        case 2: block=fopen("N-Block.dat","a+"); break;
        case 3: block=fopen("P-Block.dat","a+"); break;
        case 4: block=fopen("A-Block.dat","a+"); break;
        default: view_block();
        }

        while(fscanf(block,"%s\n%[^\n]\n%d\n",sort.regno, sort.name, &sort.room)!=EOF)
        {       if(test==0)
                {
                        printf("\t\tFollowing is the list of requested students:");
                        printf("\n\tROLL NO.\t\t\tNAME\t\t\tROOM NO.\n");
                }
                printf("\n\t%s\t %15s\t %d", sort.regno, sort.name, sort.room);
                test++;        }
        fclose(block);
        if (test==0)
                printf("\nNO RECORDS!!\n");
sort_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        main_exit=getch();
        if (main_exit==49)
                menu();
        else if(main_exit==48)
                closer();
        else
        {    printf("\nInvalid!\a");
             goto sort_list_invalid;}
}

int checkdate(int date,int month, int year)
{
        if(date > 31|| date < 1)
        {
                printf("Checking 31\n");
                return 0;
        }
        int is_leap=0;

        if (year >= 1800 && year <= 2020)
        {       if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                        is_leap = 1;
                if(month >= 1 && month <= 12)
                {       printf("Month Checkedn\n");
                        if (month == 2)
                        {       printf("Checking Feb\n");
                                if ((is_leap==1 && date == 29)||date<=28)
                                        return 1;
                                else if (date > 28)
                                        return 0; }
                        // check for dates in April, June, September and November
                        else if (month == 4 || month == 6 || month == 9 || month == 11)
                        {       printf("Checking 4,6,9,11\n");
                                if (date > 30)
                                        return 0;

                                else
                                        return 1; }
                        // For January, March, May, July, August, October and December
                        else
                                return 1; }
                else
                        return 0; }
}

void room_allotment(char a[])
{
        if (naive(a,"Female")==0 || naive(a,"female"))
        {
                printf("Yes");
        }



}
//function to remove a account
void delete_acc()
{
        system("CLS");
        FILE *recfile,*newrec;
        int test=0;
        recfile=fopen("Hostel_Management.dat","r");
        newrec=fopen("new.dat","w");
        printf("\nEnter the registration no. of student whose data you want to delete: ");
        scanf("%s",rem.regno);
        while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
        {
                if(naive(naya.regno,rem.regno)!=0)
                        fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);

                else
                {       char b;
                        test++;
                        FILE *block,*blocknew;
                        switch(naya.block)
                        {
                        case 'A':
                                block=fopen("A-Block.dat","r");
                                break;
                        //strcpy(b,"A-Block.dat");
                        case 'M':
                                block=fopen("M-Block.dat","r");
                                break;
                        //strcpy(b,"M-Block.dat");
                        case 'N':
                                block=fopen("N-Block.dat","r");
                                break;
                        //    strcpy(b,"N-Block.dat");
                        case 'P':
                                block=fopen("P-Block.dat","r");
                                break;
                                //      strcpy(b,"P-Block.dat");
                        } blocknew=fopen("blocknew.dat","w");
                        while(fscanf(block,"%s\n%[^\n]\n%d\n",sort.regno, sort.name, &sort.room)!=EOF)
                        {
                                if (naive(sort.regno,rem.regno)!=0)
                                {
                                        fprintf(blocknew,"%s\n%s\n%d\n", sort.regno, sort.name, sort.room);
                                }

                        }


                        fclose(block);
                        fclose(blocknew);
                        switch(naya.block)
                        {
                        case 'A':

                                remove("A-Block.dat");
                                rename("blocknew.dat","A-Block.dat");
                        //strcpy(b,"A-Block.dat");
                        case 'M':
                        printf("IN switch\n");
                                remove("M-Block.dat");
                                rename("blocknew.dat","M-Block.dat");
                        //strcpy(b,"M-Block.dat");
                        case 'N':
                                remove("N-Block.dat");
                                rename("blocknew.dat","N-Block.dat");
                        //    strcpy(b,"N-Block.dat");
                        case 'P':
                                remove("P-Block.dat");
                                rename("blocknew.dat","P-Block.dat");
                                //      strcpy(b,"P-Block.dat");
                        }
                        //   remove(b);
                        //   rename("blocknew.dat",b);
                        printf("\nRecord deleted successfully!\n");
                }
        }
        fclose(recfile);
        fclose(newrec);
        remove("Hostel_Management.dat");
        rename("new.dat","Hostel_Management.dat");
        if(test==0)
                printf("\nRecord not found!!\a\a\a");
erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
                menu();
        else if (main_exit==2)
                closer();
        else if(main_exit==0)
                delete_acc();
        else
        {
                printf("\nInvalid!\a");
                goto erase_invalid;
        }
}


int naive(char reg[], char match[])
{   printf("Using naive Algorithm\n");
    int M = strlen(reg );
    int N = strlen(match);
	int i=0;
    for (i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (match[i + j] != reg[j])
                break;
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            return 0;
    }
    return 1;
}



int Approxdist(char x[30], char y[30])
{
        int c=(int)strlen(x);
        int r=(int)strlen(y);
        int scost=0;
        int dist = 0;
        int **distance=NULL;
        int **action=NULL;
        int d,i,j;

        distance=(int **)malloc((r+1)*sizeof(int *));
        action=(int **)malloc((r+1)*sizeof(int *));
      
        for( i=0; i <= r; i++)
        {       distance[i]=(int *)malloc((c+1)*sizeof(int));
                action[i]=(int *)malloc((c+1)*sizeof(int));
        }
        for( i=0; i<= r; i++)
            for(j=0; j <=c; j++)
                     distance[i][j]=0;

        for(i=0; i <=c; i++)
                distance[0][i]=i;
        for( j=0; j <=r; j++)
                distance[j][0]=j;
        for(j=1; j <= r; j++)
        {    for( i=1; i <= c; i++)
             {       if(x[i-1]==y[j-1])
                             scost = 0;
                     else
                             scost = 1;

                     int op;
                     distance[j][i];
                     if(distance[j-1][i]+1 < distance[j][i-1]+1)
                     {    if(distance[j-1][i-1]+scost < distance[j-1][i]+1) {
                                  distance[j][i] = distance[j-1][i-1]+scost;
                                  op=2;                          }
                          else{ distance[j][i] = distance[j-1][i]+1;
                                op=0; }}
                     else
                     {        if(distance[j-1][i-1]+scost < distance[j][i-1]+1) {
                                      distance[j][i] = distance[j-1][i-1]+scost;
                                      op=2;
                              }
                              else{
                                      distance[j][i] = distance[j][i-1]+1;
                                      op=1;
                              }        }

                     if(op==2 && scost==0)
                             op=3;
                     action[j][i]=op;             }}
        d=distance[r][c];
         j=r;
         i=c;
        do{
                if(action[j][i]==0) {
                        j--;
                        dist++;
                }
                else if(action[j][i]==1) {
                        i--;
                        dist++;
                }
                else if(action[j][i]==2) {
                        i--;
                        j--;
                        dist+=2;
                }
                else if(action[j][i]==3) {
                        i--;
                        j--;
                }
        }while(!(j==0 && i==0));

        for( i=0; i <= r; i++)
                free(distance[i]);
        free(distance);

        for( i=0; i <= r; i++)
                free(action[i]);
        free(action);
        return dist;
}



void closer()
{
        system("CLS");
        printf("\n\n\n\n\n\n\n\t\t\t\t\tMade by Devarsh ,Tushar and Rishav\n\n\n");
}

#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                 
#include<ctype.h>                   
#include<dos.h>                    
#include<time.h>

#define RETURNTIME 15

char catagories[][15]={"New Member","Coach","Staff"};
void returnfunc(void);
void mainmenu(void);
void addmem(void);
void deletemem(void);
void editmem(void);
void searchmem(void);
void viewmem(void);
void closeapplication(void);

int  getdata();
int  checkid(int);
int t(void);

void Password();
void issuerecord();
void loaderanim();

FILE *fp,*ft,*fs;

COORD coord = {0, 0};

int s;
char findmem;
char password[10]={"open"};



void pos (int x, int y)

{

coord.X = x; coord.Y = y; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



struct meroDate

{

int mm,dd,yy;

};

struct mem

{

int id;
char stname[20];
char name[20];
char address[20];
char initdate[10];
int contact;
int count;
char *cat;
struct meroDate issued;
struct meroDate duedate;

};

struct mem a;
int main()

{

Password();
getch();
return 0;



}

void mainmenu()

{

system("cls");

int i;
pos(20,3);
printf(" \t\tTRAINING CENTER MANAGEMENT SYSTEM \n ");
printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
pos(20,5);
printf("1. ADD MEMBERS   ");
pos(20,7);
printf("2. REMOVE MEMBERS");
pos(20,9);
printf("3. SEARCH");
pos(20,11);
printf("4. DISPLAY MEMEBRS");
pos(20,13);
printf("5. MODIFY DATABASE");
pos(20,15);
printf("6. EXIT");
pos(20,22);
t();
pos(20,18);
printf("ENTER CHOICE:");



switch(getch())

{

case '1':

addmem();
break;

case '2':

deletemem();
break;

case '3':

searchmem();
break;

case '4':

viewmem();
break;

case '5':

editmem();
break;

case '6':

{

system("cls");
pos(16,3);
printf("\tTraining Centre Management System");
pos(16,4);
printf("\t THANK YOU!!!");
pos(16,8);

exit(0);

}

default:

{

pos(10,25);
printf("\aWrong Entry!!Please re-entered correct option");

if(getch())
mainmenu();

}



}

}

void addmem(void)    

{

system("cls");

int i;
pos(20,5);
printf("SELECT CATEGORIES");
pos(20,7);
printf("1.NEW MEMBER");
pos(20,9);
printf("2. TRAINER");
pos(20,11);
printf("3. STAFF");
pos(20,13);
printf("4. MAIN MENU");
pos(20,21);
printf("Enter your choice:");
scanf("%d",&s);

if(s==4)
mainmenu() ;
system("cls");
fp=fopen("stf.dat","ab+");

if(getdata()==1)

{

a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
pos(21,14);
printf("The record is sucessfully saved");
pos(21,15);
printf("Save any more?(Y / N):");

if(getch()=='n')
mainmenu();

else
system("cls");
addmem();

}

}

void deletemem()    

{

system("cls");

int d;
char another='y';

while(another=='y')  

{

system("cls");
pos(10,5);
printf("Enter the ID to  remove:");
scanf("%d",&d);
fp=fopen("stf.dat","rb+");
rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{
pos(10,7);
printf("The record is available");
pos(10,8);
printf("Name is %s",a.name);
pos(10,9);
findmem='t';

}
}

if(findmem!='t')

{

pos(10,10);
printf("No record is found modify the search");

if(getch())

mainmenu();

}

if(findmem=='t' )

{

pos(10,9);
printf("Do you want to delete it?(Y/N):");

if(getch()=='y')

{

ft=fopen("test.dat","wb+");  
rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id!=d)

{

fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); 

}                              

}

fclose(ft);
fclose(fp);
remove("stf.dat");
rename("test.dat","stf.dat"); 
fp=fopen("stf.dat","rb+");    
if(findmem=='t')

{

pos(10,10);
printf("The record is sucessfully deleted");
pos(10,11);
printf("\n\tDelete another record?(Y/N)");

}

}

else

mainmenu();
fflush(stdin);
another=getch();

}

}

pos(10,15);
mainmenu();

}

void searchmem()

{

system("cls");

int d;
printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbSearch Member\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
pos(20,10);
printf("1. Search By ID");
pos(20,14);
printf("2. Search By Name");
pos( 15,20);
printf("Enter Your Choice");
fp=fopen("stf.dat","rb+"); 
rewind(fp);   
switch(getch())

{

case '1':

{

system("cls");
pos(25,4);
printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch By Id\xdb\xdb\xdb\xdb\xdb\xdb");
pos(20,5);
printf("Enter the id:");
scanf("%d",&d);
pos(20,7);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{

Sleep(2);
pos(20,6);
printf("The Record is available\n");
pos(20,8);
printf("ID:%d",a.id);
pos(20,9);
printf("Category:%s",a.cat);
pos(20,10);
printf("Name:%s",a.name);
pos(20,11);
printf("address:%s ",a.address);
pos(20,12);
printf("Contact:%i ",a.contact);
pos(20,13);
printf("Member Since:%s",a.initdate);
findmem='t';

}



}

if(findmem!='t')  

{

printf("\aNo Record Found");

}

pos(20,17);
printf("Try another search?(Y/N)");

if(getch()=='y')
searchmem();

else
mainmenu();
break;

}

case '2':

{

char s[15];
system("cls");
pos(25,4);
printf("\xdb\xdb\xdb\xdb\xdb\xdbSearch Record By Name\xdb\xdb\xdb\xdb\xdb\xdb");
pos(20,5);
printf("Enter the Name:");
scanf("%s",s);

int d=0;

while(fread(&a,sizeof(a),1,fp)==1)

{

if(strcmp(a.name,(s))==0) 

{

	pos(20,d+7);
	printf("The Staff is available");
	pos(20,d+8);
	printf("ID:%d",a.id);
	pos(20,d+10);
	printf("Name:%s",a.name);
	pos(20,d+11);
    printf("address:%s",a.address);
    pos(20,d+12);
    printf("Contact:%i",a.contact);
    pos(20,d+13);
	printf("Member Since:%s",a.initdate);
	pos(20,d+14);
    getch();
    d+=6;

}



}

if(d==0)

printf("\aNo Record Found");
pos(20,d+11);
printf("Try another search?(Y/N)");

if(getch()=='y')
	searchmem();
else
	mainmenu();
break;

}

default :
getch();
searchmem();

}
fclose(fp);
}



void viewmem(void)  

{
int i=0,j;
system("cls");
pos(1,1);
printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdbMember List\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
pos(2,2);
printf("\n CATEGORY +++ ID ++++ NAME ++++++++ ADDRESS +++++ CONTACT ++++++ MEMBER SINCE ");


j=4;

fp=fopen("stf.dat","rb");

while(fread(&a,sizeof(a),1,fp)==1)

{
pos(1,j);
printf("%s",a.cat);
pos(14,j);
printf("%d",a.id);
pos(22,j);
printf("%s",a.name);
pos(36,j);
printf("%s",a.address);
pos(50,j);
printf("%i",a.contact);
pos(67,j);
printf("%s",a.initdate);
pos(68,j);
printf("\n\n");
j++;

}

fclose(fp);
pos(35,25);
returnfunc();

}

void editmem(void)  

{

system("cls");
int c=0;
int d,e;
pos(20,4);
printf("\xdb\xdb\xdb\xdb\xdb\xdbEdit Member's Record \xdb\xdb\xdb\xdb\xdb\xdb");
char another='y';

while(another=='y')

{
system("cls");
pos(15,6);
printf("Enter Id to be edited:");
scanf("%d",&d);
fp=fopen("stf.dat","rb+");

while(fread(&a,sizeof(a),1,fp)==1)

{

if(checkid(d)==0)

{
pos(15,7);
printf("This Member is available");
pos(15,8);
printf("The ID:%d",a.id);
pos(15,9);
printf("Enter new name:");
scanf("%s",a.name);
pos(15,10);
printf("Enter new address:");
scanf("%s",a.address);
pos(15,11);
printf("Enter new Contact:");
scanf("%i",&a.contact);
pos(15,12);
printf("Enter New Membership date:");
scanf("%s",&a.initdate);
pos(15,13);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);

c=1;

}

if(c==0)

{

pos(15,9);
printf("No record found");
}

}

pos(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;

}
returnfunc();
}

void returnfunc(void)

{

{
pos(15,20);
printf("Press ENTER to return to main menu");
}

a:

if(getch()==13) 
mainmenu();
else
goto a;

}

int getdata()

{
int t;
pos(20,3);
printf("Enter the Information Below");
pos(20,4);
printf("Category:");
pos(31,5);
printf("%s",catagories[s-1]);
pos(21,6);
printf("ID:\t");
pos(30,6);
scanf("%d",&t);
if(checkid(t) == 0)

{
pos(21,13);
printf("\aThe id already exists\a");
getch();
mainmenu();
return 0;

}

a.id=t;
pos(21,7);
printf("Name:");
pos(33,7);
scanf("%s",a.name);
pos(21,8);
printf("address:");
pos(30,8);
scanf("%s",a.address);
pos(21,9);
printf("Contact:");
pos(31,9);
scanf("%i",&a.contact);
pos(21,10);
printf("Member Since:");
scanf("%s",&a.initdate);
pos(31,17);
return 1;

}

int checkid(int t)  

{

rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  
return 1; 

}

int t(void) 
{

time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));
return 0 ;

}
void Password(void) 

{
system("cls");
char d[25]="Password Protected";
char ch,pass[10];

int i=0,j;
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Training Centre Management System \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\ MadeBy: xTracTor \n");
    printf("\t \n\n\n ENTER PASSWORD:");

while(ch!=13)

{

ch=getch();
if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;

}

}

pass[i] = '\0';
if(strcmp(pass,password)==0)

{

printf("\n\n\n\t\tACCESS GRANTED");
getch();
mainmenu();

}

else

{
printf("\n\n\n\t\t\aWarning!! \n\t   ACCESS DENIED");
getch();
Password();

}

}

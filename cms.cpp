#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include <Windows.h>


using namespace std;
char un[20];
class Admin
{
    char name[20];
    int totalsub;
    char subject[20][2];
    char mobile[15],mail[50],fname[20];
    char passwd[20],rpasswd[20];
public:
    char rollno[15];
    void getstdata()
    {
        cout<<"\nEnter the Student Name: ";
        cin>>(name);
        cout<<"\nEnter the Student ID/RollNo.: ";
        cin>>rollno;
        cout<<"\nEnter the student  Father Name: ";
        cin>>(fname);
        cout<<"\nEnter the student  Mobile Number: ";
        cin>>(mobile);
        cout<<"\nEnter The E-mail id: ";
        cin>>(mail);
        cout<<"\nEnter the total subjects: ";
        cin>>totalsub;
        for(int i=0;i<totalsub;i++)
        {
        cout<<"\n Enter the subject" <<i+1<<"Name : ";
        cin>>subject[i];
        }
        cout<<"\nCreate your login Password :";
        cin>>passwd;
        cout<<"\n Enter the  Unique Keyword to Recover Password :";
        cin>>rpasswd;
        cout<<"\n\n Please note your UserName is ID/ROll no.\n";
    }
    int login()
    {
        if((strcmp(un,rollno)==0))
           {
               cout<<"\nEnter the login  Password";
               int len=0;
               len=strlen(passwd);
               char inputpasswd[20];
               for(int i=0;i<len;i++)
                {
                    inputpasswd[i]=getch();
                    cout<<"#";
                    inputpasswd[i]=NULL;
                }

                if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
                   return 1;

                 else
                return 0;

           }
           else{
            return 0;
           }
    }
    int recover()
    {
        char key[20];
        if(strcmp(::un,rollno)==0)
        {
            cout<<"\nEnter the Unique keyword(provided by Admin): ";
            cin>>key;
            if((strcmp(key,rpasswd)==0))
               {
                   cout<<"\nYou are valid user";
                   cout<<"\nYour Password is"<<passwd;
                   cout<<"\nPlease exit to login again";
                   return 1;
               }
               else
                return 0;

        }
        else
            return 0;
    }
    int faprofile()
    {
        if((strcmp(::un,rollno)==0))
           {
               cout<<"\nFaculty Name      :"<<name;
               cout<<"\nFaculty Father's Name:"<<fname;
               cout<<"\nFaculty Mobile No:"<<mobile;
               cout<<"\nFaculty E-Mail id :"<<mail;
               return 1;
           }
           else
            return 0;
    }
  int knowfasub()
  {
      if((strcmp(::un,rollno)==0))
      {
          cout<<"\n Faculty total subject  :"<<totalsub;
          for(int i=0;i<totalsub;i++)
          {
              cout<<"\n\tsubjects"<<i+1<<":"<<subject[i];
          }
          return 1;
      }
      else
        return 0;
  }
  void addfasub()
  {
      if((strcmp(::un,rollno)==0))
      {
          cout<<"\nEnter the New subject:";
          cin>>subject[totalsub];
          totalsub++;
          cout<<"\n\nNew Subject Added successfully...";
      }
  }
  void delfasub()
  {
      knowfasub();
      int de=0;
      if((strcmp(::un,rollno)==0))
      {
          if(totalsub==0||totalsub<0)
          {
              totalsub=0;
              cout<<"\nNone subjects exit..";
              getch();
              exit(0);
          }
          cout<<"\nEnter the subject No.to be Deleted:";
          cin>>de;
          if(de==totalsub)
          {
              totalsub--;
              strcpy(subject[totalsub]," ");       }
      }
      else if(totalsub==1)
      {
          totalsub=0;
          strcpy(subject[totalsub]," ");
      }
      else
      {
          de--;
          strcpy(subject[totalsub]," ");
          for(int p=de;p<totalsub;p++)
          {
              strcpy(subject[p],subject[p+1]);
          }
          totalsub--;


      }
      cout<<"\n Records updated successfuly....";
  }
void modfaprofile()
{
    if((strcmp(::un,rollno)==0))
    {
        cout<<"\nThe profile is Details are  :";
        cout<<"\n 1. Faculty E-mail:"<<mail;
        cout<<"\n 2.Faculty Mobile:"<<mobile;
        int g=-1;
        cout<<"\n\n Enter the Detail No. to be  Modifer:";
        cin>>g;
        if(g==1)
        {
            char nmail[50];
            cout<<"\nEnter the  new Mail address:";
            strcmp(mail,nmail);
            cout<<"\n Record updated successfully...";

        }
        else if(g==2)
        {
            char nmobile[15];
            cout<<"\nEnter the  new Mobile No.:";
            gets(nmobile);
            strcpy(mobile,nmobile);
            cout<<"\n Record updated successfully....";
        }
        else
            cout<<"\n Invalid Input Provided.....";
    }
}
int stprofile()
{
    if((strcmp(::un,rollno)==0))
    {
        cout<<"\nStudent Name: "<<name;
        cout<<"\nStudent Father'Name:"<<fname;
        cout<<"\nStudent Mobile no."<<mobile;
        cout<<"\n Student E-mail ID."<<mail;
        return 1;

    }
    else
        return 0;

}
int knowstsub()
{
    if((strcmp(::un,rollno)==0))
    {
        cout<<"\nStudent Total Subjects:"<<totalsub;
        for(int i=0;i<totalsub;i++)
        {
            cout<<"\n\tStudent "<<i+1<<":"<<subject[i];
        }
        return 1;
    }
    else
        return 0;
}
void addstsub()
{
    if(strcmp(::un,rollno)==0)
    {
        cout<<"\nEnter the New subject:";
        cin>>subject[totalsub];
        totalsub++;
        cout<<"\n\n New subject Added successfully....";
    }
}
void delstsub()
{
    knowstsub();
    int de=0;
    if((strcmp(::un,rollno)==0))
    {
        if(totalsub==0||totalsub<0)
        {
            totalsub=0;
            cout<<"\n None Subject Exits...";
            getch();
            exit(0);
        }
        cout<<"\nEnter the subject No.to be Deleted:";
        cin>>de;
        if(de==totalsub)
        {
            totalsub--;
            strcmp(subject[totalsub]," ");
        }
        else if(totalsub==1)
        {
            totalsub=0;
            strcmp(subject[totalsub]," ");
        }
        else{
            de--;
            strcmp(subject[totalsub]," ");
            for(int p=de;p<totalsub;p++)
            {
                strcmp(subject[p],subject[p+1]);
            }
            totalsub--;
        }
        cout<<"\n Records Updated successfully....";
    }

}
void modstprofile()
{
    if((strcmp(::un,rollno)==0))
    {
        cout<<"\n the profile Details are:";
        cout<<"\n 1. Student E-mail:"<<mail;
        cout<<"\n 2.Student mobile:"<<mobile;
        int g=-1;
        cout<<"\n\nEnter the Detail to be Modified;";
        cin>>g;
        if(g==1)
        {
            char nmail[50];
            cout<<"\nEnter the New Mail Address:";
            strcpy(mail,nmail);
            cout<<"\nRecord Updated successfully....";




        }

        else if(g==2)
        {
             char nmobile[15];
            cout<<"\nEnter the New mobile No  :";
            gets(nmobile);
            strcpy(mobile,nmobile);
            cout<<"\nRecord Updated successfull";
        }
        else
            cout<<"\n Invalid Input Provided...";
    }
}
void getfadata()
{
    cout<<"\nEnter the Faculty Name:";
    cin>>(name);
    cout<<"\nEnter the Faculty ID/ROll No.:";
    cin>>rollno;
    cout<<"\nEnter the Faculty Father's Name:";
    cin>>(fname);
    cout<<"\nEnter the Mobile No.:";
    cin>>(mobile);
    cout<<"\nEnter the E-mail id:";
    cin>>(mail);
    cout<<"\nEnter the Total Subjects:";
    cin>>totalsub;
    for(int i=0;i<totalsub;i++)
    {
        cout<<"\nEnter The Subject"<<i+1<<"Name:";
        cin>>subject[i];

    }
    cout<<"\n Create Your Login Password:";
    cin>>passwd;
    cout<<"\nEnter the Unique keyword to Recover Password:";
    cin>>rpasswd;
    cout<<"\n\nPlease Note your UserName is Id/Roll no.\n";
}
void stdisplay()
{
    cout<<"\n student name;    "<<name;
    cout<<"\n student Id/Roll no:"<<rollno;
    cout<<"\n student father name:"<<fname;
    cout<<"\n student mobile No   :"<<mobile;
    cout<<"\n student E-mail      :"<<mail;
    cout<<"\n student Subjects     :"<<totalsub;
    for(int i=0;i<totalsub;i++)
    {
        cout<<"\n subjects"<<i+1<<":"<<subject[i];
    }
    if(totalsub==0)
        cout<<"(None subjects specified.....)";

}
void fadisplay()
{
    cout<<"\nFaculty Name  :"<<name;
    cout<<"\nFaculty ID/Roll No.:"<<rollno;
    cout<<"\nFaculty Father's Name:"<<fname;
    cout<<"\nFaculty Father's Name:"<<mail;
     cout<<"\n Faculty Mobile  No."<<mobile;
    cout<<"\n Faculty Subjects  :"<<totalsub;
    for(int i=0;i<totalsub;i++)
    {

        cout<<"\n Subject "<<i+1<<": "<<subject[i];
    }
    if(totalsub==0)
        cout<<"None Subjects Specified...";


}

}a;
Admin f;
int main()
{
    int ch;

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t   WELCOME   TO   CUIMS  ";

    cout<<" \n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Enter to continue"<<endl;

    getch();
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  PRESS 1 FOR ADMIN PORTAL";
    cout<<"\n\n\n\n\t\t\t\t\t\t  PRESS 2 FOR FACULTY PORTAL";
    cout<<"\n\n\n\n\t\t\t\t\t\t  PRESS 3 FOR STUDENT PORTAL";
    cout<<"\n\n\n\n\t\t\t  Enter your Choice:";
    cin>>ch;
    system("CLS");
    if(ch==1)
    {
        char adminuser[20],adminpass[20];
        cout<<"\n\n\n\n\n\t\t\t\t\t  WELCOME TO ADMIN LOGIN PORTAL";
        cout<<"\n\n\n\t\t\t  ENTER THE USERNAME:";
        cin>>adminuser;
        cout<<"\n\n\n\t\t\t  ENTER THE PASSWORD:";
        for(int k=0;k<5;k++)
        {
            adminpass[k]=getch();
            cout<<"*";

        }
        cout<<"\n\n\n\n\t\t\t PRESS ENTER KEY";
        getch();
        if((strcmp(adminuser,"pankaj")==0)&&(strcmp(adminpass,"12345")==0))
        {
            system("CLS");
        }
        else{
            cout<<"\n\n\n\n\n\t\t\t\t\t Invalid username or password";
            getch();
            exit(0);
        }
        char opera='y';
        do{
            int tmp;
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO ADMIN PANEL";
            cout<<"\n\n\n\t\t\t PRESS 1 TO ADD A FACULTY RECORD";
            cout<<"\n\n\n\t\t\t PRESS 3 TO VIEW ALL FACULTY RECORDS";
            cout<<"\n\n\n\t\t\t PRESS 4 TO  A DELETE FACULTY RECORD";
            cout<<"\n\n\n\t\t\t PRESS 5 TO ADD A STUDENT RECORD";
            cout<<"\n\n\n\t\t\t PRESS 7 TO VIEW ALL STUDENT RECORDS";
            cout<<"\n\n\n\t\t\t PRESS 8 TO  A DELETE STUDENT RECORD";
            cout<<"\n\n\n\t\t\t PRESS 9 TO EXIT";
                        cout<<"\n\n\n\n\n\n\n\t\t\t ENTER YOUR CHOICE:";
                        cin>>tmp;
            system("CLS");
            if(tmp==1)
            {
                cout<<"\n\n\t\t\t\t\t\t ENTER THE FACULTY DETAILS:-";
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                a.getfadata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"\n\n\n\t\t\t Record Entered  successfully...";
                cout<<"\n\n\n\n\n\n\t\t\t\t\t PRESS ENTER FOR MORE OPERATIONS";
                getch();
                system("CLS");
            }
            if(tmp==3)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int n;
                for(n=1;n<2;n++)
                {
                    fs.read((char*)&a,sizeof(Admin));
                    a.fadisplay();
                }
                fs.close();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER KEY FOR MORE OPERATION";
                getch();
                system("CLS");
            }
            if(tmp==4)
            {
                char tmpfaid[15];
                int de=0,result=-1;
                cout<<"\nEnter the faculty Id/rollNo.:";
                cin>>tmpfaid;
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt",ios::out|ios::ate);
               for(int n=1;n<2;n++)
                {
                    fs.read((char*)&a,sizeof(Admin));
                    result=strcmp(tmpfaid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else{
                        fs1.write((char*)&a,sizeof(Admin));
                    }
                    if(de==1)
                    {
                        cout<<"\n Record  Deleted  successfuly....";
                    }
                    else{
                        cout<<"\n Record not found..";
                    }
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("fanewinfo.txt","fainfo.txt");
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPRESS ENTER KEY FOR OPERATIONS:";
                getch();
                system("CLS");
            }
              if(tmp==5)
            {
                cout<<"\n\n\t\t\t\t\t\t ENTER THE STUDENT DETAILS:-";
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                a.getstdata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"\n\n\n\t\t\t Record Entered  successfully...";
                  cout<<"\n\n\n\n\t\t\t\t\t\t PRESS ENTER KEY FOR MORE OPERATIONS";
                  getch();
                  system("CLS");

            }
            if(tmp==7)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                int n;
                for(n=1;n<2;n++)
                {
                    fs.read((char*)&a,sizeof(Admin));
                    a.stdisplay();
                }
                fs.close();
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPRESS ENTER KEY FOR MORE OPERATION";
                getch();
                system("CLS");
            }
              if(tmp==8)
            {
                char tmpfaid[15];
                int de=0,result=-1;
                cout<<"\nEnter the Student Id/rollNo.:";
                cin>>tmpfaid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt",ios::out|ios::ate);
               for(int n=1;n<2;n++)
                {
                    fs.read((char*)&a,sizeof(Admin));
                    result=strcmp(tmpfaid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else{
                        fs1.write((char*)&a,sizeof(Admin));
                    }
                    if(de==1)
                    {
                        cout<<"\n Record  Deleted  successfuly....";
                    }
                    else{
                        cout<<"\n Record not found..";
                    }
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPRESS ENTER KEY FOR OPERATIONS:";
                getch();
                system("CLS");
            }
            if(tmp==9)
            {
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t THANK  YOU";
                getch();
                exit(0);
            }
            if(tmp<1||tmp>9)
            {
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t INVALID INPUT....";
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t PREE ENTER KEY FOR REENTER THE CHOISE";
                getch();

            }
        }
        while(opera=='y'||opera=='Y');
}
if(ch==2)
{
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\\t\t\t\t WELCOME TO FACULTY PORTAL";
     cout<<"\n\n\n\n\n\\n\n\t\t\\t\t\t\t\ PLEASE  PRESS ENTER TO PROCCED AHEAD...";
     system("CLS");
     char facultyuser[20],facultypass[20];
        cout<<"\n\n\n\n\n\t\t\t\t\t  WELCOME TO Faculty LOGIN PORTAL";
        cout<<"\n\n\n\t\t\t  ENTER THE USERNAME:";
        cin>>facultyuser;
        cout<<"\n\n\n\t\t\t  ENTER THE PASSWORD:";
        for(int k=0;k<4;k++)
        {
            facultypass[k]=getch();
            cout<<"*";

        }
        cout<<"\n\n\n\n\t\t\t PRESS ENTER KEY";
        getch();
        if((strcmp(facultyuser,"Gehna")==0)&&(strcmp(facultypass,"1059")==0))
        {
            system("CLS");
        }
        else if ((strcmp(facultyuser,"Vijay")==0)&&(strcmp(facultypass,"1113")==0))
        {
            system("CLS");
        }
        else if((strcmp(facultyuser,"Ravi")==0)&&(strcmp(facultypass,"1027")==0))
        {
            system("CLS");
        }
          else if((strcmp(facultyuser,"Mahesh")==0)&&(strcmp(facultypass,"1020")==0))
        {
            system("CLS");
        }
        else{
            cout<<"\n\n\n\n\n\t\t\t\t\t Invalid username or password";
            getch();
            exit(0);
        }
            char opera='y';
        do{
            int tmp;
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO FACULTY PANEL";
            cout<<"\n\n\n\t\t\t PRESS 1 TO VIEW FACULTY PROFILE";
            cout<<"\n\n\n\t\t\t PRESS 2 TO VIEW FACULTY TECHING TIME-TABLE";
            cout<<"\n\n\n\t\t\t PRESS 3 TO  VIEW ALL STUDENTS RECORD";
            cout<<"\n\n\n\t\t\t PRESS 4 TO ADD A STUDENT RECORD";
            cout<<"\n\n\n\t\t\t PRESS 5 TO  A DELETE STUDENT RECORD";
            cout<<"\n\n\n\t\t\t PRESS 6 TO VIEW  STUDENT MARKS and Update it";
            cout<<"\n\n\n\t\t\t PRESS 7 TO VIEW  STUDENT ATTENDENTION and UPDATE IT";
            cout<<"\n\n\n\t\t\t PRESS 8 TO EXIT";
                        cout<<"\n\n\n\n\n\n\n\t\t\t ENTER YOUR CHOICE:";
                        cin>>tmp;
            system("CLS");
                        if(tmp==1)
            {
                int id;
                cout<<"\n\n\t\t\t\t\t\t  FACULTY DETAILS :-";
                cout<<"\n\n\n\t\t\t Enter  Your Id:";
                    cin>>id;

                    if(id==1059)
                    {
                         string line;
  ifstream myfile1 ("faculty1.txt");
  if (myfile1.is_open())
  {
    while ( getline (myfile1,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile1.close();
  }

  else cout << "Unable to open file";

  system("CLS");
                    }
               else if(id==1113)
                    {
                         string line;
  ifstream myfile2 ("faculty2.txt");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      cout << line << '\n';
    }
    cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile2.close();
  }

  else cout << "Unable to open file";

  system("CLS");
                    }
                             else  if(id==1027)
                    {
                         string line;
  ifstream myfile3 ("faculty3.txt");
  if (myfile3.is_open())
  {
    while ( getline (myfile3,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile3.close();
  }

  else cout << "Unable to open file";

  system("CLS");
                    }
                             else if(id==1020)
                    {
                         string line;
  ifstream myfile4 ("faculty4.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  system("CLS");
                    }
                    else{
                        cout<<"\n\n\n\n\n\n\t\t\t\t\ There is not any Data Regarding this Id";
                    }
                    cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
system("CLS");

            }
            else if(tmp==2)
            {
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ Facality Time Table is";
                                         string line;
  ifstream myfile4 ("fatimetable.pdf");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  system("CLS");


            }
                       else if(tmp==3)
            {
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ Student details Table";
                                         string line;
  ifstream myfile4 ("studentdetail.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  system("CLS");


            }
                          else if(tmp==4)
            {
                cout<<"\n\n\t\t\t\t\t\t ENTER THE STUDENT DETAILS:-";
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                a.getstdata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"\n\n\n\t\t\t Record Entered  successfully...";
                  cout<<"\n\n\n\n\t\t\t\t\t\t PRESS ENTER KEY FOR MORE OPERATIONS";
                  getch();
                  system("CLS");

            }

            else if(tmp==5)
            {
                char tmpfaid[15];
                int de=0,result=-1;
                cout<<"\nEnter the Student Id/rollNo.:";
                cin>>tmpfaid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt",ios::out|ios::ate);
               for(int n=1;n<2;n++)
                {
                    fs.read((char*)&a,sizeof(Admin));
                    result=strcmp(tmpfaid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else{
                        fs1.write((char*)&a,sizeof(Admin));
                    }
                    if(de==1)
                    {
                        cout<<"\n Record  Deleted  successfuly....";
                    }
                    else{
                        cout<<"\n Record not found..";
                    }
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPRESS ENTER KEY FOR OPERATIONS:";
                getch();
                system("CLS");
            }
          else if(tmp==6)
            {


                      cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ Student details Table";
                                         string line;
  ifstream myfile4 ("studentmarks.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  cout<<"\n\n\n\n\n\t\t\t\t\t PRESS ENTER FOR MORE OPERATIONS";
  system("CLS");

            }
                        else if(tmp==7)
            {


                      cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ Student details Table";
                                         string line;
  ifstream myfile4 ("studentattend.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  cout<<"\n\n\n\n\n\t\t\t\t\t PRESS ENTER FOR MORE OPERATIONS";
  system("CLS");

            }

                else if(tmp==8)
            {
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t THANK  YOU";
                getch();
                exit(0);
            }
            else
            {
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t INVALID INPUT....";
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t PREE ENTER KEY FOR REENTER THE CHOISE";
                getch();

            }



        }while(opera=='y'||opera=='Y');

}
if(ch==3)
{
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\\t\t\t\t WELCOME TO STUDENT PORTAL";
     cout<<"\n\n\n\n\n\\n\n\t\t\\t\t\t\t\ PLEASE  PRESS ENTER TO PROCCED AHEAD...";
     system("CLS");
     char studentuser[20],studentpass[20];
        cout<<"\n\n\n\n\n\t\t\t\t\t  WELCOME TO STUDENT LOGIN PORTAL";
        cout<<"\n\n\n\t\t\t  ENTER THE USERNAME:";
        cin>>studentuser;
        cout<<"\n\n\n\t\t\t  ENTER THE PASSWORD:";
        for(int k=0;k<4;k++)
        {
            studentpass[k]=getch();
            cout<<"*";

        }
        cout<<"\n\n\n\n\t\t\t PRESS ENTER KEY";
        getch();
        if((strcmp(studentuser,"Gehna")==0)&&(strcmp(studentpass,"1059")==0))
        {
            system("CLS");
        }
        else if ((strcmp(studentuser,"Vijay")==0)&&(strcmp(studentpass,"1113")==0))
        {
            system("CLS");
        }
        else if((strcmp(studentuser,"Ravi")==0)&&(strcmp(studentpass,"1027")==0))
        {
            system("CLS");
        }
          else if((strcmp(studentuser,"Mahesh")==0)&&(strcmp(studentpass,"1020")==0))
        {
            system("CLS");
        }
        else{
            cout<<"\n\n\n\n\n\t\t\t\t\t Invalid username or password";
            getch();
            exit(0);
        }
            char opera='y';
        do{
            int tmp;
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO STUDENT PANEL";
            cout<<"\n\n\n\t\t\t PRESS 1 TO VIEW STUDENT PROFILE";
            cout<<"\n\n\n\t\t\t PRESS 2 TO VIEW STUDENT TIME-TABLE";
            cout<<"\n\n\n\t\t\t PRESS 3 TO VIEW  STUDENT MARKS";
            cout<<"\n\n\n\t\t\t PRESS 4 TO VIEW  STUDENT ATTENDENTION";
            cout<<"\n\n\n\t\t\t PRESS 5 TO EXIT";
                        cout<<"\n\n\n\n\n\n\n\t\t\t ENTER YOUR CHOICE:";
                        cin>>tmp;
            system("CLS");
                        if(tmp==1)
            {
                int id;
                cout<<"\n\n\t\t\t\t\t\t\t\t\t  STUDENT DETAILS :-";
                cout<<"\n\n\n\t\t\t Enter  Your Id:";
                    cin>>id;

                    if(id==1059)
                    {
                         string line;
  ifstream myfile1 ("faculty1.txt");
  if (myfile1.is_open())
  {
    while ( getline (myfile1,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\Press Enter for more operation";
  getch();
    myfile1.close();
  }

  else cout << "Unable to open file";

  system("CLS");
                    }
               else if(id==1113)
                    {
                         string line;
  ifstream myfile2 ("faculty2.txt");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      cout << line << '\n';
    }
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\Press Enter for more operation";
  getch();
    myfile2.close();
  }

  else cout << "Unable to open file";

  system("CLS");
                    }
                             else  if(id==1027)
                    {
                         string line;
  ifstream myfile3 ("faculty3.txt");
  if (myfile3.is_open())
  {
    while ( getline (myfile3,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile3.close();
  }

  else cout << "Unable to open file";

  system("CLS");
                    }
                             else if(id==1020)
                    {
                         string line;
  ifstream myfile4 ("faculty4.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  system("CLS");
                    }
                    else{
                        cout<<"\n\n\n\n\n\n\t\t\t\t\ There is not any Data Regarding this Id";
                    }
                    cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
system("CLS");

            }
            else if(tmp==2)
            {
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ STUDENT Time Table is";
                                         string line;
  ifstream myfile4 ("fatimetable.pdf");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  system("CLS");


            }

          else if(tmp==3)
            {


                      cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ Student  marks details Table";
                                         string line;
  ifstream myfile4 ("studentmarks.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  cout<<"\n\n\n\n\n\t\t\t\t\t PRESS ENTER FOR MORE OPERATIONS";
  system("CLS");

            }
                        else if(tmp==4)
            {


                      cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\ Student  attendence details Table";
                                         string line;
  ifstream myfile4 ("studentattend.txt");
  if (myfile4.is_open())
  {
    while ( getline (myfile4,line) )
    {
      cout << line << '\n';
    }
     cout<<"\n\n\n\t\t\t\t\t\t\t\tPress Enter for more operation";
  getch();
    myfile4.close();
  }

  else cout << "Unable to open file";
  cout<<"\n\n\n\n\n\t\t\t\t\t PRESS ENTER FOR MORE OPERATIONS";
  system("CLS");

            }

                else if(tmp==5)
            {
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t THANK  YOU";
                getch();
                exit(0);
            }
            else
            {
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t INVALID INPUT....";
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t PREE ENTER KEY FOR REENTER THE CHOISE";
                getch();

            }



        }while(opera=='y'||opera=='Y');

}

    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t presented by PANKAJ SINGH (21MCI1020)";
    getch();

system("CLS");

return 0;
}

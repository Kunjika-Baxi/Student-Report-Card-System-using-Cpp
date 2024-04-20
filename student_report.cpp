#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
   public : 
   string sname,fname;float rn,m1,m2,m3,m4,m5,total;float per;char grade,gm1,gm2,gm3,gm4,gm5,g;
   void get()
   {
      cout<<"\n----------Student Details-----------";
      cout<<"\nEnter Student Name : ";cin>>sname;
      cout<<"\nEnter Student's Father Name : ";cin>>fname;
      cout<<"\nEnter Student's Roll Number : ";cin>>rn;
      cout<<"\nEnter Maths Marks : ";cin>>m1;
      cout<<"\nEnter Science Marks : ";cin>>m2;
      cout<<"\nEnter English Marks : ";cin>>m3;
      cout<<"\nEnter Hindi Marks : ";cin>>m4;
      cout<<"\nEnter Social Studies Marks : ";cin>>m5;
      cout<<"\nEnter the Grade of Computer : ";cin>>g;
      total = m1+m2+m3+m4+m5;
      per = total/5;
      if(total>=400 && total<=500)
      grade = 'A';
      else if(total>=300&& total<=399)
      grade = 'B';
      else if(total>=250 && total<=299)
      grade = 'C';
      else if(total>=200 && total<=249)
      grade = 'D';
      else 
      grade ='F';

      if((m1>=80 && m1<=100))
      gm1 = 'A';
      else if((m1>=70&& m1<=79))
      gm1 = 'B';
      else if((m1>=60 && m1<=69))
      gm1 = 'C';
      else if((m1>=45 && m1<=59))
      gm1 = 'D';
      else 
      gm1 ='F';

      if((m2>=80 && m2<=100))
      gm2 = 'A';
      else if((m2>=70&& m2<=79))
      gm2 = 'B';
      else if((m2>=60 && m2<=69))
      gm2 = 'C';
      else if((m2>=45 && m2<=59))
      gm2 = 'D';
      else 
      gm2 ='F';

      if((m3>=80 && m3<=100))
      gm3 = 'A';
      else if((m3>=70&& m3<=79))
      gm3 = 'B';
      else if((m3>=60 && m3<=69))
      gm3 = 'C';
      else if((m3>=45 && m3<=59))
      gm3 = 'D';
      else 
      gm3 ='F';

      if((m4>=80 && m4<=100))
      gm4 = 'A';
      else if((m4>=70&& m4<=79))
      gm4 = 'B';
      else if((m4>=60 && m4<=69))
      gm4 = 'C';
      else if((m4>=45 && m4<=59))
      gm4 = 'D';
      else 
      gm4 ='F';

      if((m5>=80 && m5<=100))
      gm5 = 'A';
      else if((m5>=70&& m5<=79))
      gm5 = 'B';
      else if((m5>=60 && m5<=69))
      gm5 = 'C';
      else if((m5>=45 && m5<=59))
      gm5 = 'D';
      else 
      gm5 ='F';
   }
   void display()
   {
      cout<<"\n\t-----Student's Report Card-----";
      cout<<"\nStudent's Name : "<<sname;
      cout<<"\nFather's Name : "<<fname;
      cout<<"\nRoll Number : "<<rn;
      cout<<"\n_____________________________________________________";
      cout<<"\nSubject   \t| Marks\t| Total Marks\t| Grade";
      cout<<"\nMaths    \t| "<<m1<<"\t| 100\t\t| "<<gm1;
      cout<<"\nScience  \t| "<<m2<<"\t| 100\t\t| "<<gm2;
      cout<<"\nEnglish  \t| "<<m3<<"\t| 100\t\t| "<<gm3;
      cout<<"\nHindi    \t| "<<m4<<"\t| 100\t\t| "<<gm4;
      cout<<"\nSocial Studies\t| "<<m5<<"\t| 100\t\t| "<<gm5;
      cout<<"\nComputer \t| -\t| -\t\t| "<<g;
      cout<<"\n_____________________________________________________";
      cout<<"\nTotal    \t| "<<total<<"\t| 500";
      cout<<"\nPercentage : "<<per<<" %";
      cout<<"\nFinal Grade : "<<grade;
      cout<<"\n----------------------------------------------------";
   }
};
 student s;
 void write()
{
    ofstream fout;
    fout.open("School.dat",ios::app|ios::binary);
    s.get();
    fout.write((char*)&s,sizeof(s));
    fout.close();
    cout<<"\nData Added Successfully...";
}
void read()
{
    ifstream fin;
    fin.open("School.dat",ios::in|ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.display();
    }
    fin.close();
}
void search()
{
    fstream fin;
    int acc,flag=0;
    fin.open("School.dat",ios::in|ios::binary);
    cout<<"\nEnter the Roll Number : ";
    cin>>acc;
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(s.rn==acc)
        {
            flag=1;
            cout<<"\nRecord Found";
            s.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    fin.close();
}
void delete_specific()
{
    int ac,fl=0;
    fstream f;
    f.open("School.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("new.dat",ios::app|ios::binary);
    cout<<"\nEnter Roll Number : ";
    cin>>ac;
    while(f.read((char*)&s,sizeof(s)))
    {
        if(s.rn!=ac)
        {

            fout.write((char*)&s,sizeof(s));
        }
        else{
            fl=1;
        }
    }
    f.close();
    fout.close();
    remove("School.dat");
    rename("new.dat","school.dat");
    cout<<"\nSuccessful";

}
void update()
{
    int ac,fl=0;char ans;float m,sc,e,h,ss,t,tt,avg;char gr,g1,g2,g3,g4,g5,gra;
    fstream f;
    f.open("School.dat",ios::out|ios::in|ios::binary);
    cout<<"\nEnter the Roll Number : ";
    cin>>ac;
    while(f.read((char*)&s,sizeof(s)))
    {
        if(s.rn==ac)
        {
            fl=1;
            cout<<"\nDo you Want to Update Maths Marks ? (y/n) : ";cin>>ans;
            if(ans=='y')
            {
              cout<<"\nEnter Updated Maths Marks : ";cin>>m;
              if((m>=80 && m<=100))
      g1 = 'A';
      else if((m>=70&& m<=79))
      g1 = 'B';
      else if((m>=60 && m<=69))
      g1 = 'C';
      else if((m>=45 && m<=59))
      g1 = 'D';
      else 
      g1 ='F';
      tt=m+s.m2+s.m3+s.m4+s.m5;
      avg=tt/5;
      if(tt>=400 && tt<=500)
      gra = 'A';
      else if(tt>=300&& tt<=399)
      gra = 'B';
      else if(tt>=250 && tt<=299)
      gra = 'C';
      else if(tt>=200 && tt<=249)
      gra = 'D';
      else 
      gra ='F';
              t=f.tellp();
              s.m1=m;
              s.gm1=g1;
              s.total=tt;
              s.per=avg;
              s.grade=gra;

            }
            cout<<"\nDo you Want to Update Science Marks ? (y/n) : ";cin>>ans;
            if(ans=='y')
            {
              cout<<"\nEnter Updated Science Marks : ";cin>>sc;
              if((sc>=80 && sc<=100))
      g2 = 'A';
      else if((sc>=70&& sc<=79))
      g2 = 'B';
      else if((sc>=60 && sc<=69))
      g2 = 'C';
      else if((sc>=45 && sc<=59))
      g2 = 'D';
      else 
      g2 ='F';
      tt=s.m1+sc+s.m3+s.m4+s.m5;
      avg=tt/5;
      if(tt>=400 && tt<=500)
      gra = 'A';
      else if(tt>=300&& tt<=399)
      gra = 'B';
      else if(tt>=250 && tt<=299)
      gra = 'C';
      else if(tt>=200 && tt<=249)
      gra = 'D';
      else 
      gra ='F';
             t=f.tellp();
              s.m2=sc;
              s.gm2=g2;
              s.total=tt;
              s.per=avg;
               s.grade=gra;
            }
            cout<<"\nDo you Want to Update English Marks ? (y/n) : ";cin>>ans;
            if(ans=='y')
            {
              cout<<"\nEnter Updated English Marks : ";cin>>e;
              if((e>=80 && e<=100))
      g3 = 'A';
      else if((e>=70&& e<=79))
      g3 = 'B';
      else if((e>=60 && e<=69))
      g3 = 'C';
      else if((e>=45 && e<=59))
      g3 = 'D';
      else 
      g3 ='F';
      tt=s.m1+s.m2+e+s.m4+s.m5;
      avg=tt/5;
      if(tt>=400 && tt<=500)
      gra = 'A';
      else if(tt>=300&& tt<=399)
      gra = 'B';
      else if(tt>=250 && tt<=299)
      gra = 'C';
      else if(tt>=200 && tt<=249)
      gra = 'D';
      else 
      gra ='F';
               t=f.tellp();
              s.m3=e;
              s.gm3=g3;
              s.total=tt;
              s.per=avg;
               s.grade=gra;
            }
            cout<<"\nDo you Want to Update Hindi Marks ? (y/n) : ";cin>>ans;
            if(ans=='y')
            {
              cout<<"\nEnter Updated Hindi Marks : ";cin>>h;
              if((h>=80 && h<=100))
      g4 = 'A';
      else if((h>=70&& h<=79))
      g4 = 'B';
      else if((h>=60 && h<=69))
      g4 = 'C';
      else if((h>=45 && h<=59))
      g4 = 'D';
      else 
      g4 ='F';
      tt=s.m1+s.m2+s.m3+h+s.m5;
      avg=tt/5;
      if(tt>=400 && tt<=500)
      gra = 'A';
      else if(tt>=300&& tt<=399)
      gra = 'B';
      else if(tt>=250 && tt<=299)
      gra = 'C';
      else if(tt>=200 && tt<=249)
      gra = 'D';
      else 
      gra ='F';
               t=f.tellp();
              s.m4=h;
              s.gm4=g4;
              s.total=tt;
              s.per=avg;
               s.grade=gra;
            }
            cout<<"\nDo you Want to Update Social Studies Marks ? (y/n) : ";cin>>ans;
            if(ans=='y')
            {
              cout<<"\nEnter Updated Social Studies Marks : ";cin>>ss;
              if((ss>=80 && ss<=100))
      g5 = 'A';
      else if((ss>=70&& ss<=79))
      g5 = 'B';
      else if((ss>=60 && ss<=69))
      g5 = 'C';
      else if((ss>=45 && ss<=59))
      g5 = 'D';
      else 
      g5 ='F';
      tt=s.m1+s.m2+s.m3+s.m4+ss;
      avg=tt/5;
      if(tt>=400 && tt<=500)
      gra = 'A';
      else if(tt>=300&& tt<=399)
      gra = 'B';
      else if(tt>=250 && tt<=299)
      gra = 'C';
      else if(tt>=200 && tt<=249)
      gra = 'D';
      else 
      gra ='F';
              t=f.tellp();
              s.m5=ss;
             s.gm5=g5;
             s.total=tt;
              s.per=avg;
               s.grade=gra;
            }
            f.seekp(t-sizeof(s));
            f.write((char*)&s,sizeof(s));
        }

            cout<<"\nData Updated Successfully.....";
            break;
    }
    if(fl==0)
    {
        cout<<"\nRecord Not Found !!!";
    }

    f.close();
}
int main()
{
    string pass;
    cout<<"\n----------Welcome to Student Report Card System---------";
    while(1)
    {
       cout<<"\nEnter Password : ";
       cin>>pass;
       if(pass=="student_schools")
       {
         cout<<"\nPlease Enter your Choice From Below Menu.";break;
       }
       else 
       {
         cout<<"\nPlease Enter Valid Password";
       }
    }
    int ch;
    remove("School.dat");
    while(1)
    {
        cout<<"\nEnter : \n1.Enter Student Report Card Details\n2.View Report Cards of All Students\n3.View Report Card of Specific Student\n4.Update the Details of Specific Student's Report\n5.Remove The Record of Specific Student\n6.Exit";
        cout<<"\nEnter Your Choice : ";cin>>ch;
        switch(ch)
        {
            case 1:write();break;
            case 2:read();break;
            case 3:search();break;
            case 4:update();break;
            case 5:delete_specific();break;     
            case 6:exit(0);
            default:cout<<"\nInvalid Choice"; 
        }
    }
}
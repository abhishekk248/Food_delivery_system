#include <iostream>
#include<fstream>
using namespace std;
int n=0,id;
class veg
{
  protected:int count,selection,num[4],total,order,temp[4],userid;
  static int b;
  public: veg()
  {
    order=0;
    userid=n+1;
  }
  virtual int display()
  {
    num[0]=0,num[1]=0,num[2]=0,num[3]=0;total=0;
    temp[0]=0,temp[1]=0;
    while(1){
      cout<<"\n\nmenu\n1-gobi-manchurian\t->100\n2-corn-pizza\t\t->200\n3-veg-burger\t\t->150\n4-veg-biriyani\t\t->250\n5-bill\n";
      cin>>selection;
      switch(selection)
      {
        case 1:cout<<"enter number of gobi-manchurian\n";
          cin>>temp[0];
          num[0]+=temp[0];
          total=total+temp[0]*100;
          break;
        case 2:cout<<"enter number of corn-pizza\n";
          cin>>temp[1];
          num[1]+=temp[1];
          total=total+temp[1]*200;
          break;
        case 3:cout<<"enter number of veg-burger\n";
          cin>>temp[2];
          num[2]+=temp[2];
          total=total+temp[2]*150;
          break;
        case 4:cout<<"enter number of veg-biriyani\n";
          cin>>temp[3];
          num[3]+=temp[3];
          total=total+temp[3]*250;
          break;
        case 5: return 0;
          break;
        default:cout<<"invalid number\n";
          break;
      }
    }
  }
  virtual void bill()
  {
    count=++b;
    ++order;
    cout<<"\n------------------------------------------------\n";
    cout<<"bill no:"<<count<<"\t\t\t\torder:"<<order<<endl;
    cout<<"userid:"<<userid<<endl;
    if(num[0]!=0) cout<<"\ngobi-manchurian:\t"<<num[0]<<"*100\t="<<num[0]*100;
    if(num[1]!=0) cout<<"\ncorn-pizza:\t\t"<<num[1]<<"*200\t="<<num[1]*200;
    if(num[2]!=0) cout<<"\nveg-burger:\t\t"<<num[2]<<"*150\t="<<num[2]*150;
    if(num[3]!=0) cout<<"\nveg-biriyani:\t\t"<<num[3]<<"*250\t="<<num[3]*250;
    cout<<"\n------------------------------------------------\n";
    cout<<"\ntotal\t\t\t\t="<<total;
    cout<<"\n------------------------------------------------\n\n";
    ofstream out("data",ios::out | ios::app);
    out<<"\t"<<userid<<"\t"<<num[0]<<"\t"<<num[1]<<"\t"<<num[2]<<"\t"<<num[3]<<"\t0\t0\t0\t0\t"<<total<<"\t\t"<<count<<"\t"<<order<<endl;
    out.close();
  }
  virtual void showprevious(int check)
  {
    int l,k,u,v;
    ifstream in("data",ios::in|ios::app);
    in.ignore(100,'#');
    while(in){
      in>>userid>>num[0]>>num[1]>>num[2]>>num[3]>>k>>l>>u>>v>>total>>count>>order;
      if(in){
        if(check==userid){
          cout<<"\n------------------------------------------------\n";
          cout<<"bill no:"<<count<<"\t\t\t\torder:"<<order<<endl;
          cout<<"userid:"<<userid<<endl;
          if(num[0]!=0) cout<<"\ngobi-manchurian:\t"<<num[0]<<"*100\t="<<num[0]*100;
          if(num[1]!=0) cout<<"\ncorn-pizza:\t\t"<<num[1]<<"*200\t="<<num[1]*200;
          if(num[2]!=0)cout<<"\nveg-burger:\t\t"<<num[2]<<"*150\t="<<num[2]*150;
          if(num[3]!=0)cout<<"\nveg-biriyani:\t\t"<<num[3]<<"*250\t="<<num[3]*250;
          cout<<"\n------------------------------------------------\n";
          cout<<"\ntotal\t\t\t\t="<<total;
          cout<<"\n------------------------------------------------\n\n\n";
        }
      }
    }
    in.close();
  }
};
int veg::b;
class nonveg:public veg
{
  int selection1,numn[4],tempn[4];
  public:int display()
  {
    num[0]=0;num[1]=0,num[2]=0,num[3]=0;numn[0]=0;numn[1]=0,numn[2]=0,numn[3]=0;total=0;
    temp[0]=0,temp[1]=0,temp[2]=0,temp[3]=0,tempn[0]=0,tempn[1]=0,tempn[2]=0,tempn[3]=0;
    while(1){
      cout<<"\n\nmenu\n1-chicken-briyani\t->300\n2-mutton-curry\t\t->500\n3-chicken-tikka\t\t->250\n4-fish-fry\t\t->300";
      cout<<"\n5-gobi-manchurian\t->100\n6-corn-pizza\t\t->200\n7-veg-burger\t\t->150\n8-veg-briyani\t\t->250\n9-bill\n";
      cin>>selection1;
      switch(selection1)
      {
        case 1:cout<<"enter number of chicken-biriyani\n";
          cin>>tempn[0];
          numn[0]+=tempn[0];
          total=total+tempn[0]*300;
          break;
        case 2:cout<<"enter number of mutton-curry\n";
          cin>>tempn[1];
          numn[1]+=tempn[1];
          total=total+tempn[1]*500;
          break;
        case 3:cout<<"enter number of chicken-tikka\n";
          cin>>tempn[2];
          numn[2]+=tempn[2];
          total=total+tempn[2]*250;
          break;
        case 4:cout<<"enter number of fish-fry\n";
          cin>>tempn[3];
          numn[3]+=tempn[3];
          total=total+tempn[3]*300;
          break;
        case 5:cout<<"enter number of gobi-manchurian\n";
          cin>>temp[0];
          num[0]+=temp[0];
          total=total+temp[0]*100;
          break;
        case 6:cout<<"enter number of corn-pizza\n";
          cin>>temp[1];
          num[1]+=temp[1];
          total=total+temp[1]*200;
          break;
        case 7:cout<<"enter number of veg-burger\n";
          cin>>temp[2];
          num[2]+=temp[2];
          total=total+temp[2]*150;
          break;
        case 8:cout<<"enter number of veg-biriyani\n";
          cin>>temp[3];
          num[3]+=temp[3];
          total=total+temp[3]*250;
          break;
        case 9:return 0;
          break;
          default:cout<<"invalid no\n";
          break;
      }
    }
  }
  void bill()
  {
  count=++b;
  ++order;
  cout<<"\n-------------------------------------------------\n";
  cout<<"bill no:"<<count<<"\t\t\t\torder:"<<order<<endl;
  cout<<"userid:"<<userid<<endl;
  if(numn[0]!=0) cout<<"\nchicken-briyani:\t"<<numn[0]<<"*300\t="<<numn[0]*300;
  if(numn[1]!=0) cout<<"\nmutton-curry:\t\t"<<numn[1]<<"*500\t="<<numn[1]*500;
  if(numn[2]!=0) cout<<"\nchicken-tikka:\t\t"<<numn[2]<<"*250\t="<<numn[2]*250;
  if(numn[3]!=0) cout<<"\nfish-fry:\t\t"<<numn[3]<<"*300\t="<<numn[3]*300;
  if(num[0]!=0) cout<<"\ngobi-manchurian:\t"<<num[0]<<"*100\t="<<num[0]*100;
  if(num[1]!=0) cout<<"\ncorn-pizza:\t\t"<<num[1]<<"*200\t="<<num[1]*200;
  if(num[2]!=0) cout<<"\nveg-burger:\t\t"<<num[2]<<"*150\t="<<num[2]*150;
  if(num[3]!=0) cout<<"\nveg-biriyani:\t\t"<<num[3]<<"*250\t="<<num[3]*250;
  cout<<"\n-------------------------------------------------\n";
  cout<<"\ntotal\t\t\t\t="<<total;
  cout<<"\n-------------------------------------------------\n\n";
  ofstream out("data",ios::out | ios::app);
  out<<"\t"<<userid<<"\t"<<num[0]<<"\t"<<num[1]<<"\t"<<num[2]<<"\t"<<num[3]<<"\t";
  out<<numn[0]<<"\t"<<numn[1]<<"\t"<<numn[2]<<"\t"<<numn[3]<<"\t"<<total<<"\t\t"<<count<<"\t"<<order<<endl;
  out.close();
  }
  void showprevious(int check)
  {
    ifstream in("data",ios::in|ios::app);
    in.ignore(100,'#');
    while(in){
      in>>userid>>num[0]>>num[1]>>num[2]>>num[3]>>numn[0]>>numn[1]>>numn[2]>>numn[3]>>total>>count>>order;
      if(in)
      {
        if(check==userid){
          cout<<"\n-------------------------------------------------\n";
          cout<<"bill no:"<<count<<"\t\t\t\torder:"<<order<<endl;
          cout<<"userid:"<<userid<<endl;
          if(numn[0]!=0) cout<<"\nchicken-briyani:\t"<<numn[0]<<"*300\t="<<numn[0]*300;
          if(numn[1]!=0) cout<<"\nmutton-curry:\t\t"<<numn[1]<<"*500\t="<<numn[1]*500;
          if(numn[2]!=0) cout<<"\nchicken-tikka:\t\t"<<numn[2]<<"*250\t="<<numn[2]*250;
          if(numn[3]!=0) cout<<"\nfish-fry:\t\t"<<numn[3]<<"*300\t="<<numn[3]*300;
          if(num[0]!=0) cout<<"\ngobi-manchurian:\t"<<num[0]<<"*100\t="<<num[0]*100;
          if(num[1]!=0) cout<<"\ncorn-pizza:\t\t"<<num[1]<<"*200\t="<<num[1]*200;
          if(num[2]!=0) cout<<"\nveg-burger:\t\t"<<num[2]<<"*150\t="<<num[2]*150;
          if(num[3]!=0) cout<<"\nveg-biriyani:\t\t"<<num[3]<<"*250\t="<<num[3]*250;
          cout<<"\n-------------------------------------------------\n";
          cout<<"\ntotal\t\t\t\t="<<total;
          cout<<"\n-------------------------------------------------\n\n\n";
        }
      }
    }
    in.close();
  }
};
int main()
{
  veg *o[5];
  char x,r,w,c;
  cout<<"\t \t \t\t\tWELCOME TO TANDHA FOODS\n\n";
  AGAIN: cout<<"enter veg or non veg(n/v) \n";
  cin>>x;
  if(x=='n'||x=='N')
  {
    o[n]=new nonveg;
    cout<<"\nyournew id is:"<<n+1<<endl;
    id=n+1;
    o[n]->display();
  }
  else if(x=='v'||x=='V')
  {
    o[n]=new veg;
    cout<<"\nyournew id is:"<<n+1<<endl;
    id=n+1;
    o[n]->display();
  }
  o[n]->bill();
  second: cout<<"\ndo you want to place one more order or need to see your previous order or logout or quit(O/D/L/Q)\n";
  cin>>r;
  if(r=='o'||r=='O')
  {
    o[n]->display();
    o[n]->bill();
    goto second;
  }
  else if(r=='d'||r=='D')
  {
    o[id-1]->showprevious(id);
    goto second;
  }
  else if(r=='l'||r=='L')
  {
    system("clear");
    third: cout<<"\nnew or old user(n/o)?"<<endl;
    cin>>w;
    if(w=='n'||w=='N')
    {
      n++;
      goto AGAIN;
    }
    else
    {
      cout<<"enter id";
      cin>>id;
      if(id-1>=0&&id<=n+1)
      {
        cout<<"WELCOME BACK";
        o[id-1]->display();
        o[id-1]->bill();
        goto second;
      }
      else
      {
        cout<<"invalid id\n";
        goto third;
      }
    }
  }else if(r=='q'||r=='Q')
  {
    system("clear");
    cout<<"thank you";
  }  
  return 0;
}

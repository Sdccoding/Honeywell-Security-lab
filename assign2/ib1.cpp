#include<bits/stdc++.h>
#include <openssl/md5.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define f first
#define se second
#define ll int
#define ld long double
#define MOD 1000000007
struct node{
   string user_name;
   string password;
   ll index;
   vector<ll>v;
};
struct node info[11];  //[[Since,number of users =10]]

ifstream infile;
ofstream outfile; 

ifstream infile1;
ofstream outfile1;

ifstream infile2;
ofstream outfile2;


string hashing(string input)
{
  string str=input;
  unsigned char result[MD5_DIGEST_LENGTH];
  MD5((unsigned char*)str.c_str(), str.size(), result);

  std::ostringstream sout;
  sout<<std::hex<<std::setfill('0');
  for(long long c: result)
  {
      sout<<std::setw(2)<<(long long)c;
  }
  string ans=sout.str();
  return ans;
  cout<<endl;
  }
//Creating the files for the task.
void createfile()
{
   ll k;   //Number of honeywords
   cout<<"Please enter the number of honeywords to be generated : ";
   cin>>k;
   cout<<"I have taken 10 users.Now in order to create the username and password file,enter 10 usernames and 10 passwords"<<endl;
   cout<<"Format : Username Password"<<endl;
   ll ind=10;
   string user_name;
   string password;
    
   //f3.txt contains the mapping of index to username
   outfile.open("f3.txt");
   outfile1.open("hashFile.txt");
   outfile2.open("f1.txt");
   for(ll i=1;i<=10;i++)
   {


       cin>>user_name>>password;
       info[i].user_name=user_name;
       info[i].password=password;
       info[i].index=i;

       string md5Hex = hashing(password);
       outfile<<info[i].user_name<<" "<<info[i].index<<endl;
       outfile1<<info[i].index<<" "<<md5Hex<<endl;
       outfile2<<info[i].user_name<<" ";
       vector<ll>parents,inputs; 
       for(ll i=1;i<=10;i++)
          parents.pb(i);
       random_shuffle(parents.begin(), parents.end());
       inputs.pb(i);

       for(ll j=1;j<=k-1;j++)
       {
             if(parents[j]!=i)
             {
                 inputs.pb(parents[j]);
             }
             else
             {
                inputs.pb(parents[j+1]);
                j++;
             }
       }
       random_shuffle(inputs.begin(), inputs.end());
       for(ll i=0;i<inputs.size();i++)
        outfile2<<inputs[i]<<" ";
       
       outfile2<<endl;

   }

   outfile.close();
   outfile1.close();
   outfile2.close();
}


int main() 
{  

  while(1)
  {
   printf("Type 1 for adding 10 users\n");
   printf("Type 2 for logging in\n");
   printf("Any other number to exit\n");
   ll res=0;
   cin>>res;
   if(res==1)
     createfile();
   else if(res==2)
   {     
         string username;
         string password;
         printf("Please enter username:");
         cin>>username;
         printf("Please enter password:");
         cin>>password;
         ll cp=0;
         for(ll i=1;i<=10;i++)
         {
             if(info[i].user_name==username)
             {
                if(info[i].password==password)
                {
                  cout<<"Successfully Login\n"<<endl;
                }
                else
                  cout<<"Wrong Password.But No threat"<<endl;
                cp=1;
                break;
             }
         }
         if(cp==0)
          cout<<"No such user found"<<endl;
   }
   else
    break;
}



}
      



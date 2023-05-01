#include<iostream>
using namespace std;

   int panal[50][50],temp,gap_panal,miss_panal,minV;
    char par[10][10];

int min_panal(int i,int j,int k)
{
    if (i<=j)
    {
        minV=i;
    }
    else
    {
        minV=j;
    }
    if(k<minV)
    {
        minV=k;
    }
    return minV;
}
int getMatch(char a,char b,int c)
{
    if (a==b)
    {
        return 0;
    }
    else
    {
        return c;
    }
}
void print_alignment_seq1(int panlal[][50],char par[][10],string str1,int i,int j)
{
  if(par[i][j]=='D')
  {
    print_alignment_seq1(panlal,par,str1, i-1, j-1);
    cout<<str1[j-1];

  }
  else if(par[i][j]=='V')
  {
    print_alignment_seq1(panlal,par,str1, i-1, j);
    cout<<'_';
  }
  else if(par[i][j]=='H')
  {
      print_alignment_seq1(panlal,par,str1, i, j-1);
    cout<<str1[j-1];
  }
}
void print_alignment_seq2(int panlal[][50],char par[][10],string str2,int i,int j)
{
  if(par[i][j]=='D')
  {
    print_alignment_seq2(panlal,par,str2, i-1, j-1);
    cout<<str2[i-1];

  }
  else if(par[i][j]=='V')
  {
    print_alignment_seq2(panlal,par,str2, i-1, j);
    cout<<str2[i-1];
  }
  else if(par[i][j]=='H')
  {
    print_alignment_seq1(panlal,par,str2, i, j-1);
    cout<<'_';
  }
}
int main()
{
    string str1,str2;

    cout<<"enter your two string"<<endl;
    cin>>str1>>str2;
    cout<<"enter gap panelty"<<endl;
    cin>>gap_panal;
    cout<<"enter missmatch panelty"<<endl;
    cin>>miss_panal;

    for (int i=0; i<str2.length()+1; i++)
    {
        for(int j=0; j<str1.length()+1; j++)
        {
            if(i==0&&j==0)
            {
                panal[i][j]=0;
            }
            else if(i==0)
            {
                panal[i][j]=panal[i][j-1]+gap_panal;
                par[i][j]='H';
            }
            else if(j==0)
            {
                panal[i][j]=panal[i-1][j]+gap_panal;
                par[i][j]='V';
            }
            else
            {
                panal[i][j]= min_panal(panal[i-1][j-1]+getMatch(str2[i-1],str1[j-1],miss_panal) ,panal[i-1][j]+gap_panal, panal[i][j-1]+gap_panal);
                temp=panal[i][j];
                if (panal[i-1][j-1]+getMatch(str2[i-1],str1[j-1],miss_panal)==temp)
                {
                par[i][j]='D';

                }
                else if (panal[i-1][j]+gap_panal==temp)
                {
                 par[i][j]='V';
                }
                else if (panal[i][j-1]+gap_panal==temp)
                {
                   par[i][j]='H';
                }
        }

    }
    cout<<endl;
}
cout<<"minimum panalty "<<panal[str2.length()][str1.length()]<<endl;

print_alignment_seq1(panal,par,str1,str2.length(),str1.length());
cout<<endl;
print_alignment_seq2(panal,par,str2,str2.length(),str1.length());

}

#include<iostream>
#include<string>


using namespace std;

void convert_lowercase( string &word );

int main()
{

 string words[ 1000 ];
 string token,temp;
 int i,j,index=0;
 int numbers[ 1000 ];
 int vocab_size=0;


 for( i=0 ; i < 1000 ; i++ )
 {
  numbers[ i ]=0;
 }

 

 while( cin>>token )
 {
  convert_lowercase( token );
  words[ index ]=token;
  index++;
 }

 for( i=1 ; i < index ; i++ )
 {
   for( j=1 ; j < index ; j++ )
    {   
        if( words[ j-1 ] > words[ j ] )
        {
           temp=words[ j-1 ];
           words[ j-1 ]=words[ j ];
           words[ j ]=temp;
        }
    }
 }


 for( i=0 ; i < index ; i++ )
{

 for( j=0 ; j < index ; j++ )
  {

   if( words[ i ]==words[ j ] )
    {
      numbers[ i ]=numbers[ i ]+1;
    }

  }
}


  for( i=0 ; i < index && numbers[ i ] !=0 ;  )
 {

 
  i=i+numbers[ i ];
  ++vocab_size;

 }

 cout<<"Vocabulary Size = "<<vocab_size<<endl;

 for( i=0 ; i < index && numbers[ i ] !=0 ; )
 {
   cout<<words[ i ]<<" "<<numbers[ i ]<<endl;
   i=i+numbers[ i ];
 }

}

  
void convert_lowercase( string &word )
{
 
 int i;

 for( i=0 ; word[ i ] !='\0' ; i++ )
 {

  word[ i ]=static_cast<char>(tolower(char(word[ i ])));
 }

}















#include<iostream>
#include<fstream>
using namespace std;
int main(){
	string word = "",str;
	int temp;
	string n;
	
	cout<<"ENTER THE ENCRYPTED TEXT: ";
	getline (cin,n);
	
	cout<<"ENTER 1ST WORD:"<<endl;
	cin>>str;
	
	string decrypted_string;
	int key=0;
	//for finding the key
	
	for(int i=-1 ; i>=-9 ; i--){
		decrypted_string="";
		int todecrement=i;
		for(int j=0;j<str.size();j++){
			int ch=str[j];
				if(ch>=65 && ch<=90){		
					ch=ch+todecrement;
					if( ch > 90 ){ 
						ch%=90; 
						ch+=64;
					}
				}
				
				char out_char=ch;
			
				decrypted_string+=out_char;		
		}
		
		fstream myfile;
       	myfile.open("dictionary.txt",ios::in);
       	string word;
        	
		while(myfile>>word){
			if(word==decrypted_string){
			key=i;
			break;
			}	
		}
   }
	cout<<"KEY: "<< key <<endl;
	
	//DECRYPTING AFTER THE KEY IS FOUND
	temp=key;
	cout<<"\nDECRYPTED TEXT: ";
		int decrement=temp;
		for(int i=0;i<n.size();i++)
		{
			if(n[i]==' ')
			{
			    decrement-=2;
		      	cout<<" ";
		    			}
			else
			{
				int X=n[i];
				if(X>=65 && X<=90)
				{		X+=decrement;
						if(X>90) { X%=90; X+=64;}
						else if(X<65){ X=91-(65%X) ;}
						
				}
				else if((X>=97 && X<=122))
				{
					X+=decrement;
					if(X>122) { X%=122; X+=96;}
					else if(X<97){ X=123-(97%X) ;}
					
				}
				char out_char=X;	
				cout<<out_char;	
			}
		}

}

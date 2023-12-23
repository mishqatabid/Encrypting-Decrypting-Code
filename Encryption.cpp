#include<iostream>
using namespace std;
int main(){
	string txt;
	int key;
	
	cout << "ENTER THE TEXT TO ENCRYPT IT." << endl;
	getline (cin,txt);		//taking the sentence from the user to encrypt
	
	cout << "\nENTER THE LAST DIGIT OF RegID." << endl;
	cin >> key;		//taking the key from user to know how many shift it have to do
	 
	cout << "\nENCRYTED TEXT: " << endl;
	
	for(int i=0 ;i<txt.size() ;i++){
		int cha = int(txt[i]);
	//if statement for increment in the key after space	
		if (cha == 32){
			key += 2; 	//key=key+2
			cout << " " ;
			i++;
			cha=int(txt[i]);
		}
	//comparing ASCII values	
		if (cha >= 97 && cha <= 122){
			cha += key;		//adding key to the ASCII value of the string
			if (cha > 122){
				cha -= 26;		//cha=cha-26
			}
		}
		else{
			cha += key;		//cha=cha+key
			if(cha>90){
				cha -= 26;	//cha=cha-26	
			}
		}
		char ch = char(cha);
		cout << ch;		//showing the text after encryption (cipher text)
	}
	return 0;	
}	

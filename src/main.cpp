#include <iostream>
using namespace std;
string encrypt(string,string);
string decrypt(string,string);

int main() {
  char x;
  char y = '@';    //ASCII table used
  string choice;    //choice of user
  string plnText;    //plain text to encrypt/decrypt
  string key;    //key used to encrypt/decrypt
  cout << "Welcome to the Vigenere Cipher Decryption program by Joseph Caraan and Paul Ingram.\n\n";
  cout << "Enter 1 to encrypt or 2 to decrypt text (with no spaces or symbols): ";
  cin >> choice;
  while(choice != "1" && choice != "2"){
    cout << "ERROR. Please enter either 1 to encrypt to 2 to decrypt: ";
    cin >> choice;
  }
  if(choice == "1"){    //encryption
    cout << "Enter text that you wish to encrypt: ";
    cin >> plnText;
    cout << "Enter the key that you wish to use to encrypt your text: ";
    cin >> key;
    for(int i=0;i<plnText.size();i++) plnText[i] = toupper(plnText[i]);    //make sure lowercase strings are made uppercase
    for(int i=0;i<key.size();i++) key[i] = toupper(key[i]);    
    cout << "Encrypted text: " << encrypt(plnText,key) << endl;
  }
  else{    //decryptio
    cout << "Enter text that you wish to decrypt: ";
    cin >> plnText;
    cout << "Enter the key that you wish to use to decrypt your text: ";
    cin >> key;
    for(int i=0;i<plnText.size();i++) plnText[i] = toupper(plnText[i]);
    for(int i=0;i<key.size();i++) key[i] = toupper(key[i]);
    cout << "Decrypted text: " << decrypt(plnText,key) << endl;
  }
  return 0;
}

string encrypt(string inp,string key){
  string enc = "";
  int charToInt1;
  int charToInt2;
  int j = 0;
  for(int i=0;i<inp.size();i++){
    charToInt1 = int(inp[i])-65;   //row index Pi
    charToInt2 = int(key[j])-65;   //col index Ki
    j++;
    if(key[j]=='\0') j = 0;
    char c = char((charToInt1+charToInt2) % 26 + 65);    //+65 to fit right char on ascii
    enc += c;
  }
  return enc;
}

string decrypt(string inp,string key){
  string dec = "";
  int charToInt1;
  int charToInt2;
  int j = 0;
  for(int i=0;i<inp.size();i++){
    charToInt1 = int(inp[i])-65;    //Ei
    charToInt2 = int(key[j])-65;    //Ki
    j++;
    if(key[j]=='\0') j = 0;
    char c = char((charToInt1 - charToInt2 + 26) % 26 + 65);    //+65 to fit on ascii again, given on project directions
    dec += c;
  }
  return dec;
}
#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
using namespace std;

class RSA{
private:
int i,p,q,n,phi,e,k=1,d,msg_size;                                                                                                                                                                 ;
public:
char msg_ascii[100],cypher_ascii[100];
char msg[100],cypher[100];
int pgcd(int a, int b);
void printTexture();
bool isPrime(int n);
int mod(int a, int b, int n);
int encrypt(int letter, int e, int n);
int decrypt(int letter, int d, int n);
void Insert();
int get(char choice);
char arraycpy(char choice);
};

int RSA::pgcd(int a, int b){
   if (b == 0)
   return a;
   return pgcd(b, a % b);
}



bool RSA::isPrime(int n){
    bool vrai = true;
    if (n == 0 || n == 1) {
        vrai = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                vrai = false;
                break;
            }
        }
    }
    return vrai;
}

int RSA::mod(int a, int b, int n){
    long long x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}

int RSA::encrypt(int letter, int e, int n) {
int res;
res = mod(letter,e,n);
return res;
}

int RSA::decrypt(int  letter, int d, int n) {
int res;
res = mod(letter,d,n);
return res;
}

void RSA::Insert(){
	////Key generation
	do{
	do{
	cout<<"\n\t\t    Veillez choisir un nombre premier P> ";
	cin>>p;
	cout<<"\n\t\t    Veillez choisir un nombre premier Q> ";
	cin>>q;
	if ((isPrime(p) == false || isPrime(q) == false))
	cout<<"\t\t    Mauvaise entree! Entrez de nouveau"<<endl;
	} while (!(isPrime(p) == true && isPrime(q) == true) );
	n = p * q;
	phi = (p-1)*(q-1);
	cout<<"\t\t\t    P= "<<p<<"\t"<<"Q= "<<q<<endl;
	cout<<"\t\t\t    N= "<<n<<"\t"<<"Phi= "<<phi<<endl;
	///Choose E
	cout<<"\n\t\t    Entrez un nombre premier E tel que (1<E<Phi)> ";
	cin>>e;
	if (pgcd(phi,e)!=1){
	system("cls");
	cout<<"\t\t    Mauvaise entree! Entrez de nouveau"<<endl;
	}
	}while(pgcd(phi,e)!=1);
	cout<<"\t\t\t    E= "<<e<<endl;
	///Find d
	do{
	d = (phi*k+1)/e;
	if (e*d == phi*k+1)
	break;
	k++;
	} while(true);
	cout<<"\t\t\t    k= "<<k<<"\t"<<"d= "<<d<<endl;
	cout<<"\t\t\t    La cle publique (e,n) = ("<<e<<","s<<n<<")"<<endl;
	cout<<"\t\t\t    La cle prive (d,n) = ("<<d<<","<<n<<")\n"<<endl;
    ////Encryptin & Decrypting
    cout<<"\n\t\t    PlainText> ";
	cin>>msg;
//    cin.getline(msg,100);
	///Print the msg
	cout<<"\t\t\t    PlainText: ";
    i=0;
	while (msg[i] != '\0'){
	cout<<msg[i];
	i++;
	}
	i=0;
	cout<<endl;
	///ABC to ASCII
	while (msg[i] != '\0'){
	msg_ascii[i] =  msg[i];
	i++;
	}
	///Print the ASCII msg
	msg_size = i;
	cout<<"\t\t\t    PlainText(ASCII): ";
	for (i=0;i<msg_size;i++) {
	cout<<msg_ascii[i]<<" ";
	}
	cout<<endl;
	///Encrypting
	for (i=0;i<msg_size;i++) {
	cypher_ascii[i] = encrypt(msg_ascii[i],e,n);
	}
	///Print the ASCII cyphertext
	cout<<"\t\t\t    CypherText(ASCII): ";
	for (i=0;i<msg_size;i++) {
	cout<<cypher_ascii[i]<<" ";
	}
	cout<<endl;
	///ASCII to ABC
	for (i=0;i<msg_size;i++) {
	cypher[i] = cypher_ascii[i];
	}
	///Print the cyphertext
	cout<<"\t\t\t    CypherText(ABC): ";
	for (i=0;i<msg_size;i++) {
	cout<<cypher[i]<<" ";
	}
	cout<<endl;
	///Decrypting
	for (i=0;i<msg_size;i++) {
	msg_ascii[i] = decrypt(cypher_ascii[i],d,n);
	}
	///ASCII to ABC msg
	for (i=0;i<msg_size;i++) {
	msg[i] = msg_ascii[i];
	}
	///Print the msg ABC
	cout<<"\t\t\t    PlainText(ABC): ";
	for (i=0;i<msg_size;i++) {
	cout<<msg[i];
	}
}

int RSA::get(char choice){
switch(choice) {
case 'p':
        return p;
        break;
case 'q':
        return q;
        break;
case 'n':
        return n;
        break;
case 'f':
        return phi;
        break;
case 'd':
        return d;
        break;
case 'k':
        return k;
        break;
case 'e':
        return e;
        break;
case 's':
        return msg_size;
        break;
}
}


char RSA::arraycpy(char choice){
switch(choice) {
case 'm':
for(int i=0;i<msg_size;i++){
return msg[i];
}
break;
case 'M':
for(int i=0;i<msg_size;i++){
return msg_ascii[i];
}
break;
case 'c':
for(int i=0;i<msg_size;i++){
return cypher[i];
}
break;
case 'C':
for(int i=0;i<msg_size;i++){
return cypher_ascii[i];
}
break;
}
}

int main() {
	cout << "RSA ENCRYPTION AND DECRYPTION PROGRAMME"; 
  
    // We can print the statement first 
    // and then changed the color 
  
    // E for background Color(Light Yellow) 
    // 4 for text color(Red) 
    system("Color 40"); 
RSA run;
run.printTexture();
run.Insert();
ofstream log("log.txt");
log <<"[Rsa: log]"<<endl;
log<<"\t\t\t    P = "<<run.get('p')<<"\t"<<"Q = "<<run.get('q')<<endl;
log<<"\t\t\t    N = P*Q = "<<run.get('n')<<"\t"<<"Phi = (P-1) (Q-1) = "<<run.get('f')<<endl;
log<<"\t\t\t    E = "<<run.get('e')<<endl;
log<<"\t\t\t    K = "<<run.get('k')<<"\t"<<"D = (Phi*K+1)/E = "<<run.get('d')<<endl;
log<<"\t\t\t    La cle publique (e,n) = ("<<run.get('e')<<","<<run.get('n')<<")"<<endl;
log<<"\t\t\t    La cle prive (d,n) = ("<<run.get('d')<<","<<run.get('n')<<")\n"<<endl;
log<<"\t\t\t    PlainText: ";
for (int i=0;i<run.get('s');i++){
log<<run.msg[i];
}
log<<endl;
log<<"\t\t\t    PlainText(ASCII): ";
for (int i=0;i<run.get('s');i++){
log<<run.msg_ascii[i];
}
log<<endl;
log<<"\t\t\t    CypherText(ASCII): ";
for (int i=0;i<run.get('s');i++){
log<<run.cypher_ascii[i];
}
log<<endl;
log<<"\t\t\t    CypherText: ";
for (int i=0;i<run.get('s');i++){
log<<run.cypher[i];
}
log<<endl;
log.close();

return 0;
}

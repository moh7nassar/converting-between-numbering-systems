#include<iostream> 

#include<sstream> 

#include<algorithm> 

#include<vector> 

#include<iomanip> 

#include<cmath> 

using namespace std; 

int Hexachecking(string s) 

{ 

if (s.find("A") < 10000 || s.find("B") < 100000 || s.find("C") < 100000 || s.find("D") < 100000 || s.find("E") < 100000 || s.find("F") < 10000 || 

s.find("8") < 10000 || s.find("9") < 10000) 

return 1; 

else 

return 0; 

} 

int DecimalCheck(string s) 

{ 

for (int i = 0; i < s.size(); i++) 

{ 

if (s[i] >= 'A'&&s[i] <= 'Z') 

return 0; 

} 

return 1; 

} 

int binaryChecking(string s) 

{ 

for (int i = 0; i < s.size(); i++) 

{ 

for (char j = '2'; j <= '9'; j++) 

{ 

if (s[i] == j) 

return 0; 

} 

} 

return 1; 

} 

int errorChecking(string s) 

{ 

char ar[] = {'!','@','$','#','%','^','&','*','(',')','`','~',',','[',']','"','/','|','?','<','>','+','-','_','=',':',';'}; 

int size = sizeof(ar) / sizeof(ar[0]); 

for(int i=0;i<s.size();i++) 

    { 

        for(int j=0;j<size;j++) 

        { 

            if(s[i]==ar[j]) 

                return 0; 

        } 

    } 

for (int i = 0; i < s.size(); i++) 

{ 

for (char j = 'G'; j <= 'Z'; j++) 

{ 

if (s[i] == j) 

return 0; 

} 

} 

return 1; 

} 

int main() 

{ 

cout << "This program converts Decimal to any other numbering system or the opposite." << endl; 

cout << "************************************************************************************************" << endl; 

cout << "From Hexadecimal, Octal, Binary --> Decimal" << endl; 

cout << "                  OR                   " << endl; 

cout << "From Decimal --> Hexadecimal, Octal, Binary" << endl; 

cout << "------------------------------------------------------------------------------------------------" << endl; 

cout << "Enter the numbering system of the number that you have (D for decimal, H for Hexadecimal, O for Octal, B for Binary ) :" << endl; 

string numbering; 

cin >> numbering; 

while (true) 

{ 

numbering[0] = toupper(numbering[0]); 

if ((numbering[0] == 'O' || numbering[0] == 'H' || numbering[0] == 'D' || numbering[0] == 'B') && (numbering.size() == 1 || numbering.size() == 2 && numbering[1] == ' ')) 

break; 

else 

{ 

cout << "Unknown system was entered, please try again : "; 

cin >> numbering; 

} 

} 

if (numbering[0] == 'D') 

{ 

cout << "Enter a Decimal value : "; 

string dec,decalt; 

cin >> dec; 

while (true) 

{ 

for (int i = 0; i < dec.size(); i++) 

{ 

if (dec[i] >= 'a'&&dec[i] <= 'z') 

dec[i] = toupper(dec[i]); 

} 

if (errorChecking(dec) == 0) 

{ 

cout << "You entered an ambiguous number, please enter another one : "; 

cin >> dec; 

} 

else if (errorChecking(dec) == 1 && DecimalCheck(dec) == 0) 

{ 

cout << "This is a Hexadecimal Value please enter a Decimal one : "; 

cin >> dec; 

} 

else 

break; 

} 

decalt=dec; 

stringstream geek(dec); 

double x; 

geek >> x;//converting the string to double after being checked. 

int integer = (int)x; 

double fraction = x - integer; 

//-------------------------------------------------------------------------------------------------------------------- 

cout << "Please enter the numbering system that you want to convert to, B for Binary, H for Hexadecimal, O for Octal" << endl; 

string ch; 

cin >> ch; 

while (true) 

{ 

ch[0] = toupper(ch[0]); 

if ((ch[0] == 'H' || ch[0] == 'B' || ch[0] == 'O') && (ch.size() == 1 || ch.size() == 2 && ch[1] == ' ')) 

break; 

else 

{ 

cout << "Unknown system was entered, please try again : "; 

cin >> ch; 

} 

 

} 

int sys, integRemainder; 

//Declaring a String variable for presentation purposes. 

string s; 

//Declaring two vectors one for the integer part & one for the fraction part. 

vector<int>in; 

vector<double>doub; 

if (ch[0] == 'B') { s = "Binary"; sys = 2; } 

else if (ch[0] == 'O') { s = "Octal"; sys = 8; } 

else if (ch[0] == 'H') { s = "Hexadecimal"; sys = 16; } 

while (integer != 0) 

{ 

integRemainder = integer % sys; 

in.push_back(integRemainder); 

integer /= sys; 

} 

cout << "************************************************************************************************" << endl; 

cout << "The value that you entered " << decalt << " in Decimal system equals to "; 

if ((int)x == 0)cout << "0"; 

for (int i = in.size() - 1; i >= 0; i--) 

{ 

if (ch[0] == 'H') 

{ 

if (in[i] == 10)cout << "A"; 

else if (in[i] == 11)cout << "B"; 

else if (in[i] == 12)cout << "C"; 

else if (in[i] == 13)cout << "D"; 

else if (in[i] == 14)cout << "E"; 

else if (in[i] == 15)cout << "F"; 

else cout << in[i]; 

} 

else 

cout << in[i]; 

} 

cout << "."; 

double FracMulti; 

for (int i = 0; i < 4; i++) 

{ 

if (i == 0) 

FracMulti = fraction * sys; 

else FracMulti *= sys;//Multiply the new value of the Fraction By the system's base. 

doub.push_back((int)FracMulti); 

FracMulti = FracMulti - (int)FracMulti; 

} 

for (int i = 0; i < doub.size(); i++) 

{ 

if (ch[0] == 'H') 

{ 

if (doub[i] == 10)cout << "A"; 

else if (doub[i] == 11)cout << "B"; 

else if (doub[i] == 12)cout << "C"; 

else if (doub[i] == 13)cout << "D"; 

else if (doub[i] == 14)cout << "E"; 

else if (doub[i] == 15)cout << "F"; 

else cout << doub[i]; 

} 

else 

cout << doub[i]; 

} 

cout << " in " << s << " system" << endl; 

} 

else if (numbering[0] == 'H' || numbering[0] == 'O' || numbering[0] == 'B') 

{ 

vector<int>nt; 

vector<double>found; 

vector<double>frac; 

char c = toupper(numbering[0]); 

int sys; 

string s, name, alternative; 

if (c == 'B') 

{ 

name = "Binary"; 

cout << "Please enter a Binary number : "; 

sys = 2; 

} 

else if (c == 'H') 

{ 

name = "Hexadecimal"; 

cout << "Please enter a Hexadecimal number : "; 

sys = 16; 

} 

else { 

name = "Octal"; 

cout << "Please enter an Octal number : "; 

sys = 8; 

} 

cin >> s; 

for (int i = 0; i < s.size(); i++) 

{ 

if (s[i] >= 'a'&&s[i] <= 'z') 

{ 

s[i] = toupper(s[i]); 

} 

} 

if (errorChecking(s) == 0) 

{ 

while (errorChecking(s) == 0) 

{ 

cout << "You entered an ambiguous number, please enter another one : "; 

cin >> s; 

for(int i=0;i<s.size();i++) 

                { 

                    if(s[i]>='a'&&s[i]<='z') 

                        s[i]=toupper(s[i]); 

                } 

    } 

} 

alternative = s; 

c = toupper(c); 

if (Hexachecking(s) == 1 && c != 'H') 

{ 

while (true) { 

cout << "The number you entered doesn't match with the system you have chosen please enter another number : "; 

cin >> s; 

for(int i=0;i<s.size();i++) 

                { 

                    if(s[i]>='a'&&s[i]<='z') 

                        s[i]=toupper(s[i]); 

                } 

if (errorChecking(s) != 0) { 

 

if (Hexachecking(s) != 1) 

{ 

alternative = s; 

break; 

} 

} 

else 

{ 

while (errorChecking(s) == 0) 

{ 

cout << "You entered an ambiguous number, please enter another one : "; 

cin >> s; 

for(int i=0;i<s.size();i++) 

                        { 

                            if(s[i]>='a'&&s[i]<='z') 

                            s[i]=toupper(s[i]); 

                        } 

} 

if (Hexachecking(s) != 1) 

{ 

alternative = s; 

break; 

} 

 

} 

} 

} 

bool flag = true; 

if (c == 'B') 

{ 

while (true) 

{ 

    for(int i=0;i<s.size();i++) 

                { 

                    if(s[i]>='a'&&s[i]<='z') 

                        s[i]=toupper(s[i]); 

                } 

if(errorChecking(s)==0) 

                { 

                    cout<<"You entered an ambiguous number, please try again : "; 

                    cin>>s; 

                    continue; 

                } 

                if(binaryChecking(s)==1 && Hexachecking(s)==0) 

                { 

                    alternative=s; 

                    break; 

                } 

                else if(binaryChecking(s)==0 || Hexachecking(s)==1) 

                { 

                    cout<<"This is not a binary number, please try again : "; 

                    cin>>s; 

                } 

} 

} 

/*for (int i = 0; i < s.size(); i++) 

{ 

if (s[i] >= 'a'&&s[i] <= 'z') 

{ 

s[i] = toupper(s[i]); 

alternative[i] = toupper(alternative[i]); 

} 

}*/ 

int num, exp = 0, power; 

bool dot = false; 

if (s.find(".") > 10000) 

{ 

dot = true; 

} 

if (dot == true) 

{ 

//fraction is not found. 

for (int i = s.size() - 1; i >= 0; i--) 

{ 

if (c == 'H') 

{ 

if (s[i] == 'A')num = 10; 

else if (s[i] == 'B')num = 11; 

else if (s[i] == 'C')num = 12; 

else if (s[i] == 'D')num = 13; 

else if (s[i] == 'E')num = 14; 

else if (s[i] == 'F')num = 15; 

else 

{ 

//number 0 ASCII code equals to 48 and here the program deals with the ASCII code of each indivisual element in the String. 

num = s[i]; 

num -= 48; 

} 

} 

else 

{ 

num = s[i]; 

num -= 48; 

} 

power = pow(sys, exp); 

num = num * power; 

nt.push_back(num); 

exp++; 

} 

int sum = 0; 

for (int k = 0; k < nt.size(); k++) 

{ 

sum += nt[k]; 

} 

cout << "************************************************************************************************" << endl; 

cout << "The value that you entered " << alternative << " in " << name << " system equals to " << sum << " in Decimal system" << endl; 

} 

else if (dot == false) 

{ 

//fraction is found. 

int sumInt = 0, expo = 0, expo2 = -1; 

double sumFrac = 0; 

for (int i = (s.find(".")) - 1; i >= 0; i--) 

{ 

if (c == 'H') 

{ 

if (s[i] == 'A')num = 10; 

else if (s[i] == 'B')num = 11; 

else if (s[i] == 'C')num = 12; 

else if (s[i] == 'D')num = 13; 

else if (s[i] == 'E')num = 14; 

else if (s[i] == 'F')num = 15; 

else 

{ 

num = s[i]; 

num -= 48; 

} 

} 

else 

{ 

num = s[i]; 

num -= 48; 

} 

power = pow(sys, expo); 

num = num * power; 

found.push_back(num); 

expo++; 

} 

for (int k = 0; k < found.size(); k++) 

{ 

sumInt += found[k]; 

} 

 

double num2, power2; 

for (int i = (s.find(".")) + 1; i < s.size(); i++) 

{ 

if (c == 'H') 

{ 

if (s[i] == 'A')num2 = 10; 

else if (s[i] == 'B')num2 = 11; 

else if (s[i] == 'C')num2 = 12; 

else if (s[i] == 'D')num2 = 13; 

else if (s[i] == 'E')num2 = 14; 

else if (s[i] == 'F')num2 = 15; 

else 

{ 

num2 = s[i]; 

num2 -= 48; 

} 

} 

else 

{ 

num2 = s[i]; 

num2 -= 48; 

} 

power2 = pow(sys, expo2); 

num2 = num2 * power2; 

frac.push_back(num2); 

expo2--; 

} 

for (int v = 0; v < frac.size(); v++) 

{ 

sumFrac += frac[v]; 

} 

sumFrac += sumInt; 

cout << "************************************************************************************************" << endl; 

cout << "The value that you entered " << alternative << " in " << name << " system equals to " << setprecision(4) << fixed << sumFrac << " in Decimal system" << endl; 

} 

 

} 

cout << endl << "Thanks for trusting this program (: " << endl << endl; 

return 0; 

} 
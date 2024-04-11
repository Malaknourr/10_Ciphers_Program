/*
File Name : CS112_A2_T4_S19,20_20230419_20230144_20230166.cpp
Authors :
(1) Malak Nour-Elhussien Samir , ID: 20230419 , S19 ,problem taken :problem9,E-mail :nourrm218@gmail.com
 purpose p#9 : is to take the input and shape it like railfecnce then we read line by line and the decryption is the reverse.
 Bouns : pb#1(route) , pb#5(simple subtitution) and the menu.

(2) Reem Abdou Mohamed , ID : 20230144 , S19 , problem taken :problem4 ,E-mail :reem64404@gmail.com
 purpose p#4 : Replace every letter with group of 5 letters "a" or "b" using binary encoding.
Bouns : pb#7 (morse code) , pb#3 (vignere) , pb#0 (affine)

(3) Sara Ibrahim Mohamed , ID: 20230166 , S20 , problem taken :problem6 ,E-mail :si6357141@gmail.com
 purpose p#6 : using numbers. Each letter is replaced with two numbers according to the following table (row, column)
Bouns : pb#8 XOR , pb#2 (atbash)

Date : 19 March 2024
*/

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

//problem 0

void main_E0(){
    string MESSAGE;
    string message;
    cout<<"a)enter a,b,c values\n"<<"b)set a,b,c values by defult\n";
    string choice;
    cin>>choice;
    int a,b,c;
    while (choice!="a"&&choice!="b"){
        cout<<"Invalid choice:Try again";
        cin>>choice;
    }
    if (choice=="a"){
        cout << "Enter a,b,c values: \n";
        cin>>a>>b>>c;
        while (a*c%26!=1){
            cout << "Please enter valid values for where (a*c%26)=0:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>a>>b>>c;
        }
    }
    else if (choice=="b"){
        a=5;
        b=8;
        c=21;
    }
    cout << "Enter your message: \n";
    getline (cin >> ws, message);
    //convert message to uppercase
    for (int x = 0; x < message.size (); x++){
        char chr = toupper (message[x]);
        MESSAGE = MESSAGE + chr;}

    cout<<"your ciphered message is: ";

    //loop for every index in the string(message)
    for (int n = 0; n < MESSAGE.size (); n++){
        if (isalpha(MESSAGE[n])){
            //convert alphabetic char to ascci code in order to number alphabetic chars from 0 to 25
            int num = int (MESSAGE[n]) - 65;
            int code = (num*5+8)%26;
            cout<< char(code+65);
        }
        else {
            continue;
        }
    }
    cout<<endl;
}

void main_D0(){
    string MESSAGE;
    string message;
    cout<<"a)enter a,b,c values\n"<<"b)set a,b,c values by defult\n";
    string choice;
    cin>>choice;
    while (choice!="a"&&choice!="b"){
        cout<<"Invalid choice:Try again";
        cin>>choice;
    }
    int a,b,c;
    if (choice=="a"){
        int a,b,c;
        cout << "Enter a,b,c values: \n";
        cin>>a>>b>>c;
        while (a*c%26!=1){
            cout << "Please enter valid values for where (a*c%26)=0:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>a>>b>>c;
        }
    }
    else if (choice=="b"){
        a=5;
        b=8;
        c=21;
    }

    cout << "Enter your message: \n";
    getline (cin >> ws, message);
    //convert message to uppercase
    for (int x = 0; x < message.size (); x++){
        char chr = toupper (message[x]);
        MESSAGE = MESSAGE + chr;}

    cout<<"your deciphered message is: ";

    //loop for every index in the string(message)
    for (int n = 0; n < MESSAGE.size (); n++){
        if (isalpha(MESSAGE[n])){
            //convert alphabetic char to ascci code in order to number alphabetic chars from 0 to 25
            int num = int (MESSAGE[n]) - 65;
            int code = (c*(num-b));
            if (code >= 0){
                cout<< char((code%26)+65);
            }
            else if (code < 0 && -code>26){
                cout<< char(((26%-code)-(-code%26))+65);
            }
            else if (code < 0 && -code<26){
                cout<< char((26%-code)+65);
            }


        }
        else {
            continue;
        }
    }
}

// problem 1


int valid_key(string plainTEXT){
    int Number;
    bool valid = true;
    while (valid) {
        cout<<"PLEASE ENTER YOUR SECRET KEY"<<endl<<"NOTE ! key must be > 1 or <= the number of text characters"<<endl<<"==>";
        string keyNumber;
        getline(cin, keyNumber);
        if (keyNumber.find_first_not_of("0123456789") !=
            string::npos) {       // Check if the input contains only digits.
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;   //This line causes the loop to skip the rest of the current iteration and start a new one if the input is invalid.
        }
        Number = stoi(keyNumber);
        if (Number > 1 && Number <= (plainTEXT.length() / 2)){
            valid = false;
        }
        else{
            continue;
        }
    }
    return Number;
}

string valid_characters(string plainTEXT){
    string validstr = "";
    for(char letter : plainTEXT){
        if(isalpha(letter)){
            validstr += toupper(letter);
        }
        else{
            continue;
        }
    }
    return validstr;

}

void route_cipher() {
    cout << "WELCOME TO ROUTE CIPHER " << endl << "PLEASE ENTER YOUR MESSAGE ==>";
    string text_cipher;
    getline(cin, text_cipher);
    string new_STRING = valid_characters(text_cipher);
    int KEY = valid_key(new_STRING);
    int rows;
    if ((new_STRING.length()) % KEY == 0) {
        rows = new_STRING.length() / KEY;
    } else {
        rows = (new_STRING.length() / KEY) + 1;
    }

    //making the matrix as in-going filling.
    char route[rows][KEY];
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < KEY; j++) {
            route[i][j] = new_STRING[index++];
            if(index > new_STRING.length()){
                route[i][j] ='X';
            }
        }
    }


    //reading outer frame.
    int counter = 0 ;

    for (int rside = 0; rside < rows; rside++) { //ITAHE
        cout << route[rside][KEY - 1];
        counter++;
    }
    for (int bottom = KEY - 2; bottom > 0; bottom--) { //V
        cout << route[rows - 1][bottom];
        counter++;
    }
    for (int lside = rows - 1; lside > 0; lside--) { //ONOGB
        cout << route[lside][0];
        counter++;
    }
    for (int top = 0; top < KEY - 1; top++) { //R
        cout << route[0][top];
        counter++;
    }


    //reading in a sprial way.

    int i_1 = 0;
    int i_2 = 1;
    int i_3 = 0;
    int i_4 = 1 ;

    int ntimes = KEY * rows;
    while ((counter < ntimes)) {
        //cout <<"1"<<endl;
        //for each sprial colums should be minus one and rows should be plus one.
        for (int rside = 1 + (i_1) ; rside < rows - 1 - (i_1) ; rside++) { //HND
            cout <<route[rside][KEY - 2 - (i_1)];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        //cout<<endl;
        ++i_1;

        if(counter == ntimes){
            break;
        }
        //cout <<"2"<<endl;

        for (int bottom = KEY - 2 - (i_2) ; bottom > 1  ; bottom --) {
            cout <<route[rows - 1 - (i_2)][bottom];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_2;
        //cout<<endl;

        if(counter == ntimes){
            break;
        }

        //cout <<"3"<<endl;
        for (int lside = rows - 2 - (i_3); lside > 1 ; lside --) {
            cout <<route[lside - (i_3) ][(i_3) + 1];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_3;
        //cout<<endl;

        if(counter == ntimes){
            break;
        }

        //cout <<"4"<<endl;
        for (int top = 1 ; top < KEY - 1 - (i_4) ; top++) {//m
            cout<<route[i_4][top];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_4;
        //cout<<endl;

        if(counter == ntimes){
            break;
        }

    }
    //you are my sun shine my only sun shine you

}

void route_decipher() {
    cout << "WELCOME TO ROUTE DECIPHER " << endl << "PLEASE ENTER YOUR MESSAGE ==>";
    string text_cipher;
    getline(cin, text_cipher);
    string new_STRING = valid_characters(text_cipher);
    int KEY = valid_key(new_STRING);
    int rows;
    if ((new_STRING.length()) % KEY == 0) {
        rows = new_STRING.length() / KEY;
    } else {
        rows = (new_STRING.length() / KEY) + 1;
    }

    //making the matrix as in-going filling.
    char route[rows][KEY];
    int index = 0;
    //reading outer frame.
    int counter = 0 ;

    for (int rside = 0; rside < rows; rside++) { //ITAHE
        route[rside][KEY - 1] = new_STRING[index++];
        counter++;
    }

    for (int bottom = KEY - 2; bottom > 0; bottom--) { //V
        route[rows - 1][bottom] = new_STRING[index++];
        counter++;
    }
    for (int lside = rows - 1; lside > 0; lside--) { //ONOGB
        route[lside][0] = new_STRING[index++];
        counter++;
    }
    for (int top = 0; top < KEY - 1; top++) { //R
        route[0][top] = new_STRING[index++];
        counter++;
    }


    int i_1 = 0;
    int i_2 = 1;
    int i_3 = 0;
    int i_4 = 1 ;

    int ntimes = KEY * rows;
    while (counter < ntimes && index < new_STRING.length()) {

        //for each sprial colums should be minus one and rows should be plus one.

        for (int rside = 1 + (i_1) ; rside < rows - 1 - (i_1) ; rside++) { //HND
            route[rside][KEY - 2 - (i_1)] = new_STRING[index++];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_1;

        if(counter == ntimes){
            break;
        }

        for (int bottom = KEY - 2 - (i_2) ; bottom > 1  ; bottom --) {
            route[rows  - (i_2)][bottom] = new_STRING[index++];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_2;

        if(counter == ntimes){
            break;
        }

        for (int lside = rows - 2 - (i_3); lside > 1 ; lside --) {
            route[lside - (i_3) ][(i_3) + 1] = new_STRING[index++];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_3;

        if(counter == ntimes){
            break;
        }

        for (int top = 1 ; top < KEY - 1 - (i_4) ; top++) {//m
            route[i_4][top] = new_STRING[index++];
            counter++;
            if(counter == ntimes){
                break;
            }
        }
        ++i_4;

        if(counter == ntimes){
            break;
        }

    }

    // Output the deciphered message excluding 'X'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < KEY; j++) {
            if (route[i][j] != 'X') {
                cout << route[i][j];
            }
        }
    }
}


// Function to encrypt and decrypt a message using the Atbash cipher
string encrypt_atbash(const string& message) {
    string res = "";
    for (char ch : message) {
        if (isalpha(ch)) { // Check if the character is alphabetic
            char mirror_char = isupper(ch) ? 'Z' - (ch - 'A') : 'Z' - (ch - 'a'); // Calculate mirror character
            res += mirror_char; // Append mirror character to result
        }
        else {
            res += ch; // Append non-alphabetic characters as they are
        }
    }
    return res;
}

// Function to encrypt and decrypt a message using a modified Atbash cipher
string encrypt_atbash_v2(const string& message) {
    string res = "";
    for (char ch : message) {
        if (isalpha(ch)) { // Check if the character is alphabetic
            if (ch >= 'a' && ch <= 'z') { // Check if the character is lowercase
                if (ch >= 'n') // Check if the character is in the second half of the alphabet
                    res += 'Z' - (ch - 'n'); // Encrypt using the second half of the alphabet
                else
                    res += 'M' - (ch - 'a'); // Encrypt using the first half of the alphabet
            }
            else { // Character is uppercase
                if (ch >= 'N') // Check if the character is in the second half of the alphabet
                    res += 'Z' - (ch - 'N'); // Encrypt using the second half of the alphabet
                else
                    res += 'M' - (ch - 'A'); // Encrypt using the first half of the alphabet
            }
        }
        else {
            res += ch; // Append non-alphabetic characters as they are
        }
    }
    // Convert res to uppercase
    for (char& c : res) {
        c = toupper(c);
    }
    return res;
}

// Function to validate and filter input text
string Valid_Text(string input) {
    string plainText = "";
    for (char& c : input) {
        if (isalpha(c)) {
            plainText += tolower(c); // Convert characters to lowercase
        }
    }
    return plainText;
}



// Function to encrypt a message (version 1)
void main_E1_1() {
    string plaintext;
    cout << "Please enter the text you want to encrypt: ";
    getline(cin,plaintext );
    plaintext = Valid_Text(plaintext);

    string ciphertext = encrypt_atbash(plaintext);

    cout << "plaintext: " << plaintext << endl;
    cout << "ciphertext: " << ciphertext << endl;
}

// Function to decrypt a message (version 1)
void main_D1_1() {
    string ciphertext;
    cout << "Please enter the text you want to decrypt: ";
    getline(cin,ciphertext);
    ciphertext = Valid_Text(ciphertext);

    string plaintext = encrypt_atbash(ciphertext);

    cout << "ciphertext: " << ciphertext << endl;
    cout << "plaintext: " << plaintext << endl;
}

// Function to encrypt a message (version 2)
void main_E1_2() {
    string plaintext;
    cout << "Please enter the text you want to encrypt: ";
    getline(cin,plaintext );
    plaintext = Valid_Text(plaintext);

    string ciphertext = encrypt_atbash_v2(plaintext);

    cout << "plaintext: " << plaintext << endl;
    cout << "ciphertext: " << ciphertext << endl;
}

// Function to decrypt a message (version 2)
void main_D1_2() {
    string ciphertext;
    cout << "Please enter the text you want to decrypt: ";
    getline(cin,ciphertext );
    ciphertext = Valid_Text(ciphertext);

    string plaintext = encrypt_atbash_v2(ciphertext);

    cout << "ciphertext: " << ciphertext << endl;
    cout << "plaintext: " << plaintext << endl;
}
void menu_E1_(){
    cout << " Welcome to the Atbash Cipher" << endl;
    cout << "=================================================================" << endl;
    cout << "What is version of Atbash cipher do you want to use?" << endl;
    cout << "1) Atbash cipher version one." << "\n" << "2) Atbash cipher version two."  << "\n";
    string choice;
    cin >> choice;
    cin.ignore(); // Clear the newline character from the input buffer
    if (choice == "1") {
        main_E1_1();
    } else if (choice == "2") {
        main_E1_2();

    }else {
        cout << "Invalid choice,Please enter a valid choice." << endl << endl;
        return menu_E1_();
    }
}


void menu_D1_(){
    cout << " Welcome to the Atbash decipher" << endl;
    cout << "==================================================================" << endl;
    while (true) {
        cout << "What is version of Atbash decipher do you want to use?" << endl;
        cout << "1) Atbash decipher v1" << "\n" << "2) Atbash decipher v2"  <<  endl;
        string choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
        if (choice == "1") {
            main_D1_1();
            break;
        } else if (choice == "2") {
            main_D1_2();
            break;
        }else {
            cout << "Invalid choice,Please enter a valid choice." << endl << endl;
            return menu_D1_();
        }
    }
}

// problem 3

void Vignere_Cipher() {
    string message;
    string MESSAGE = "";
    string key;
    string KEY = "";
    string KEYWORD = "";
    int n,m;
    cout << "Enter your message: \n";
    getline (cin >> ws, message);
    //Check length of message
    while ( message.size()>80){
        cout << "Please Enter a message <= 80 characters : \n";
        getline (cin >> ws, message);
    }
    cout << "Enter key: \n";
    getline (cin >> ws, key);
    //check lenght of key
    while ( key.size()>8){
        cout << "Please Enter message <= 8 characters : \n";
        getline (cin >> ws, key);
    }
    //make key lenght = message lenght
    n = message.size() / key.size();
    m = message.size() % key.size();
    for (int i = 0 ; i < n ; i++){
        KEY = KEY + key;
    }
    for (int j = 0 ; j < m ; j++){
        KEY = KEY + key[j];
    }
    //convert text to uppercase
    for (int x = 0; x < message.size (); x++)
    {
        char chr = toupper (message[x]);
        MESSAGE = MESSAGE + chr;
    }
    //convert KEY to uppercase
    for (int x = 0; x < KEY.size (); x++)
    {
        char chr = toupper (KEY[x]);
        KEYWORD = KEYWORD + chr;
    }
    //encode every letter in the massage
    for (int n = 0; n < MESSAGE.size (); n++){
        int num = (int(MESSAGE[n])+int(KEYWORD[n]))%26 + 65 ;
        if (isalpha(MESSAGE[n])){
            cout<<(char)num;
        }
        else {
            cout<<MESSAGE[n];
        }
    }
}


void Vignere_Decipher() {
    string message;
    string MESSAGE = "";
    string key;
    string KEY = "";
    string KEYWORD = "";
    int n,m;
    cout << "Enter your message: \n";
    getline (cin >> ws, message);
    //Check length of message
    while ( message.size()>80){
        cout << "Please Enter a message <= 80 characters : \n";
        getline (cin >> ws, message);
    }
    cout << "Enter key: \n";
    getline (cin >> ws, key);
    //check lenght of key
    while ( key.size()>8){
        cout << "Please Enter message <= 8 characters : \n";
        getline (cin >> ws, key);
    }
    //make key lenght = message lenght
    n = message.size() / key.size();
    m = message.size() % key.size();
    for (int i = 0 ; i < n ; i++){
        KEY = KEY + key;
    }
    for (int j = 0 ; j < m ; j++){
        KEY = KEY + key[j];
    }
    //convert text to uppercase
    for (int x = 0; x < message.size (); x++)
    {
        char chr = toupper (message[x]);
        MESSAGE = MESSAGE + chr;
    }
    //convert KEY to uppercase
    for (int x = 0; x < KEY.size (); x++)
    {
        char chr = toupper (KEY[x]);
        KEYWORD = KEYWORD + chr;
    }
    //loop for every letter in message
    for (int n = 0; n < MESSAGE.size (); n++){
        if (isalpha(MESSAGE[n])){
            int num = int(MESSAGE[n])-int(KEYWORD[n]) + 65 ;
            if (num>=90 || num<65){
                int num = int(MESSAGE[n])-int(KEYWORD[n]) + 91 ;
                cout<<(char)num;
            }
            else{
                cout<<(char)num;
            }
        }
        else {
            cout<<MESSAGE[n];
        }
    }
}

//problem4
void  main_E4 (){
//list contains cipher of every character
    string code[26] ={ "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba","aabbb","abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb","baaaa","baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa","bbaab"};
    string MESSAGE;
    string message;
    cout << "Enter your message: \n";
    getline (cin >> ws, message);
//convert text to uppercase
    for (int x = 0; x < message.size (); x++)
    {
        char chr = toupper (message[x]);
        MESSAGE = MESSAGE + chr;
    }
    cout << "your ciphered message is: ";
//loop for every index in the string(message)
    for (int n = 0; n < MESSAGE.size (); n++)
    {
        if (isalpha (MESSAGE[n]))
        {
            //convert alphabetic char to ascci code in order to number alphabetic chars from 0 to 25
            int num = int (MESSAGE[n]) - 65;
            cout << code[num];
            cout << " ";
        }
        else {
            cout<<MESSAGE[n];
        }
    }
    cout<<endl;
}

void main_D4() {
    //list contains cipher of every character
    string code[26] ={ "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba","aabbb","abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb","baaaa","baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa","bbaab"};
    cout << "Enter your message: \n";
    string message;
    string alpha = "";
    getline(cin >> ws, message);
    cout<<"==> \"NOTE: IF you enter a non valid code starts with \"a\" or \"b\" it will be ignored\";"<<endl;
    cout << "your deciphered message is: ";
    for (int i = 0; i < message.size();) {
        string alpha = "";
        if (message[i] == 'a' || message[i] == 'b') {
            //loop that take every 5 letters in a varibal (alpha)
            for (int m = 0; m < 5; m++) {
                alpha = alpha + message[i + m];
            }
            //searching for equivalent alphaptic char
            for (int x = 0; x < 26; x++) {
                if (alpha == code[x]) {
                    //convert ascci number to its alphabetic char
                    x = x + 65;
                    cout << (char) x;
                }
            }
            i += 5;
        }
        else if (message[i] == ' ' && message[i+1]!=' ' ) {
            i++;
        }
        else if (message[i] == ' ' && message[i+1]==' ') {
            cout<<" ";
            i++;
        }
        else {
            cout << message[i];
            i++;
        }

    }
    cout<<endl;
}

// problem 5

bool check_key(const vector<char>& key) {   // check the secret key's validation
    // Check if elements are distinct
    set<char> unique_elements(key.begin(), key.end());
    //The set container automatically removes duplicates, so if key has duplicate elements, they will be removed.

    if (unique_elements.size() != key.size()) {     // means that there are duplicated letters.
        return false;
    }

    // Check if elements are alphabetical
    for (char element : key) {
        if (!isalpha(element)) {
            return false;
        }
    }
    return true;
}

string New_Alphabetic() {   //rearrange the alphabetic letters by the inputed secret key
    string newAlphabetic;
    vector<char> key_array(5);
    bool valid = false;

    while (!valid) {
        cout << "ENTER A VALID SECRET KEY" << endl << "INSERT 5 DISTINCT LETTERS ==> ";
        for (int index = 0; index < 5; index++) {
            cin >> key_array[index];
        }

        if (check_key(key_array)) {
            valid = true;
        } else {
            cout << "Invalid key. Please try again." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    }

    // if the key is cairo so the new alpha is "cairo+{the 21 remaining letters}".
    for(int i = 0 ; i <= 4 ; i++) {
        newAlphabetic += tolower(key_array[i]);
    }
    //adding the rest of non-taken alphabetic letters
    for(char restLetters = 'a' ; restLetters <= 'z' ; restLetters++) {
        bool found = false;
        for(char keyLetter : key_array) {  //avoid repeated letters
            if (restLetters == keyLetter) {
                found = true;
                break;
            }
        }
        if (!found) {   // inserting the rest letters
            newAlphabetic += restLetters;
        }
    }
    return newAlphabetic;
}

void main_E5(){
    cout << "WELCOME TO THE SIMPLE SUBSTITUTION CIPHER" << endl;
    string new_alpha = New_Alphabetic();
    string encryption_text = "";
    cout << "NOW ENTER THE MESSAGE YOU WANT TO ENCRYPT :" << endl;
    string plain_text;
    getline(cin, plain_text);

    /* so we know our alpha==>       a b c d e f g h i j k l m n o p q ....z
    if we considered cairo as key :  c a i r o b d e f g h j k l m n p q...z
    if the encrypted message was "I LOVE C PLUS PLUS"
    so we replace each letter by the one in its place in the new alpha
    I = f , L=j , O = m , v = v , ...etc
     */

    // The function iterates through each character in the input message, one character at a time.
    for(char ch : plain_text){  //for each char in the text lets take  "I"
        if(isalpha(ch)){
            char encrypted_char = new_alpha[tolower(ch) - 'a']; // Compute encrypted character
            if(isupper(ch)){ // Preserve original case
                encrypted_char = tolower(encrypted_char);
            }
            encryption_text += (encrypted_char); // Convert encrypted character to lowercase and append
        }
        else {
            encryption_text += ch; // Preserve non-alphabetic characters
        }
    }
    cout << "HERE IS YOUR ENCRYPTED MESSAGE ==> " << encryption_text<<endl;
}

int index_number(char text_ch, const string& new_alpha) { // to find the index of the char in the message
    int index = 0;
    while (index < new_alpha.length()) {
        if (new_alpha[index] == text_ch) {
            break;
        } else {
            index++;
        }
    }
    return index;
}

void main_D5() {
    cout << "WELCOME TO THE SIMPLE SUBSTITUTION CIPHER" << endl;
    string new_alpha = New_Alphabetic();
    string our_alpha ="abcdefghijklmnopqrstuvwxyz";
    string decryption_text = "";
    cout << "NOW ENTER THE MESSAGE YOU WANT TO DECRYPT :" << endl;
    string text;
    getline(cin, text);

    /*we considered cairo as key :  c a i r o b d e f g h j k l m n p q...z
     so we know our alpha==>        a b c d e f g h i j k l m n o p q ....z
     so we want to know the index of each letter in the input and replace it with its position in the oldalpha.
     like if i input air ==>  a => 1 , i => 2, r => 3
     so we replace it as ==>  1 => b , 2 => c , 3 => d
     */

    for(char ch : text){
        if(isalpha(ch)) {
            int index = index_number(tolower(ch), new_alpha);
            decryption_text += our_alpha[index];
        } else{
            decryption_text += ch;
        }
    }
    cout << "HERE IS YOUR DECRYPTED MESSAGE ==> " << decryption_text<<endl;
}


//problem 6

// Function to check if the input string contains only distinct numbers.
bool is_ValidKey(const string& input) {
    stringstream ss(input);
    int num;
    vector<int> numbers;

    while (ss >> num) {
        if (num < 1 || num > 5) {
            return false; // Numbers should be in the range 1-5
        }

        auto it = find(numbers.begin(), numbers.end(), num);
        if (it != numbers.end()) {
            return false; // Numbers should be distinct
        }

        numbers.push_back(num);
    }

    return numbers.size() == 5;
}

// Function to encrypt a message using Polybius Square matrix.
string encrypt_message(const char matrix[6][6], const string& message) {
    string encrypted_message = "";
    for (char ch : message) {
        char current_char = toupper(ch);
        if (current_char == 'J') {
            current_char = 'I';
        }
        if (current_char >= 'A' && current_char <= 'Z') {
            for (int i = 1; i < 6; i++) {
                for (int j = 1; j < 6; j++) {
                    if (current_char == matrix[i][j]) {
                        encrypted_message += matrix[0][i];
                        encrypted_message += matrix[j][0];
                    }
                }
            }
        }
    }
    return encrypted_message;
}

// Function to decrypt a message using Polybius Square matrix
string decrypt_message(const char matrix[6][6], const string& message) {
    string decrypted_message = "";
    for (int i = 0; i < message.length(); i += 2) {
        char rowChar = message[i];
        char colChar = message[i + 1];

        int row, col;
        for (int j = 1; j < 6; j++) {
            if (rowChar == matrix[0][j]) {
                row = j;
            }
            if (colChar == matrix[j][0]) {
                col = j;
            }
        }
        decrypted_message += matrix[row][col];
    }
    return decrypted_message;
}

void main_E6(){
    string key;
    // Keep prompting the user until a valid key is entered
    do {
        cout << "Please enter the key (5 distinct numbers from 1 to 5 separated by spaces): "<<endl;
        getline(cin, key);

        if (!is_ValidKey(key)) {
            cout << "Invalid key. Please enter 5 distinct numbers from 1 to 5 separated by spaces." << endl;
        }
    } while (!is_ValidKey(key));

    // analyse the validated key input
    stringstream key_stream(key);
    int c[5];
    for (int i = 0; i < 5; i++) {
        key_stream >> c[i];
    }

    // Create a 6x6 Polybius Square matrix with the user-entered key
    char matrix[6][6];
    int k = 0;

    // Fill the first row with the key (setting the first index as an empty char)
    for (int i = 1; i < 6; i++) {
        matrix[0][0] = ' ' ;
        matrix[0][i] = c[i - 1] + '0';
    }

    // Fill the first column with the key (setting the first index as an empty char)
    for (int i = 1; i < 6; i++) {
        matrix[0][0] = ' ' ;
        matrix[i][0] = c[i - 1] + '0';
    }

    // Fill the remaining positions with the alphabet (excluding 'J')
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            char next_char;
            do {
                next_char = 'A' + k;
                k++;
            } while (next_char == 'J');

            matrix[i][j] = next_char;
        }
    }

    // Display the Polybius Square matrix
    cout << "\nThe Polybius Square matrix is:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    string message;
    {
        do {
            cout << "\nPlease enter the message you want to encrypt (should contain at least one alphabetical character): ";
            getline(cin, message);

            if (all_of(message.begin(), message.end(), [](char c) { return isdigit(c) || isspace(c); })) {
                cout << "Invalid message. Please enter a message with at least one alphabetical character." << endl;
            }
        } while (all_of(message.begin(), message.end(), [](char c) { return isdigit(c) || isspace(c); }));


        // Encrypt the message using the Polybius Square matrix
        string Encrypted_Message = encrypt_message(matrix, message);

        cout << "\nEncrypted message: " << Encrypted_Message << endl;
    }
}

void main_D6() {
    string key;

    // Keep prompting the user until a valid key is entered
    do {
        cout << "Please enter the key ((1-5) distinct numbers separated by spaces): ";
        getline(cin, key);

        if (!is_ValidKey(key)) {
            cout << "Invalid key. Please enter (1-5) distinct numbers separated by spaces." << endl;
        }
    } while (!is_ValidKey(key));

    // analyse the validated key input
    stringstream keyStream(key);
    int c[5];
    for (int i = 0; i < 5; i++) {
        keyStream >> c[i];
    }

    // Create a 6x6 Polybius Square matrix with the user-entered key
    char matrix[6][6];
    int k = 0;

    // Fill the first row with the key (setting the first index as an empty char)
    for (int i = 1; i < 6; i++) {
        matrix[0][0] = ' ';
        matrix[0][i] = c[i - 1] + '0';
    }

    // Fill the first column with the key (setting the first index as an empty char)
    for (int i = 1; i < 6; i++) {
        matrix[0][0] = ' ';
        matrix[i][0] = c[i - 1] + '0';
    }

    // Fill the remaining positions with the alphabet (excluding 'J')
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            char next_char;
            do {
                next_char = 'A' + k;
                k++;
            } while (next_char == 'J');

            matrix[i][j] = next_char;
        }
    }

    // Display the Polybius Square matrix
    cout << "\nThe Polybius Square matrix is:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    string message;

    // Keep prompting the user until a valid message with an even number of characters is entered
    do {
        cout << "\nPlease enter the message you want to decrypt (should contain an even number of numerical characters): ";
        getline(cin, message);

        if (all_of(message.begin(), message.end(), [](char c) { return isalpha(c) || isspace(c); })) {
            cout << "Invalid message. Please enter a message with an even number of numerical characters." << endl;
        } else {
            // Check if the entered numbers are within the valid range
            bool valid_range = true;
            for (char c : message) {
                if (isdigit(c)) {
                    int num = c - '0';
                    if (num < 1 || num > 5) {
                        valid_range = false;
                        break;
                    }
                }
            }

            if (!valid_range || message.length() % 2 != 0) {
                cout << "Invalid input. Please enter an even number of numbers within the range (1-5)." << endl;
            } else {
                break; // Break out of the loop if the input is valid
            }
        }
    } while (true);

    // Decrypt the message using the Polybius Square matrix
    string Decrypted_Message = decrypt_message(matrix, message);
    cout << "\nDecrypted message: " << Decrypted_Message << endl;
}

// problem 7

void Morse_decipher(){
    //list contains morse code of every character
    string code[63] ={"-.-.--","",".-..-.","...-..-","",".-...",".----.","-.--.","-.--.-","",".-.-.","--..--","-....-",".-.-.-","-..-.","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","---...","-.-.-.","","-...-","","..--..",".--.-.",".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....","..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.","--.-",".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--","--..","","-..-.","","","..--.-"};
    cout << "NOTE:program decipher chatcter that it's value between 32:96" <<endl;
    cout << "Enter your message: \n";
    string message;
    string alpha = "";
    getline (cin >> ws, message);
    cout<<"NOTE: All invalid code symbols will be ignored"<<endl;
    cout << "your deciphered message is: "<<endl;
    //loop for every index in the string(message)
    for (int i = 0; i < message.size(); i++){
        if(message[i]=='-'|| message[i]=='.'){
            alpha = alpha+message[i];
            //check the next character
            if (message[i+1]==' ' || i== (message.size()-1)){
                for (int x = 0; x < 63; x++){
                    bool found=false;
                    if (alpha==code[x]){
                        //convert ascii code to it's alphabetic char
                        x = x + 33;
                        cout<<(char)x;
                        found = true;
                        break; }
                }
                //Set alpha to null
                alpha="";
            }
        }
        //check spaces
        if (message[i]==' ' && message[i+1]==' ' && message[i+2]==' '){
            cout<<" ";
            //Set alpha to null
            alpha="";}
    }
}

void Morse_cipher(){
    //list contains morse code of every character
    string code[63] ={"-.-.--","",".-..-.","...-..-","",".-...",".----.","-.--.","-.--.-","",".-.-.","--..--","-....-",".-.-.-","-..-.","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","---...","-.-.-.","","-...-","","..--..",".--.-.",".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....","..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.","--.-",".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--","--..","","-..-.","","","..--.-"};

    string MESSAGE;
    string message;
    cout << "NOTE:program cipher chatcter that it's Ascii value between 32:96" <<endl;
    cout << "Enter your message: \n";
    getline (cin >> ws, message);

    //convert text to uppercase
    for (int x = 0; x < message.size (); x++){
        char chr = toupper (message[x]);
        MESSAGE = MESSAGE + chr;}

    cout<<"your ciphered message is: ";

    //loop for every index in the string(message)
    for (int n = 0; n < MESSAGE.size (); n++){
        if ((MESSAGE[n])==' '){
            cout<<"  ";
        }
        else {
            //convert alphabetic char to ascci code in order to number alphabetic chars from 0 to 25
            int num = int (MESSAGE[n]) - 33;
            cout << code[num];
            //set space between characters
            cout << " ";
            //set spaces between words
        }
    }
}

// problem 8

// Function to repeat the key to match the length of the plaintext or ciphertext
string repeatKey(const string& key, size_t length) {
    string repeatedKey;
    size_t keyLength = key.size();
    for (size_t i = 0; i < length; ++i) {
        repeatedKey += key[i % keyLength];
    }
    return repeatedKey;
}

// Function to encrypt plaintext using XOR with repeated key
string encrypt(const string& plaintext, const string& key) {
    string repeatedKey = repeatKey(key, plaintext.size());
    string ciphertext;
    for (size_t i = 0; i < plaintext.size(); ++i) {
        char encryptedChar = plaintext[i] ^ repeatedKey[i % repeatedKey.size()];
        ciphertext += encryptedChar;
    }
    return ciphertext;
}

// Function to decrypt ciphertext using XOR with repeated key
string decrypt(const string& ciphertext, const string& key) {
    string repeatedKey = repeatKey(key, ciphertext.size());
    return encrypt(ciphertext, repeatedKey); // XOR encryption and decryption are symmetric
}

// Function to convert a string to its hexadecimal representation
string stringToHex(const string& input) {
    static const char hexDigits[] = "0123456789ABCDEF";
    string hexString;
    for (char c : input) {
        unsigned char uc = static_cast<unsigned char>(c);
        hexString.push_back(hexDigits[uc >> 4]);
        hexString.push_back(hexDigits[uc & 0xF]);
    }
    return hexString;
}

// Function to convert a hexadecimal string to its ASCII representation
string hexToString(const string& hex) {
    string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        istringstream converter(hex.substr(i, 2));
        int value;
        converter >> std::hex >> value;
        result += static_cast<char>(value);
    }
    return result;
}

// Function to validate if a single digit is '1' or '2'
bool validateSingleDigit(char digit) {
    return (digit == '1' || digit == '2');
}

// Function to validate if a choice is valid (either '1' or '2')
bool validateChoice(const string& choice) {
    if (choice.size() != 1) {
        return false; // Only accept single-digit choices
    }
    return validateSingleDigit(choice[0]); // Validate if the single digit is '1' or '2'
}
bool validateHexInput(const string& input) {
    for (char c : input) {
        if (!isxdigit(c)) {
            return false;
        }
    }
    return true;
}
void main_E8(){
    string plaintext;
    string key;

    cout << "Enter the plain text: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    getline(cin, key);
    string repeatedKey = repeatKey(key, plaintext.size());

    string ciphertext = encrypt(plaintext, repeatedKey);
    cout << "Cipher text: " << ciphertext << endl;
    cout << "Hexa: " << stringToHex(ciphertext) << endl;
}

void main_D8(){
    string hexCiphertext;
    string key;

    // Loop until the user enters a valid hexadecimal ciphertext (with no spaces)
    do {
        cout << "Enter the hexa cipher text (with no spaces): ";
        getline(cin, hexCiphertext);
        if (!validateHexInput(hexCiphertext)) {
            cout << "Invalid input. Please enter hexadecimal characters only." << endl;
        }
    } while (!validateHexInput(hexCiphertext));

    string ciphertext = hexToString(hexCiphertext);

    cout << "Enter the key: ";
    getline(cin, key);
    string repeatedKey = repeatKey(key, ciphertext.size());

    string decryptedText = decrypt(ciphertext, repeatedKey);
    cout << "Decrypted text: " << decryptedText << endl;
}


// problem 9

string valid_Text(string input){  //filter out non-alphabetic characters from the input
    string Plain_Text = "";
    for (char& c : input){
        if(isalpha(c)){
            Plain_Text += tolower(c); //making every letter lower case
        }
        else
        {
            continue;
        }
    }
    return Plain_Text;
}

//output the encrypted message by rail fence pattern as :
/* when I input "my own"
 * m     n  diffrence between indesies here = 4
 *  y    w  diffrence between indesies here = 2
 *    o     diffrence between indesies here = 4
*/

void rail_fence_encryption(string fixed_input){
    cout<<"NOTE : Non-alphabetic inputs are ignored."<<endl;
    cout<<"HERE IS YOUR ENCRYPTED MESSAGE : " << endl << "==>";
    for(int i = 0 ; i < fixed_input.size() ; i += 4 ){ //printing first row
        cout<<fixed_input[i];
    }
    for(int n = 1 ; n < fixed_input.size() ; n += 2 ){ //printing second row
        cout<<fixed_input[n];
    }
    for(int k = 2 ; k < fixed_input.size() ; k += 4 ) { //printing third row
        cout <<fixed_input[k];
    }
    cout<<endl;
}
void main_E9(){
    cout<<"WELCOME TO THE RAIL-FENCE ENCRYPTION METHOD"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Please enter your message :" <<endl;
    string input ;
    getline(cin , input);
    string fixed_input = valid_Text(input); //filtering input text
    rail_fence_encryption(fixed_input);     //encrypt it
}

//output the decrypted message by rail fence pattern.
/* when I input "mnywo"
 * m     n (1st loop) diffrence between indesies here = 4
 *  y    w (2nd loop) diffrence between indesies here = 2
 *    o    (3rd loop) diffrence between indesies here = 4
*/

void rail_fence_decryption(const string& input) {//decryption function to fill in a string the decrptes message.
    int len = input.length();
    string text = valid_Text(input);
    string plain_text(len, ' '); // Initialize a string with spaces
    int index = 0; //to loop over the encrypted message.
    for (int i = 0 ; i < len ; i += 4) {
        plain_text[i] = text[index++];
    }
    for (int n = 1 ; n < len ; n += 2) {
        plain_text[n] = text[index++];
    }
    for (int k = 2 ; k < len ; k += 4) {
        plain_text[k] = text[index++];
    }
    cout<<"NOTE : Non-alphabetic inputs are ignored"<<endl;
    cout << "HERE IS YOUR DECRYPTED MESSAGE : " << '\n' <<"==>"<< plain_text << endl;
}
void main_D9() {
    cout << "WELCOME TO THE RAIL-FENCE DECRYPTION METHOD" << endl;
    cout << "===========================================" << endl;
    cout<<"Please enter your message :" <<endl;
    string input ;
    getline(cin , input);//get the encrypted message
    string fixed_input = valid_Text(input); //filtering input text
    rail_fence_decryption(fixed_input);     //decrypt it
}


//menu functions
int Validmenu_Choice() {
    int Number;
    while(true) {
        string input1;
        getline(cin , input1);
        if (input1.find_first_not_of("0123456789") != string::npos) {  // Check if the input contains only digits.
            cout << "Invalid input. Please enter a valid number :" << endl;
            continue;   //This line causes the loop to skip the rest of the current iteration and start a new one if the input is invalid.
        }
        //check validation.
        try {
            Number = stoi(input1); // convert input to an integer
            if (Number < 1 || Number > 10) {
                cout << "Please enter a valid number : " << endl;
                continue;
            } else
            {
                break;  //This line sets the flag to false once a valid number is entered, terminating the loop.
            }
        }
        catch (const invalid_argument &e){ //to prevent error when the user click enter without write anything
            cout << "Invalid input. Please enter a valid number : " <<endl;
            cin.clear();    // Clear error flags
            continue;
        }
        catch (const out_of_range &e) {   //to prevent error when the user input a very big ranged number.
            cout << "Input out of range. Please enter a valid number within the range :" <<endl;
            cin.clear();
            continue;
        }
    }

    return Number;
}

//menu optipns.
void menu () { //it works until user exit.
    bool flag = true ;
    while (flag) {
        cout << "===========================================" << endl;
        cout << "WELCOME TO OUR CIPHER PROGRAM , OUR DEAR USER" << endl;
        cout << "What would you like to do ? " << '\n' << "(1)Encrypt a message" << '\n' << "(2)Decrypt a message"
             << '\n'
             << "(3)EXIT"<<endl;

        int choice = Validmenu_Choice();
        if (choice == 1) {
            cout << "WELCOME TO THE ENCRYPTION PROGRAM" << endl;
            cout << "=================================" << endl;
            cout << "Please choose the encryption method : " << '\n' << "(1)Affine Cipher " << '\n'<<"(2)Route Cipher"<<'\n'
                 <<"(3)Atbash Cipher"<<'\n'<<"(4)Vingere Cipher"<<'\n'<<"(5)Baconian Cipher"<<'\n'<<"(6)Simple substitution Cipher"<<'\n'<<"(7)Polybius-Square Cipher"<<'\n'<<"(8)Morse code Cipher"
                 << '\n' <<"(9)XOR Cipher"<<'\n'<< "(10)Rail-Fence Cipher"<<endl;
            int choice_encrypt = Validmenu_Choice();
            if (choice_encrypt == 1) {
                main_E0();
            }
            else if (choice_encrypt == 2) {
                route_cipher();
            }
            else if (choice_encrypt == 3) {
                menu_E1_();
            }
            else if (choice_encrypt == 4) {
                Vignere_Cipher();
            }
            else if (choice_encrypt == 5) {
                main_E4();
            }
            else if (choice_encrypt == 6) {
                main_E5();
            }
            else if (choice_encrypt == 7) {
                main_E6();
            }
            else if (choice_encrypt == 8) {
                Morse_cipher();
            }
            else if (choice_encrypt == 9) {
                main_E8();
            }
            else {
                main_E9();
            }

        }
        else if (choice == 2) {
            cout << "WELCOME TO THE DECRYPTION PROGRAM" << endl;
            cout << "=================================" << endl;
            cout << "Please choose the decryption method : " << '\n' << "(1)Affine Cipher " << '\n'<<"(2)Route Cipher"<<'\n'
                 <<"(3)Atbash Cipher"<<'\n'<<"(4)Vingere Cipher"<<'\n'<<"(5)Baconian Cipher"<<'\n'<<"(6)Simple substitution Cipher"<<'\n'<<"(7)Polybius-Square Cipher"<<'\n'<<"(8)Morse code Cipher"
                 << '\n' <<"(9)XOR Cipher"<<'\n'<< "(10)Rail-Fence Cipher"<<endl;
            int choice_decrypt = Validmenu_Choice();
            if ((choice_decrypt) == 1) {
                main_D0();
            }
            else if ((choice_decrypt) == 2) {
                route_decipher();
            }
            else if ((choice_decrypt) == 3){
                menu_D1_();
            }
            else if((choice_decrypt) == 4){
                Vignere_Decipher();
            }
            else if((choice_decrypt) == 5){
                main_D4();
            }
            else if ((choice_decrypt) == 6){
                main_D5();
            }
            else if((choice_decrypt) == 7){
                main_D6();
            }
            else if ((choice_decrypt) == 8){
                Morse_decipher();
            }
            else if((choice_decrypt) == 9){
                main_D8();
            }
            else {
                main_D9();
            }

        }
        else if (choice == 3){
            cout << "THE PROGRAM HAS ENDED"<<endl;
            flag = false;
        }
        else{
            cout<<"INVALID CHOICE"<<endl;
            menu();
        }
    }
}

int main() {
    menu();
}
#include"textEditor.h"

string txtName;
fstream myFile;

void openFile(){
    // Function to open a file
    cout<<"Please enter file name: ";
    getline(cin, txtName);
    txtName+=".txt";
    myFile.open(txtName);
    if (myFile.fail())   //Tests if a file exists
    {
        cout <<"Error: " << txtName << "doesn't exist!" << endl;
        openFile();
    }
    myFile.close();
    cout<<endl;
}

void newText(){
    string newText;  // declaring newText as a string and asking user to enter it
    cout << "Please enter the text you wish to add: ";
    getline (cin, newText);
    myFile.open(txtName, ios::app); //Open the file in append mode
    if(!myFile.fail()) //if it opens add to newText to the end of the file
    {
        myFile << newText;
    }
    else //if it fails to open, display error message
        cout << "Error couldn't open!" << endl;
    myFile.close();
}

void displayContent(){
    string line;
    myFile.open(txtName, ios::in);
    if(myFile.fail()){
        cout<<"Error: Couldn't open!";
    }
    else{
        while(getline(myFile, line)){
            cout<<line<<endl;
        }
    }
    myFile.close();
    cout << "\n\n";
}



void emptyFile(){
    myFile.open(txtName , ios :: out); //Open file in output mode
    if(myFile.fail()){  //if it fails to open, display error message
        cout<<"Error couldn't open!" << endl;
    }
    else{ //else print an empty string
    cout << "";
    }
    myFile.close();
}

void Encrypt(){
    string text, line;
    myFile.open(txtName, ios::in);
    if(myFile.fail()){
        cout<<"Error couldn't open!" << endl;   
    }
    else{
        while(getline(myFile, line)){
            text+= line + "\n";
        }
            for(int i = 0 ; i < text.size(); i++){
                text[i] = text[i]+1;
            }
        myFile.close();
        myFile.open(txtName, ios::out);
        for(int i = 0 ; i < text.size(); i++){
                myFile.put(text[i]);
            }
            myFile.put('\n');
        myFile.close();
    }
}

void Decrypt(){
    string text, line;
    myFile.open(txtName, ios::in);
    if(myFile.fail()){
        cout<<"Error couldn't open!" << endl;   
    }
    else{
        while(getline(myFile, line)){
            text+= line + "\n";
        }
            for(int i = 0 ; i < text.size(); i++){
                text[i] = text[i]-1;
            }
        myFile.close();
        myFile.open(txtName, ios::out);
        for(int i = 0 ; i < text.size(); i++){
                myFile.put(text[i]);
            }
            myFile.put('\n');
        myFile.close();
    }
}

int numWords(){
    int num;
    myFile.open(txtName, ios::in);
    string line;
    while(getline(myFile, line)){
        if(isalnum(line[0])){
            num++;
        }
        for(int i = 0; i < line.length()-1; i++)
        {
            if(isspace(line[i]) && isalnum(line[i+1])){
                num++;
            }
        }
    }
    myFile.close();
    return num;
}

int countWord(string word){
    int num;
    myFile.open(txtName, ios::in);
    string line, temp, orig;
    for(int i=0;i<word.length();i++){
        temp.push_back(tolower(word[i]));
    }
    orig = temp;
    while(getline(myFile, line)){
        for(int i=0; i<line.length()-word.length()+1; i++){
            temp="";
            if(isalpha(line[i]) && !isalpha(line[i-1]) && !isalpha(line[i+word.length()])){
                for(int j=i; j < word.length()+i;j++){
                    temp.push_back(tolower(line[j]));
                }
                if (temp == orig){
                    num++;
                }
            }
        }
    }
    myFile.close();
    return num;
}

void upCase(){
    myFile.open(txtName, ios::in);
    string line, content;

    while(getline(myFile, line)){
        content+=line;
        content.push_back('\n');
    }
    myFile.close();

    for(int i=0;i<content.length();i++){
        if(isalpha(content[i])){
            content[i]= toupper(content[i]);
        }
    }
    myFile.open(txtName, ios::out);
    for(int i=0;i<content.length();i++){
        myFile << content[i];
    }
    myFile.close();
}

void lowCase(){
    myFile.open(txtName, ios::in);
    string line, content;

    while(getline(myFile, line)){
        content+=line;
        content.push_back('\n');
    }
    myFile.close();

    for(int i=0;i<content.length();i++){
        if(isalpha(content[i])){
            content[i]= tolower(content[i]);
        }
    }
    myFile.open(txtName, ios::out);
    for(int i=0;i<content.length();i++){
        myFile << content[i];
    }
    myFile.close();
}

void firstCaps(){
    myFile.open(txtName, ios::in);
    string line, content;

    while(getline(myFile, line)){
        content+=line;
        content.push_back('\n');
    }
    myFile.close();

    for(int i=0;i<content.length();i++){
        if(isalpha(line[i]) && i==0){ 
            content[i]=toupper(content[i]);
        } else if(isalpha(content[i]) && !isalnum(content[i-1])){
            content[i]=toupper(content[i]);
        } else{
            content[i]=tolower(content[i]);
        }
    }
    myFile.open(txtName, ios::out);
    for(int i=0;i<content.length();i++){
        myFile << content[i];
    }
    myFile.close();
}

int numChars()
{
    string line;
    int count = 0;
    myFile.open(txtName, ios::in);   //Open file in input mode
    while (getline(myFile, line))     //get every line 
    {
        count += line.length();       // count increases by the length of every line
    }
    myFile.close();
    return count;
 }

int numLines()
{
    string line;
    int count = 0;
    myFile.open(txtName, ios::in);  //Open file in input mode
    while (getline(myFile, line))   //get every line 
    {
        count += 1;                 // count increases by the 1 every line
    }
    myFile.close();
    return count;
}

void mergeFiles()
{
    myFile.open(txtName);
    string file2;
    fstream myFile2;
    if (myFile.is_open())
    {
        cout<<"Please enter file 2 name: "; 
        getline(cin, file2);
        file2 += ".txt";
        cout<<endl;
        myFile2.open(file2, ios::in); // open a second txt file
        if(!myFile2.fail()) // if it opens 
        {
            ofstream myFile (txtName , ios :: app);  // open the first file in append mode 
            myFile<< myFile2.rdbuf();   // add the contents of the second file to the first file
            cout << "-Files merged successfully-"<<endl;
        }
        else  // if it doesn't open 
            cout << "ERROR: Couldn't open second file!";
    }
    else if (myFile.fail())  // if first file doesn't open 
    {
        cout << "ERROR: Couldn't open file!";
    }
    myFile.close();
    myFile2.close();
}

void findWord()
{
    // myFile.open(txtName, ios::in); // open in read mode
    // string line, word;
    string word;
    int res;
    cout << "Please enter a word to search for: ";  
    getline(cin,word); //enter a word to search
    res = countWord(word);
    if(res!=0){
        cout<<word<<" is Found!"<<endl;
    } else{
        cout<<word<<" is Not Found!"<<endl;
    }
}

void save(){
    string in, line, text, newFile;
    cout<<"1- Save in same file\n2- Save in different file\n==> ";
    getline(cin, in);
    while(in!="1" && in!="2"){
        cout<<"Please enter 1 or 2,\n";
        save();
    }
    if(in=="1"){
        myFile.close();
    }else{
        line="", text="";
        myFile.open(txtName, ios::in);
        while(!myFile.eof()){
            getline(myFile, line);
            text+=line;
        }
        myFile.close();
        cout<<"Enter name of new file: ";
        getline(cin, newFile);
        newFile+=".txt";
        myFile.open(newFile,ios::out);
        myFile<<text;
        myFile.close();
    }
}
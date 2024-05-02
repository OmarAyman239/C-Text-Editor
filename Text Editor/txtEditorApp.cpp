// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: txtEditorApp.cpp
// Last modification Date: 16/05/2022
// Author1 and ID and Group: Omar Ayman - 20210262 - S16
// Author2 and ID and Group: Amr Fayez - 20210278 - S16
// Author3 and ID and Group: Ahmed Khaled - 20210016 - S16
// Teaching Assistant: Nesma Mohamed - Yousra Ayman
// Purpose: Text Editor with multioption menu
#include "textEditor.h"
#include "txtEditorFunc.cpp"

int main(){
    string choice;
    cout<<"\nWelcome to our Text Editor App\n"<<endl;
    openFile();
    while (choice != "16")
    {
        cout<<"Choose an option from 1 to 16"<<endl;
        cout<<"1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content\n5. Decrypt the file content\n";
        cout<<"6. Merge another file\n7. Count the number of words in the file\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n10. Search for a word in the file\n";
        cout<<"11. Count the number of times a word exists in the file\n12. Turn the file content to upper case\n13. Turn the file content to lower case\n14. Turn file content to 1st caps (1st char of each word is capital)\n15. Save\n";
        cout<<"16. Exit\n";
        cout<<"Please enter your choice => ";
        getline(cin, choice);
        if(choice=="16"){
            cout<<"Goodbye!"<<endl;
            break;
        } else if(choice=="1"){
            newText();   
        } else if(choice=="2"){
            displayContent();
        } else if(choice=="3"){
            emptyFile();
        } else if(choice=="4"){
            Encrypt();
        } else if(choice=="5"){
            Decrypt();
        } else if(choice=="6"){
            mergeFiles();
        } else if(choice=="7"){
            cout<<"Number of words is "<<numWords()<<endl;
        } else if(choice=="8"){
            cout << "Number of characters in file is: " << numChars() << endl;
        } else if(choice=="9"){
            cout << "Number of lines in file is: " << numLines() << endl;
        } else if(choice=="10"){
            findWord();
        } else if(choice=="11"){
            string word;
            cout<<"Enter word to count: ";
            getline(cin, word);
            cout<<"Count of "<<word<<" is "<<countWord(word)<<endl;
        } else if(choice=="12"){
            upCase();
        } else if(choice=="13"){
            lowCase();
        } else if(choice=="14"){
            firstCaps();
        } else if(choice=="15"){
            save();
        } else{
            cout<<"---Wrong input!---"<<endl;
        }
    }
}
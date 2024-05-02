#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include<iostream>
#include<fstream>
#include<cctype>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// string word, line;
void openFile();
void newText();
void displayContent();
void emptyFile();
void Encrypt();
void Decrypt();
int numWords();
int countWord(string word);
void upCase();
void lowCase();
void firstCaps();
void mergeFiles();
int numChars();
int numLines();
void findWord();
void save();

#endif
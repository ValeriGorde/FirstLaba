#pragma once

bool ExistFile(string path);
bool FileCorrectChecking(string path);
bool FileNotEmpty(string path);
int OpenFromFile();
void SaveInFile(int result);
void SaveInitialInFile(string& text, string& str);
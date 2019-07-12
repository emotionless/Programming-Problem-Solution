#include <iostream>
#include <fstream>
#include <windows.h>
#include<vector>
using namespace std;

void lockfolder();
void unlockfolder();
void setcolour(unsigned int colour);
void show_locked();

vector<string> Lines;

int main()
{
    unsigned int choice=0;
    SetConsoleTitle("Folder Lock");
    system("CLS");
    setcolour(10);
    cout << "\t\t\t\t" << "  Folder Lock\n";
    cout << "\t\t\t\t" << "-----------------\n";
    setcolour(15);

    setcolour(30);
    while(true){
    cout << "\n\n" << "Options:\t\t\t\n";
    cout << "\t======================\n";
    cout << "\t1. - Hide Folder.\n";
    cout << "\t2. - Unhide Folder.\n";
    cout << "\t3. - Show Hidden Folders.\n";
    cout << "\t4. - Exit.\n";
    cout << "\t======================  \n";
    setcolour(128);
    cout << "\nEnter your choice: ";
    cin >> choice;
    getchar();
    switch (choice)
    {
    case 1:
        lockfolder();
        break;
    case 2:
        unlockfolder();
        break;
    case 3:
        show_locked();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "\nError. Unknown Option Entered. Quitting ....\n";
        exit(0);
        break;
    }
    }

    return 0;
}
void setcolour(unsigned int colour)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, colour);
}

void lockfolder()
{
    //char pass[15]="";
    ofstream lfolder;
    char path[100]={0};
    char tempfolder[200]= {'0'};
    char attributes[50]= {'0'};
    setcolour(13);

    cout << "\nEnter the complete path to the Folder: ";
    gets(path);
    ofstream OutFile;
    OutFile.open("FolderList.srpe",ios::app);
    OutFile << path << endl;
    OutFile.close();

    strcpy(tempfolder, path);
    strcat(path, "\\Desktop.ini");
    lfolder.open(path, ios::out);
    lfolder << "[.shellClassInfo]" << endl;
    lfolder << "CLSID = {63E23168-BFF7-4E87-A246-EF024425E4EC}" << endl;
    lfolder.close();

    strcpy(attributes, "attrib +h +s ");
    strcat(attributes, "\"");
    strcat(attributes, tempfolder);
    strcat(attributes, "\"");

    WinExec(attributes, NULL);

//    lfolder.open("C:\\windows\\db.dat", ios::app);
//    lfolder << "Folder Locked: " << tempfolder << endl;
//    lfolder.close();
    cout << "\n\n" << tempfolder << " has been locked successfully!\n";
}


void show_locked()
{
    ifstream inFile;
    inFile.open("FolderList.srpe");
    string line;
    while(getline(inFile,line))
    {
        cout << line << endl;
    }
    inFile.close();
}

void unlockfolder()
{
    char folder[255];
    char tempfolder[255];
    char attributes[50];
    char del[50];
    ofstream lfolder;

    setcolour(14);

    cout << "\nEnter the complete path to the Folder: ";
    gets(folder);
    Lines.clear();
    ifstream inFile;
    inFile.open("FolderList.srpe");
    string line;
    while(getline(inFile,line))
    {
        if(line.size() > 0 && line!=folder){
                Lines.push_back(line);
//                cout<<line<<endl;
        }
    }
    inFile.close();

    ofstream outFile;
    outFile.open("FolderList.srpe",ios::trunc);
    for(int i=0; i<Lines.size();i++)
    {
        outFile << Lines[i] << endl;
    }
    outFile.close();
    strcpy(tempfolder, folder);
    strcat(folder, "\\Desktop.ini");
    strcpy(del, "del ");
    strcat(del, folder);

    strcpy(attributes, "attrib -h -s ");
    strcat(attributes, "\"");
    strcat(attributes, tempfolder);
    strcat(attributes, "\"");

    WinExec(attributes, NULL);

//    lfolder.open("C:\\windows\\db.dat", ios::app);
//    lfolder << "! Folder Unlocked: " << tempfolder << endl;
//    lfolder.close();

    cout << "\n\n" << tempfolder << " has been unlocked successfully!\n";
}

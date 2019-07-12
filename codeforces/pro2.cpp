#include <iostream>
#include <fstream>
#include <windows.h>
#include<vector>
#include<conio.h>
using namespace std;

void lockfolder();
void unlockfolder();
void setcolour(unsigned int colour);
void show_locked();
bool get_path_to_unhide();
//bool get_path_to_hide();
string inputpass();
string get_pass();
void change_password();

char folder[2000];
char tempfolder[2000];
char attributes[2000];
char del[2000];
char path[2000];
char ispath[2000];
vector<string> Lines;
string password;

int main()
{
    SetConsoleTitle("Folder Hide");
    password=get_pass();
    if(password!="")

    {
        system("color 1e");
        setcolour(11);
        cout << "\t\t\t\t" << "  Folder Hide\t\t\t\t       \n";
        cout << "\t\t\t\t" << "===============\t\t\t\t\t\n";
        string pass;
        while(true)
        {
            setcolour(11);
            cout << "Enter password: ";
            pass=inputpass();
            if(pass==password)
                break;
            setcolour(7);
            cout << "\n\nPassword incorrect. Default password is blank. Try again.\n\n";
            pass = "";
        }
    }
    while(true)
    {
        system("CLS");
        system("color 1e");
        unsigned int choice=0;
        setcolour(11);
        cout << "\t\t\t\t" << "  Folder Hide\t\t\t\t       \n";
        cout << "\t\t\t\t" << "===============\t\t\t\t\t\n";
        setcolour(7);

        cout <<"\n\n"<<"Options:\n";             //C:\Users\Sabera\Desktop\new folder
        cout <<"======================================\n";
        setcolour(27);
        cout << "\t1. - Hide Folder.\n";
        cout << "\t2. - Unhide Folder.\n";
        cout << "\t3. - Change password.\n";
        cout << "\t4. - Exit.\n";
        setcolour(7);
        cout <<"======================================\n";
        setcolour(7);
        cout << "\n\nEnter your choice: ";
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
            change_password();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\nError. Unknown Option\n";
            break;
        }
        setcolour(7);
        cout<< "\n\nPress Any Key to Continue or press 4 to Exit";
        char  ch = _getch();
        if(ch=='4')
            exit(0);
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
    system("CLS");
    system("color 1e");
    setcolour(11);
    cout << "\t\t\t\t" << "  Folder Hide\t\t\t\t       \n";
    cout << "\t\t\t\t" << "===============\t\t\t\t\t\n";
    ofstream lfolder;
    setcolour(11);
    cout << "\nEnter the complete path to the Folder:\n\n";
    setcolour(15);
    gets(path);
    strcpy(ispath,"type ");
    strcat(ispath,"\"");
    strcat(ispath,path);
    strcat(ispath,"\"");
    if(WinExec(ispath,NULL)==NULL);
    else
    {
        ofstream OutFile;
        OutFile.open("FolderList.srpe",ios::app);
        OutFile << path << endl;
        OutFile.close();

        strcpy(tempfolder, path);
        strcat(path, "\\Desktop.ini");
        lfolder.open(path, ios::out);
        lfolder << "[.shellClassInfo]" << endl;
        lfolder << "CLSID2 = {63E23168-BFF7-4E87-A246-EF024425E4EC}" << endl;
        lfolder.close();

        strcpy(attributes, "attrib +h +s ");
        strcat(attributes, "\"");
        strcat(attributes, tempfolder);
        strcat(attributes, "\"");

        WinExec(attributes, NULL);
        setcolour(7);
        cout << "\nYour folder has been locked successfully!\n";
    }
}
void show_locked()
{
    ifstream inFile;
    inFile.open("FolderList.srpe");
    string line;
    setcolour(7);
    cout<<"\nYour Hidden Folders Are:\n\n";
    setcolour(11);
    while(getline(inFile,line))
    {
        cout << line << endl;
    }
    inFile.close();
}

void unlockfolder()
{
    system("CLS");
    system("color 1e");
    setcolour(11);
    cout << "\t\t\t\t" << "  Folder Hide\t\t\t\t       \n";
    cout << "\t\t\t\t" << "===============\t\t\t\t\t\n";
    ofstream lfolder;
    show_locked();
    setcolour(15);
    cout << "\nEnter the complete path to the Folder you want to unhide:\n\n";
    bool got=get_path_to_unhide();
    while(got!=1)
    {
        setcolour(7);
        cout<<"\nWrong path! Enter correct path\n\n";
        got=get_path_to_unhide();
    }

    ofstream outFile;
    outFile.open("FolderList.srpe",ios::trunc);
    for(int i=0; i<Lines.size(); i++)
    {
        outFile << Lines[i] << endl;
    }
    outFile.close();
    strcpy(tempfolder, folder);
    strcat(folder, "\\Desktop.ini");
    strcpy(del, "del ");
    strcat(del,"\"");
    strcat(del, folder);
    strcat(del,"\"");
    system(del);

    strcpy(attributes, "attrib -h -s ");
    strcat(attributes, "\"");
    strcat(attributes, tempfolder);
    strcat(attributes, "\"");

    WinExec(attributes, NULL);

    setcolour(7);
    cout << "\nYour folder has been unlocked successfully!\n";
}
bool get_path_to_unhide()
{
    setcolour(11);
    bool got=0;
    gets(folder);
    Lines.clear();
    ifstream inFile;
    inFile.open("FolderList.srpe");
    string line;
    while(getline(inFile,line))
    {
        if(line.size() > 0 && line!=folder)
        {
            Lines.push_back(line);
        }
        if(line==folder)
            got=1;
    }
    inFile.close();
    return got;
}
string get_pass()
{
    ifstream inFile;
    inFile.open("SystemFile.pass",ios::in|ios::out);
    string pass;
    getline(inFile, pass);
    inFile.close();
    return pass;
}
void change_password()
{
    system("CLS");
    system("color 1e");
    setcolour(11);
    cout << "\t\t\t\t" << "  Folder Hide\t\t\t\t       \n";
    cout << "\t\t\t\t" << "===============\t\t\t\t\t\n";
    string pass;
    while(true)
    {
        setcolour(11);
        cout<<"\nEnter old password: ";
        pass=inputpass();
        if(pass == password) break;
        else
        {
            setcolour(7);
            cout << "\n\nPasswords don't match. Try again.\n";
        }
        pass = "";
    }
    pass = "";
    string pass1;
    setcolour(11);
    cout << "\n\nEnter new password: ";
    pass1=inputpass();
    password = pass1;
    ofstream outFile;
    outFile.open("SystemFile.pass",ios::trunc);
    outFile << password;
    outFile.close();
    setcolour(7);
    cout << "\n\nPassword changed successfully.\n";
    pass1="";
}
string inputpass()
{
    string pass;
    char ch = _getch();
    while(ch!=13)
    {
        if(ch==8)
        {
            if(pass.length()!=0)
            {
                cout <<"\b \b";
                pass.resize(pass.length()-1);
            }
        }
        else if(ch==0 || ch==224) // handle escape sequences
        {
            getch(); // ignore non printable chars
            continue;
        }
        else
        {
            pass+=ch*2+5;
            cout <<'*';
        }
        ch=_getch();
    }
    return pass;
}

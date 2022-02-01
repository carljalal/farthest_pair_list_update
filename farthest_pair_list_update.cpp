// directories
// storages
// organization of words and id's

#include "iostream"
#include "Windows.h"
#include "vector"
#include "conio.h"
#include "string"
#include "fstream"
#include "easy_utility_functions.h"
using namespace std;

// read file or text
// vectorize
// have id's
// parsing by line, by delimiter, into arrays
// doing the right thing

// interactive loop with instructions/directions
// automatic (optional) process

// get interrupt key (optional)
// ask for input

// save results


// recursion rooms in rooms, partitions in partitions
// peaceful and kindness and understanding interactions
// honest and kindness and understanding feedback interaction communications
// togetherness
// friendliness

// line by line
// following instructions
// permuting, finding all pairs or permutations of a list
// submodules
// importance of wording feedback accuracy precision intention

// one by one
// inputs
// start1, start2, stop1, stop2
// arrive, leave
// clear, add, send request, open response
// open, add, clear, close

// get, give, position
// middle? check? equals? switch cases

// give, get, put, position

// which
// sources
// destinations

// ?!
// 00-99

// one feature at a time

// list of features
// lines one-by-one
// joy of testing one-by-one building
// togetherness



//display load file name instruction
//display save file name instruction
//display appendload file name instruction

// gradual building on top of
// experiences, memories, love, givings

// sources
// storages
// processing areas

// interactions, instructions (interrupt, prompt)

// code exploration

// high level

// 1 add
// 2 clear
// 3 save
// 4 load
// 5 process
// 6 interrupt

// wisdom
// learning
// noticing
// peace
// precision
// focus
// accuracy
// attention
// empathy
// responsive
// wholistic
// cheer up
// joy together

// string manipulations

// patterned transformation


string getfilename();
int current_word_index = 0;


char process(vector<string> arrayofwords) {
    if (arrayofwords.size() == 0) {
        cout << "no words in array!\n";
        return -1;
    }
    while (1) {
        if (_kbhit()) {
            char c = _getch();
            return c;
        }
        if (current_word_index >= arrayofwords.size()) current_word_index = 0;
        cout << arrayofwords[current_word_index] << "\n";
        Sleep(1000);
        current_word_index++;
        system("cls");
        
    }
}

int main()
{
    vector<string> arrayofwords;
    while (1) {
        cout << "enter cmd: ";
        string cmd;
        getline(cin, cmd);
        if (cmd == ". add") {
            cout << "enter word: ";
            string word;
            getline(cin, word);
            arrayofwords.push_back(word);
            cout << word << " added\n";
        }
        else if (cmd == ". clear") {
            arrayofwords.clear();
            cout << "words cleared\n";
        }
        else if (cmd == ". save") {
            cout << "enter save filepath: ";
            string filepath_save;
            filepath_save = getfilename();
            //getline(cin, filepath_save);
            ofstream f_save(filepath_save);
            for (int i = 0; i < arrayofwords.size(); i++) {
                f_save << arrayofwords[i] << "\n";
            }
            f_save.close();
            cout << arrayofwords.size() << " words saved to file " << filepath_save << "\n";
        }
        else if (cmd == ". load") {
            cout << "enter load filepath: ";
            string filepath_load;
            filepath_load = getfilename();
            //getline(cin, filepath_load);
            ifstream f_read(filepath_load);

            int f_read_count = 0;
            while (f_read) {
                string getword;
                getline(f_read, getword);
                if (getword == "") break;
                arrayofwords.push_back(getword);
                f_read_count++;
            }
            cout << f_read_count << " words read from file " << filepath_load << "\n";

        }
        else if (cmd == ". process") {
            process(arrayofwords);
        }
        else if (cmd == ". cheer up") {
            cout << "remember joy together\n";
        }
        else {
            cout << "invalid command\n";
        }
        
    }
}


string getfilename() // select file dialog box and returns file path as string
{
    char filename[MAX_PATH];

    OPENFILENAME ofn;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
    ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrTitle = "Select a File, yo!";
    ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn))
    {
        return filename;
    }
    else
    {
        // All this stuff below is to tell you exactly how you messed up above. 
        // Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
        switch (CommDlgExtendedError())
        {
        case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
        case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
        case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
        case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
        case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
        case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
        case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
        case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
        case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
        case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
        case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
        case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
        case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
        case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
        case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
        default: std::cout << "You cancelled.\n";
        }
    }
}
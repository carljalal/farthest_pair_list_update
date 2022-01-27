// directories
// storages
// organization of words and id's

#include "iostream"
#include "Windows.h"
#include "vector"
#include "conio.h"
#include "string"
#include "fstream"
using namespace std;

// read file or text
// vectorize
// have id's
// parsing by line, by delimiter, into arrays


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
        if (cmd == ". clear") {
            arrayofwords.clear();
            cout << "words cleared\n";
        }
        if (cmd == ". save") {
            cout << "enter save filepath: ";
            string filepath_save;
            getline(cin, filepath_save);
            ofstream f_save(filepath_save);
            for (int i = 0; i < arrayofwords.size(); i++) {
                f_save << arrayofwords[i] << "\n";
            }
            f_save.close();
            cout << arrayofwords.size() << " words saved to file " << filepath_save << "\n";
        }
        if (cmd == ". load") {
            cout << "enter load filepath: ";
            string filepath_load;
            getline(cin, filepath_load);
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
        if (cmd == ". process") {
            process(arrayofwords);
        }
        if (cmd == ". cheer up") {
            cout << "remember joy together\n";
        }
        
    }
}



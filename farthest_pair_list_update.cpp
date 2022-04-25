// directories
// storages
// organization of words and id's

#include "iostream"
#include "Windows.h"
#include "vector"
#include "conio.h"
#include "string"
#include "fstream"
#include "../cpp_code_snippets/easy_utility_functions.h"
#include <sstream>
#include "algorithm"
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
// waiting for something

// high level

// learning how to write
// reading how to write

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

// hugs
// great healing


int current_word_index = 0;
int speed = 1000;

char process(vector<string> &arrayofwords) {
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
        Sleep(speed);
        current_word_index++;
        system("cls");
        
    }
}

INT64 count_file_lines(string filename) {
    INT64 count = 0;
    INT64 textcount = 0;
    ifstream ifile(filename);

    

    string s;
    while (ifile) {
        getline(ifile, s);
        count++;
        //textcount += s.size();
        if (count % 1000 == 0) {
            cout << "count: " << count << '\n'; //", text size: " << textcount << "\n";
            
        }
    }
    ifile.close();

    cout << "there are " << count << " lines in this file!\n";
    return count;
}

void save_file(vector<string>& arrayofwords, string filepath_save) {
    ofstream f_save(filepath_save);
    for (int i = 0; i < arrayofwords.size(); i++) {
        f_save << arrayofwords[i] << "\n";
    }
    f_save.close();
    cout << arrayofwords.size() << " words saved to file " << filepath_save << "\n";
}

void find_word_in_file(string fs) {
    INT64 count = 0;
    INT64 wordfound = 0;
    ifstream ifile(getfilename());



    string s;
    while (ifile) {
        getline(ifile, s, ' ');
        if(fs == s) 
            wordfound++;
        count++;
        if (count % 1000 == 0) {
            cout << "count: " << count << ", text size: " << wordfound << "\n";
        }
    }
    ifile.close();

    cout << "there are " << wordfound << " lines in this file!\n";
    return;
}
// peace, patience
void find_word_in_vector(int width, string s, vector<string> &sv) {
    if (sv.size() <= 0) return;
    INT64 count = 0;
    vector<string> temp_vector;
    for (INT64 i = 0; i < sv.size(); i++) {
        if (s == sv[i]) {
            //count++;
            temp_vector.push_back(s);
            if (width < 0) {
                for (int j = width; j < 0 && i+j >=0 && i+j <sv.size(); j++) {
                    temp_vector.back() += " " + sv[i + j];
                }
            }
            if (width > 0) {
                for (int j = 1; j < width && i + j >= 0 && i + j < sv.size(); j++) {
                    temp_vector.back() += " " + sv[i + j];
                }
            }
            //cout << '\n';
        }
    }
    sort(temp_vector.begin(), temp_vector.end());
    vector<string> temp_vector2;
    vector<int> temp_vector2_count;
    count = 1;
    INT64 count_unique = 0;
    for (INT64 i = 1; i < temp_vector.size(); i++) {
        if (temp_vector[i] != temp_vector[i - 1]) {
            //cout << temp_vector[i - 1] << " " << count << "\n";
            temp_vector2.push_back(temp_vector[i - 1]);
            temp_vector2_count.push_back(count);
            count = 0;
            count_unique++;
        }
        count++;
    }
    count_unique++;
    cout << temp_vector.back() << " " << count << "\n";
    cout << count_unique << " unique phrases found!\n";
    temp_vector2.push_back(temp_vector.back());
    temp_vector2_count.push_back(count);
    string filename = s + to_string(width) + ".txt";

    vector<string> temp_vector3;
    for (INT64 i = 0; i < temp_vector2.size(); i++) {
        temp_vector3.push_back(to_string(temp_vector2_count[i]) + "," + temp_vector2[i]);
    }

    save_file(temp_vector3, filename);
    system(filename.c_str());
    //cout << "we found " << s << " " << count << " times!\n";
}

void parse_string_into_vector_by_delimiter(string s, char c, vector<string> &sv) {
    stringstream ss(s);
    while (ss) {
        string new_s;
        getline(ss, new_s, c);
        if (new_s != "") {
            sv.push_back(new_s);
        }
    }
}

void parse_file_into_vector_by_delimiter(char delimiter, vector<string> &sv) {
    ifstream ifile(getfilename());
    INT64 count = 0;
    while (ifile) {
        count++;
        string s;
        getline(ifile, s, '\n');
        if (s != "") {
            parse_string_into_vector_by_delimiter(s, delimiter, sv);
            
        }
        if (count % 1000 == 0) {
            //sv.shrink_to_fit();
            cout << count << "\n";
        }
    }
    ifile.close();
}

void split_file() {
    string str_splits = prompt_cin_input("enter number of splits: ");
    int splits = stoi(str_splits);
    string ifilename = getfilename();
    INT64 filelines = count_file_lines(ifilename);
    ifstream ifile(ifilename);

    INT64 interval = filelines / splits;
    for (int split = 1; split <= splits; split++) {
        ofstream ofile(ifilename + to_string(split));
        if (split == splits) {
            while (ifile)
            {
                string s;
                getline(ifile, s);
                if (s != "") {
                    ofile << s << '\n';
                }
            }
        }
        else {
            for (INT64 i = 0; i < interval; i++) {
                string s;
                getline(ifile, s);
                ofile << s << '\n';
            }
        }
    }
}

void list_help() {
    cout << ". split file\n";
    cout << ". file to vector\n";
    cout << ". find word in vector \n";
    cout << ". countlines\n";
    cout << ". add\n";
    cout << ". clear\n";
    cout << ". save\n";
    cout << ". load file\n";
    cout << ". load html\n";
    cout << ". process\n";
    cout << ". cheer up\n";
    cout << ". help\n";
}




int main()
{





    //getchar();
    list_help();
    vector<string> arrayofwords;
    while (1) {
        cout << "enter cmd: ";
        string cmd;
        getline(cin, cmd);
        if (cmd == ". split file") {
            split_file();
        }
        if (cmd == ". help") {
            list_help();
        }
        else if (cmd == ". file to vector") {
            string delimiter;
            cout << "enter delimiter: ";
            getline(cin, delimiter);
            parse_file_into_vector_by_delimiter(delimiter[0], arrayofwords);
        }
        else if (cmd.substr(0, 22) == ". find word in vector ") {
            {
                int length_of_beginning_of_command = 22;
                int move_for_next_word = 1;
                char space_between_words = ' ';
                int position_after_second_space = cmd.find(space_between_words, length_of_beginning_of_command) + move_for_next_word;
                string w = cmd.substr(position_after_second_space);
                int position_of_second_space = cmd.find(space_between_words, length_of_beginning_of_command);
                int width = stoi(cmd.substr(length_of_beginning_of_command, position_of_second_space));
                //getline(cin, w);
                find_word_in_vector(width, w, arrayofwords);
            }
        }
        else if (cmd.substr(0, 8) == ". speed ") {
            {
                int length_of_beginning_of_command = 8;
                int start_of_command = 0;
                speed = stoi(cmd.substr(length_of_beginning_of_command));
            }
        }
        else if (cmd == ". countlines") {
            string filepath = getfilename();
            count_file_lines(filepath);
        }
        else if (cmd == ". add") {
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
            save_file(arrayofwords, filepath_save);
        }
        else if (cmd == ". load file") {
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
        else if (cmd == ". load html") {
            cout << "enter url: ";
            string url;
            getline(cin, url);
            string ret = gethtml(url);
            vector<string> list;
            tokenize_string(list, ret);
            append_vector(arrayofwords, list);
            cout << "\n"<< list.size() <<" words from webpage have been added!\n";
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

// memory word pool
// hope of doing good work
// body
// sustained slow focused meditations
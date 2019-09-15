// A brainfuck interpreter in C++
/*
    Tryna make this a skeleton for writing one in assembly
    Then, when it's good in assembly, I can make a compiler, maybe. Or
    a pseudo-compiler and manually write out an asm file w/ python or 
    whatevs and compile it like in shellforge.

*/

#include <iostream>
#include <fstream>

char* tape;
int count;

using namespace std;



class Interpreter {
    public:
        char memory[30000]; //change this if you want different tape size
        char *dp; // data pointer register
        const char *ip; //instruction pointer register

    Interpreter(const char bf[]){
        dp = memory;
        ip = bf;        
    }

    void inc_dp(){
        ++dp;
    }

    void inc_tape(){
        ++(*dp);
    }

    void dec_dp(){
        --dp;
    }

    void dec_tape(){
        --(*dp);
    }

    void output_STD(){
        cout << *dp;
    }

    void input_STD(){
        cin >> *dp;
    }


    void start_brace(){
        if(*dp==0){
            count = 1;
            while(count>0){
                ip++;
                if(*ip == '['){
                    count++;
                } else if (*ip == ']'){
                    count--;
                }
            }
        }
        
    }

    void end_brace(){
        if(*dp != 0){
            count = 1;
            while(count>0){
                ip--;
                if(*ip == '['){
                    count--;
                } else if (*ip == ']'){
                    count++;
                }
            }
        }
    }
    

    bool interpret(){
        while(*ip){
            switch(*ip){
                case '>': inc_dp(); break;
                case '<': dec_dp(); break;
                case '+': inc_tape(); break;
                case '-': dec_tape(); break;
                case '.': output_STD(); break;
                case ',': input_STD(); break;
                case '[': start_brace(); break;
                case ']': end_brace(); break;
            }
            ip++;
        }
        return true;
    }


};

void usage(){
    cout << "Brainfuck interpreter." << endl;
    cout << "Basic for now, soon to have networking" << endl;
    cout << "usage: $ ./bfnet [filename]" << endl;
}

int main(int argc, char *argv[]){

    if(argc != 2){
        usage();
        return 0;
    }
    //file is argv[1]
    std::ifstream t;
    int length;
    t.open(argv[1]);
    t.seekg(0,std::ios::end);
    length = t.tellg();
    t.seekg(0, std::ios::beg);
    tape = new char[length];
    t.read(tape,length);
    t.close();
/* this confirms we can iterate through all data passed via tape[]
    for(int i = 0; i < length; i++)
        cout << tape[i];
*/    
    Interpreter interpreter = Interpreter(tape);
    interpreter.interpret();

    return 0;
}

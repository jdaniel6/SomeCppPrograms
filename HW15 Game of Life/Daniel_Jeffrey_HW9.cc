#include <iostream>
#include <fstream>
#include <cmath>

//Exception handling
class Exception{
    private:
        std::string name;
        std::string file;
        uint16_t line;
    public:    
        Exception(std::string name, std::string file, uint16_t line) : name(name), file(file), line(line) {}
        friend std::ostream& operator<<(std::ostream &os, Exception e){
            return os << e.name << " occurred at line " << e.line << " in " << e.file << " at " << __TIME__ << ".\n";
        }
};


class Life{
    private:
        uint8_t* board;
        uint64_t rows;
        uint64_t cols;
    public:
        Life();
        Life(uint64_t num_of_rows, uint64_t num_of_cols);
        Life(Life &old);
        Life(Life &&old);
        Life operator=(Life orig);
        void read(std::string file_name);
        void read(uint8_t* board);
        void get_next_gen();
        void get_gen(uint64_t generation_number);
        void print();
        friend std::ostream& operator<<(std::ostream &os, const Life &life);
};


int main(){
    Life new_life;
    new_life.read("mylife.txt");
    new_life.print();
    for(uint8_t i = 0; i < 10; i++){
        //new_life.print();
        //new_life.get_next_gen();
    }
    //Life life2 = new_life;
    //life2 = new_life;
}
#if 0
int main(){
    try{
        uint8_t* trialboard;
        Life new_life;
        new_life.read(trialboard);
    }
    catch(const Exception &e){
        std::cout << e;
    }
    
}
#endif





//default constructors
Life::Life(){
    board = new uint8_t[0];
    rows = 0;
    cols = 0;
}

Life::Life(uint64_t num_of_rows, uint64_t num_of_cols){
    board = new uint8_t[num_of_rows * num_of_cols];
    rows = num_of_rows;
    cols = num_of_cols;
}

//copy constructor
Life::Life(Life &old) : rows(old.rows), cols(old.cols) {
    this->board = new uint8_t[rows * cols];
    for(uint64_t i = 0; i < rows*cols; i++){
        board[i] = old.board[i];
    }
}

//move constructor
Life::Life(Life &&old) : rows(old.rows), cols(old.cols) {
    old.board = nullptr;
}

//= operator overloading
Life Life::operator=(Life orig){
    this->rows = orig.rows;
    this->cols = orig.cols;
    std::swap(this->board, orig.board);
    return *this;
}

//read a board from a file
void Life::read(std::string file_name){
    std::ifstream is(file_name);
    uint16_t element;
    is >> rows >> cols;
    board = new uint8_t[rows * cols];
    uint64_t pos = 0;
    while(is >> element){        
        board[pos] = element;
        pos++;
    }
}

//read a board from raw data
void Life::read(uint8_t* board){
    //to be implemented
}

//get next generation of the current board
void Life::get_next_gen(){

}

//get a certain generation of the current board
void Life::get_gen(uint64_t generation_number){

}

//print out the board
void Life::print(){
    for(uint64_t i = 0; i < rows; i++){
        for(uint64_t j = 0; j < cols; j++){
            std::cout << (uint16_t)board[i * cols + j] << "\t";
        }
        std::cout << "\n";
    }
}


//change to uint16_t
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "bitmap.hh"


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

Exception InvalidDataException("Read Invalid Data", __FILE__, __LINE__);

class Life{
    private:
        uint16_t* board;
        uint64_t rows;
        uint64_t cols;
    private:
        uint64_t get_count_live_cells(uint64_t row, uint64_t col, uint64_t current_position);
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
        void draw(std::string filename);
        friend std::ostream& operator<<(std::ostream &os, const Life &life);
};


int main(){
    Life new_life;
    new_life.read("mylife.txt");
    for(uint8_t i = 0; i < 11; i++){
        new_life.print();
        std::string filename = "stages/stage" + std::to_string(i) + ".png";
        new_life.draw(filename);
        new_life.get_next_gen();
    }
    //Life life2 = new_life;
    //life2 = new_life;
    Life glider;
    glider.read("glider.txt");
    for(uint8_t i = 0; i < 11; i++){
        std::cout << std::to_string(i);
        glider.print();
        std::string filename = "stages_glider/stage" + std::to_string(i) + ".png";
        glider.draw(filename);
        glider.get_next_gen();
    }
    
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
    board = new uint16_t[0];
    rows = 0;
    cols = 0;
}

Life::Life(uint64_t num_of_rows, uint64_t num_of_cols){
    board = new uint16_t[num_of_rows * num_of_cols];
    rows = num_of_rows;
    cols = num_of_cols;
}

//copy constructor
Life::Life(Life &old) : rows(old.rows), cols(old.cols) {
    this->board = new uint16_t[rows * cols];
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
    board = new uint16_t[rows * cols];
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

//get number of live cells around a particular cell
uint64_t Life::get_count_live_cells(uint64_t row, uint64_t col, uint64_t current_position){
    if(row == 0){
        if(col == 0){   //first element in the first row, has only 3 neighbours
            return (board[1] + board[cols] + board[cols+1]);
        }
        else{
            if(col == (cols-1)){    //last element in first row has only 3 neighbours
                return (board[cols-2] + board[2*cols - 2] + board[2*cols - 1]);
            }
            else{   //all other elements in first row have 5 neighbours
                return (board[current_position - 1] + board[current_position + cols - 1] + board[current_position + cols] + board[current_position + cols + 1] + board[current_position + 1]);
            }
        }
    }
    else{
        if(row == (rows-1)){
            if(col == 0){   //first element in the last row, only has 3 neighbours
                return(board[(rows-1)*cols + 1] + board[(rows-2)*cols] + board[(rows-2)*cols + 1]);
            }
            else{
                if(col == (cols-1)){    //last element in last row has only 3 neighbours
                    return(board[rows*cols - 2] + board[(rows-1)*cols - 1] + board[(rows-1)*cols - 2]);
                }
                else{   //all other elements in last row have 5 neighbours
                    return (board[current_position - 1] + board[current_position - cols - 1] + board[current_position - cols] + board[current_position - cols + 1] + board[current_position + 1]);
                }
            }
        }
        else{
            if((col%cols) == 0){    //first column has 5 neighbours (top and bottom have already been taken care of)
                return(board[current_position - cols] + board[current_position - cols + 1] + board[current_position + 1] + board[current_position + cols] + board[current_position + cols + 1]);
            }
            else{
                if((col%cols) == (cols-1)){ //last column has 5 neighbours (top and bottom have already been taken care of)
                    return(board[current_position - cols] + board[current_position - cols - 1] + board[current_position - 1] + board[current_position + cols - 1] + board[current_position + cols]);
                }
                else{   //all edgecases have been dealt with; all other cells have 8 neighbours
                    return(board[current_position - cols - 1] + board[current_position - cols] + board[current_position - cols + 1] + board[current_position + 1] + board[current_position + cols + 1] + board[current_position + cols] + board[current_position + cols - 1] + board[current_position - 1]);
                }
            }
        }
    }
}

//get next generation of the current board
void Life::get_next_gen(){
    uint16_t* next_board = new uint16_t[rows*cols];
    for(uint64_t i = 0; i < rows; i++){
        for(uint64_t j = 0; j < cols; j++){
            uint16_t current_state = i * cols + j;
            uint16_t count = get_count_live_cells(i, j, current_state);
            if(board[current_state] == 1){
                if((count == 2) || (count == 3)){
                    next_board[current_state] = 1;
                }
                else{
                    next_board[current_state] = 0;
                }
            }
            else{
                if(board[current_state] == 0){
                    if(count == 3){
                        next_board[current_state] = 1;
                    }
                    else{
                        next_board[current_state] = 0;
                    }
                }
                else{                    
                    std::cout << InvalidDataException;
                }
            }
        }
    }
    delete [] board;
    board = next_board;
}

//get a certain generation of the current board
void Life::get_gen(uint64_t generation_number){

}

//print out the board
void Life::print(){
    for(uint64_t i = 0; i < rows; i++){
        for(uint64_t j = 0; j < cols; j++){
            std::cout << board[i * cols + j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

//draw the board
void Life::draw(std::string filename){
    bitmap bm(512, 512);
    //draw grid
    uint64_t x_dist = bm.getw()/cols;   //the size of unit cell width
    uint64_t y_dist = bm.geth()/rows;   //the size of unit cell height

    //if location is 1: draw a yellow rectangle, otherwise BLACK
    for(uint64_t i = 0; i < rows; i++){
        for(uint64_t j = 0; j < cols; j++){
            if(board[i * cols + j]){
                bm.fill_rect(j * x_dist, i * y_dist, x_dist, y_dist, color::YELLOW);
            }
            else{
                bm.fill_rect(j * x_dist, i * y_dist, x_dist, y_dist, color::BLUE);
            }
        }
    }
        
    for(uint32_t pos = 1; pos < cols; pos++){       //draw vertical lines to indicate columns
        bm.vert_line(pos * x_dist, 0, bm.geth(), color::RED);
    }
    for(uint32_t pos = 1; pos < rows; pos++){       //draw horizontal lines to indicate rows
        bm.horiz_line(0, bm.getw(), pos * y_dist, color::RED);
    }

    bm.save(filename);
    
}
#include <cstdint>
#include <fstream>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>

class Chip8
{
public:
    static const unsigned int VIDEO_HEIGHT = 32;
    static const unsigned int VIDEO_WIDTH = 64;
    static const unsigned int START_ADDRESS = 0x200;
    static const unsigned int FONTSET_SIZE = 80;
    static const unsigned int FONTSET_START_ADDRESS = 0x50;

    typedef void (Chip8::*Chip8Func)();
	Chip8Func table[0xF + 1];
	Chip8Func table0[0xE + 1];
	Chip8Func table8[0xE + 1];
	Chip8Func tableE[0xE + 1];
	Chip8Func tableF[0x65 + 1];

    uint8_t registers[16]{};        // 16 8 bit registers
    uint8_t memory[4096]{};         // 4k bytes of memory
    uint16_t index{};               // 16 bit index register
    uint16_t pc{};                  // 16 bit program counter
    uint16_t stack[16];             // 16 level stack
    uint8_t sp{};                   // stack pointer
    uint8_t delayTimer{};           // 8 bit delay timer
    uint8_t soundTimer{};           // 8 bit sound timer
    uint8_t keypad[16]{};           // 16 input keys
    uint32_t video[VIDEO_HEIGHT * VIDEO_WIDTH]{};      // 64 * 32 monochrome display memory
    uint16_t opcode;                // 16 bit opcode
    
    // RNG
    std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;
    
    static const uint8_t fontset[FONTSET_SIZE];
    // constructor
    Chip8();

    // desctuctor
    ~Chip8();

    //functions
    void Table0();
	void Table8();
	void TableE();
	void TableF();
	void OP_NULL();

    void Cycle();
    void LoadROM(char const*);
    void OP_00E0(); 
    void OP_00EE();
    void OP_1nnn();
    void OP_2nnn();
    void OP_3xkk();
    void OP_4xkk();
    void OP_5xy0();
    void OP_6xkk();
    void OP_7xkk();
    void OP_8xy0();
    void OP_8xy1();
    void OP_8xy2();
    void OP_8xy3();
    void OP_8xy4();
    void OP_8xy5();
    void OP_8xy6();
    void OP_8xy7();
    void OP_8xyE();
    void OP_9xy0();
    void OP_Annn();
    void OP_Bnnn();
    void OP_Cxkk();
    void OP_Dxyn();
    void OP_Ex9E();
    void OP_ExA1();
    void OP_Fx07();
    void OP_Fx0A();
    void OP_Fx15();
    void OP_Fx18();
    void OP_Fx1E();
    void OP_Fx29();
    void OP_Fx33();
    void OP_Fx55();
    void OP_Fx65();

};
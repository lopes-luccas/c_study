#ifndef HANG_MAN
#define HANG_MAN

#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <windows.h>
#include "printHangman.h"

// Consts:
#define ROBOT 1
#define PLAYER 0
#define WORDS_LENGTH 15	
#define LETTERS_LENGTH 9
#define MAX_NAME 50
#define MAX_KICKS 26
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

//  Prototypes:
void waitRead();
void setcolor();
void clearScreen();
void invalidOption();

void startSystem();
void startGame(const unsigned is_robot);

void readFirstPlayer();
void readSecondPlayer();
void greeting(const char*player_name);

unsigned wrongKicks();

int endGame();
int hangMan();
int winGame();
int loseGame();
int vsPlayer();
int vsComputer();
int chooseOption();
int randomPassword();
int createPassword();
int defaultSettings();
int alreadyKicked(char kick);
int letterExists(char letter);
int choiceModeGame(char*option);
int askToPlayAgain(unsigned *play_again);
int choiceDifficultLevel(char*difficult_level);
int toKick(unsigned*attemps, const unsigned isRobot);

// Global variables:
char *first_player_name, *second_player_name;
const char passwords[WORDS_LENGTH][LETTERS_LENGTH]={
	"OLHO", "DADO", "ALHO", "BOLA", "FACA", 
	"MISTER", "BARATO", "ISENTO", "FORMAL", "CORDAO", 
	"INVASIVO", "EQUIDADE", "IMINENTE", "DEFERIDO", "CARAMELO"
};

// Structs:
struct data_game {
	char *password;
	char *alphabet;
	unsigned *kicks;
	unsigned kicks_given;
	unsigned max_letters;	
} DATA_GAME;

#endif

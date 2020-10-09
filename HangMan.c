// Autor: Luccas Lopes Silva | Prontuário: pt3009343;

// Imports:
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>

#ifdef _WIN32
	#include <windows.h>
#endif

// Consts:
#define ROBOT 1
#define PLAYER 0
#define NLETTERS 9
#define MAX_NAME 50
#define MAX_KICKS 26
#define WORDS_LENGTH 15	
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Structs:
struct data_game {
	char *password;
	char *alphabet;
	unsigned *kicks;
	unsigned kicks_given;
	unsigned max_letters;	
} DATA_GAME;

//  Prototypes:
void waitRead();
void setcolor();
void clearScreen();
void invalidOption();

void printMenu();
void printTrophy();
void printHangMan();
void printLoseGame();
void printPassword();
void printDataPlays();
void printHang(const unsigned erros);

void sSystem();
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
const char passwords[WORDS_LENGTH][NLETTERS]={
	"OLHO", "DADO", "ALHO", "BOLA", "FACA", 
	"MISTER", "BARATO", "ISENTO", "FORMAL", "CORDAO", 
	"INVASIVO", "EQUIDADE", "IMINENTE", "DEFERIDO", "CARAMELO"
};

//  Functions:
int main(void) {
//	System:
	sSystem();
	
//	Dead end:
	return EXIT_SUCCESS;
}

// Utilizando ponteiros de função para inicializar o jogo:
void sSystem() {
    defaultSettings();
	int(*p_hangMan_f)()=&hangMan;
	p_hangMan_f();
}

// Settings:
int defaultSettings() {
	setcolor();
	srand(time(NULL));
	setlocale(LC_ALL, "PORTUGUESE");		
		
//	Dead end:
	return EXIT_SUCCESS;	
}

// Jogo:
int hangMan() {
//	Settings:
	DATA_GAME.kicks_given=0;
	first_player_name=(char *)malloc(MAX_NAME*sizeof(char));
	second_player_name=(char *)malloc(MAX_NAME*sizeof(char));
	DATA_GAME.password=(char *)malloc(WORDS_LENGTH*sizeof(char));
	DATA_GAME.alphabet=(char *)malloc(MAX_KICKS*sizeof(char));
	DATA_GAME.kicks=(unsigned *)calloc(MAX_KICKS, sizeof(unsigned));
	
//	Variables:
	char mode_game;
	static unsigned play_again=1;
	
//	Commands:
	clearScreen();
	readFirstPlayer();
	choiceModeGame(&mode_game);
	mode_game=='1'? vsPlayer():vsComputer();
	askToPlayAgain(&play_again);
	
//	 A linha comentada abaixo é uma forma de limpar os chutes.
//	 memset(DATA_GAME.kicks, 0, sizeof(DATA_GAME.kicks)); 
	
	free(DATA_GAME.kicks);
	free(first_player_name);
	free(second_player_name);
	free(DATA_GAME.password);
	free(DATA_GAME.alphabet);
	
// 	Dead end:
	return play_again? hangMan():endGame();
}

// Fim de jogo:
int endGame() {
	clearScreen();
	printf("Obrigado por jogar!\nAluno: Luccas Lopes Silva | Prontuário: pt3009343.\n");
	return EXIT_SUCCESS;
}

// Verifica se o jogador perdeu o jogo:
int loseGame() { return wrongKicks()>=7; }

// Verifica se o jogador ganhou o jogo:
int winGame() {
	for(int i=0; i<strlen(DATA_GAME.password); i++)
		if(!alreadyKicked(DATA_GAME.password[i])) return 0;
	return 1;
}

// Modo de jogo Jogador versus Jogador:
int vsPlayer() {
//	Commands:
	readSecondPlayer();
	createPassword();
	
	printf("Jogador %s, agora é com você!\n", second_player_name);
	
	startGame(PLAYER);
	
	winGame()? printTrophy():printf("Derrota!\n");
	
//	Dead end:
	return EXIT_SUCCESS;
}

// Chuta uma letra para a palavra-passe:
int toKick(unsigned *attemps, const unsigned is_robot) {
//	Variables:
	char kick;
	int index_alphabet;
	
//	Commands:
	++*attemps;
	
	printf("%dª Tentativa.\nDigite uma letra: ", *attemps);
	
//	Na condição verdadeira o robô quem faz a jogada, senão, o jogador que digita.
	if(is_robot) {
		index_alphabet=rand() % strlen(DATA_GAME.alphabet);
		kick=DATA_GAME.alphabet[index_alphabet];
		memmove(&DATA_GAME.alphabet[index_alphabet], &DATA_GAME.alphabet[index_alphabet + 1], strlen(DATA_GAME.alphabet) - index_alphabet);
	} else kick=getch();
	
//	Verifique se a letra digitada pelo jogador é maiúscula caso contrário não some às tentativa:
	if(kick>=65 && kick<=90) {
		if(alreadyKicked(kick)) {
			printf("\nVocê já chutou essa letra.\n");
			--*attemps;
			sleep(1);
		} else {
			DATA_GAME.kicks[DATA_GAME.kicks_given]=kick;
			++DATA_GAME.kicks_given;
			printf("\n");
			if(is_robot) sleep(1);
		}	
	} else {
		printf("\nCaractere inválido.\n");
		--*attemps;	
		sleep(1);
	}
	printf("\n");
	
//	Dead end:
	return EXIT_SUCCESS;
}

// Verifica se já chutou a letra:
int alreadyKicked(const char kick) {
	for(unsigned index_kick=0; index_kick<MAX_KICKS; ++index_kick)
		if(DATA_GAME.kicks[index_kick]==kick) return 1;
	return 0;
}

// Verifica se a letra existe na palavra-passe:
int letterExists(const char letter) {
	for(unsigned index_pass=0; index_pass<strlen(DATA_GAME.password); ++index_pass)
		if(letter==DATA_GAME.password[index_pass]) return 1;
	return 0;
}

// Conta quantos erros o jogador fez:
unsigned wrongKicks() {
//	Variables:
	unsigned errors=0;
	
//	Command:
	for(unsigned index_kick=0; index_kick<DATA_GAME.kicks_given; ++index_kick)
		if(!letterExists(DATA_GAME.kicks[index_kick])) ++errors;
	
//	Dead end:
	return errors;
}

// Escolhe a opção de jogo para o vsComputer:
int chooseOption() {
//	Variables:
	char option;
	int valid_option=0;
	
//	Commands:
	printf("\\('-')/: Você quer escolher a palavra ou eu escolho?\n");
	printf("[1. Eu escolho!] | [2. Escolha por mim!]: ");
	option=getch();
	option=='1' || option=='2'? valid_option=1:invalidOption();
	clearScreen();
	
//	Dead end:
	return valid_option? option:chooseOption();
}

// Jogar contra o computador:
int vsComputer() {
//	Variables:
	unsigned attemps=0;
	char option=chooseOption(), difficult_level;

//	Commands:	
	strcpy(DATA_GAME.alphabet, ALPHABET);
	if(option=='1') {
		int (*p_createPassword_f)()=&createPassword;
		p_createPassword_f();
		printf("\\(^-^)/: Agora é a minha vez, jogador %s.\n", first_player_name);
		sleep(1);
		startGame(ROBOT);
	} else {	
		choiceDifficultLevel(&difficult_level);
		int (*p_randomPassword_f)();
		p_randomPassword_f=&randomPassword;
		(p_randomPassword_f)();
		printf("\\(^-^)/: Jogador %s, agora é a sua vez.\n", first_player_name);
		startGame(PLAYER);
	}
	winGame()? printTrophy():printf("Derrota!\n");
	strcpy(DATA_GAME.alphabet, ALPHABET);
	
//	Dead end:
	return EXIT_SUCCESS;
}

// A máquina seleciona um senha aleatória:
int randomPassword() {
//  Variables:
	int random_index, valid_password=0;
	
//	Commands:
	random_index=rand()%WORDS_LENGTH;
	if(strlen(passwords[random_index])==DATA_GAME.max_letters) {
		valid_password=1;
		strcpy(DATA_GAME.password, passwords[random_index]);
		printf("\\(^-^)/: Okay, já escolhi a palavra-passe!\n");
		waitRead();
	}
	
//	Dead end:
	return valid_password? EXIT_SUCCESS:randomPassword();
}

// Primeiro jogador cria uma senha:
int createPassword() {
//	Variables:
	int validate_password=0, invalid_password=0;
	
//	Commands:
	while(!validate_password) {
		printf("Jogador %s, digite a palavra-passe: ", first_player_name);
		scanf("%s", DATA_GAME.password);
		for(unsigned index_letter=0; index_letter<strlen(DATA_GAME.password); ++index_letter) {
			if(DATA_GAME.password[index_letter]<65 || DATA_GAME.password[index_letter]>90) {
				printf("A palavra precisa ter somente letras maiúsculas.\n");
				invalid_password=1;
				waitRead();
				break;
			}
		} if(!invalid_password) {
			DATA_GAME.max_letters=strlen(DATA_GAME.password);
			validate_password=1;
		} else invalid_password=0;
	} clearScreen();
	
//	Dead end:
	return EXIT_SUCCESS;
}

// Seleciona o nível de dificuldade no vsComputer:
int choiceDifficultLevel(char *difficult_level) {
//	Variables:
	int valid_level=0;
	
//	Commands:
	printf("[1. Fácil (4 letras)] | [2. Médio (6 letras)] | [3. Difícil (8 letras)]\n");
	printf("Escolha um nível de dificuldade: ");
	*difficult_level=getch();
	*difficult_level>'0' && *difficult_level<'4'? valid_level=1:invalidOption();
	if(*difficult_level=='1') DATA_GAME.max_letters=4;
	else if(*difficult_level=='2') DATA_GAME.max_letters=6;
	else DATA_GAME.max_letters=8;
	clearScreen();
	
//	Dead end:
	return valid_level? EXIT_SUCCESS:choiceDifficultLevel(difficult_level); 
}

// Escolhe o modo de jogo:
int choiceModeGame(char *mode_game) {
//	Variables:
	int valid_mode=0;
	
//	Commands:
	printf("Escolha o modo de jogo [1. Jogador vs Jogador] | [2. Jogador vs Computador]: ");
	*mode_game=getch();
	*mode_game=='1' || *mode_game=='2'? valid_mode=1:invalidOption();
	clearScreen();
	
//	Dead end:
	return valid_mode? EXIT_SUCCESS:choiceModeGame(mode_game);
}

// Começa o jogo:
void startGame(const unsigned is_robot) {
//	Variables:
	unsigned attemps=0;
	
//	Commands:
	while(!winGame() && !loseGame()) {
		printHangMan();
		toKick(&attemps, is_robot);
		clearScreen();
	}
}

// Pergunta se quer jogar de novo:
int askToPlayAgain(unsigned *play_again) {
//  Variables:
	char input;
	unsigned valid_option=0;
 
//	Commands:
	printf("Gostaria de jogar novamente? (S/N): ");
	input=getch();
	input=='N' || input=='S'? valid_option=1:invalidOption();
	if(input=='N') *play_again=0;
	clearScreen();
	
//	Dead end:
	return valid_option? EXIT_SUCCESS:askToPlayAgain(play_again);
}

// Mostra as informações das jogadas do jogador:
void printDataPlays() {
	printf("Letras já utilizadas: ");
	for(unsigned i=0; i<DATA_GAME.kicks_given; ++i)
		printf("%c ", DATA_GAME.kicks[i]);
	printf("\n");
	printf("Erros: %d.\n", wrongKicks());
}

// Imprime o jogo:
void printHangMan() {
//	Variables:
	const unsigned errors=wrongKicks();
	
//	Commands:
	printDataPlays();
	printHang(errors);
	printPassword();
}

// Imprime a forca:
void printHang(const unsigned errors) {
	printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", (errors>=1? '(':' '), (errors>=1? '_' :' '), (errors>=1? ')':' '));
	printf(" |      %c%c%c  \n", (errors>=4?'\\':' '), (errors>=2?'|':' '), (errors>=3?'/':' '));
	printf(" |       %c     \n", (errors>=5?'|':' '));
	printf(" |      %c %c   \n", (errors>=6?'/':' '), (errors>=7?'\\':' '));
	printf(" |              \n");
	printf("_|___         \n\n");
}

// Imprime a palavra-passe:
void printPassword() {
	printf("Palavra-passe: ");
	for(unsigned i=0; i<DATA_GAME.max_letters; ++i) {
		if(alreadyKicked(DATA_GAME.password[i])) printf("%c ", DATA_GAME.password[i]);
		else printf("_ ");
	} printf("\n");
}

// Imprime o troféu:
void printTrophy() {
    printf("    ___________      \n");
    printf("   '._==_==_=_.'     \n"); 
    printf("  .-\\:        /-.   \n");
    printf("  | (|:.     |) |    \n");  
    printf("   '-|:.     |-'     \n");        
    printf("    \\::.    /       \n");           
    printf("      '::. .'        \n");
    printf("        ) (          \n");             
    printf("      _.' '._        \n");         
    printf("      ´''''`	   \n\n");
    printf("      Vitória!     \n\n");
}

// Lê o segundo jogador:
void readSecondPlayer() {
//	Commands:
	printf("Digite o nome do 2º jogador: ");
	scanf("%s", second_player_name);
	clearScreen();
	greeting(second_player_name);
	waitRead();
}

// Lê o primeiro jogador:
void readFirstPlayer() {	
//	Commands:
	printf("Olá, qual o seu nome? ");
	scanf("%s", first_player_name);
	clearScreen();
	greeting(first_player_name);
	waitRead();
}

// Configura a cor do terminal:
void setcolor() {
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes=consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else 
		system("clear");
	#endif
}

// Espera o jogador ler a mensagem:
void waitRead() { sleep(1); clearScreen(); }

// Imprime a mensagem de erro:
void invalidOption() { printf("\nOpção inválida!\n"); sleep(1); }

// Cumprimenta o jogador:
void greeting(const char *player_name) { printf("Olá %s, seja bem-vindo!\n", player_name); }

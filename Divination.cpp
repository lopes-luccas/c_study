#include <ctime>
#include <cmath>
#include <clocale>
#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;

void configurarIdioma() {
	setlocale(LC_ALL, "PORTUGUESE");
//	cout << "Idioma " << setlocale(LC_ALL, "PORTUGUESE") << " configurado com sucesso!\n\n");
}

void configurarAleatoriedade() {
	srand(time(NULL));
//	cout << "Aleatoriedade configurada com sucesso! ";
}

class JogoAdvinhacao {
	private:
		char tentarNovamente;
		bool dificuldadeValida, ganhou, chuteInvalido;
		string dificuldade, chuteViavel;
		int tentativas, chute, numeroSecreto, dificuldadeViavel, pontuacao, chutesDados[15];

	public:	
		JogoAdvinhacao() {
			ganhou = false;
			pontuacao = 100;
			chuteInvalido = false;
			configurarIdioma();
			imprimirJogo();
			configurarDificuldade();
			gerarNumeroSecreto();
			inicializarJogo();
		}
		
		void imprimirJogo() {
			cout << "\t\t|-------------------------------------|\n";
			cout << "\t\t|   Bem vindo ao jogo da advinha��o   |\n";
			cout << "\t\t|   [1]-F�cil [2]-M�dio [3]-Dif�cil   |\n";
			cout << "\t\t| Selecione um n�vel de dificuldade: ";
		}
		
		void configurarDificuldade() { if(dificuldadeValidaSelecionada()) configurarAleatoriedade(); }
		
		void verificarDificuldade(int dificuldade) {
			switch(dificuldade) {
				case 1: 
					tentativas = 15;
					dificuldadeValida = true;
					cout << "\t\t|       N�vel f�cil selecionado       |\n";
					break;
				case 2:
					tentativas = 10;
					dificuldadeValida = true;
					cout << "\t\t|       N�vel m�dio selecionado       |\n";
					break;
				case 3:
					tentativas = 5;
					dificuldadeValida = true;
					cout << "\t\t|      N�vel dif�cil selecionado      |\n";
					break;
				default:
					cout << "\t\t|    N�vel de dificuldade inv�lida!   |\n\t\t|  Seleciona uma dificuldade v�lida: ";
			}
		}
		bool dificuldadeValidaSelecionada() {
//			Configurar Vari�vel de inst�ncia 'dificuldadeValida' para falso.
			dificuldadeValida = false;
			while(!dificuldadeValida) {
				cin >> dificuldade;
				stringstream ss;
				ss << dificuldade;
				ss >> dificuldadeViavel;
				verificarDificuldade(dificuldadeViavel);
				
			}
			return true;	
		}
		void gerarNumeroSecreto() { numeroSecreto = rand() % 101; }
		
		bool verificarChute() {
			if(chute == numeroSecreto) return true;
			for(int i=0; i<15; i++) {
				if(chutesDados[i] == chute) {
					chuteInvalido = true;
					break;
				}
			}
			if(!chuteInvalido) chutesDados[tentativas] = chute;
			return false;
		}
		
		void mostrarTentativasRestantes() { 
			cout << "\t\t|                                     |\n";
			if(tentativas < 10) {
				cout << "\t\t|    Voc� tem [" << tentativas << "] chutes restando     |\n";		
			} else {
				cout << "\t\t|    Voc� tem [" << tentativas << "] chutes restando    |\n";	
			}
		}
		
		void perguntarSeQuerJogarDeNovo() {
			cout << "\t\t|                                     |\n";
			while(true) {
				cout << "\t\t|  Que tal tentar novamente? (s/n): ";
				cin >> tentarNovamente;
				cout << "\t\t|                                     |\n";
				if(tentarNovamente == 's' || tentarNovamente == 'S') {
					break;
				} else if(tentarNovamente == 'n' || tentarNovamente == 'N') {
					cout << "\t\t|          Tenha um bom dia!          |\n";
					cout << "\t\t|_____________________________________|\n";
					exit(0);	
				} else {
					cout << "\t\t|N�o foi poss�vel entender sua reposta|\n";
				}	
			}
		}
		
		void parabenizar() {
			cout << "\t\t|                                     |\n";
			cout << "\t\t|        Parab�ns voc� ganhou!        |\n";
			if(pontuacao < 10) {
				cout << "\t\t|       Voc� obteve " << pontuacao << " pontos!         |" << endl;	
			} else if(pontuacao >= 10 && pontuacao < 100){
				cout << "\t\t|        Voc� obteve " << pontuacao << " pontos!       |" << endl;	
			} else {
				cout << "\t\t|       Voc� obteve " << pontuacao << " pontos!       |" << endl;	
			}
			ganhou = true;
			perguntarSeQuerJogarDeNovo();
			jogarNovamente();
		}
		
		void jogarNovamente() { JogoAdvinhacao(); }
		
		
		void amenizarDerrota() {
			cout << "\t\t|                                     |\n";
			cout << "\t\t|  Ahh, que pena, n�o foi dessa vez!  |\n";
			perguntarSeQuerJogarDeNovo();
			jogarNovamente();
		}
		void regularChute() {
			cout << "\t\t|                                     |\n";
			if(chute > numeroSecreto) {
				cout << "\t\t|    Voc� errou! � um n�mero menor!   |\n";
			} else {
				cout << "\t\t|    Voc� errou! � um n�mero maior!   |\n";
			}
		}
		void chutar() {
			while(tentativas > 0) {
				mostrarTentativasRestantes();
				cout << "\t\t|          Chute um n�mero: ";
				cin >> chuteViavel;
				stringstream ss;
				ss << chuteViavel;
				ss >> chute;
				if(verificarChute()) {
					parabenizar();
					break;
				} else {
					
					if(chute == 0 && numeroSecreto != 0 || chuteInvalido) {
						cout << "\t\t|           Chute inv�lido!           |" << endl;
						chuteInvalido = false;
						
					} else {
						pontuacao = pontuacao * (100-tentativas) / 100;
						tentativas--;
						regularChute();	
					}
				}	
			}
			if(!ganhou) amenizarDerrota();
		}
		void inicializarJogo() {
			chutar();
		}
};

int main(void) {
	JogoAdvinhacao novoJogo;
	return 0;
}

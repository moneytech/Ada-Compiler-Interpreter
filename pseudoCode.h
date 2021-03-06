
#include <stdio.h>
#include <stdlib.h>

typedef enum {ADD, SUB, DIV, DUPL, JMP, JNE, JGE, JG, LABEL, LOAD, LOADARRAY, MULT, POP, PRNT, PUSH, STORE, SWAP, DATA, SCAN, MESSAGE, ARRAY, PRINTARRAY, AFFARRAY} CODOP;

typedef struct {
	char name[30];
	double value;
	int type; // 0 int, 1 double, 3 float
	int use;
}namevalue;

typedef struct{
	double* T;
	char name[30];
	int type;
	int length;
}array;

typedef struct{
	int bInf;
	int bSup;
	char name[30];
	int type;
}arrayType;


typedef union {
	char var[30];
	// pour LOAD / STORE
	double _const;
	// pour PUSH
	char label_name[30]; // pour JMP/JNE/JG/LABEL

	namevalue nv;

	arrayType Array;
} Param;

typedef struct {
	CODOP codop ;
	Param param ; // une opération possède un paramètre au maximum
}pseudoinstruction;

struct pseudocodenode{
	pseudoinstruction first ;
	struct pseudocodenode* next ;
};

typedef struct pseudocodenode* pseudocode;

double value(char* name);
char* name(int rang, namevalue* TS);
double value2(int rang, namevalue* TS);
int indexVar(char* name, namevalue* TS, int n);


void initialiser_TS();

void initialiser_VM();
void interpreter_pseudo_code_inst(pseudoinstruction pc) ;
void interpreter_pseudo_code_list_inst() ;

pseudoinstruction rechercher_instruction_au_label(char* label);

void loadPseudoCode(char* nameFile);
void store(char* name, double value);
void data(char* name, double value, int type);
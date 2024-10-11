#ifndef __BUILD_TREE_H__
#define __BUILD_TREE_H__

#define MAXOPS 100
#define MAXNODES 100
#define MAXNUMLENGTH 12
#define MAXEXPRLENGTH 100
#define LR 0
#define RL 1
#define NUMOPTYPES 13
#define NUMREG 32
#define NUMVAR 10

typedef enum { VAR, REG, CONST, UNARYOP, BINARYOP } nodetype_t;

typedef enum {
  UMINUS,
  ADD,
  SUB,
  MUL,
  DIV,
  AND,
  OR,
  XOR,
  NOT,
  SLL,
  SRL,
  LPAREN,
  RPAREN
} ops_t;

typedef struct {
  nodetype_t type;//type of node: variable, binary operator, 
  int prec;//precedence, lowest is first and highest is last
  int assoc;//if both operators have same precedence, the association determines which instruction subset is carried out first, aka leftmost or rightmost derivation?
    /*ex:
      -5 + 3 + 2   (both operators have same precedence so we must choose which operation to do first)
      -LR: (5+3)+2
      -RL: 5+(3+2)
    */
  char symbol[3];//c code symbol
  char instr[4];//corresponding assembly instr
} operator_t;

extern const operator_t optable[];

typedef struct node {
  nodetype_t type;
  int data;
  struct node *left, *right;
} node_t;

// Back-end functions
void initRegisters(void);
void init_regtable(void);
void init_vartable(void);
int assign_reg(int var);
void printregtable(void);
void printvartable(void);
node_t *generate_code(node_t *);

// Build tree function
void postorder(const node_t *);

// Main function
node_t *build_tree(const char exprin[]);

typedef struct {
  unsigned int top;
  int ops[MAXOPS];
} operatorstack_t;

typedef struct {
  unsigned int top;
  node_t *nodes[MAXNODES];
} nodestack_t;

//global variable
extern char *variableAtRegister[32];

#endif

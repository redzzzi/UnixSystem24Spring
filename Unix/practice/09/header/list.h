struct node {
  int value;
  struct node * next;
};

typedef struct node List;
extern List *head;

int isEmpty();
void add(int);
void remove(int);

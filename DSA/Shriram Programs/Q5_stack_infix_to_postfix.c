#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void init(struct Stack *s) { s->top = -1; }
int isEmpty(struct Stack *s) { return s->top == -1; }
void push(struct Stack *s, char x) { s->arr[++s->top] = x; }
char pop(struct Stack *s) { return s->arr[s->top--]; }
char peek(struct Stack *s) { return s->arr[s->top]; }

int precedence(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': case '%': return 2;
    case '^': return 3;
    default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s; init(&s);
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            if (!isEmpty(&s)) pop(&s); // remove '('
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
                postfix[k++] = pop(&s);
            push(&s, ch);
        }
    }
    while (!isEmpty(&s))
        postfix[k++] = pop(&s);
    postfix[k] = '\0';
}

int evalPostfix(char postfix[]) {
    int i = 0;
    struct IntStack { int arr[MAX]; int top; } st;
    st.top = -1;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            st.arr[++st.top] = ch - '0';
        } else {
            int b = st.arr[st.top--];
            int a = st.arr[st.top--];
            int res;
            switch (ch) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
            case '%': res = a % b; break;
            default: res = 0;
            }
            st.arr[++st.top] = res;
        }
    }
    return st.arr[st.top];
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression (single-digit operands): ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Evaluation: %d\n", evalPostfix(postfix));
    return 0;
}

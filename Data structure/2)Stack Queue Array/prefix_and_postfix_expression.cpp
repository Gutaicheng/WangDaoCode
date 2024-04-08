//
// Created by 86187 on 2024/4/7.
//
/**
 * 注意
 * 1. 本代码因为需要计算，所以只能处理带具体数值的表达式
 * 如：1+2，（A+B）则不行
 * 2. 本代码只能处理数值为0~9之间的数字，多位数也能做，但是不适合学习使用
 * 3. 如果需要修改表达式长度，请调整MaxSize
 * 4. 为方便阅读，没有加函数声明，请勿模仿
 */
#include "stdio.h"
#include "string.h"

#define Maxsize 20

typedef struct Stack {
    char data[Maxsize];
    int top;
}operandStack, symbolStack, postfixStack;

bool InitStack(Stack &S) {
    S.top = -1;
    return true;
}

bool StackIsEmpty(Stack S) {
    if (S.top == -1) return true;
    return false;
}

bool StackIsFull(Stack S) {
    if (S.top == Maxsize - 1) return true;
    return false;
}

bool StackPush(Stack &S, char e) {
    if (StackIsFull(S)) return false;
    S.data[++S.top] = e;
    return true;
}

bool StackPop(Stack &S, char &e) {
    if (StackIsEmpty(S)) return false;
    e = S.data[S.top--];
    S.data[S.top + 1] = 0;
    return true;
}

char GetStackTop(Stack S) {
    return S.data[S.top];
}

bool isValidExpression(char prefix[]) {
    symbolStack boundaryStack;
    InitStack(boundaryStack);
    int length = strlen(prefix);
    for (int i = 0; i < length; i++) {
        char c = prefix[i], e;
        if (c == '(')
            StackPush(boundaryStack, c);
        if (c == ')') {
            if (StackIsEmpty(boundaryStack)) return false;
            StackPop(boundaryStack, e);
        }
    }
    if (StackIsEmpty(boundaryStack)) return true;
    return false;
}

bool isOperand(char e) {
    if (e >= 48 && e <= 57) return true;
    return false;
}

bool isOperator(char e) {
    if (e == '+' || e == '-' || e == '*' || e == '/' ) 
        return true;
    return false;
}

bool topIsPriority(char top, char c) {
    // 若 当前 c 为 '+' 或 '-'，栈顶 top 肯定是同级或者高级
    if (c == '+' || c == '-')
        return true;
    // 若 当前 c 为 '*' 或 '/' 栈顶 top 是 '*' 或 '/' 才是同级
    if (top == '*' || top == '/')
        return true;
    return false;
}

void prefix_to_postfix(char prefix[], postfixStack &postfix, operandStack &operandStack) {
    int length = strlen(prefix);
    // 循环读取输入的中缀表达式
    for (int i = 0; i < length; ++i) {
        char c = prefix[i];
        // 如果当前 c 是操作数，直接入后缀表达式栈
        if (isOperand(c))
            StackPush(postfix, c);
        // 如果当前 c 是 左界限符号 '('，直接入操作符栈
        if (c == '(')
            StackPush(operandStack, c);
        // 如果当前 c 是 右界限符 ')'，
        // 将操作符栈依次弹出，直到栈顶是 左界限符 '('
        // 注：如果输入的是错误表达式，则可能出现右界限符单身的问题
        if (c == ')') {
            char e;
            while (GetStackTop(operandStack) != '(') {
                StackPop(operandStack, e);
                StackPush(postfix, e);
            }
            StackPop(operandStack, e); // 弹出 '('
        }
        // 如果当前 c 是操作符，
        // 将操作符栈依次弹出，
        // 直到栈顶是 左界限符 '(' 或者 栈顶的优先级低于 c 或者空栈
        if (isOperator(c)) {
            char top = GetStackTop(operandStack), f;
            while (top != '(' && topIsPriority(top, c) && !StackIsEmpty(operandStack)) {
                StackPop(operandStack, f);
                StackPush(postfix, f);
                top = GetStackTop(operandStack);
            }
            // 最后再把当前 c 压入操作符栈
            StackPush(operandStack, c);
        }
    }
    // 全部读取完之后，把操作符栈依次弹出，再压入到后缀表达式栈
    char c;
    while (!StackIsEmpty(operandStack)) {
        StackPop(operandStack, c);
        StackPush(postfix, c);
    }
}

void calculate(char c, float left_operand, float right_operand, float &R) {
    if (c == '+') R = left_operand + right_operand;
    if (c == '-') R = left_operand - right_operand;
    if (c == '*') R = left_operand * right_operand;
    if (c == '/') R = left_operand / right_operand;
}

float evaluate_postfix(postfixStack &postfix) {
    int length = strlen(postfix.data);
    // 模拟结果栈
    float result[Maxsize], right_operand, left_operand, R;
    int result_flag = -1;
    for (int i = 0; i < length; i++) {
        char c = postfix.data[i];
        if (isOperand(c))
            result[++result_flag] = (float )c - 48;
        else {
            right_operand = result[result_flag--];
            left_operand = result[result_flag--];
            calculate(c, left_operand, right_operand, R);
            result[++result_flag] = R;
        }
    }
    return R;
}

int main() {
    char prefix[30];
    // 输入参考 ((9/(7-(1+3)))*3)-(2+(1+1))
    gets(prefix);

    // 后缀表达式栈
    postfixStack postfix;
    InitStack(postfix);
    // 操作符栈
    operandStack operandStack;
    InitStack(operandStack);

    // 判断表达式是否合法
    if (isValidExpression(prefix)) {
        prefix_to_postfix(prefix, postfix, operandStack);
        printf("后缀表达式：");
        puts(postfix.data);
        float r = evaluate_postfix(postfix);
        printf("计算结果%.2f\n", r);
    } else printf("表达式不合法\n");

    return 0;
}
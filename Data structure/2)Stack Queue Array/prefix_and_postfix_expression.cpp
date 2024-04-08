//
// Created by 86187 on 2024/4/7.
//
/**
 * ע��
 * 1. ��������Ϊ��Ҫ���㣬����ֻ�ܴ����������ֵ�ı��ʽ
 * �磺1+2����A+B������
 * 2. ������ֻ�ܴ�����ֵΪ0~9֮������֣���λ��Ҳ���������ǲ��ʺ�ѧϰʹ��
 * 3. �����Ҫ�޸ı��ʽ���ȣ������MaxSize
 * 4. Ϊ�����Ķ���û�мӺ�������������ģ��
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
    // �� ��ǰ c Ϊ '+' �� '-'��ջ�� top �϶���ͬ�����߸߼�
    if (c == '+' || c == '-')
        return true;
    // �� ��ǰ c Ϊ '*' �� '/' ջ�� top �� '*' �� '/' ����ͬ��
    if (top == '*' || top == '/')
        return true;
    return false;
}

void prefix_to_postfix(char prefix[], postfixStack &postfix, operandStack &operandStack) {
    int length = strlen(prefix);
    // ѭ����ȡ�������׺���ʽ
    for (int i = 0; i < length; ++i) {
        char c = prefix[i];
        // �����ǰ c �ǲ�������ֱ�����׺���ʽջ
        if (isOperand(c))
            StackPush(postfix, c);
        // �����ǰ c �� ����޷��� '('��ֱ���������ջ
        if (c == '(')
            StackPush(operandStack, c);
        // �����ǰ c �� �ҽ��޷� ')'��
        // ��������ջ���ε�����ֱ��ջ���� ����޷� '('
        // ע�����������Ǵ�����ʽ������ܳ����ҽ��޷����������
        if (c == ')') {
            char e;
            while (GetStackTop(operandStack) != '(') {
                StackPop(operandStack, e);
                StackPush(postfix, e);
            }
            StackPop(operandStack, e); // ���� '('
        }
        // �����ǰ c �ǲ�������
        // ��������ջ���ε�����
        // ֱ��ջ���� ����޷� '(' ���� ջ�������ȼ����� c ���߿�ջ
        if (isOperator(c)) {
            char top = GetStackTop(operandStack), f;
            while (top != '(' && topIsPriority(top, c) && !StackIsEmpty(operandStack)) {
                StackPop(operandStack, f);
                StackPush(postfix, f);
                top = GetStackTop(operandStack);
            }
            // ����ٰѵ�ǰ c ѹ�������ջ
            StackPush(operandStack, c);
        }
    }
    // ȫ����ȡ��֮�󣬰Ѳ�����ջ���ε�������ѹ�뵽��׺���ʽջ
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
    // ģ����ջ
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
    // ����ο� ((9/(7-(1+3)))*3)-(2+(1+1))
    gets(prefix);

    // ��׺���ʽջ
    postfixStack postfix;
    InitStack(postfix);
    // ������ջ
    operandStack operandStack;
    InitStack(operandStack);

    // �жϱ��ʽ�Ƿ�Ϸ�
    if (isValidExpression(prefix)) {
        prefix_to_postfix(prefix, postfix, operandStack);
        printf("��׺���ʽ��");
        puts(postfix.data);
        float r = evaluate_postfix(postfix);
        printf("������%.2f\n", r);
    } else printf("���ʽ���Ϸ�\n");

    return 0;
}
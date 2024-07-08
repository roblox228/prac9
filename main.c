#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
int minSteps(int x, int y) {
    int diff = y - x;
    if (diff <= 1) return diff;

    int steps = 2;  // ������ � ������� ����
    int current = x + 1;
    int step = 1;

    while (current < y - 1) {
        if (current + step + 1 <= y) {
            current += step;
            step++;
        } else if (current + step <= y) {
            current += step;
        } else {
            current += step - 1;
            step--;
        }
        steps++;
    }

    return steps;
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int x, y;
    printf("������ x �� y (0 <= x <= y < 2^31): ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("������� ��� ��������� ������� �����\n");
        return 1;
    }

    if (x < 0 || y < x || y >= (1LL << 31)) {
        printf("��������� ����� ���\n");
        return 1;
    }

    int result = minSteps(x, y);
    printf("̳������� ������� �����: %d\n", result);

    return 0;
}

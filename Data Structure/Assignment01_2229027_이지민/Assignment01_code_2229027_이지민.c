#include <stdio.h>

void hanoi_tower(int disks)
{
    int pegs = disks + 1;

    for (int i=1; i<pegs; i++)
    {
        printf("disk %d moves to %dth peg from 0th peg.\n", i-1, i); // 0번째 막대에서 디스크들을 전부 꺼내 나열
    }
    for (int j=disks-1; j>0; j--)
    {
        printf("disk %d moves to %dth peg from %dth peg.\n", j-1, pegs-1, j); // 큰 디스크부터 차례대로 마지막 막대에 쌓는다. 
    }
}

int main()
{
    int num_disks = 5; // changable 
    hanoi_tower(num_disks);
    return 0;
}
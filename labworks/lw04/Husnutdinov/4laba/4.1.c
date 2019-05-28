#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



//pipe имеет и другое название – именованный канал.
//Pipe представляет собой область памяти, недоступную пользовательским
//процессам напрямую, зачастую организованную в виде кольцевого буфера.
int main(){
    printf("Лабораторная работа №4.1\nВыполнил Хуснутдинов А.И ИСТбд-21\n");
    int fd[2];
    size_t size;
    char string[] = "Hello, world!";
    char resstring[14];
    int er = pipe(fd);
    if (er == -1) {
        printf("Ошибка создания канала...\n");
        exit(2);
    }

    // Запись всей строки вместе с признаком конца строки в канал
    printf("Начали запись строки...\n");
    size = write(fd[1], string, 14);
    printf("Записали строку...\n");
//* Чтение строки из канала
    printf("Начали чтение строки...\n");
    size = read(fd[0], resstring, 14);
    printf("Прочитали строку...\n");
// Печать прочитанной строки
    printf("Прочитанная строка: \n");
    printf("%s\n",resstring);
// Закрыть входной и выходной потоки
    close(fd[0]);
    close(fd[1]);

    return 0;
}

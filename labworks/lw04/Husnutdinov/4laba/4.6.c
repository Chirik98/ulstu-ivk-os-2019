#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Лабораторная работа №4.6 \nВыполнил Хуснутдинов А.И ИСТбд-21\n");
	int fd;
	size_t size;
	char result[1024];
	printf("Открываем FIFO на чтение...\n");
	fd = open("/home/asd/codeblocks/fifo", O_RDONLY );
    //Если FIFO открывается только для чтения, и флаг O_NDELAY не задан,
    //то процесс, осуществивший системный вызов, блокируется до тех пор, пока
    //какой-либо другой процесс не откроет FIFO на запись.
    printf("Начало чтения...\n");
	char *s = result;// считываемый символ
	do {
		size = read(fd, s, 1);
		s++;
        if (size = 0)
            break;
	} while (size != 0);//считываем по одному символу пока они не закончатся
	printf("Данные прочитаны\n");
	printf("Результат: %s\n", result);
	close(fd);

	return 0;
}

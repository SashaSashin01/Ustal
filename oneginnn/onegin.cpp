#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t count_fsize(const char* filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fclose(file);
    return size;
}

size_t preprocess(char* text_buf) {
    size_t count = 0;
    for (size_t i = 0; text_buf[i] != '\0'; ++i) {
        if (!(text_buf[i] == '\n' && text_buf[count - 1] == '\n')) {
            text_buf[count++] = text_buf[i];
        }
    }
    text_buf[count] = '\0';
    return count;
}

void fill_string_array(char* text_buf, size_t str_count, char** text) {
    size_t j = 0;
    text[0] = text_buf;
    for (size_t i = 0; text_buf[i] != '\0'; ++i) {
        if (text_buf[i] == '\n') {
            text_buf[i] = '\0';
            text[++j] = &text_buf[i + 1];
        }
    }
}
// не до конца понимаю что делает void, но так было на паре, вроде как
int compare_strings(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void print_text(char** text, size_t str_count) {
    for (size_t i = 0; i < str_count; ++i) {
        printf("%s\n", text[i]);
    }
}

int main() { 
    //читаем размер файла
    size_t file_size = count_fsize("onegin.txt");
    //выделяем память под буфер
    char* text_buf = (char*)calloc(1, file_size + 1);
    //копируем файл с диска в буффер
    FILE *input = fopen("onegin.txt", "rb");
    fread(text_buf, 1, file_size, input);
    fclose(input);
    //удаление переноса строк
    size_t str_count = preprocess(text_buf);
    //память для массива строк
    char** text = (char**)calloc(str_count, sizeof(char*));
    //заполняем массив
    fill_string_array(text_buf, str_count, text);
    //сортировка при помощи qsort
    qsort(text, str_count, sizeof(char*), compare_strings);
    //вывод строк
    print_text(text, str_count);
    //вывод массива
    free(text);
    free(text_buf);

    return 0;
}
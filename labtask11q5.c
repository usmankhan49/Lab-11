#include <stdio.h>
#include <math.h>

struct FileInfo {
    char fileName[50];
    int originalSize;
    float reductionRate;
};

int find_compressed_size(int current_size, float reduction_rate, int round_index) {
    if (round_index == 0) {
        return current_size;
    }

    int reduce_amount = ceil(current_size * reduction_rate);
    int new_size = current_size - reduce_amount;

    return find_compressed_size(new_size, reduction_rate, round_index - 1);
}

int main() {
    struct FileInfo myFile;
    struct FileInfo *ptr_file;

    ptr_file = &myFile;

    int total_rounds;
    int final_size;

    printf("enter file name: ");
    scanf("%s", ptr_file->fileName);

    printf("enter original size: ");
    scanf("%d", &ptr_file->originalSize);

    printf("enter reduction rate (example 0.10 for 10 percent): ");
    scanf("%f", &ptr_file->reductionRate);

    printf("enter number of compression rounds: ");
    scanf("%d", &total_rounds);

    final_size = find_compressed_size(ptr_file->originalSize, ptr_file->reductionRate, total_rounds);

    printf("\nfile: %s\n", ptr_file->fileName);
    printf("size after %d rounds: %d\n", total_rounds, final_size);

    return 0;
}


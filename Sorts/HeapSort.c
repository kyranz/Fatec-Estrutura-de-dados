#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapl(long vetor[], long x, long y) {
    long aux = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = aux;
}

long getRight(long i) {
    return 2 * i + 2;
}

long getLeft(long i) {
    return 2 * i + 1;
}

long getMidle(long heapSize) {
    long i = 0;
    long hexp = 0;

    while (hexp < heapSize) {
        hexp = exp2(i);
        i++;
    }

    return ((hexp / 2) - 2);
}

void heapfy(long vet[], long root, long size) {
    long left = getLeft(root);
    long right = getRight(root);
    long max;

    if (left < size && vet[root] < vet[left]) {
        max = left;
    }
    else {
        max = root;
    }
    if (right < size && vet[max] < vet[right]) {
        max = right;
    }
    if (max != root) {
        swapl(vet, root, max);
        heapfy(vet, max, size);
    }
}

void MaxHeap(long vet[], long size) {
    long i = getMidle(size);

    while (i >= 0) {
        heapfy(vet, i, size);
        i--;
    }
}

void HeapSort(long vet[], long size) {
    while (size > 0) {
        MaxHeap(vet, size);
        swapl(vet, 0, size - 1);
        size--;
    }
}
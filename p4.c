#include<stdio.h>
#include<malloc.h>

#define MOD 998244353
typedef long long ll;

#include<stdio.h>
#include<malloc.h>

#define MOD 998244353
typedef long long ll;

int* array_queries(int N, int M, int* A, int* B, int Q, int** queries, int* out_n) {
    int* result = (int*)malloc((Q + 1) * sizeof(int));

    ll sumA = 0, sumB = 0;
    ll sumAi = 0, sumBj = 0;

    for (int i = 0; i < N; i++) {
        sumA = (sumA + A[i]) % MOD;
        sumAi = (sumAi + 1LL * A[i] * (i + 1)) % MOD;
    }

    for (int j = 0; j < M; j++) {
        sumB = (sumB + B[j]) % MOD;
        sumBj = (sumBj + 1LL * B[j] * (j + 1)) % MOD;
    }

    result[0] = (int)((sumAi * sumB + sumBj * sumA) % MOD);

    for (int q = 0; q < Q; q++) {
        int type = queries[q][0];
        int i = queries[q][1] - 1;
        int j = queries[q][2] - 1;

        if (type == 1) {
            int a_i = A[i], b_j = B[j];

            A[i] = b_j;
            B[j] = a_i;

            sumA = ((sumA - a_i + b_j) % MOD + MOD) % MOD;
            sumB = ((sumB - b_j + a_i) % MOD + MOD) % MOD;

            sumAi = ((sumAi - 1LL * a_i * (i + 1) + 1LL * b_j * (i + 1)) % MOD + MOD) % MOD;
            sumBj = ((sumBj - 1LL * b_j * (j + 1) + 1LL * a_i * (j + 1)) % MOD + MOD) % MOD;

        } else if (type == 2) {
            if (i != j) {
                int a_i = A[i], a_j = A[j];

                sumAi = ((sumAi - 1LL * a_i * (i + 1) - 1LL * a_j * (j + 1)) % MOD + MOD) % MOD;
                sumAi = (sumAi + 1LL * a_i * (j + 1) + 1LL * a_j * (i + 1)) % MOD;

                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        } else if (type == 3) {
            if (i != j) {
                int b_i = B[i], b_j = B[j];

                sumBj = ((sumBj - 1LL * b_i * (i + 1) - 1LL * b_j * (j + 1)) % MOD + MOD) % MOD;
                sumBj = (sumBj + 1LL * b_i * (j + 1) + 1LL * b_j * (i + 1)) % MOD;

                int tmp = B[i];
                B[i] = B[j];
                B[j] = tmp;
            }
        }

        result[q + 1] = (int)((sumAi * sumB + sumBj * sumA) % MOD);
    }

    *out_n = Q + 1;
    return result;
}

int main() {
    int out_n;
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++) {
        int N, M;
        scanf("%d %d", &N, &M);

        int *A = (int *)malloc(sizeof(int) * N);
        for(int i = 0; i < N; i++) scanf("%d", &A[i]);

        int *B = (int *)malloc(sizeof(int) * M);
        for(int i = 0; i < M; i++) scanf("%d", &B[i]);

        int Q;
        scanf("%d", &Q);

        int **queries = (int **)malloc(Q * sizeof(int *));
        for(int i = 0; i < Q; i++) {
            queries[i] = (int *)malloc(3 * sizeof(int));
            for(int j = 0; j < 3; j++) {
                scanf("%d", &queries[i][j]);
            }
        }

        int* out_ = array_queries(N, M, A, B, Q, queries, &out_n);
        printf("%d", out_[0]);
        for(int i = 1; i < out_n; i++) printf(" %d", out_[i]);
        printf("\n");
    }
    return 0;
}

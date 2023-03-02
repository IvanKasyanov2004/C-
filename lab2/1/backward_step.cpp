#include <iostream>
#include <random>

#ifndef N
#define N 100
#endif

void generate_array(int (&a)[N]){
    int arr[ ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0 , 9);

    for(unsigned counter = 0; counter < N; counter++){
        a[counter] = arr[dstr(rng)];
    }  
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void show_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;    
}

void backward_step(int (&a)[N], unsigned const begin_idx, unsigned const end_idx){
    for(int i = begin_idx; i > end_idx; i--){
        if(a[i - 1] > a[i]){
            swap(a[i - 1], a[i]);
        }
    }
}

int main(){
    int a[N];
    generate_array(a);
    show_array(a);
    for(int i = 0; i < N - 1; i++){
        backward_step(a, N - 1, i);
    }
    show_array(a);
}
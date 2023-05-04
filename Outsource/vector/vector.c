/*
Create Vector
Free Vector
Add Item
Delete Item

*/
const size_t VECTOR_INIT_CAPACITY = 4;

typedef struct {
    void ** data;
    size_t count;
    size_t capacity;
} Vector
// https://alexandra-zaharia.github.io/posts/implementing-a-vector-in-c/


Vector *CreateVector() {
    Vector *vec = malloc(sizeof(Vector));
    if (!vec) return NULL;

    vec->count = 0;
    vec->capacity = VECTOR_INIT_CAPACITY;
    vec->data = malloc(vector->capacity *sizeof(void*));
    if (!vector->data) return NULL;
    return v;
}
void FreeVector(Vector *vec) {
    if (!(vec && vec->data)) return;
    free(vec->data);
    free(vec);
}
static int _ResizeVector(Vector *vec,size_t capacity) {
    
}
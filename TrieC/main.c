#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct Trie Trie;

struct Trie{
    Trie* children[ALPHABET_SIZE];
    bool is_leaf;
};

Trie* trieCreate();
void trieInsert(Trie* obj, char* word);
bool trieSearch(Trie* obj, char* word);
bool trieStartsWith(Trie* obj, char* word);
void trieFree(Trie* obj);

int main(void) {
    bool const expected_param_2 = false;
    bool const expected_param_3 = true;

    Trie* obj = trieCreate();
    trieInsert(obj, "apple");

    bool param_2 = trieSearch(obj, "app");
    bool param_3 = trieStartsWith(obj, "app");

    printf("param_2: %d\nparam_3: %d\n", expected_param_2 == param_2, expected_param_3 == param_3);

    trieFree(obj);
}

Trie* trieCreate() {
    Trie* new_trie = (Trie*)calloc(1, sizeof(Trie));
    return new_trie;
}

void trieInsert(Trie* obj, char* word) {
    Trie* curr_node = obj;

    for (size_t i = 0; word[i] != '\0'; ++i) {
        if (curr_node->children[word[i] - 'a'] == NULL) {
            curr_node->children[word[i] - 'a'] = trieCreate();
        }

        curr_node = curr_node->children[word[i] - 'a'];
    }

    curr_node->is_leaf = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* curr_node = obj;

    for (size_t i = 0; word[i] != '\0'; ++i) {
        if (curr_node->children[word[i] - 'a'] == NULL)
            return false;
        
        curr_node = curr_node->children[word[i] - 'a'];
    }

    return curr_node->is_leaf;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* curr_node = obj;

    for (size_t i = 0; prefix[i] != '\0'; ++i) {
        if (curr_node->children[prefix[i] - 'a'] == NULL)
            return false;
        
        curr_node = curr_node->children[prefix[i] - 'a'];
    }

    return true;
}

void trieFree(Trie* obj) {
    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
        if (obj->children[i] != NULL)
            trieFree(obj->children[i]);
    }

    free(obj);
}
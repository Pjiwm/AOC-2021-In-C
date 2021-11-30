#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


// Strings

// add element to end of list
void str_insert_tail(String_Node** _root, char* _value) {
    String_Node* new_node = malloc(sizeof(String_Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->value = _value;

    if (*_root == NULL) {
        *_root = new_node;
        return;
    }

    String_Node* curr = *_root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}
// add element to beginning of list
void str_insert_head(String_Node** _root, char* _value) {
    String_Node* new_node = malloc(sizeof(String_Node));
    // if(new_node == NULL) {
    //     return 3;
    // }
    new_node->value = _value;
    new_node->next = *_root;

    *_root = new_node;
}
// add element after root
void str_insert_after(String_Node* node, char* value) {
    String_Node* new_node = malloc(sizeof(String_Node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
    // if(new_node == NULL) {
    //     return 4;
    // }
}

void str_deallocate(String_Node** _root) {
    String_Node* curr = *_root;

    while (curr != NULL) {
        String_Node* aux = curr;
        curr = curr->next;
        free(aux);
    }

    *_root = NULL;
}

// Ints

// add element to end of list
void int_insert_tail(Int_Node** _root, int _value) {
    Int_Node* new_node = malloc(sizeof(Int_Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->value = _value;

    if (*_root == NULL) {
        *_root = new_node;
        return;
    }

    Int_Node* curr = *_root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}
// add element to beginning of list
void int_insert_head(Int_Node** _root, int _value) {
    Int_Node* new_node = malloc(sizeof(Int_Node));
    // if(new_node == NULL) {
    //     return 3;
    // }
    new_node->value = _value;
    new_node->next = *_root;

    *_root = new_node;
}
// add element after root
void int_insert_after(Int_Node* node, int value) {
    Int_Node* new_node = malloc(sizeof(Int_Node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
    // if(new_node == NULL) {
    //     return 4;
    // }
}

void int_deallocate(Int_Node** _root) {
    Int_Node* curr = *_root;

    while (curr != NULL) {
        Int_Node* aux = curr;
        curr = curr->next;
        free(aux);
    }

    *_root = NULL;
}




// Long long ints

// add element to end of list
void long_long_int_insert_tail(Long_Long_Int_Node** _root, long long int _value) {
    Long_Long_Int_Node* new_node = malloc(sizeof(Long_Long_Int_Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->value = _value;

    if (*_root == NULL) {
        *_root = new_node;
        return;
    }

    Long_Long_Int_Node* curr = *_root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}
// add element to beginning of list
void long_long_int_insert_head(Long_Long_Int_Node** _root, long long int _value) {
    Long_Long_Int_Node* new_node = malloc(sizeof(Long_Long_Int_Node));
    // if(new_node == NULL) {
    //     return 3;
    // }
    new_node->value = _value;
    new_node->next = *_root;

    *_root = new_node;
}
// add element after root
void long_long_int_insert_after(Long_Long_Int_Node* node, long long int value) {
    Long_Long_Int_Node* new_node = malloc(sizeof(Long_Long_Int_Node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
    // if(new_node == NULL) {
    //     return 4;
    // }
}

void long_long_int_deallocate(Long_Long_Int_Node** _root) {
    Long_Long_Int_Node* curr = *_root;

    while (curr != NULL) {
        Long_Long_Int_Node* aux = curr;
        curr = curr->next;
        free(aux);
    }

    *_root = NULL;
}

// int main() {
//     StringNode* root = NULL;
//     str_insert_tail(&root, "s");
//     str_insert_tail(&root, "sd");
//     str_insert_tail(&root, "tit");
//     str_insert_head(&root, "ddd");

//     insert_after(root->next, "woo");

//     for (Node* curr = root; curr != NULL; curr = curr->next) {
//         printf("%s\n", curr->value);
//     }

//     str_deallocate(&root);
//     return 0;
// }